#include <stdio.h>
#include<malloc.h>
#include <string.h>
#define FILE_PATH "Text.txt"

typedef struct Task
{
    char name[20];
    char start[11];
    char end[11];
    int parTask;
} Task;
typedef struct Resources
{
    int budget;
    char** people;
    char specComm[50];
} Resources;
typedef struct Project
{
    struct Resources res;
    struct Task** tasks;
    struct Project* pNext;
    struct Project* pPrev;
    char prName[20];
    int amount, peopleSize;
} Project;
typedef struct List
{
    struct Project* head;
    int size;
} List;
List Push(List*, Project*);
void AddProject(List*);
List Pop(List*);
void FromFileToList(List*);
void FromListToFile(List*);
void PrintTable(List*);
void InformationAboutProjects(List*, int);
List ClearList(List*);
List Delete(List*, int);

int main() {
    List bpro, * proj = &bpro;
    bpro.head = NULL;
    bpro.size = 0;
    int num = 0;
    FromFileToList(proj);
    while (1){
        printf("Enter a number:\n1. Add project\n2. Delete project\n3. Spreadsheet of projects\n4. Full project's editing\n5. More information about project\n6. Write to file\n7. Exit\n");
        while (1) {
            if (!scanf("%d", &num) || num <= 0 || getchar() != '\n')
                while (getchar() != '\n');
            else
                break;
            printf("Error. Enter a number: ");
        }
        switch (num) {
        case 1:
            AddProject(proj);
            printf("\n\n");
            break;
        case 2:
            printf("ID of the object:\n");
            while (1) {
                if (!scanf("%d", &num) || num <= 0 || getchar() != '\n')
                    while (getchar() != '\n');
                else
                    break;
                printf("Error. Enter a number: ");
            }
            printf("\n\n");
            Delete(proj, num);
            break;
        case 3:
            PrintTable(proj);
            break;
        case 4:
            printf("ID of the object:\n");
            while (1) {
                if (!scanf("%d", &num) || num <= 0 || getchar() != '\n')
                    while (getchar() != '\n');
                else
                    break;
                printf("Error. Enter ID: ");
            }
            printf("\n\n");
            Delete(proj, num);
            AddProject(proj);
            break;
        case 5:
            printf("ID of the object:\n");
            while (1) {
                if (!scanf("%d", &num) || num <= 0 || getchar() != '\n')
                    while (getchar() != '\n');
                else
                    break;
                printf("Error. Enter ID: ");
            }
            printf("\n\n");
            InformationAboutProjects(proj, num);
            break;
        case 6:
            FromListToFile(proj);
            printf("\n\n");
            break;
        case 7:
            ClearList(proj);
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}

List Push(List* list, Project* data) {
    if (list->head == NULL) {
        list->head = (Project*)malloc(sizeof(Project));
        list->head->pNext = NULL;
        list->head->pPrev = NULL;
        list->head->amount = data->amount;
        list->head->peopleSize = data->peopleSize;
        list->head->res.people = (char**)malloc(list->head->peopleSize * sizeof(char*));
        for (int i = 0; i < list->head->peopleSize; i++)
            list->head->res.people[i] = (char*)malloc(20 * sizeof(char));
        for (int i = 0; i < data->peopleSize; i++)
            strcpy(list->head->res.people[i], data->res.people[i]);
        strcpy(list->head->res.specComm, data->res.specComm);
        list->head->res.budget = data->res.budget;
        list->head->tasks = (Task**)malloc(list->head->amount * sizeof(Task*));
        for (int i = 0; i < list->head->amount; i++)
            list->head->tasks[i] = (Task*)malloc(1 * sizeof(Task));
        for (int i = 0; i < data->amount; i++) {
            data->tasks[i]->end[10] = '\0';
            data->tasks[i]->start[10] = '\0';
            strcpy(list->head->tasks[i]->name, data->tasks[i]->name);
            strcpy(list->head->tasks[i]->end, data->tasks[i]->end);
            strcpy(list->head->tasks[i]->start, data->tasks[i]->start);
        }
        strcpy(list->head->prName, data->prName);
    }
    else {
        Project* p = list->head;
        while (p->pNext != NULL)
            p = p->pNext;
        p->pNext = (Project*)malloc(sizeof(Project));
        (p->pNext)->pNext = NULL;
        (p->pNext)->pPrev = p;
        (p->pNext)->amount = data->amount;
        (p->pNext)->peopleSize = data->peopleSize;
        (p->pNext)->res.people = (char**)malloc((p->pNext)->peopleSize * sizeof(char*));
        for (int i = 0; i < (p->pNext)->peopleSize; i++)
            (p->pNext)->res.people[i] = (char*)malloc(20 * sizeof(char));
        for (int i = 0; i < data->peopleSize; i++)
            strcpy((p->pNext)->res.people[i], data->res.people[i]);
        strcpy((p->pNext)->res.specComm, data->res.specComm);
        (p->pNext)->res.budget = data->res.budget;
        (p->pNext)->tasks = (Task**)malloc((p->pNext)->amount * sizeof(Task*));
        for (int i = 0; i < (p->pNext)->amount; i++)
            (p->pNext)->tasks[i] = (Task*)malloc(1 * sizeof(Task));
        for (int i = 0; i < (p->pNext)->amount; i++) {
            strcpy((p->pNext)->tasks[i]->name, data->tasks[i]->name);
            strcpy((p->pNext)->tasks[i]->end, data->tasks[i]->end);
            strcpy((p->pNext)->tasks[i]->start, data->tasks[i]->start);
        }
        strcpy(p->pNext->prName, data->prName);
    }
    list->size++;
}

void AddProject(List* project) {
    Project* newProject = (Project*)malloc(1 * sizeof(Project));
    newProject->amount = 1, newProject->peopleSize = 1;
    char symb = '0', name[20], st[11], end[11];
    int number;
    printf("Enter project's name, budget(int), comment\n");
    scanf("%20s %d %50s", &newProject->prName, &newProject->res.budget, &newProject->res.specComm);
    while (1) {
        printf("Enter task's name, start date, end date\n");
        scanf("%s %10s %10s", &name, &st, &end);
        st[10] = '\0';
        end[10] = '\0';
        if (newProject->amount == 1) {
            newProject->tasks = (Task**)malloc(1 * sizeof(Task*));
            newProject->tasks[0] = (Task*)malloc(1 * sizeof(Task));
        }
        else {
            newProject->tasks = (Task**)realloc(newProject->tasks, (newProject->amount) * sizeof(Task*));
            newProject->tasks[newProject->amount - 1] = (Task*)malloc(1 * sizeof(Task));
        }
        strcpy(newProject->tasks[newProject->amount - 1]->name, name);
        strcpy(newProject->tasks[newProject->amount - 1]->start, st);
        strcpy(newProject->tasks[newProject->amount - 1]->end, end);
        strcpy(name, "");
        strcpy(st, "");
        strcpy(end, "");
        printf("Continue? If yes - enter 1, if no - enter 0\n");
        while (1) {
            if (!scanf("%d", &number) || (number != 0 && number != 1) || getchar() != '\n')
                while (getchar() != '\n');
            else
                break;
            printf("Error. Enter number: ");
        }
        if (number == 0)
            break;
        else
            newProject->amount++;

    }
    while (1) {
        printf("Enter project's participant name\n");
        scanf("%20s", &name);
        if (newProject->peopleSize == 1) {
            newProject->res.people = (char**)malloc(1 * sizeof(char*));
            newProject->res.people[0] = (char*)malloc(20 * sizeof(char));
        }
        else
        {
            newProject->res.people = (char**)realloc(newProject->res.people, (newProject->peopleSize) * sizeof(char*));
            newProject->res.people[newProject->peopleSize - 1] = (char*)malloc(20 * sizeof(char));
        }
        strcpy(newProject->res.people[newProject->peopleSize - 1], name);
        strcpy(name, "");
        printf("Continue? If yes - enter 1, if no - enter 0\n");
        while (1) {
            if (!scanf("%d", &number) || (number != 0 && number != 1) || getchar() != '\n')
                while (getchar() != '\n');
            else
                break;
            printf("Error. Enter a number: ");
        }
        if (number == 0)
            break;
        else
            newProject->amount++;
    }
    Push(project, newProject);
    for (int i = 0; i < newProject->amount; i++)
        free(newProject->tasks[i]);
    for (int i = 0; i < newProject->peopleSize; i++)
        free(newProject->res.people[i]);
    free(newProject->tasks);
    free(newProject->res.people);
    newProject->amount = 1;
    newProject->peopleSize = 1;
    free(newProject);
}

List Pop(List* list) {
    Project* pProject = list->head;
    list->head = (list->head)->pNext;
    if (list->head != NULL)
        list->head->pPrev = NULL;
    for (int i = 0; i < pProject->amount; i++)
        free(pProject->tasks[i]);
    for (int i = 0; i < pProject->peopleSize; i++)
        free(pProject->res.people[i]);
    free(pProject->tasks);
    free(pProject->res.people);
    free(pProject);
    list->size--;
}

void FromFileToList(List* project) {
    Project* newProject = (Project*)malloc(1 * sizeof(Project));
    newProject->amount = 1, newProject->peopleSize = 1;

    char symb = '0', name[20], st[11], end[11];
    int par = 1;

    FILE* test;;
    if ((test = fopen(FILE_PATH, "r")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    while (1) {
        fscanf(test, "\n'%s %d$ %s\n", &newProject->prName, &newProject->res.budget, &newProject->res.specComm);
        while (fscanf(test, "%s %10s %10s %d %c\n", &name, &st, &end, &par, &symb) != EOF) {
            name[strlen(name)] = '\0';
            st[10] = '\0';
            end[10] = '\0';
            if (newProject->amount == 1) {
                newProject->tasks = (Task**)malloc(1 * sizeof(Task*));
                newProject->tasks[0] = (Task*)malloc(1 * sizeof(Task));
            }
            else {
                newProject->tasks = (Task**)realloc(newProject->tasks, (newProject->amount) * sizeof(Task*));
                newProject->tasks[newProject->amount - 1] = (Task*)malloc(1 * sizeof(Task));
            }
            strcpy(newProject->tasks[newProject->amount - 1]->name, name);
            strcpy(newProject->tasks[newProject->amount - 1]->start, st);
            strcpy(st, "");
            strcpy(newProject->tasks[newProject->amount - 1]->end, end);
            strcpy(end, "");
            strcpy(name, "");
            if (symb == '.') {
                symb = ',';
                break;
            }
            newProject->amount++;
        }
        fscanf(test, "%s\n", name);
        while (fscanf(test, "%s %c", &name, &symb) != EOF) {
            if (newProject->peopleSize == 1) {
                newProject->res.people = (char**)malloc(1 * sizeof(char*));
                newProject->res.people[0] = (char*)malloc(20 * sizeof(char));
            }
            else {
                newProject->res.people = (char**)realloc(newProject->res.people, (newProject->peopleSize) * sizeof(char*));
                newProject->res.people[newProject->peopleSize - 1] = (char*)malloc(20 * sizeof(char));
            }
            strcpy(newProject->res.people[newProject->peopleSize - 1], name);
            strcpy(name, "");
            if (symb == '.') {
                symb = ',';
                break;
            }
            newProject->peopleSize++;
        }
        if (fscanf(test, "%s", &name) == EOF)
            break;
        Push(project, newProject);
        for (int i = 0; i < newProject->amount; i++) {
            free(newProject->tasks[i]);
        }
        for (int i = 0; i < newProject->peopleSize; i++) {
            free(newProject->res.people[i]);
        }
        free(newProject->tasks);
        free(newProject->res.people);
        newProject->amount = 1;
        newProject->peopleSize = 1;
    }
    free(newProject);
    fclose(test);
}

void FromListToFile(List* project){
     Project* newProject = project->head;
     FILE* file;
     if ((file = fopen(FILE_PATH, "w")) == NULL) {
         printf("Cannot open file.\n");
         exit(1);
     }
    int budjet = 0;
    char b[17];
    char* r;
    for (int z = 0; z < project->size; z++) {
        budjet = newProject->res.budget;
        fprintf(file, "'%s %d$ %s\n", &newProject->prName, budjet, &newProject->res.specComm);
        for (int i = 0; i < newProject->amount; i++) {
            if (i != newProject->amount - 1)
                fprintf(file, "%s %10s %10s 1 ,\n", &newProject->tasks[i]->name, &newProject->tasks[i]->start, &newProject->tasks[i]->end);
            else
                fprintf(file, "%s %10s %10s 0 .\n", &newProject->tasks[i]->name, &newProject->tasks[i]->start, &newProject->tasks[i]->end);
        }
        fprintf(file, "-People:\n");
        char name[20];
        for (int j = 0; j < newProject->peopleSize; j++) {
            strcpy(name, newProject->res.people[j]);
            if (j != newProject->peopleSize - 1)
                fprintf(file, "%s ;\n", &name);
            else
                fprintf(file, "%s .", &name);
        }
        if (z != project->size - 1)
            fprintf(file, "\n+\n\n");
        newProject = newProject->pNext;
    }
    fclose(file);
}

void PrintTable(List* project) {
    Project* pProject = project->head;
    printf("________________________________________________________________\n");
    printf("................................................................\n");
    for (int i = 0; i < project->size; i++) {
        printf("|%2d |Project's name: %20s |Budjet: %10d$ |\n", i + 1, pProject->prName, pProject->res.budget);
        printf("----------------------------------------------------------------\n");
        for (int j = 0; j < pProject->amount; j++)
            printf("|Task %2d |   Task's name: %20s |limits in p. 5 | \n", j + 1, pProject->tasks[j]->name);
        printf("................................................................\n");
        pProject = pProject->pNext;
    }
    printf("________________________________________________________________\n\n\n\n");
}

void InformationAboutProjects(List* project, int number){
    number--;
    if (number < project->size){
        Project* pProject = project->head;
        for (int i = 0; i < number; i++)
            pProject = pProject->pNext;
        printf("Project-> %s Special Comment: %s\n ", pProject->prName, pProject->res.specComm);
        printf("People amount: %5d\n{\n", pProject->peopleSize);
        for (int i = 0; i < pProject->peopleSize; i++)
            printf("    %d: %s\n", i + 1, pProject->res.people[i]);
        printf("}\n");
        printf("Amount of tasks: %5d\n", pProject->amount);
        Task* problem;
        char date[11], currDate[11];
        int* critic = (int*)malloc(1 * sizeof(int));
        int day_1, day_2, month_1, month_2, year_1, year_2;
        int maxDay = 0, minDay = 0, maxMonth = 0, minMonth = 0, maxYear = 0, minYear = 0;
        int range = 0;
        int j = 0;
        for (int i = 0; i < pProject->amount; i++){
            problem = pProject->tasks[i];
            strcpy(currDate, problem->end);
            strcpy(date, problem->start);
            critic = (int*)realloc(critic, (j + 1) * sizeof(int));
            if (!strcmp(date, "0") && !strcmp(date, "0"))
                critic[j] = 0;
            else
                critic[j] = 1;
            j++;
        }
        for (int i = 0; i < pProject->amount; i++){
            problem = pProject->tasks[i];
            if (critic[i] == 1){
                strcpy(currDate, problem->end);
                strcpy(date, problem->start);
                if (!strcmp(date, "0")){
                    day_1 = month_1 = year_1 = 0;
                    day_2 = (currDate[0] - 48) * 10 + currDate[1] - 48;
                    month_2 = (currDate[3] - 48) * 10 + currDate[4] - 48;
                    year_2 = (currDate[6] - 48) * 1000 + (currDate[7] - 48) * 100 + (currDate[8] - 48) * 10 + currDate[9] - 48;
                }
                else if (!strcmp(currDate, "0")){
                    day_2 = month_2 = year_2 = 0;
                    day_1 = (date[0] - 48) * 10 + date[1] - 48;
                    month_1 = (date[3] - 48) * 10 + date[4] - 48;
                    year_1 = (date[6] - 48) * 1000 + (date[7] - 48) * 100 + (date[8] - 48) * 10 + date[9] - 48;
                }
                else{
                    day_1 = (date[0] - 48) * 10 + date[1] - 48;
                    day_2 = (currDate[0] - 48) * 10 + currDate[1] - 48;
                    month_1 = (date[3] - 48) * 10 + date[4] - 48;
                    month_2 = (currDate[3] - 48) * 10 + currDate[4] - 48;
                    year_1 = (date[6] - 48) * 1000 + (date[7] - 48) * 100 + (date[8] - 48) * 10 + date[9] - 48;
                    year_2 = (currDate[6] - 48) * 1000 + (currDate[7] - 48) * 100 + (currDate[8] - 48) * 10 + currDate[9] - 48;
                }
                if (year_1 < minYear){
                    minYear = year_1;
                    minMonth = month_1;
                    minDay = day_1;
                }
                else if (year_1 == minYear){
                    if (month_1 < minMonth){
                        minMonth = month_1;
                        minDay = day_1;
                    }
                    else if (month_1 == minMonth){
                        if (day_1 < minDay){
                            minDay = day_1;
                        }
                    }
                }
                else{
                    if (!minYear){
                        minYear = year_1;
                        minMonth = month_1;
                        minDay = day_1;
                    }
                }
                if (year_2 > maxYear){
                    maxYear = year_1;
                    maxMonth = month_2;
                    maxDay = day_2;
                }
                else if (year_2 == maxYear){
                    if (month_2 > maxMonth){
                        maxMonth = month_2;
                        maxDay = day_2;
                    }
                    else if (month_2 == maxMonth)
                        if (day_2 > maxDay)
                            maxDay = day_2;
                    else if (!maxMonth)
                            maxMonth = month_2;
                }
            }
        }
        printf("[Parallel]: \n");
        for (int i = 0; i < pProject->amount; i++) {
            problem = pProject->tasks[i];
            if (critic[i] == 0) {
                printf("|%20s; ", problem->name);
            }
        }
        printf("[Critical]: \n");
        for (int i = 0; i < pProject->amount; i++){
            problem = pProject->tasks[i];
            if (critic[i] == 1){
                strcpy(currDate, problem->end);
                strcpy(date, problem->start);
                if (!strcmp(date, "0")){
                    day_1 = month_1 = year_1 = 0;
                    day_2 = (currDate[0] - 48) * 10 + currDate[1] - 48;
                    month_2 = (currDate[3] - 48) * 10 + currDate[4] - 48;
                    year_2 = (currDate[6] - 48) * 1000 + (currDate[7] - 48) * 100 + (currDate[8] - 48) * 10 + currDate[9] - 48;
                }
                else if (!strcmp(currDate, "0")){
                    day_2 = month_2 = year_2 = 0;
                    day_1 = (date[0] - 48) * 10 + date[1] - 48;
                    month_1 = (date[3] - 48) * 10 + date[4] - 48;
                    year_1 = (date[6] - 48) * 1000 + (date[7] - 48) * 100 + (date[8] - 48) * 10 + date[9] - 48;
                }
                else{
                    day_1 = (date[0] - 48) * 10 + date[1] - 48;
                    day_2 = (currDate[0] - 48) * 10 + currDate[1] - 48;
                    month_1 = (date[3] - 48) * 10 + date[4] - 48;
                    month_2 = (currDate[3] - 48) * 10 + currDate[4] - 48;
                    year_1 = (date[6] - 48) * 1000 + (date[7] - 48) * 100 + (date[8] - 48) * 10 + date[9] - 48;
                    year_2 = (currDate[6] - 48) * 1000 + (currDate[7] - 48) * 100 + (currDate[8] - 48) * 10 + currDate[9] - 48;
                }
                if (strcmp(problem->start, "0") != 0 && strcmp(problem->end, "0") != 0)
                    range = (year_2 - year_1) * 365 + (month_2 - month_1) * 31 + (day_2 - day_1);
                else if (strcmp(problem->end, "0") != 0)
                    range = (maxYear - year_1) * 365 + (maxMonth - month_1) * 31 + (maxDay - day_1);
                else
                    range = (year_2 - minYear) * 365 + (month_2 - minMonth) * 31 + (day_2 - minDay);
                printf("|%20s; ", problem->name);
                if (strcmp(problem->start, "0") != 0)
                    printf("%11s ", problem->start);
                if (strcmp(problem->end, "0") != 0)
                    printf("%11s Leeway: %d days\n", problem->end, range);
            }
        }
        printf("\n\n\n");
        free(critic);
    }
}

List ClearList(List* list){
    while (list->size)
        Pop(list);
}

List Delete(List* list, int number){
    number--;
    if (number == 0)
        Pop(list);
    else if (number < list->size){
        Project* previos = list->head;
        for (int i = 0; i < number - 1 && previos->pNext != NULL; i++)
            previos = previos->pNext;
        Project* delete = previos->pNext;
        if (previos->pNext != NULL){
            previos->pNext = delete->pNext;
            (delete->pNext)->pPrev = previos;
        }
        for (int i = 0; i < delete->amount; i++)
            free(delete->tasks[i]);
        for (int i = 0; i < delete->peopleSize; i++)
            free(delete->res.people[i]);
        free(delete->tasks);
        free(delete->res.people);
        free(delete);
        list->size--;
        if (list->size == 0)
            list->head = NULL;
    }
}