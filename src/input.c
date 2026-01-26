#include "../include/input.h"
#include <stdio.h>
#include <string.h>

const char delimiters[] = " \t\n|><&;";

int get_input(char output[512]) {
  printf("🍣🍣🍣> ");

  char input_buffer[512];
  char *tmp = fgets(input_buffer, 511, stdin); // WARN: Check if n correct

  tokenize(input_buffer, output);

  return !((strcmp(input_buffer, "exit\n") == 0 || (tmp == NULL)));
}

void tokenize(char input[512], char output[512]) {
  char *token;
  token = strtok_r(input, delimiters, &input);

  while (token) {
    strlcat(output, token, 512);
  }

  printf("tokens: {%s}", output);
}
