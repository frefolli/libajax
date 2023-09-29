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

size_t Ajax::handleResponseHeaders(char *buffer, size_t size, size_t nitems, void *destination) {
    std::map<std::string, std::string>* headers = (std::map<std::string, std::string>*) destination;
    size_t nread = 0;
    size_t index = 0;
    while (nread != nitems && index != size) {
       
    }
    return index;
}

size_t Ajax::handleResponseData(char *ptr, size_t size, size_t nmemb, void *destination) {
    std::string* data = (std::string*) destination;
    data->append(ptr, size * nmemb);
    return size * nmmemb;
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
    
    // get HEADERS
    std::map<std::string, std::string> responseHeaders;
    rescue(curl_easy_setopt(handle, CURLOPT_HEADERFUNCTION, &Ajax::handleResponseHeaders));
    rescue(curl_easy_setopt(CURL *handle, CURLOPT_HEADERDATA, (void*) &responseHeaders));

    // get DATA
    std::string responseData;
    rescue(curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, &Ajax::handleResponseData));
    rescue(curl_easy_setopt(CURL *handle, CURLOPT_WRITEDATA, (void*) &responseData));

    // perform REQUEST
    rescue(curl_easy_perform(handle));

    // get STATUS
    Status responseStatus;
    rescue(curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &responseStatus));

    curl_slist_free_all(headers);
    curl_easy_cleanup(handle);

    // deliver an empty response for now, TODO
    return Response(responseStatus, responseData, responseHeaders);
}
