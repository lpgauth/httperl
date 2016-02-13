#include <erl_nif.h>
#include <stdbool.h>
#include <stdint.h>

#include "uriparser.h"

#define MAX_PARAMS 4

static ERL_NIF_TERM make_atom(ErlNifEnv *env,
                              const char *name)
{
    ERL_NIF_TERM ret;

    if (enif_make_existing_atom(env, name, &ret, ERL_NIF_LATIN1)) {
        return ret;
    }
    return enif_make_atom(env, name);
}


static ERL_NIF_TERM make_binary_string(ErlNifEnv *env,
                                       const char *buffer,
                                       int size)
{
    ErlNifBinary bin;

    enif_alloc_binary(size, &bin);
    memcpy(bin.data, buffer, size);
    bin.size = size;
    return enif_make_binary(env, &bin);
}


static ERL_NIF_TERM make_error(ErlNifEnv *env,
                               const char *mesg)
{
    ERL_NIF_TERM error = make_atom(env, "error");
    return enif_make_tuple2(env, error, make_atom(env, mesg));
}


static ERL_NIF_TERM uriparser_parse_uri(ErlNifEnv *env,
                                        int argc __attribute__ ((unused)),
                                        const ERL_NIF_TERM argv[])
{
    ErlNifBinary input;
    ERL_NIF_TERM ret;

    if (!enif_inspect_iolist_as_binary(env, argv[0], &input))
        return enif_make_badarg(env);

    const char* schema;
    size_t schema_len;
    const char* host;
    size_t host_len;
    int port;
    const char* path;
    size_t path_len;
    struct uri_keyvalue params[MAX_PARAMS];
    size_t num_params = MAX_PARAMS;
    const char* fragment;
    size_t fragment_len;

    int parse_ret = parse_uri(input.data, input.size, &schema, &schema_len,
        &host, &host_len, &port, &path, &path_len, params, &num_params,
        &fragment, &fragment_len);

    if (parse_ret == 0) {
        ret = enif_make_new_map(env);

        enif_make_map_put(env, ret, make_atom(env, "schema"),
            make_binary_string(env, schema, schema_len) , &ret);
        enif_make_map_put(env, ret, make_atom(env, "host"),
            make_binary_string(env, host, host_len) , &ret);
        enif_make_map_put(env, ret, make_atom(env, "path"),
            make_binary_string(env, path, path_len) , &ret);
        enif_make_map_put(env, ret, make_atom(env, "port"),
            enif_make_int(env, port), &ret);
    } else {
      ret = make_error(env, "invalid_uri");
    }

    return ret;
}


static int on_load(ErlNifEnv *env __attribute__((unused)),
                   void **priv __attribute__((unused)),
                   ERL_NIF_TERM info __attribute__((unused)))
{
    return 0;
}


static int upgrade(ErlNifEnv* env __attribute__((unused)),
                   void ** priv __attribute__((unused)),
                   void **old_priv __attribute__((unused)),
                   ERL_NIF_TERM load_info __attribute__((unused)))
{
    return 0;
}


static ErlNifFunc nif_functions[] = {
    {"parse_uri", 1, uriparser_parse_uri, 0}
};

ERL_NIF_INIT(httperl, nif_functions, &on_load, NULL, &upgrade, NULL)
