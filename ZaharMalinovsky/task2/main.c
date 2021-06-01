#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char *str, *result;
  const int MAX_STR_LEN = 1000;
  str = malloc(sizeof(char) * (MAX_STR_LEN + 1));
  result = malloc(sizeof(char) * (2 * MAX_STR_LEN + 1));
  if (str == NULL || result == NULL){
    printf("Memory error.");
    free(str); free(result);
    return 1;
  }

  FILE *input_file, *output_file;
  if ((input_file = fopen("input.txt", "r")) == NULL){
    printf("Error opening input file");
    free(str); free(result);
    return 1;
  }
  if ((output_file = fopen("output.txt", "w")) == NULL){
    printf("Error opening output file");
    free(str); free(result);
    fclose(input_file);
    return 1;
  }

  fgets(str, MAX_STR_LEN, input_file);

  int i = 0, j = 0, n = strlen(str);
  while (i < n){
    if (str[i] == ',' || str[i] == ':' || str[i] == ';' || str[i] == '.' || str[i] == '?' || str[i] == '!'){
      int is_end_of_sentence = str[i] == '.' || str[i] == '?' || str[i] == '!';
      result[j] = str[i];
      i++; j++;
      while (i < n && str[i] == ' ') i++;
      if (i < n){
        // if it isn't last word in string, insert space
        result[j] = ' '; j++;
        if (is_end_of_sentence){
          // make current letter uppercase
          str[i] = toupper(str[i]);
        }
      }
    } else {
      result[j] = str[i];
      i++; j++;
    }
  }
  fputs(result, output_file);

  free(str); free(result);
  fclose(input_file);
  fclose(output_file);
  return 0;
}