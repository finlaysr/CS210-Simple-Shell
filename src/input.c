#include <stdio.h>
#include <string.h>

void tokenize(char input[512]) {
  const char delimiters[] = " \t|><&;";

  char *token;
  token = strtok(input, delimiters);

  while (token) {
    printf("%s\n", token);

    token = strtok(NULL, delimiters);
  }
}
