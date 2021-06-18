#include <stdio.h>  
#include <stdlib.h>
#include <ctype.h>
void CorrectedLine() {
    int strLength = 0;
    char str[255], ch,prevCh;
    while ((ch = getchar()) != '\n') {  
        if (ch == ',' || ch == ':' || ch == ';' || ch == '.' || ch == '!' || ch == '?') {  
            str[strLength++] = ch;     
            str[strLength++] = ' ';          //добавляем пробелы по правилу после указанных символов
        } 
        else if (ch == ' ' && !isalpha(prevCh )) {
            continue;               //срезаем лишние пробелы, если таковые есть в начальной строке
        }
        else {
            str[strLength++] = ch;  //копируем символы в выходную строку
        }
        prevCh = ch;
    }
    for (int i = 0; i < strLength; i++) {
        if (str[i] == '.' || str[i] == '?' || str[i] == '!' && str[i + 2] != '\0') {
            str[i + 2] = toupper(str[i + 2]);  //добавляем заглавные буквы по правилу
        }
    }
    str[strLength] = '\0';
    printf("Your corrected line is: \n");
    puts(str);
}
void main()
{    
    printf("Enter your line please \n");
    CorrectedLine();                
}
