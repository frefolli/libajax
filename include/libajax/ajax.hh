#ifndef LIBAJAX_AJAX_HH
#define LIBAJAX_AJAX_HH

#include <libajax/request.hh>
#include <libajax/response.hh>
#include <cstddef>

class Ajax {
    public:
        static Response perform(Request request);
        static size_t handleResponseHeaders(char *buffer, size_t size, size_t nitems, void *userdata);
        static size_t handleResponseData(char *ptr, size_t size, size_t nmemb, void *userdata);
};

#endif
