#pragma once
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include <ctype.h>

typedef struct dataBaseNode
{
	int date[3] = { 0,0,0 };
	char Theme[35] = "";
	char Language[20] = "";
	char Data[1500] = "";//Исходник для кода и содержание для статьи
}DataBaseNode;

typedef struct dataBaseElement
{
	DataBaseNode sourceCode[1];
	DataBaseNode Statements[5];
	char Comments[5][1000] = {"","","","",""};
	int ComSize = 0;
	int StateSize = 0;
}DataBaseElement;

void FillSourceInfo(DataBaseElement* current, const char* Language, const char* Theme, int year, int month, int day,char* filename);
void FillComInfo(DataBaseElement* current, int index,const char* Data);
void FillStateInfo(DataBaseElement* current, int index, const char* _Language, const char* _Theme, int year, int month, int day);
void ShowInfo(DataBaseElement* current,int index);


