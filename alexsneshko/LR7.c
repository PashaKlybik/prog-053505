#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include <stdbool.h>

typedef struct node {
    int accountNumber;
    char NameSurname[50];
    char sex[10];
    char dataBorn[10];
    int Height;
    int Weight;
    char city[15];
    char hobby[15];
    char badHabits[10];
    char introdution[50];
    char wishes[15];
    struct node* pNext;
    struct node* pPrev;
}Node;

typedef struct informationAboutPeople
{
    Node* head;
    Node* tail;
}InformationAboutPeople;

void pushBack(InformationAboutPeople* users, Node* node) {
    node->pNext = NULL;
    node->pPrev = NULL;
    Node* current = (Node*)malloc(sizeof(Node));

    current->accountNumber = node->accountNumber;
    strcpy(current->NameSurname, node->NameSurname);
    strcpy(current->sex, node->sex);
    strcpy(current->dataBorn, node->dataBorn);
    current->Height = node->Height;
    current->Weight = node->Weight;
    strcpy(current->city, node->city);
    strcpy(current->hobby, node->hobby);
    strcpy(current->badHabits, node->badHabits);
    strcpy(current->introdution, node->introdution);
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

void deleteByAN(int AN, InformationAboutPeople* users) {

    if (getLenght(users) > 1) {
        if (users->head->accountNumber == AN) {
            Node* toDelete = users->head;
            users->head = users->head->pNext;
            users->head->pPrev = NULL;
            free(toDelete);
        }
        else if (users->tail->accountNumber == AN) {
            Node* toDelete = users->tail;
            users->tail = users->tail->pPrev;
            users->tail->pNext = NULL;
            free(toDelete);
        }
        else {
            Node* current = users->head;

            while (current->pNext->accountNumber != AN)
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

void printInfoCurrent(Node* user) {
    printf("Account number : %d\n", user->accountNumber);
    printf("Surname Name : %s\n", user->NameSurname);
    printf("Sex : %s\n", user->sex);
    printf("Data born : %s\n", user->dataBorn);
    printf("Height : %d\n", user->Height);
    printf("Weight : %d\n", user->Weight);
    printf("City : %s\n", user->city);
    printf("Hobby : %s\n", user->hobby);
    printf("Bad habits : %s\n", user->badHabits);
    printf("Introdution : %s\n", user->introdution);
    printf("Wishes : %s\n", user->wishes);
}

void printTable(InformationAboutPeople* users) {
    printf("\n===========================================\n");

    if (users->head != NULL) {
        Node* current = users->head;
        while (current->pNext)
        {
            printInfoCurrent(current);
            printf("\n");
            current = current->pNext;
        }
        printInfoCurrent(current);
    }
    else {
        printf("\nYour table is empty\n");
    }
    printf("===========================================\n\n");
}

int getLenght(InformationAboutPeople* users) {
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

bool checkAN(int AN, InformationAboutPeople* users) {
    Node* current = users->head;

    while (current) {
        if (current->accountNumber == AN) return true;
        current = current->pNext;
    }

    return false;
}

Node* getUserByAN(int AN, InformationAboutPeople* users) {
    Node* current = users->head;

    while (current) {
        if (current->accountNumber == AN) return current;
        current = current->pNext;
    }
}

void getPair(Node* user, InformationAboutPeople* users, FILE* file) {
    char* neddedSex = (char*)malloc(6 * sizeof(char));
    int neddedCity;
    int mutualCounter = 0;

    if (!strcmp(user->sex, "male")) { neddedSex = "female"; }
    else { neddedSex = "male"; }
    printf("If you want to get list of people from your city then press 1, else press 0: ");
    scanf_s("%d", &neddedCity);
    printf("\n");

    Node* current = users->head;
    if (neddedCity == 1) {
        while (current) {
            if (!strcmp(neddedSex, current->sex) && !strcmp(user->city, current->city) && strstr(current->introdution, user->wishes)) {
                if (strstr(user->introdution, current->wishes)) printf("!Mutual sympathy\n");
                printInfoCurrent(current);
                mutualCounter++;
                printf("\n");
            }
            current = current->pNext;
        }
    }
    else {
        while (current) {
            if (!strcmp(neddedSex, current->sex) && strstr(current->introdution, user->wishes)) {
                if (strstr(user->introdution, current->wishes)) printf("----!Mutual sympathy----\n");
                printInfoCurrent(current);
                mutualCounter++;
                printf("\n");
            }  
            current = current->pNext;
        }
    }

    if (mutualCounter) {
        int choice;
        do {
            printf("Print AN of your second couple or print -1 if there is not here: ");
            scanf_s("%d", &choice);
            if (choice == -1) break;

            if (checkAN(choice, users) && (user->accountNumber != choice)) {
                printf("Congratulations, you've found your second couple, wish you all the best!");
                fprintf(file, "%s <--pair--> %s\n", user->NameSurname, getUserByAN(choice, users)->NameSurname);
                fflush(file);
                deleteByAN(choice, users);
                deleteByAN(user->accountNumber, users);
                choice = -1;
            }
            else {
                printf("No such acount number\n");
            }
        } while (choice != -1);
    }
    else printf("Sorry but we haven't got pairs with your wishes");
}

void clear(InformationAboutPeople* users) {
    while (getLenght(users))
        deleteByAN(users->head->accountNumber, users); 
}

int main()
{
    InformationAboutPeople users = { NULL,NULL };
    FILE* file;
    file = fopen("Input.txt", "r");
    int c = 0;
    char str[255];
    char* next = 0;

    while (!feof(file))
    {
        fgets(str, 255, file);
        char* s = strtok_s(str, ";", &next);
        Node current = { 0,NULL,"",0,"",NULL,NULL };
        do {
            switch (c)
            {
            case 0:
                current.accountNumber = atoi(s);
                break;
            case 1:
                strcat(current.NameSurname, s);
                break;
            case 2:
                strcat(current.sex, s);
                break;
            case 3:
                strcat(current.dataBorn, s);
                break;
            case 4:
                current.Height = atoi(s);
                break;
            case 5:
                current.Weight = atoi(s);
                break;
            case 6:
                strcat(current.city, s);
                break;
            case 7:
                strcat(current.hobby, s);
                break;
            case 8:
                strcat(current.badHabits, s);

            case 9:
                strcat(current.introdution, s);
                break;
            case 10:
                strcat(current.wishes, s);
                break;
            }
            c++;
        } while (s = strtok_s(0, ";", &next));
        c = 0;
        pushBack(&users, &current);
    }
    fclose(file);
    printTable(&users);

    file = fopen("Archive.txt", "w");
    int choice;

    do {
        printf("\n\n--------------------------------\n");
        printf("Print: \n1 - to get pair \n2 - to print all users \n3 - to delete user \n0 - to exit\n");
        scanf_s("%d", &choice);
        printf("\n");

        switch (choice) {
        case 0: break;
        case 1: {
            int accountNumber;
            printf("Print account number for whom you want to get pair: ");
            scanf_s("%d", &accountNumber);

            if (checkAN(accountNumber, &users)) {
                getPair(getUserByAN(accountNumber, &users), &users, file);
            }
            else {
                printf("Wrong account number");
            }
            break;
        }
        case 2: {
            printTable(&users);
            break;
        }
        case 3: {
            int accountNumber;
            printf("Print account number who you want to delete: ");
            scanf_s("%d", &accountNumber);

            if (checkAN(accountNumber, &users)) {
                deleteByAN(accountNumber, &users);
            }
            break;
        }
        }

    } while (choice);

    clear(&users);
    fclose(file);
    return 0;
}