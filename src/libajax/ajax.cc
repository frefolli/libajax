#include <libajax/ajax.hh>
#include <curl/curl.h>
#include <sstream>
#include <stdexcept>

std::string makeHeader(std::string name, std::string value) {
    std::ostringstream out ("");
    out << name << ": " << value;
    return out.str();
}

void inline rescue(CURLcode code) {
    if (code != CURLE_OK) {
        throw std::runtime_error(curl_easy_strerror(code));
    }
}

Response Ajax::perform(Request request) {
    CURL* handle = curl_easy_init();
    
    // set URL
    rescue(curl_easy_setopt(handle, CURLOPT_URL, request.getUrl().c_str()));
    rescue(curl_easy_setopt(handle, CURLOPT_VERBOSE, 1L));

    // set METHOD
    rescue(curl_easy_setopt(handle, CURLOPT_CUSTOMREQUEST, toString(request.getMethod()).c_str()));

    // set DATA
    if (request.getData().size() > 0) {
        rescue(curl_easy_setopt(handle, CURLOPT_POSTFIELDS, request.getData().c_str()));
    }

    // set HEADERS
    bool headersPresent = false;
    struct curl_slist *headers = nullptr;
    for (auto pair : request.getHeaders()) {
        headers = curl_slist_append(headers, makeHeader(pair.first, pair.second).c_str());
        headersPresent = true;
    }

    if (headersPresent) {
        rescue(curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers));
        rescue(curl_easy_setopt(handle, CURLOPT_HEADEROPT, CURLHEADER_SEPARATE));
    }

    // perform REQUEST
    rescue(curl_easy_perform(handle));

    Status status;
    rescue(curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &status));
    
    curl_slist_free_all(headers);
    curl_easy_cleanup(handle);

    // deliver an empty response for now, TODO
    return Response(status, "", {});
}
