#include "../include/input.h"
#include <stdio.h>
#include <string.h>

const char delimiters[] = " \t\n|><&;";

int get_input(char *input_buffer, char *output[INPUT_LEN]) {
  printf("--> ");
  fflush(stdout); // Fix for prompt not printing correctly

  char *ret = fgets(input_buffer, INPUT_LEN, stdin);
  // Exit if CTR-d pressed
  if (!ret) {
    return 0;
  }

  tokenize(input_buffer, output);
  // If input is empty
  if (!*output) {
    return 1;
  }

  // Exit if exit (and nothing else) inputted
  return (strcmp(output[0], "exit") || output[1]);
}

int tokenize(char input[INPUT_LEN], char *output[INPUT_LEN]) {
  // Check input is not empty
  if (!input) {
    return 1;
  }
  char *token = strtok_r(input, delimiters, &input);

  for (int i = 0; token; i++) {
    output[i] = token;
    token = strtok_r(input, delimiters, &input);
  }
  return 1;
}

int clear(char *array[INPUT_LEN]) {
  // Check array is not already empty
  if (!*array) {
    return 1;
  }
  for (int i = 0; array[i]; i++) {
    array[i] = NULL;
  }
  return 0;
}
