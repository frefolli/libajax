#ifndef LIBAJAX_REQUEST_HH
#define LIBAJAX_REQUEST_HH

#include <string>
#include <map>
#include <libajax/method.hh>

class Request {
    private:
        std::string url;
        Method method;
        std::string data;
        std::map<std::string, std::string> headers;
    public:
        Request(std::string url,
                Method method,
                std::string data,
                std::map<std::string, std::string> headers);
        Method getMethod();
        std::string getUrl();
        std::string getData();
        std::map<std::string, std::string> getHeaders();
        std::string toString();
};

#endif
