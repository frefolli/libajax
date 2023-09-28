#include <libajax/method.hh>
#include <sstream>

std::ostream& operator<<(std::ostream& out, Method method) {
    switch (method) {
        case HEAD: out << "HEAD"; break;
        case GET: out << "GET"; break;
        case POST: out << "POST"; break;
        case PUT: out << "PUT"; break;
        case PATCH: out << "PATCH"; break;
        case DELETE: out << "DELETE"; break;
    }
    return out;
}

std::string toString(Method method) {
    std::ostringstream out ("");
    out << method;
    return out.str();
}
