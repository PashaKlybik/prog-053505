#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int Length(char* str)
{
    int i = 0;
    while (str[i] != '\0')  i++;
    return i;
}

int main()
{
    const int max_length = 1000;

    char* input = malloc(sizeof(char) * (max_length + 1));
    char* output = malloc(sizeof(char) * (2 * max_length + 1));

    if (input == NULL || output == NULL)
    {
        printf("Lack of memory");
        free(input); 
        free(output);
        return 1;
    }

    gets(input);
    
    int i = 0, j = 0, input_length = Length(input);

    while (i < input_length)
    {
        if (input[i] == ',' || input[i] == ':' || input[i] == ';' || input[i] == '.' || input[i] == '?' || input[i] == '!')
        {
            bool is_end_of_sentence = input[i] == '.' || input[i] == '?' || input[i] == '!';
            output[j] = input[i];
            i++; j++;

            while (i < input_length && input[i] == ' ') i++;

            if (i < input_length)
            {
                output[j] = ' '; j++;
                if (is_end_of_sentence) 
                {
                    input[i] = toupper(input[i]);
                }
            }
        }
        else
        {
            output[j] = input[i];
            i++; j++;
        }
    }

    input[i] = '\0'; output[j] = '\0';

    puts(output);

    free(input); free(output);

    return 0;
}

//good afternoon,Tim.how are you?i am fine!colors:red;white;yellow;blue.