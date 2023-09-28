#include <libajax/method.hh>
#include <libajax/request.hh>
#include <libajax/response.hh>
#include <libajax/request_builder.hh>
#include <libajax/ajax.hh>
#include <iostream>
#include <stdexcept>

int main(int argc, char** args) {
    RequestBuilder builder;
    Request request = builder
                        .setUrl("https://www.google.com")
                        .setMethod(GET).build();
    try {
        Response response = Ajax::perform(request);
        std::cout << response.toString()  << std::endl;
    } catch(std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
    }
}
