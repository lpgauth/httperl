
#line 1 "uriparser.rl"
#include <stddef.h>
#include "uriparser.h"

#define EPARSE -1
#define ETOOMANYPARAMS -2


#line 11 "uriparser.c"
static const char _uri_parser_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1,
	3, 1, 4, 1, 5, 1, 6, 1,
	9, 1, 10, 1, 11, 1, 12, 1,
	14, 2, 0, 1, 2, 3, 11, 2,
	5, 8, 2, 7, 8, 2, 9, 10,
	2, 13, 14, 3, 6, 7, 8
};

static const char _uri_parser_key_offsets[] = {
	0, 0, 8, 16, 17, 18, 28, 36,
	38, 48, 55, 62, 70, 78, 87, 95,
	103
};

static const char _uri_parser_trans_keys[] = {
	43, 58, 45, 46, 48, 57, 97, 122,
	43, 58, 45, 46, 48, 57, 97, 122,
	47, 47, 47, 58, 60, 127, 0, 32,
	34, 35, 62, 63, 38, 127, 0, 32,
	34, 35, 60, 62, 48, 57, 34, 35,
	47, 58, 60, 62, 63, 127, 0, 32,
	60, 62, 127, 0, 32, 34, 35, 60,
	62, 127, 0, 32, 34, 35, 34, 35,
	60, 62, 63, 127, 0, 32, 34, 35,
	38, 127, 0, 32, 60, 62, 34, 35,
	38, 61, 127, 0, 32, 60, 62, 34,
	35, 38, 60, 62, 127, 0, 32, 34,
	35, 38, 60, 62, 127, 0, 32, 35,
	47, 63, 48, 57, 0
};

static const char _uri_parser_single_lengths[] = {
	0, 2, 2, 1, 1, 4, 2, 0,
	8, 3, 3, 6, 4, 5, 6, 6,
	3
};

static const char _uri_parser_range_lengths[] = {
	0, 3, 3, 0, 0, 3, 3, 1,
	1, 2, 2, 1, 2, 2, 1, 1,
	1
};

static const char _uri_parser_index_offsets[] = {
	0, 0, 6, 12, 14, 16, 24, 30,
	32, 42, 48, 54, 62, 69, 77, 85,
	93
};

static const char _uri_parser_indicies[] = {
	0, 2, 0, 0, 0, 1, 3, 4,
	3, 3, 3, 1, 5, 1, 6, 1,
	1, 1, 1, 1, 1, 1, 1, 7,
	1, 1, 1, 1, 1, 8, 9, 1,
	1, 11, 12, 13, 1, 1, 14, 1,
	1, 10, 1, 1, 1, 1, 1, 15,
	1, 1, 1, 1, 1, 16, 1, 18,
	1, 1, 19, 1, 1, 17, 1, 20,
	21, 1, 1, 1, 8, 1, 23, 24,
	25, 1, 1, 1, 22, 1, 27, 28,
	1, 1, 1, 1, 26, 1, 30, 31,
	1, 1, 1, 1, 29, 20, 32, 34,
	33, 1, 0
};

static const char _uri_parser_trans_targs[] = {
	2, 0, 3, 2, 3, 4, 5, 8,
	13, 16, 8, 9, 11, 7, 12, 10,
	10, 11, 9, 12, 9, 6, 13, 9,
	6, 14, 15, 9, 6, 15, 9, 6,
	11, 16, 12
};

static const char _uri_parser_trans_actions[] = {
	1, 0, 25, 0, 3, 0, 0, 5,
	9, 40, 0, 7, 28, 7, 7, 15,
	0, 0, 21, 21, 0, 0, 0, 31,
	31, 11, 13, 43, 43, 0, 34, 34,
	19, 23, 0
};

static const char _uri_parser_eof_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	7, 37, 17, 21, 0, 31, 43, 34,
	0
};

static const int uri_parser_start = 1;
static const int uri_parser_first_final = 8;
static const int uri_parser_error = 0;

static const int uri_parser_en_main = 1;


#line 12 "uriparser.rl"


