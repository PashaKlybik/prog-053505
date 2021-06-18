#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include <stdbool.h>

typedef struct node {
    int groupNumber;
    int course;
    int subject1;
    int subject2;
    int subject3;
    int subject4;
    int subject5;
    struct node* Next;
    struct node* Prev;
}Node;

typedef struct groupsInformation
{
    Node* head;
    Node* tail;
}GroupsInformation;

void pushBack(GroupsInformation* groups, Node* stud) {
    stud->Next = NULL;
    stud->Prev = NULL;
    Node* current = (Node*)malloc(sizeof(Node));

    current->groupNumber = stud->groupNumber;
    current->course = stud->course;
    current->subject1 = stud->subject1;
    current->subject2 = stud->subject2;
    current->subject3 = stud->subject3;
    current->subject4 = stud->subject4;
    current->subject5 = stud->subject5;

    current->Next = NULL;
    current->Prev = NULL;
    if (groups->head == NULL) {
        groups->head = current;
        groups->tail = current;
    }
    else
    {
        current->Prev = groups->tail;
        groups->tail->Next = current;
        groups->tail = current;
    }
}

void deleteByNum(int Num, GroupsInformation* groups) {

    if (getLenght(groups) > 1) {
        if (groups->head->groupNumber == Num) {
            Node* toDelete = groups->head;
            groups->head = groups->head->Next;
            groups->head->Prev = NULL;
            free(toDelete);
        }
        else if (groups->tail->groupNumber == Num) {
            Node* toDelete = groups->tail;
            groups->tail = groups->tail->Prev;
            groups->tail->Next = NULL;
            free(toDelete);
        }
        else {
            Node* current = groups->head;

            while (current->Next->groupNumber != Num)
                current = current->Next;

            Node* toDelete = current->Next;
            current->Next = current->Next->Next;
            current->Next->Prev = current;
            free(toDelete);
        }
    }
    else {
        free(groups->head);
        groups->head = NULL;
        groups->tail = NULL;
    }
}

void Sort(GroupsInformation* groups, Node* stud) {
    Node* temp = groups->head;
    Node* tempNext = temp->Next;
    int ended = 1;
    while (ended) {
        ended = 0;
        while (tempNext)
        {
            if (((float)(temp->subject1 + temp->subject2 + temp->subject3 + temp->subject4 + temp->subject5) / 5) <
                ((float)(tempNext->subject1 + tempNext->subject2 + tempNext->subject3 + tempNext->subject4 + tempNext->subject5) / 5))
            {
                ended = 1;
                int tempNumber = temp->groupNumber;
                int tempCourse = temp->course;
                int tempsubject1 = temp->subject1;
                int tempsubject2 = temp->subject2;
                int tempsubject3 = temp->subject3;
                int tempsubject4 = temp->subject4;
                int tempsubject5 = temp->subject5;
                temp->groupNumber = tempNext->groupNumber;
                temp->course = tempNext->course;
                temp->subject1 = tempNext->subject1;
                temp->subject2 = tempNext->subject2;
                temp->subject3 = tempNext->subject3;
                temp->subject4 = tempNext->subject4;
                temp->subject5 = tempNext->subject5;
                tempNext->subject1 = tempsubject1;
                tempNext->subject2 = tempsubject2;
                tempNext->subject3 = tempsubject3;
                tempNext->subject4 = tempsubject4;
                tempNext->subject5 = tempsubject5;
                tempNext->course = tempCourse;
                tempNext->groupNumber = tempNumber;
            }
            temp = temp->Next;
            tempNext = temp->Next;
        }
        while (stud->Prev)
        {
            stud = stud->Prev;
        }
        tempNext = stud->Next;
        break;

    }
}
void SortByCourse(GroupsInformation* groups, Node* stud) {
    Node* temp = groups->head;
    Node* tempNext = temp->Next;
    int ended = 1;
    while (ended) {
        ended = 0;
        while (tempNext)
        {
            if (temp->course < tempNext->course)
            {
                ended = 1;
                int tempNumber = temp->groupNumber;
                int tempCourse = temp->course;
                int tempsubject1 = temp->subject1;
                int tempsubject2 = temp->subject2;
                int tempsubject3 = temp->subject3;
                int tempsubject4 = temp->subject4;
                int tempsubject5 = temp->subject5;
                temp->groupNumber = tempNext->groupNumber;
                temp->course = tempNext->course;
                temp->subject1 = tempNext->subject1;
                temp->subject2 = tempNext->subject2;
                temp->subject3 = tempNext->subject3;
                temp->subject4 = tempNext->subject4;
                temp->subject5 = tempNext->subject5;
                tempNext->subject1 = tempsubject1;
                tempNext->subject2 = tempsubject2;
                tempNext->subject3 = tempsubject3;
                tempNext->subject4 = tempsubject4;
                tempNext->subject5 = tempsubject5;
                tempNext->course = tempCourse;
                tempNext->groupNumber = tempNumber;
            }
            temp = temp->Next;
            tempNext = temp->Next;
        }
        while (stud->Prev)
        {
            stud = stud->Prev;
        }
        tempNext = stud->Next;
        break;

    }
}


