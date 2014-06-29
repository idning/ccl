/*
 * file   : example.c
 * author : ning
 * date   : 2014-06-28 08:34:37
 */

#include <stdio.h>
#include "nc_core.h"

typedef struct kv_server_s {
    /* General */
    char *config_file;          /* Absolute config file path, or NULL */
    nc_conf_t conf;


    char *ip;
    int port;

    int tcp_timeout;


    struct array * blacklist;
}kv_server_t;

kv_server_t server;

int main(int argc, const char **argv) {

    server.config_file = "conf/kv.conf";
    if (NC_ERROR == nc_conf_init(&server.conf, server.config_file)) {
        return -1;
    }

    server.ip = nc_conf_get_str(&server.conf, "ip", "0.0.0.0");
    server.port = nc_conf_get_num(&server.conf, "port", 8000);

    server.tcp_timeout = nc_conf_get_num(&server.conf, "tcp.timeout", 100);

    log_stderr("start with ip:%s, port:%d, tcp_timeout:%d ", server.ip, server.port, server.tcp_timeout);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */


