//
// Created by huibin on 6/22/17.
//

#include <curl/curl.h>

#include <microhttpd/microhttpd.h>
#include <stdlib.h>
#include <string.h>

#define PAGE "<html><head><title>libmicrohttpd demo</title>"\
             "</head><body>libmicrohttpd demo</body></html>"

void curl_get_test() {
    CURL *curl;
    CURLcode res;

    /* In windows, this will init the winsock stuff */
    curl_global_init(CURL_GLOBAL_ALL);

    /* get a curl handle */
    curl = curl_easy_init();
    if (curl) {
        /* First set the URL that is about to receive our POST. This URL can
           just as well be a https:// URL if that is what should receive the
           data. */
        curl_easy_setopt(curl, CURLOPT_URL,
                         "http://114.80.117.173/qyrrs?url=http%3A%2F%2Fvdata.tvxio.com%2Fcdn%2F0%2F1f%2F20170323%2Fdf845611c7418f9c80a999eee6e8ae%2FH264%2Fhigh%2Fslice%2F14858_1.m3u8&quality=high&sn=go_grf7qt3h&clipid=1785703&sid=a4d3146858734a9c8fe35625e515f3723&sign=abfda0ef5177de62bbe610935e7147d3&ne=1&clip=1");
        /* Now specify the POST data */
//        curl_easy_setopt(curl, CURLOPT_G, "name=daniel&project=curl");

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}


static int ahc_echo(void *cls,
                    struct MHD_Connection *connection,
                    const char *url,
                    const char *method,
                    const char *version,
                    const char *upload_data,
                    size_t *upload_data_size,
                    void **ptr) {
    static int dummy;
    const char *page = cls;
    struct MHD_Response *response;
    int ret;

    if (0 != strcmp(method, "GET"))
        return MHD_NO; /* unexpected method */
    if (&dummy != *ptr) {
        /* The first time only the headers are valid,
           do not respond in the first round... */
        *ptr = &dummy;
        return MHD_YES;
    }
    if (0 != *upload_data_size)
        return MHD_NO; /* upload data in a GET!? */
    *ptr = NULL; /* clear context pointer */
    response = MHD_create_response_from_buffer(strlen(page),
                                               (void *) page,
                                               MHD_RESPMEM_PERSISTENT);
    ret = MHD_queue_response(connection,
                             MHD_HTTP_OK,
                             response);
    MHD_destroy_response(response);
    return ret;
}

int microhttpserver_start_test(int port) {
    struct MHD_Daemon *d;
    d = MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION,
                         atoi("8080"),
                         NULL,
                         NULL,
                         &ahc_echo,
                         PAGE,
                         MHD_OPTION_END);
    if (d == NULL)
        return 1;
    (void) getc(stdin);
    MHD_stop_daemon(d);
    return 0;
}

int main(int argc, char *argv[]) {
    microhttpserver_start_test(8080);
    return 0;
}
