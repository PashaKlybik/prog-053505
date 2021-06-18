#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define HAVE_STRUCT_TIMESPEC

#include "nodes.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define esc 27
#define delimetr "======================================================================================================================="

//redefine this if (number of websites) or (maximal length of their name + 1) changes
//redefine this if you'd like to change password or subfolder for databases       
#define NUM_OF_WEBS 8
#define MAX_WEBNAME_LENGTH 11
#define PASSWORD "password"
#define FOLDER_NAME "\\data\\"
//redefine this if (number of websites) or (maximal length of their name + 1) changes
//redefine this if you'd like to change password or subfolder for databases

extern struct List* webs[NUM_OF_WEBS];
extern const char web_names[][MAX_WEBNAME_LENGTH];
extern short file_flags[NUM_OF_WEBS];

void clrscr(void);
void header(char* path, char* hint);
void program_info(void);
void get_unsigned(int* num);
void free_mem(void);