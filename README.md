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
