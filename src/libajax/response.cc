#include <libajax/response.hh>
#include <sstream>

Response::Response(Status status,
     std::string data,
     std::map<std::string, std::string> headers) :
    status(status), data(data), headers(headers) {}

Status Response::getStatus() {
    return status;
}

std::string Response::getData() {
    return data;
}

std::map<std::string, std::string> Response::getHeaders() {
    return headers;
}

std::string Response::toString() {
    std::ostringstream out ("");
    out << "Response(" << status << ", \"" << /*data <<*/ "\", ";
    
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