void showInfo(Node* stud) {
    printf("Group number: %d\n", stud->groupNumber);
    printf("Course: %d\n", stud->course);
    printf("Subject 1 mark: %d\n", stud->subject1);
    printf("Subject 2 mark: %d\n", stud->subject2);
    printf("Subject 3 mark: %d\n", stud->subject3);
    printf("Subject 4 mark: %d\n", stud->subject4);
    printf("Subject 5 mark: %d\n", stud->subject5);
    printf("Average mark is: %.2f\n", (float)(stud->subject1 + stud->subject2 + stud->subject3 + stud->subject4 + stud->subject5) / 5);
    printf("________________________________________\n");
}
void infoByCourse(Node* stud, int courseNum) {
    if (stud->course == courseNum) {
        printf("Group number: %d\n", stud->groupNumber);
        printf("Course: %d\n", stud->course);
        printf("Subject 1 mark: %d\n", stud->subject1);
        printf("Subject 2 mark: %d\n", stud->subject2);
        printf("Subject 3 mark: %d\n", stud->subject3);
        printf("Subject 4 mark: %d\n", stud->subject4);
        printf("Subject 5 mark: %d\n", stud->subject5);
        printf("Average mark is: %.2f\n", (float)(stud->subject1 + stud->subject2 + stud->subject3 + stud->subject4 + stud->subject5) / 5);
        printf("________________________________________\n");
    }
}
void infoByGroup(GroupsInformation* groups, Node* user, int groupNum) {

    if (user->groupNumber == groupNum) {
        printf("Group number: %d\n", user->groupNumber);
        printf("Course: %d\n", user->course);
        printf("Subject 1 mark: %d\n", user->subject1);
        printf("Subject 2 mark: %d\n", user->subject2);
        printf("Subject 3 mark: %d\n", user->subject3);
        printf("Subject 4 mark: %d\n", user->subject4);
        printf("Subject 5 mark: %d\n", user->subject5);
        printf("Average mark is: %.2f\n", (float)(user->subject1 + user->subject2 + user->subject3 + user->subject4 + user->subject5) / 5);
        printf("________________________________________\n");
    }
}
void groupComparer(GroupsInformation* groups, Node* stud, int groupNum)
{
    SortByCourse(groups, stud);
    Node* current = groups->head;
    Node* prevSession = current->Next;
    int counter = 0;
    int groupCourse1 = 0;
    int groupCourse2 = 0;
    int finalCompare = 0;
    float groupAverage1 = 0;
    float groupAverage2 = 0;
    while (current != NULL)
    {
        if (current->groupNumber == groupNum)
        {
            groupCourse1 = current->course;
            groupAverage1 = (float)(current->subject1 + current->subject2 + current->subject3 + current->subject4 + current->subject5) / 5;
            break;
        }
        current = current->Next;
    }

    current = groups->head;
    current = current->Next;
    if (current->course == groupCourse1 - 1)
    {
        while (current != NULL)
        {
            groupCourse2 = current->course;
            groupAverage2 = (float)(current->subject1 + current->subject2 + current->subject3 + current->subject4 + current->subject5) / 5;
            current = current->Next;
        }
    }
    else
    {
        return 0;
    }
    if (groupAverage1 < groupAverage2)
    {
        if (groupCourse1 < groupCourse2)
        {
            printf("wow! this group became better!\n");
        }
        else if (groupCourse1 > groupCourse2)
        {
            printf("meh this group got worse\n");
        }
    }
    else if (groupAverage1 > groupAverage2)
    {
        if (groupCourse1 < groupCourse2)
        {
            printf("meh this group got worse\n");
        }
        else if (groupCourse1 > groupCourse2)
        {
            printf("wow! this group became better!\n");
        }
    }
    else if (groupAverage1 == groupAverage2 && groupAverage1 != 0 && groupAverage2 != 0)
    {
        printf("well... this group is still on the same level");
    }
}

