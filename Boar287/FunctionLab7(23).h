#pragma once
#include "DataBaseElement.h"
#include <stdlib.h>

void FillSourceCode(DataBaseElement* current,char* FileName);
void FillStatementCode(DataBaseElement* current,char* FileName);
int CountNumberInFile(char* FileName);
void GetElemInfo(DataBaseElement current,int index);
void Functionality(int* Choice);
void CommnetFunctionality(int* Choice);
void GetAllInfo(DataBaseElement* database,int SIZE);
void SortByTheme(DataBaseElement* database, int SIZE);
void SortByLanguage(DataBaseElement* database, int SIZE);
void DeleteComment(DataBaseElement* current);
void AddComment(DataBaseElement* current);
void RedactComment(DataBaseElement* current);