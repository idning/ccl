/*
 * file   : test_event.c
 * author : ning
 * date   : 2014-06-30 17:26:31
 */

#include "nc_core.h"
#include "testhelp.h"

static const char       *log_file = "/tmp/test_log.log";

void
clean()
{
    char buf[1024];
    snprintf(buf, sizeof(buf), "rm %s", log_file);;;;
    system(buf);
}

int
str_count(const char *haystack, const char *needle)
{
    char       *p = haystack;
    int         cnt = 0;
    int         needle_len = strlen(needle);

    for (;*p; p++) {
        if(0 == strncmp(needle, p, needle_len))
            cnt ++;
    }
    return cnt;
}

int
test_log()
{
    FILE       *f;
    char        buf[1024];

    log_init(LOG_NOTICE, (char *)log_file);
    clean();

    log_reopen(); /* create new file */

    loga("1. loga");
    log_debug(LOG_DEBUG, "2. debug log");
    log_debug(LOG_NOTICE, "3. notice log");
    log_debug(LOG_WARN, "4. warn log");

    f = fopen(log_file, "r");
    if (f == NULL) {
        test_cond("open file", 0);
    }
    fread(buf, 1, sizeof(buf), f);

    test_cond("cnt-line",
              3 == str_count(buf, "\n"));
    test_cond("loga",
              strstr(buf, "loga"));

    test_cond("debug",
              !strstr(buf, "debug"));

    test_cond("notice",
              strstr(buf, "notice"));

    test_cond("warn",
              strstr(buf, "warn"));
}

int
main()
{
    test_log();

    test_report();
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
