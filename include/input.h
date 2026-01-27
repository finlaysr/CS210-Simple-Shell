#define INPUT_LEN 512

// Read in input from stdin
int get_input(char *output[INPUT_LEN]);

// Turn input string into array of strings in output
void tokenize(char input[INPUT_LEN], char *output[INPUT_LEN]);

// Delete all words in array
int clear(char *array[INPUT_LEN]);
