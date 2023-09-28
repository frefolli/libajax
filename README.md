# libajax

A sane and c++-oriented LibCurl wrapper

# Semantica

Request(url, method, data, headers)

Request = RequestBuilder.addX.build

Response = Ajax::perform(Request)

Response(status, data, headers)
