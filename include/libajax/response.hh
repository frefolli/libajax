#ifndef LIBAJAX_RESPONSE_HH
#define LIBAJAX_RESPONSE_HH

#define Status unsigned int

#include <string>
#include <map>

class Response {
    private:
        Status status;
        std::string data;
        std::map<std::string, std::string> headers;
    public:
        Response(Status status,
                 std::string data,
                 std::map<std::string, std::string> headers);
        Status getStatus();
        std::string getData();
        std::map<std::string, std::string> getHeaders();
        std::string toString();
};

#endif
