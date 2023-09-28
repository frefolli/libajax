#include <libajax/request_builder.hh>

RequestBuilder::RequestBuilder() {}

RequestBuilder& RequestBuilder::setUrl(std::string url) {
    this->url = url;
    return *this;
}

RequestBuilder& RequestBuilder::setMethod(Method method) {
    this->method = method;
    return *this;
}

RequestBuilder& RequestBuilder::setData(std::string data) {
    this->data = data;
    return *this;
}

RequestBuilder& RequestBuilder::addHeader(std::string name, std::string value) {
    headers[name] = value;
    return *this;
}

Request RequestBuilder::build() {
    return Request(url, method, data, headers);
}
