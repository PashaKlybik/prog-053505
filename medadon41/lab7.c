#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node {
    int ID;
    int height;
    int weight;
    char fullName[50];
    char sex[10];
    char bthday[10];
    char city[15];
    char hobby[15];
    char badHabits[10];
    char description[50];
    char wishes[15];
    struct Node* pNext;
    struct Node* pPrev;
}Node;

typedef struct PeopleList
{
    Node* head;
    Node* tail;
}PeopleList;

void PushBack(PeopleList* users, Node* node);

void PopByID(int ID, PeopleList* users);

void GetCurrent(Node* user);

void GetList(PeopleList* users);

int GetListLength(PeopleList* users);

bool CheckID(int ID, PeopleList* users);

Node* GetByID(int ID, PeopleList* users);

bool CheckMatch(Node* user, Node* pair) {
    int reuslt;

    if (strcmp(user->wishes, "Низкие") && pair->height < 170) {
        return true;
    }
    else if (strcmp(user->wishes, "Высокие") && pair->height >= 170) {
        return true;
    }
    else if (strcmp(user->wishes, "Умные") && strstr(pair->description, "Учусь")) {
        return true;
    }
    else {
        return false;
    }
}

void GenerateMatch(Node* user, PeopleList* users) {
    char* neddedSex = (char*)malloc(8 * sizeof(char));
    int neddedCity;
    int mutualCounter = 0;

    if (!strcmp(user->sex, "мужской")) { neddedSex = "женский"; }
    else { neddedSex = "мужской"; }
    printf("Для поиска в Вашем городе введите 1, если не важно - 0: ");
    scanf_s("%d", &neddedCity);
    printf("\n");

    Node* current = users->head;
    if (neddedCity == 1) {
        while (current) {
            if (!strcmp(neddedSex, current->sex) && !strcmp(user->city, current->city) && CheckMatch(user, current)) {
                if (strstr(user->description, current->wishes)) printf("It's a match!\n");
                GetCurrent(current);
                mutualCounter++;
                printf("\n");
            }
            current = current->pNext;
        }
    }
    else {
        while (current) {
            if (!strcmp(neddedSex, current->sex) && CheckMatch(user, current)) {
                if (strstr(user->description, current->wishes)) printf("It's a match!\n");
                GetCurrent(current);
                mutualCounter++;
                printf("\n");
            }
            current = current->pNext;
        }
    }

    if (mutualCounter) {
        int choice;
        do {
            printf("Введите ID или имя желаемой второй половинки или -1 если таковой тут нет: ");
            scanf_s("%d", &choice);
            if (choice == -1) break;

            if (CheckID(choice, users) && (user->ID != choice)) {
                printf("Поздравляем, вы нашли свою пару!");
                PopByID(choice, users);
                PopByID(user->ID, users);
                choice = -1;
            }
            else {
                printf("Такого ID не существует\n");
            }
        } while (choice != -1);
    }
    else printf("По заданным фильтрам пар не найдено!");
}

void ClearList(PeopleList* users) {
    while (GetListLength(users))
        PopByID(users->head->ID, users);
}

int main()
{
    system("chcp 1251");
    system("cls");
    PeopleList users = { NULL,NULL };
    FILE* file;
    file = fopen("input.txt", "r");
    char str[256];
    char* next = 0;

    while (!feof(file))
    {
        Node current = { 0, 0, 0, "", "", "", "", "", "", "", "", NULL, NULL };
        for (int c = 0; c < 11; c++) {
            fgets(str, 256, file);
            switch (c)
            {
            case 0:
                current.ID = atoi(str);
                break;
            case 1:
                strcat(current.fullName, str);
                break;
            case 2:
                strcat(current.sex, str);
                break;
            case 3:
                strcat(current.bthday, str);
                break;
            case 4:
                current.height = atoi(str);
                break;
            case 5:
                current.weight = atoi(str);
                break;
            case 6:
                strcat(current.city, str);
                break;
            case 7:
                strcat(current.hobby, str);
                break;
            case 8:
                strcat(current.badHabits, str);
                break;
            case 9:

                strcat(current.description, str);
                break;
            case 10:
                strcat(current.wishes, str);
                break;
            }
        }
        PushBack(&users, &current);
    }
    fclose(file);

    int choice;

    do {
        printf("\n\n--------------------------------\n");
        printf("\n1. Найти пару \n2. Вывести всех пользователей \n3. Удалить пользователя \n0. Выход\n");
        scanf_s("%d", &choice);
        printf("\n");

        switch (choice) {
        case 0: break;
        case 1: {
            int ID;
            printf("Введите ID пользователя, для которого хотите найти пару: ");
            scanf_s("%d", &ID);

            if (CheckID(ID, &users)) {
                GenerateMatch(GetByID(ID, &users), &users);
            }
            else {
                printf("Неверный ID");
            }
            break;
        }
        case 2: {
            GetList(&users);
            break;
        }
        case 3: {
            int ID;
            printf("Введите ID пользователя, которого хотите удалить: ");
            scanf_s("%d", &ID);

            if (CheckID(ID, &users)) {
                PopByID(ID, &users);
            }
            break;
        }
        }

    } while (choice);

    ClearList(&users);
    fclose(file);
    return 0;
}