void showAll(GroupsInformation* groups) {

    if (groups->head != NULL) {
        Node* current = groups->head;
        while (current->Next)
        {
            showInfo(current);
            printf("\n");
            current = current->Next;
        }
        showInfo(current);
    }
    else {
        printf("\nYour table is empty\n");
    }
}
void showAllByCourses(GroupsInformation* groups, int courseNum) {

    if (groups->head != NULL) {
        Node* current = groups->head;
        while (current->Next)
        {
            infoByCourse(current, courseNum);
            printf("\n");
            current = current->Next;
        }
        infoByCourse(current, courseNum);
    }
    else {
        printf("\nYour table is empty\n");
    }
}
void showAllByGroup(GroupsInformation* groups, int groupNum) {

    if (groups->head != NULL) {
        Node* current = groups->head;
        while (current->Next)
        {
            infoByGroup(groups, current, groupNum);
            printf("\n");
            current = current->Next;
        }
        infoByGroup(groups, current, groupNum);
        groupComparer(groups, current, groupNum);
    }
    else {
        printf("\nYour table is empty\n");
    }
}
int getLenght(GroupsInformation* groups) {
    if (groups->head != NULL) {
        Node* current = groups->head;
        int counter = 1;

        while (current->Next) {
            current = current->Next;
            counter++;
        }

        return counter;
    }
    return 0;
}

bool checkNum(int Num, GroupsInformation* groups) {
    Node* current = groups->head;

    while (current) {
        if (current->groupNumber == Num)
        {
            return true;
        }

        current = current->Next;
    }

    return false;
}


void clear(GroupsInformation* groups) {
    while (getLenght(groups))
        deleteByNum(groups->head->groupNumber, groups);
}
void save(GroupsInformation* students)
{
    FILE* fp;
    fp = fopen("Output.txt", "w");
    if (fp == NULL) {
        printf("Error while trying to open output file\n");
        exit(1);
    }
    else {
        Node* p = students->head;
        while (p != NULL) {
            fprintf(fp, "%d; ", p->groupNumber);
            fprintf(fp, "%d; ", p->course);
            fprintf(fp, "%d; ", p->subject1);
            fprintf(fp, "%d; ", p->subject2);
            fprintf(fp, "%d; ", p->subject3);
            fprintf(fp, "%d; ", p->subject4);
            fprintf(fp, "%d\n", p->subject5);
            p = p->Next;
        }
        printf("Succesfully saved!\n");
    }
    fclose(fp);
}

