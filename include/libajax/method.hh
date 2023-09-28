#ifndef LIBAJAX_METHOD_HH
#define LIBAJAX_METHOD_HH

#include <ostream>
#include <string>

enum Method {
    HEAD, GET, POST, PUT, PATCH, DELETE
};

std::ostream& operator<<(std::ostream& out, Method method);
std::string toString(Method method);

#endif
