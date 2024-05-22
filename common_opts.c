#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "common_opts.h"

char *progname = NULL;
char *common_optstring = "fvhl";

bool flag_foreground;
bool flag_show_version;
bool flag_log_syslog;

void maybe_daemon() {
  if (!flag_foreground) {
    if (!daemon(0, 0)) {
      perror("daemon");
      exit(1);
    }
  }
}

int common_getopt(int argc, char **argv, char *optstring) {
  if (progname == NULL) {
    progname = argv[0];
  }
  int c;
  char *os;
  os = (char *)malloc(strlen(optstring) + strlen(common_optstring));
  sprintf(os, "%s%s", common_optstring, optstring);
  printf("final optstring: %s\n", os);
  while (-1 != (c = getopt(argc, argv, os))) {
    switch (c) {
    case 'f':
      flag_foreground = true;
      printf("will not run in foreground\n");
      break;
    case 'v':
      show_version();
      exit(0);
      break;
    case 'h':
      show_help(stdout);
      exit(0);
    case 'l':
      flag_log_syslog = true;
      break;

    default:
      return c;
    }
  }

  return -1;
}
