//
//  main.c
//  4.1.1
//
//  Created by Дима Гузерчук on 28.03.21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
 
//С клавиатуры вводится многострочный текст.
//Отсортировать по длине и вывести на печать все слова текста.

int main(int argc, char *argv[])
{
  setlocale(LC_ALL,"");
  char str[100];
  printf("Введите предложение:\n");
  gets(str);
  int n = strlen(str);
  char str3[100]={0};
 
  // запись в дмумерный массив
  char str2[80][80]={0};
  int s=1;
  for(int i=0, j=0, y=0; str[i]!=0; i++)
  {
    if(str[i]==' '&&str[i-1]!=' ')
    {
      s++;
      j++;
      y=0;
      continue;
    }
    str2[j][y]=str[i];
    y++;
  }
 
  // построчно количество букв и позиция
  int a[s][2];
  for(int i=0; i<s; i++)
    a[i][0] = (int)strlen(str2[i]);
  for(int i=0; i<s; i++)
    a[i][1]=i;
 
  //сортировка количества букв
  int b[2];
  for(int i=0; i<s; i++)
  {
    for(int j=i+1; j<s; j++)
    {
      if(a[j][0]>a[i][0])
      {
         for(int y=0; y<2; y++)
           b[y]=a[i][y];
         for(int y=0; y<2; y++)
           a[i][y]=a[j][y];
         for(int y=0; y<2; y++)
           a[j][y]=b[y];
      }
    }
  }
  
  //сортировка строки
    for(int i=0, p=0; (void)(i<s), p<n; i++)
  {
    int y=a[i][1];
    for(int j=0; j<a[i][0]; j++)
    {
      str3[p]=str2[y][j];
      p++;
    }
    str3[p]=' ';
    p++;
  }
  puts(str3);
    return 0;
}