void PushBack(PeopleList* users, Node* node) {
    node->pNext = NULL;
    node->pPrev = NULL;
    Node* current = (Node*)malloc(sizeof(Node));
    current->ID = node->ID;
    strcpy(current->fullName, node->fullName);
    strcpy(current->sex, node->sex);
    strcpy(current->bthday, node->bthday);
    current->height = node->height;
    current->weight = node->weight;
    strcpy(current->city, node->city);
    strcpy(current->hobby, node->hobby);
    strcpy(current->badHabits, node->badHabits);
    strcpy(current->description, node->description);
    strcpy(current->wishes, node->wishes);

    current->pNext = NULL;
    current->pPrev = NULL;
    if (users->head == NULL) {
        users->head = current;
        users->tail = current;
    }
    else
    {
        current->pPrev = users->tail;
        users->tail->pNext = current;
        users->tail = current;
    }
}

void PopByID(int ID, PeopleList* users) {

    if (GetListLength(users) > 1) {
        if (users->head->ID == ID) {
            Node* toDelete = users->head;
            users->head = users->head->pNext;
            users->head->pPrev = NULL;
            free(toDelete);
        }
        else if (users->tail->ID == ID) {
            Node* toDelete = users->tail;
            users->tail = users->tail->pPrev;
            users->tail->pNext = NULL;
            free(toDelete);
        }
        else {
            Node* current = users->head;

            while (current->pNext->ID != ID)
                current = current->pNext;

            Node* toDelete = current->pNext;
            current->pNext = current->pNext->pNext;
            current->pNext->pPrev = current;
            free(toDelete);
        }
    }
    else {
        free(users->head);
        users->head = NULL;
        users->tail = NULL;
    }
}

void GetCurrent(Node* user) {
    printf("ID: %d\n", user->ID);
    printf("Полное имя: %s\n", user->fullName);
    printf("Пол: %s\n", user->sex);
    printf("Дата рождения: %s\n", user->bthday);
    printf("Рост: %d\n", user->height);
    printf("Вес: %d\n", user->weight);
    printf("Город: %s\n", user->city);
    printf("Увлечения: %s\n", user->hobby);
    printf("Вредные привычки: %s\n", user->badHabits);
    printf("Описание: %s\n", user->description);
    printf("Фильтры: %s\n", user->wishes);
}

void GetList(PeopleList* users) {
    printf("\n===========================================\n");

    if (users->head != NULL) {
        Node* current = users->head;
        while (current->pNext)
        {
            GetCurrent(current);
            printf("\n");
            current = current->pNext;
        }
        GetCurrent(current);
    }
    else {
        printf("\nСписок пользователей пуст!\n");
    }
    printf("===========================================\n\n");
}

int GetListLength(PeopleList* users) {
    if (users->head != NULL) {
        Node* current = users->head;
        int counter = 1;

        while (current->pNext) {
            current = current->pNext;
            counter++;
        }

        return counter;
    }
    return 0;
}

bool CheckID(int ID, PeopleList* users) {
    Node* current = users->head;

    while (current) {
        if (current->ID == ID) return true;
        current = current->pNext;
    }

    return false;
}

Node* GetByID(int ID, PeopleList* users) {
    Node* current = users->head;

    while (current) {
        if (current->ID == ID) return current;
        current = current->pNext;
    }
}
