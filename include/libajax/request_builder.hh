#ifndef LIBAJAX_REQUEST_BUILDER_HH
#define LIBAJAX_REQUEST_BUILDER_HH

#include <libajax/request.hh>

class RequestBuilder {
    private:
        std::string url;
        Method method;
        std::string data;
        std::map<std::string, std::string> headers;
    public:
        RequestBuilder();
        RequestBuilder& setUrl(std::string url);
        RequestBuilder& setMethod(Method method);
        RequestBuilder& setData(std::string data);
        RequestBuilder& addHeader(std::string name, std::string value);
        Request build();
};

#endif