int main()
{
    GroupsInformation studs = { NULL,NULL };
    FILE* file;
    file = fopen("Input.txt", "r"); //input.txt
    int c = 0;
    char str[255];
    char* next = 0;
    int sortBy = 0;
    int accountNumber;
    int courseNum;
    int simpleNum;
    int groupNum;
    if (!file)
    {
        printf("Error while trying to open input file\n");
        exit(1);
    }
    while (!feof(file))
    {
        fgets(str, 255, file);
        char* s = strtok_s(str, ";", &next);
        Node current = { 0,0,0,0,0,0,0,NULL,NULL };
        do {
            switch (c)
            {
            case 0:
                current.groupNumber = atoi(s);
                break;
            case 1:
                current.course = atoi(s);
                break;
            case 2:
                current.subject1 = atoi(s);
                break;
            case 3:
                current.subject2 = atoi(s);
                break;
            case 4:
                current.subject3 = atoi(s);
                break;
            case 5:
                current.subject4 = atoi(s);
                break;
            case 6:
                current.subject5 = atoi(s);
                break;
            }
            c++;
        } while (s = strtok_s(0, ";", &next));
        c = 0;
        pushBack(&studs, &current);
    }
    fclose(file);

    int choice;

    do {
        printf("Action: \n1 - Sort \n2 - Show all groups \n3 - Delete groupe \n4 - Add groupe\n5 - Find by group number \n6 - Find by course\n7 - Save \n0 - Exit\n");
        scanf_s("%d", &choice);
        printf("\n");
        Node current = { 0,0,0,0,0,0,0,NULL,NULL };
        switch (choice) {
        case 1:
            system("cls");
            printf("1-Sort by course\n2 - Sort by group\n3 - Sort all \n");
            scanf_s("%d", &sortBy);
            switch (sortBy) {
            case 1:
                Sort(&studs, &current);
                printf("Enter  a course you want to sort by\n");
                scanf_s("%d", &courseNum);
                showAllByCourses(&studs, courseNum);
                break;
            case 2:
                Sort(&studs, &current);
                printf("Enter  a group you want to sort by\n");
                scanf_s("%d", &groupNum);
                showAllByGroup(&studs, groupNum);
                break;
            case 3:
                Sort(&studs, &current);
                showAll(&studs);
                break;
            default:
                break;
            }
            break;
        case 2:
            system("cls");
            showAll(&studs);
            break;
        case 3:
            system("cls");
            printf("Enter a group number you want to delete: ");
            scanf_s("%d", &accountNumber);

            if (checkNum(accountNumber, &studs)) {
                deleteByNum(accountNumber, &studs);
            }
            break;
        case 4:
            system("cls");
            printf("\nEnter group number: ");
            scanf_s("%d", &simpleNum);
            current.groupNumber = simpleNum;

            printf("\nEnter course: ");
            scanf_s("%d", &simpleNum);
            while (simpleNum > 5 || simpleNum <= 0)
            {
                printf("course can be only from 1 to 5\n");
                scanf_s("%d", &simpleNum);
            }
            current.course = simpleNum;

            printf("\nEnter subject 1 mark: ");
            scanf_s(" %d", &simpleNum);
            while (simpleNum > 10 || simpleNum <= 0)
            {
                printf("mark can be only from 1 to 10\n");
                scanf_s("%d", &simpleNum);
            }
            current.subject1 = simpleNum;

            printf("\nEnter subject 2 mark: ");
            scanf_s(" %d", &simpleNum);
            while (simpleNum > 10 || simpleNum <= 0)
            {
                printf("mark can be only from 1 to 10\n");
                scanf_s("%d", &simpleNum);
            }
            current.subject2 = simpleNum;

            printf("\nEnter subject 3 mark: ");
            scanf_s(" %d", &simpleNum);
            while (simpleNum > 10 || simpleNum <= 0)
            {
                printf("mark can be only from 1 to 10\n");
                scanf_s("%d", &simpleNum);
            }
            current.subject3 = simpleNum;

            printf("\nEnter subject 4 mark: ");
            scanf_s(" %d", &simpleNum);
            while (simpleNum > 10 || simpleNum <= 0)
            {
                printf("mark can be only from 1 to 10\n");
                scanf_s("%d", &simpleNum);
            }
            current.subject4 = simpleNum;

            printf("\nEnter subject 5 mark: ");
            scanf_s(" %d", &simpleNum);
            while (simpleNum > 10 || simpleNum <= 0)
            {
                printf("mark can be only from 1 to 10\n");
                scanf_s("%d", &simpleNum);
            }
            current.subject5 = simpleNum;

            pushBack(&studs, &current);
            break;
        case 5:
            system("cls");
            printf("Enter a group you want to see\n");
            scanf_s("%d", &groupNum);
            showAllByGroup(&studs, groupNum);
            break;
        case 6:
            system("cls");
            printf("Enter a course you want to see\n");
            scanf_s("%d", &courseNum);
            showAllByCourses(&studs, courseNum);
            break;
        case 7:
            save(&studs);
            break;
        default:
            break;
        }

    } while (choice);
    clear(&studs);
    return 0;
}