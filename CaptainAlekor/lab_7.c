#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <windows.h>

typedef struct specialty
{
	char name[120];
	char faculty[6];
	int places;
	int id;
	struct specialty* next;
	struct specialty* prev;
}Specialty;

typedef struct document
{
	char fullName[40];
	int certAverage;
	char passport[16];
	char residence[100];
	int specId;
	int docId;
	struct document* next;
	struct document* prev;
}Document;

typedef struct specialties
{
	int size;
	Specialty* head;
	Specialty* tail;
}Specialties;

typedef struct documents
{
	int size;
	Document* head;
	Document* tail;
}Documents;

Specialties* CreateSpecList() 
{
	Specialties* list = (Specialties*)malloc(sizeof(Specialties));
	list->head = list->tail = NULL;
	list->size = 0;
	return list;
}

void AddSpec(Specialties* specList, char** data)
{
	Specialty* spec = (Specialty*)malloc(sizeof(Specialty));
	int i = -1;
	do 
	{
		i++;
		spec->name[i] = data[0][i];
	} while (data[0][i] != '\0');
	i = -1;
	do 
	{
		i++;
		spec->faculty[i] = data[1][i];
	} while (data[1][i] != '\0');
	spec->places = atoi(data[2]);
	spec->next = spec->prev = NULL;
	if (specList->head == NULL) 
	{
		specList->head = specList->tail = spec;
	}
	else 
	{
		specList->tail->next = spec;
		spec->prev = specList->tail;
		specList->tail = spec;
	}
	specList->size++;
	spec->id = specList->size;
}

void DeleteSpecList(Specialties* list) 
{
	Specialty* cur = list->head;
	while (cur) 
	{
		cur = list->head->next;
		free(list->head);
		list->head = cur;
	}
	free(list);
}

Documents* CreateDocList() 
{
	Documents* list = (Documents*)malloc(sizeof(Documents));
	list->head = list->tail = NULL;
	list->size = 0;
	return list;
}

void AddDoc(Documents* docList, char** data) 
{
	Document* doc = (Document*)malloc(sizeof(Document));
	int i = -1;
	do 
	{
		i++;
		doc->fullName[i] = data[0][i];
	} while (data[0][i] != '\0');
	doc->certAverage = atoi(data[1]);
	i = -1;
	do
	{
		i++;
		doc->passport[i] = data[2][i];
	} while (data[2][i] != '\0');
	i = -1;
	do 
	{
		i++;
		doc->residence[i] = data[3][i];
	} while (data[3][i] != '\0');
	doc->specId = atoi(data[4]);
	doc->docId = docList->size + 1;
	doc->next = doc->prev = NULL;
	if (docList->head == NULL)
	{
		docList->head = docList->tail = doc;
	}
	else 
	{
		docList->tail->next = doc;
		doc->prev = docList->tail;
		docList->tail = doc;
	}
	docList->size++;
}

