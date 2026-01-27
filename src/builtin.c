#include "../include/builtin.h"
#include "../include/input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int num = 2;
const char *names[] = {"getpath", "setpath"};
int (*funcs[])(char **) = {&getpath, &setpath};

int check_builtin(char *input[INPUT_LEN]) {
  for (int i = 0; i < num; i++) {
    if (!strcmp(input[0], names[i])) {
      funcs[i](input);
      return 1;
    }
  }
  return 0;
}

int getpath(char *input[INPUT_LEN]) {
  if (input[1]) {
    printf("getpath doesn't take any arguments!\n");
    return 1;
  }
  printf("%s\n", getenv("PATH"));
  return 0;
}

int setpath(char *input[INPUT_LEN]) {
  if (!input[1]) {
    printf("Please provide a path!\n");
    return 1;
  }
  return setenv("PATH", input[1], 1);
}
