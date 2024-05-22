#ifndef _COMMON_OPTS_H
#define _COMMON_OPTS_H

#include <stdbool.h>
#include <stdio.h>

extern char *progname;
extern bool flag_foreground;
extern bool flag_show_version;
extern bool flag_log_syslog;

void show_version();
void show_help(FILE *);
int common_getopt(int, char **, char *);

#endif // _COMMON_OPT_H