void DelLastC(char* str) 
{
	if (str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';
}

void ReadSpecFile(char* fileName, Specialties* specList) 
{
	FILE* file;
	if (fopen_s(&file, fileName, "r"))
	{
		printf("Ошибка при открытии файла");
		getchar();
		exit(0);
	}
	char* buffer = (char*)malloc(sizeof(char) * 120);
	int linesAmount = 0;
	while (fgets(buffer, 120, file) != NULL) linesAmount++;
	free(buffer);
	rewind(file);
	if (linesAmount % 3) 
	{
		printf("Неправильное количество строк в файле специальностей");
		getchar();
		exit(0);
	}
	char** data = (char**)malloc(sizeof(char*) * 3);
	data[0] = (char*)malloc(sizeof(char) * 120);
	data[1] = (char*)malloc(sizeof(char) * 7);
	data[2] = (char*)malloc(sizeof(char) * 5);
	for (int i = 0; i < linesAmount / 3; i++) 
	{
		fgets(data[0], 120, file);
		fgets(data[1], 7, file);
		fgets(data[2], 5, file);
		for (int j = 0; j < 3; j++) DelLastC(data[j]);
		AddSpec(specList, data);
	}
	for (int i = 0; i < 3; i++)
	{
		free(data[i]);
	}
	free(data);
	fclose(file);
}

void AddLastC(char* str) 
{
	int length = strlen(str);
	str[length] = '\n';
	str[length + 1] = '\0';
}

void ReadDocFile(char* fileName, Documents* docList) 
{
	FILE* file;
	if (fopen_s(&file, fileName, "r"))
	{
		printf("Ошибка при открытии файла заявлений");
		getchar();
		exit(0);
	}
	char* buffer = (char*)malloc(sizeof(char) * 120);
	int linesAmount = 0;
	while (fgets(buffer, 120, file) != NULL) linesAmount++;
	free(buffer);
	rewind(file);
	if (linesAmount % 5) 
	{
		printf("Неправильное количество строк в файле заявлений");
		getchar();
		exit(0);
	}
	char** data = (char**)malloc(sizeof(char*) * 5);
	data[0] = (char*)malloc(sizeof(char) * 40);
	data[1] = (char*)malloc(sizeof(char) * 5);
	data[2] = (char*)malloc(sizeof(char) * 16);
	data[3] = (char*)malloc(sizeof(char) * 100);
	data[4] = (char*)malloc(sizeof(char) * 5);
	for (int i = 0; i < linesAmount / 5; i++) 
	{
		fgets(data[0], 40, file);
		fgets(data[1], 5, file);
		fgets(data[2], 16, file);
		fgets(data[3], 100, file);
		fgets(data[4], 5, file);
		for (int j = 0; j < 5; j++) DelLastC(data[j]);
		AddDoc(docList, data);
	}
	for (int i = 0; i < 5; i++) free(data[i]);
	free(data);
	fclose(file);
}

char SaveDocFile(char* fileName, Documents* docList)
{
	FILE* file;
	if (fopen_s(&file, fileName, "w")) 
	{
		printf("Ошибка при открытии файла для сохранения");
		return 0;
	}
	Document* current = docList->head;
	char buffer[100];
	while (current) 
	{
		AddLastC(current->fullName);
		fputs(current->fullName, file);
		_itoa_s(current->certAverage, buffer, 100, 10);
		AddLastC(buffer);
		fputs(buffer, file);
		AddLastC(current->passport);
		fputs(current->passport, file);
		AddLastC(current->residence);
		fputs(current->residence, file);
		_itoa_s(current->specId, buffer, 100, 10);
		AddLastC(buffer);
		fputs(buffer, file);
		current = current->next;
	}
	fclose(file);
	return 1;
}

void DeleteDocList(Documents* list) 
{
	Document* cur = list->head;
	while (cur) 
	{
		cur = list->head->next;
		free(list->head);
		list->head = cur;
	}
	free(list);
}

void MakeApp(Documents* docList, char* specId)
{

	char** data = (char**)malloc(sizeof(char*) * 8);
	data[0] = (char*)malloc(sizeof(char) * 40);
	data[1] = (char*)malloc(sizeof(char) * 5);
	data[2] = (char*)malloc(sizeof(char) * 16);
	data[3] = (char*)malloc(sizeof(char) * 100);
	data[4] = (char*)malloc(sizeof(char) * 5);
	int ball = 0;
	char buf[5];
	printf("Введите ФИО:");
	gets_s(data[0], 40);
	printf("Введите бал по первому предмету ЦТ:");
	gets_s(buf, 5);
	ball += atoi(buf);
	printf("Введите бал по второму предмету ЦТ:");
	gets_s(buf, 5);
	ball += atoi(buf);
	printf("Введите бал по третьему предмету ЦТ:");
	gets_s(buf, 5);
	ball += atoi(buf);
	printf("Введите бал за аттестат:");
	gets_s(buf, 5);
	ball += atoi(buf);
	_itoa_s(ball, data[1], 5, 10);
	printf("Введите паспортные данные:");
	gets_s(data[2], 16);
	printf("Введите место проживания:");
	gets_s(data[3], 100);
	int i = -1;
	do 
	{
		i++;
		data[4][i] = specId[i];
	} while (specId[i] != '\0');
	AddDoc(docList, data);
	for (int i = 0; i < 5; i++)
	{
		free(data[i]);
	}
	free(data);
}

void DeleteApp(Documents* docList, int docId) 
{
	if (docList->head == docList->tail) 
	{
		docList->head = docList->tail = NULL;
		docList->size = 0;
		return;
	}
	Document* cur = docList->head;
	while (cur->docId != docId) cur = cur->next;
	if (cur == docList->head) 
	{
		docList->head = docList->head->next;
		docList->head->prev = NULL;
	}
	else if (cur == docList->tail) 
	{
		docList->tail = docList->tail->prev;
		docList->tail->next = NULL;
		docList->size--;
		free(cur);
		return;
	}
	else 
	{
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
	}
	free(cur);
	docList->size--;
	cur = docList->head;
	while (cur->docId != docId + 1) cur = cur->next;
	while (cur) 
	{
		cur->docId++;
		cur = cur->next;
	}
}

void PickApp(Documents* list, char* passport) 
{
	Document* cur = list->head;
	while (cur) 
	{
		if (!strcmp(cur->passport, passport))
		{
			printf("Введите \"да\" для удаления заявления\n");
			char* option = (char*)malloc(sizeof(char) * 5);
			gets_s(option, 5);
			if (!strcmp(option, "да")) 
			{
				DeleteApp(list, cur->docId);
				printf("Удаление завершено\n");
			}
			else 
			{
				printf("Удаление заявления отменено\n");
			}
			free(option);
			return;
		}
		cur = cur->next;
	}
	printf("Заявление не найдено\n");
}

void ShowMenu() 
{
	printf("1.Вывести специальности\n");
	printf("2.Подать заявление\n");
	printf("3.Забрать заявление\n");
	printf("4.Вывести рейтинг специальностей\n");
	printf("5.Вывести рейтинг абитуриентов\n");
	printf("6.Рейтинг факультетов\n");
	printf("7.Зачисление\n");
	printf("8.Проходные баллы\n");
	printf("9.Выход\n");
}

void ShowFacults() {
	printf("1.ФКП\n");
	printf("2.ФИТУ\n");
	printf("3.ФРЭ\n");
	printf("4.ФКСИС\n");
	printf("5.ФИК\n");
	printf("6.ИЭФ\n");
	printf("7.ВФ\n");
}

int GetSpecId(Specialties* specList)
{
	int specId = ShowSpecs(specList);
	Specialty* cur = specList->head;
	while (cur->id != specId) cur = cur->next;
	int specNum = 1;
	while (cur->next) 
	{
		cur = cur->next;
		specNum++;
	}
	printf("Введите номер специальности\n");
	char num = getchar();
	while ((num > '0' + specNum) || num < '1') num = getchar();
	getchar();
	cur = specList->head;
	while (cur->id != specId) cur = cur->next;
	for (int i = 1; i < (int)(num - '0'); i++) 
	{
		cur = cur->next;
	}
	return cur->id;
}

int ShowFac(Specialties* specList, char* str) 
{
	Specialty* cur = specList->head;
	while (strcmp(cur->faculty, str) && cur) 
	{
		cur = cur->next;
	}
	if (!cur) return -1;
	int specNum = 1;
	puts(str);
	int specId = cur->id;
	while (!strcmp(cur->faculty, str)) 
	{
		printf("\t%d)", specNum);
		puts(cur->name);
		specNum++;
		cur = cur->next;
		if (cur == NULL) break;
	}
	return specId;
}

int ShowSpecs(Specialties* specList) 
{
	printf("Выберите факультет\n");
	ShowFacults();
	char fac = getchar();
	while (fac > '7' || fac < '1') fac = getchar();
	getchar();
	int specNumber;
	if (fac == '1') specNumber = ShowFac(specList, "ФКП");
	else if (fac == '2') specNumber = ShowFac(specList, "ФИТУ");
	else if (fac == '3') specNumber = ShowFac(specList, "ФРЭ");
	else if (fac == '4') specNumber = ShowFac(specList, "ФКСИС");
	else if (fac == '5') specNumber = ShowFac(specList, "ФИК");
	else if (fac == '6') specNumber = ShowFac(specList, "ИЭФ");
	else if (fac == '7') specNumber = ShowFac(specList, "ВФ");
	return specNumber;
}

void SortEnrollee(Documents* docList)
{
	Document* cur = docList->head->next;
	Document* moving;
	for (; cur->docId <= docList->size; )
	{
		moving = cur;
		for (; moving->prev->certAverage > moving->certAverage;)
		{
			moving->prev->docId++;
			moving->docId--;
			if (moving->prev == docList->head) 
			{
				docList->head->next = moving->next;
				moving->next->prev = moving->prev;
				moving->next = moving->prev;
				moving->prev->prev = moving;
				moving->prev = NULL;
				docList->head = moving;
				break;
			}
			if (moving == docList->tail) 
			{
				moving->next = moving->prev;
				moving->prev = moving->prev->prev;
				moving->next->prev->next = moving;
				moving->next->prev = moving;
				moving->next->next = NULL;
				docList->tail = moving->next;
				continue;
			}
			Document* temp = moving->prev->prev;
			moving->prev->prev->next = moving;
			moving->next->prev = moving->prev;
			moving->prev->next = moving->next;
			moving->prev->prev = moving;
			moving->next = moving->prev;
			moving->prev = temp;
		}
		cur = cur->next;
		if (!cur) break;
	}
}

void ShowEnrollee(Documents* docList) 
{
	Document* cur = docList->tail;
	while (cur) 
	{
		printf("%d)%d баллов\t", docList->size - cur->docId + 1, cur->certAverage);
		puts(cur->fullName);
		cur = cur->prev;
	}
}

int GetPassingScore(Documents* docList, Specialties* specList, int specId) 
{
	if (specId > specList->size) return 401;
	Specialty* curSpec = specList->head;
	while (curSpec->id != specId) curSpec = curSpec->next;
	int mest = curSpec->places;
	SortEnrollee(docList);
	Document* curDoc = docList->tail;
	int i = 0;
	while (curDoc && i < mest) 
	{
		while (curDoc->specId != specId)
		{
			curDoc = curDoc->prev;
			if (!curDoc) break;
		}
		if (!curDoc)break;
		i++;
		curDoc = curDoc->prev;
	}
	if (!curDoc) return 0;
	return curDoc->certAverage;
}

void Copy(char* copy, char* str)
{
	int i = 0;
	while (str[i] != '\0') 
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
}

void ShowSpecsRating(Documents* docList, Specialties* specList) 
{
	int* specsScore = (int*)malloc(sizeof(int) * specList->size);
	char names[36][120];
	Specialty* cur = specList->head;
	for (int i = 0; i < specList->size; i++) 
	{
		specsScore[i] = GetPassingScore(docList, specList, i + 1);
		Copy(names[i], cur->name);
		cur = cur->next;
	}
	for (int i = 1; i < specList->size; i++) 
	{
		for (int j = i; j > 0 && specsScore[j - 1] > specsScore[j]; j--) 
		{
			int temp = specsScore[j];
			specsScore[j] = specsScore[j - 1];
			specsScore[j - 1] = temp;
			char temp1[120];
			Copy(temp1, names[j]);
			Copy(names[j], names[j - 1]);
			Copy(names[j - 1], temp1);
		}
	}
	for (int i = specList->size; i > 0; i--) 
	{
		if (specsScore[i - 1]) 
		{
			printf("%d) %d Проходной\t", specList->size - i + 1, specsScore[i - 1]);
		}
		else printf("%d) Недобор\t", specList->size - i + 1);
		puts(names[i - 1]);
	}
	free(specsScore);
}

int GetAverageBall(Documents* docList, Specialties* specList, char* facult) 
{
	Specialty* curS = specList->head;
	while (strcmp(curS->faculty, facult)) curS = curS->next;
	int specId1 = curS->id;
	while (!strcmp(curS->faculty, facult)) 
	{
		if (!curS->next) break;
		curS = curS->next;
	}
	int specId2 = curS->id;
	Document* cur = docList->head;
	int ball = 0, num = 0;
	while (cur)
	{
		if (cur->specId >= specId1 && cur->specId <= specId2) 
		{
			ball += cur->certAverage;
			num++;
		}
		cur = cur->next;
	}
	if (!num) return 0;
	return ball / num;
}

void ShowFacultRating(Documents* docList, Specialties* specList) 
{
	Specialty* cur = specList->head;
	char names[7][6] = { "ФКП", "ФИТУ", "ФРЭ", "ФКСИС" , "ФИК" , "ИЭФ" , "ВФ" };
	int rating[7];
	for (int i = 0; i < 7; i++) 
	{
		rating[i] = GetAverageBall(docList, specList, names[i]);
	}
	for (int i = 1; i < 7; i++)
	{
		for (int j = i; j > 0 && rating[j - 1] > rating[j]; j--) 
		{
			int temp = rating[j];
			rating[j] = rating[j - 1];
			rating[j - 1] = temp;
			char temp1[6];
			Copy(temp1, names[j]);
			Copy(names[j], names[j - 1]);
			Copy(names[j - 1], temp1);
		}
	}
	for (int i = 6; i >= 0; i--) 
	{
		printf("%d) %d средний балл ", 7 - i, rating[i]);
		puts(names[i]);
	}
}

void ShowEnrolled(Documents* docList, Specialties* specList) 
{
	Specialty* curS = specList->head;
	SortEnrollee(docList);
	Document* curD;
	puts(curS->faculty);
	while (curS)
	{
		int i = 0;
		curD = docList->tail;
		if (curS->prev && strcmp(curS->faculty, curS->prev->faculty)) puts(curS->faculty);
		printf("\t");
		puts(curS->name);
		while (i < curS->places && curD) 
		{
			if (curD->specId == curS->id) 
			{
				printf("\t%d)%d баллов\t", i + 1, curD->certAverage);
				puts(curD->fullName);
				i++;
			}
			curD = curD->prev;
		}
		curS = curS->next;
		printf("\n");
	}
}

void ShowMinEnrollBalls(Documents* docList, Specialties* specList) 
{
	Specialty* curS = specList->head;
	puts(curS->faculty);
	while (curS) 
	{
		if (curS->prev && strcmp(curS->prev->faculty, curS->faculty)) puts(curS->faculty);
		int score = GetPassingScore(docList, specList, curS->id);
		if (score) 
		{
			printf("\t%d) %d проходной\t", curS->id, score);
		}
		else printf("\t%d) Недобор\t", curS->id, score);
		puts(curS->name);
		curS = curS->next;
	}
}

int main() 
{
	char specFile[] = "specialties.txt";
	char docFile[] = "documents.txt";
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Specialties* specList = CreateSpecList();
	ReadSpecFile(specFile, specList);
	Documents* docList = CreateDocList();
	ReadDocFile(docFile, docList);
	while (1)
	{
		ShowMenu();
		printf("\n");
		char option = getchar();
		while (option > '9' || option < '1')
		{
			option = getchar();
		}
		getchar();
		printf("\n");
		if (option == '1') ShowSpecs(specList);
		else if (option == '2') 
		{
			int specId = GetSpecId(specList);
			char buffer[5];
			_itoa_s(specId, buffer, 5, 10);
			printf("\n");
			MakeApp(docList, buffer);
		}
		else if (option == '3') 
		{
			printf("\nВведите паспортные данные\n");
			char buffer[16];
			gets_s(buffer, 16);
			printf("\n");
			PickApp(docList, buffer);
		}
		else if (option == '4') 
		{
			ShowSpecsRating(docList, specList);
		}
		else if (option == '5') 
		{
			SortEnrollee(docList);
			ShowEnrollee(docList);
		}
		else if (option == '6') 
		{
			ShowFacultRating(docList, specList);
		}
		else if (option == '7') ShowEnrolled(docList, specList);
		else if (option == '8') ShowMinEnrollBalls(docList, specList);
		else if (option == '9') break;
		printf("\n");
	}
	SaveDocFile(docFile, docList);
	DeleteSpecList(specList);
	DeleteDocList(docList);
}