-module(httperl).

-export([
    % parse_request/1,
    parse_response/1,
    parse_uri/1
]).

%% internal
-export([
    init/0
]).

-on_load(init/0).

-define(NOT_LOADED, not_loaded(?LINE)).

-type parsed_uri() :: # {
    scheme => binary(),
    host   => binary(),
    port   => integer(),
    path   => binary()
}.

%% public
%% TODO: specs
% parse_request(_) ->
%     ?NOT_LOADED.

% TODO: specs
parse_response(_) ->
    ?NOT_LOADED.

-spec parse_uri(string()) ->
    {ok, parsed_uri()} | {error, invalid_uri}.

parse_uri(_) ->
    ?NOT_LOADED.

%% internal
-spec init() -> ok.

init() ->
    SoName = filename:join(priv_dir(), "httperl_nif"),
    case erlang:load_nif(SoName,[]) of
        ok -> ok;
        {error, Reason} ->
            error_logger:error_msg("httperl load_nif error: ~p~n", [Reason])
    end.

%% private
not_loaded(Line) ->
    erlang:nif_error({not_loaded, [{module, ?MODULE}, {line, Line}]}).

priv_dir() ->
    case code:priv_dir(?MODULE) of
        {error, _} ->
            EbinDir = filename:dirname(code:which(?MODULE)),
            AppPath = filename:dirname(EbinDir),
            filename:join(AppPath, "priv");
        Dir -> Dir
    end.
