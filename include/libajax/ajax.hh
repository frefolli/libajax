#ifndef LIBAJAX_AJAX_HH
#define LIBAJAX_AJAX_HH

#include <libajax/request.hh>
#include <libajax/response.hh>

class Ajax {
    public:
        static Response perform(Request request);
};

#endif
