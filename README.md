# httperl

High Performance Erlang HTTP library

## Examples

```erlang
1> httperl:parse_uri(<<"http://rtb.adgrx.com/impressions/INFO/1337.js">>).
#{host => <<"rtb.adgrx.com">>,
  path => <<"/impressions/INFO/1337.js">>,
  port => -1,
  schema => <<"http">>}
```

-type error()    :: {error, atom()}.

-type request()  :: # {
    min_version => 0 | 1,
    status      =>
    msg         => binary()
}.

-type response() :: # {


}.

-type url()      :: # {
    protocol => http | https,
    host     => binary(),
    port     => pos_integer(),
    path     => binary(),
}.

-spec parse_request(binary()) -> {ok, request()} | error().
-spec parse_response(binary()) -> {ok, response()} | error().
-spec parse_url(binary()) -> {ok, url()} | error().
