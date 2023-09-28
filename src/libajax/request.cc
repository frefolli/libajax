#include <libajax/request.hh>
#include <sstream>

Request::Request(std::string url,
        Method method,
        std::string data,
        std::map<std::string, std::string> headers) :
    url(url), method(method), data(data), headers(headers) {}

Method Request::getMethod() {
    return method;
}

std::string Request::getUrl() {
    return url;
}

std::string Request::getData() {
    return data;
}

std::map<std::string, std::string> Request::getHeaders() {
    return headers;
}

std::string Request::toString() {
    std::ostringstream out ("");
    out << "Request(\"" << url << "\", " << method << ", \"" << data << "\", ";
    
    out << "{";
    bool notFirst = false;
    for (auto pair : headers) {
        if (notFirst)
            out << ", ";
        else
            notFirst = true;

        out << "\"" << pair.first << "\": " << "\"" << pair.second << "\"";
    }
    out << "}";
    
    out << ")";
    return out.str();
}
