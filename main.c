#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "common_opts.h"

void show_version() { printf("version 0.0.0\n"); }

void show_help(FILE *out) {
  fprintf(out, "%s: usage: %s [-fvh] ...\n", progname, progname);
}

int main(int argc, char **argv) {
  int c;

  while (-1 != (common_getopt(argc, argv, "a:bc"))) {
    switch (c) {
    case 'a':
      printf("opt a: %s\n", optarg);
      break;
    case 'b':
      printf("opt b\n");
      break;
    case 'c':
      printf("opt c\n");
      break;
    }
  }
}
