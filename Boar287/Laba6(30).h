#pragma once
#include <ctype.h>
#include <stdio.h>
#include "BinaryTree.h"
int Length(const char* string);
void FillBinaryTree(struct binaryTree *Oak,const char* Sentence);
void PrintBinaryTree(struct binaryTree* Oak, const char* Sentence);
void DivideSentence(char* Sentence);