int parse_uri(const char* buf_start, size_t buf_len,
                      const char** scheme, size_t* scheme_len,
                      const char** host, size_t* host_len,
                      int* port,
                      const char** path, size_t* path_len,
                      struct uri_keyvalue* params, size_t* num_params,
                      const char** fragment, size_t* fragment_len)
{
  const char *p = buf_start;
  const char *pe = p + buf_len;
  int cs;
  const char *eof = pe;
  int err = 0;

  *scheme = NULL;
  *scheme_len = 0;
  *host = NULL;
  *host_len = 0;
  *port = -1;
  *path = NULL;
  *path_len = 0;
  size_t max_params = *num_params;
  *num_params = 0;
  *fragment = NULL;
  *fragment_len = 0;


#line 137 "uriparser.c"
	{
	cs = uri_parser_start;
	}

#line 142 "uriparser.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _uri_parser_trans_keys + _uri_parser_key_offsets[cs];
	_trans = _uri_parser_index_offsets[cs];

	_klen = _uri_parser_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _uri_parser_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _uri_parser_indicies[_trans];
	cs = _uri_parser_trans_targs[_trans];

	if ( _uri_parser_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _uri_parser_actions + _uri_parser_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 15 "uriparser_common.rl"
	{
    *scheme = p;
  }
	break;
	case 1:
#line 19 "uriparser_common.rl"
	{
    *scheme_len = p - *scheme;
  }
	break;
	case 2:
#line 23 "uriparser_common.rl"
	{
    *host = p;
  }
	break;
	case 3:
#line 27 "uriparser_common.rl"
	{
    *host_len = p - *host;
  }
	break;
	case 4:
#line 31 "uriparser_common.rl"
	{
    if (*num_params >= max_params) {
      err = URI_TOOMANYPARAMS_ERR;
      {p++; goto _out; }
    }
    params[*num_params].name = p;
    params[*num_params].value = NULL;
  }
	break;
	case 5:
#line 40 "uriparser_common.rl"
	{
    params[*num_params].name_len = p - params[*num_params].name;
  }
	break;
	case 6:
#line 44 "uriparser_common.rl"
	{
    params[*num_params].value = p;
  }
	break;
	case 7:
#line 48 "uriparser_common.rl"
	{
    params[*num_params].value_len = p - params[*num_params].value;
  }
	break;
	case 8:
#line 52 "uriparser_common.rl"
	{
    (*num_params)++;
  }
	break;
	case 9:
#line 56 "uriparser_common.rl"
	{
    *fragment = p;
  }
	break;
	case 11:
#line 64 "uriparser_common.rl"
	{
    *path = p;
  }
	break;
	case 12:
#line 68 "uriparser_common.rl"
	{
    *path_len = p - *path;
  }
	break;
	case 13:
#line 72 "uriparser_common.rl"
	{
    *port = 0;
  }
	break;
	case 14:
#line 76 "uriparser_common.rl"
	{
    *port = *port * 10 + (*p) - '0';
  }
	break;
#line 305 "uriparser.c"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	const char *__acts = _uri_parser_actions + _uri_parser_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 3:
#line 27 "uriparser_common.rl"
	{
    *host_len = p - *host;
  }
	break;
	case 5:
#line 40 "uriparser_common.rl"
	{
    params[*num_params].name_len = p - params[*num_params].name;
  }
	break;
	case 6:
#line 44 "uriparser_common.rl"
	{
    params[*num_params].value = p;
  }
	break;
	case 7:
#line 48 "uriparser_common.rl"
	{
    params[*num_params].value_len = p - params[*num_params].value;
  }
	break;
	case 8:
#line 52 "uriparser_common.rl"
	{
    (*num_params)++;
  }
	break;
	case 9:
#line 56 "uriparser_common.rl"
	{
    *fragment = p;
  }
	break;
	case 10:
#line 60 "uriparser_common.rl"
	{
    *fragment_len = p - *fragment;
  }
	break;
	case 12:
#line 68 "uriparser_common.rl"
	{
    *path_len = p - *path;
  }
	break;
#line 369 "uriparser.c"
		}
	}
	}

	_out: {}
	}

#line 43 "uriparser.rl"


  if (err) {
      return err;
  } else if (cs < uri_parser_first_final) {
      return URI_PARSE_ERR;
  }

  return 0;
}
