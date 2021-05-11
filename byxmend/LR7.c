#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct node
{
    int flightNumber;
    int typeOfPlane; // number of seats
    int numberOfTickets;
    char startLocation[20];
    char finishLocation[20];
    char place[20];
    char time[20];
    char date[20];
    struct node* pNext;
    struct node* pPrev;
} Node;

typedef struct informationAboutSchedule
{
    Node* head;
    Node* tail;
    Node* top;
} InformationAboutSchedule; 

char* concat(const char* s1, const char* s2)
{
    char* result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);

    return result;
}

void pushBack(InformationAboutSchedule* schedules, Node* node)
{
    node->pNext = NULL;
    node->pPrev = NULL;
    Node* currant = (Node*)malloc(sizeof(Node));

    currant->flightNumber = node->flightNumber;
    currant->typeOfPlane = node->typeOfPlane;
    currant->numberOfTickets = 0;
    strcpy(currant->startLocation, node->startLocation);
    strcpy(currant->finishLocation, node->finishLocation);
    strcpy(currant->place, node->place);
    strcpy(currant->time, node->time);
    strcpy(currant->date, node->date);

    currant->pNext = NULL;
    currant->pPrev = NULL;

    if (schedules->head == NULL)
    {
        schedules->head = currant;
        schedules->top = currant;
        schedules->tail = currant;
    }
    else
    {
        currant->pPrev = schedules->top;
        schedules->top->pNext = currant;
        schedules->top = currant;
        schedules->tail = currant;
    }
}

void printElementOfList(InformationAboutSchedule schedules, int counter)
{
    Node* p = schedules.head;

    for (int i = 0; i < counter; i++)
    {
        p = p->pNext;
    }

    printf("\n1. Flight number: %d", p->flightNumber);
    printf("\n2. Type of plane: %d", p->typeOfPlane);
    printf("\n3. Start location: %s", p->startLocation);
    printf("\n4. Finish location: %s", p->finishLocation);
    printf("\n5. Place: %s", p->place);
    printf("\n6. Time: %s", p->time);
    printf("\n7. Date: %s", p->date);
}

// flightNumber
void findByFlightNumber(InformationAboutSchedule schedules, int numb)
{
    Node* p = schedules.head;
    int counter = 0;

    while (p != NULL)
    {
        if (p->flightNumber == numb)
        {
            printElementOfList(schedules, counter);
        }

        p = p->pNext;
        counter++;
    }
}

// typeOfPlane
void findByTypeOfPlane(InformationAboutSchedule schedules, int numb)
{
    Node* p = schedules.head;
    int counter = 0;

    while (p != NULL)
    {
        if (p->typeOfPlane == numb)
        {
            printElementOfList(schedules, counter);
        }

        p = p->pNext;
        counter++;
    }
}

// startLocation
void findByStartLocation(InformationAboutSchedule schedules, char* str)
{
    Node* p = schedules.head;
    int counter = 0;

    while (p != NULL)
    {
        if (strcmp(str, p->startLocation) == 0)
        {
            printElementOfList(schedules, counter);
        }

        p = p->pNext;
        counter++;
    }
}

// finishLocation
void findByFinishLocation(InformationAboutSchedule schedules, char* str)
{
    Node* p = schedules.head;
    int counter = 0;

    while (p != NULL)
    {
        if (strcmp(str, p->finishLocation) == 0)
        {
            printElementOfList(schedules, counter);
        }

        p = p->pNext;
        counter++;
    }
}

// place
void findByPlace(InformationAboutSchedule schedules, char* str)
{
    Node* p = schedules.head;
    int counter = 0;

    while (p != NULL)
    {
        if (strcmp(str, p->place) == 0)
        {
            printElementOfList(schedules, counter);
        }

        p = p->pNext;
        counter++;
    }
}

// time
void findByTime(InformationAboutSchedule schedules, char* str)
{
    Node* p = schedules.head;
    int counter = 0;

    while (p != NULL)
    {
        if (strcmp(str, p->time) == 0)
        {
            printElementOfList(schedules, counter);
        }

        p = p->pNext;
        counter++;
    }
}

// date
void findByDate(InformationAboutSchedule schedules, char* str)
{
    Node* p = schedules.head;
    int counter = 0;

    while (p != NULL)
    {
        if (strcmp(str, p->date) == 0 || strcmp(concat(str, "\n"), p->date) == 0)
        {
            printElementOfList(schedules, counter);
        }

        p = p->pNext;
        counter++;
    }
}

void numberOfAvailableSeats(InformationAboutSchedule schedules)
{
    Node* p = schedules.head;
    int numbOfSeats;

    while (p != NULL)
    {
        numbOfSeats = p->typeOfPlane - p->numberOfTickets;

        printf("\n\nFlight number: %d", p->flightNumber);
        printf("\nNumber of available seats: %d", numbOfSeats);

        p = p->pNext;
    }
}

// nearest flight
void findNearestFlight(InformationAboutSchedule schedules, char* strStartLocation, char* strFinishLocation)
{
    Node* p = schedules.head;
    Node* e;
    int counter = 0, numberOfDates = 1;
    int firstMonthNumber = 12, firstDayNumber = 31;
    int secondMonthNumber = 0, secondDayNumber = 0;
    int secondMonthFirstNumber = 0, secondMonthSecondNumber = 0;
    int secondDayFirstNumber = 0, secondDaySecondNumber = 0;

    printf("\nAll flight dates:\n");

    while (p != NULL)
    {
        if (strcmp(strStartLocation, p->startLocation) == 0 &&
            strcmp(strFinishLocation, p->finishLocation) == 0)
        {
            // convert date
            e = p->date;
            char allString[20] = { 0 };
            strcat(allString, e);

            // day
            secondDayFirstNumber = allString[0] - '0';
            secondDaySecondNumber = allString[1] - '0';
            secondDayNumber = (secondDayFirstNumber * 10) + secondDaySecondNumber;

            // month
            secondMonthFirstNumber = allString[3] - '0';
            secondMonthSecondNumber = allString[4] - '0';
            secondMonthNumber = (secondMonthFirstNumber * 10) + secondMonthSecondNumber;

            // check
            if (secondMonthNumber < firstMonthNumber)
            {
                firstMonthNumber = secondMonthNumber;
                firstDayNumber = secondDayNumber;
            }
            else if (secondMonthNumber == firstMonthNumber && secondDayNumber < firstDayNumber)
                firstDayNumber = secondDayNumber;

            // print date
            printf("\n%d. Date: %s", numberOfDates, p->date);
            numberOfDates++;
        }

        p = p->pNext;
        counter++;
    }

    printf("\n\nNearest flight date: ");

    if (firstDayNumber < 10)
        printf("0%d:", firstDayNumber);
    else
        printf("%d:", firstDayNumber);

    if (firstMonthNumber < 10)
        printf("0%d\n", firstMonthNumber);
    else
        printf("%d\n", firstMonthNumber);
}

void printAllTickets(InformationAboutSchedule schedules)
{
    Node* p = schedules.head;
    int counter = 0, index = 1;

    while (p != NULL)
    {
        if (p->numberOfTickets > 0)
        {
            printf("\nTicket number #%d", index);
            printElementOfList(schedules, counter);
            printf("8. Number of tickets: %d\n", p->numberOfTickets);

            index++;
        }

        p = p->pNext;
        counter++;
    }
}

void bookATicket(InformationAboutSchedule* schedules, char* strStartLocation,
    char* strFinishLocation, char* date)
{
    Node* p = schedules->head;
    int counter = 0, numberOfDates = 1, selectedNumber = 0;
    char str[20] = { 0 };

    while (p != NULL)
    {
        if (strcmp(strStartLocation, p->startLocation) == 0 &&
            strcmp(strFinishLocation, p->finishLocation) == 0 &&
            (strcmp(date, p->date) == 0 || strcmp(concat(date, "\n"), p->date) == 0))
        {
            printf("\n%d. Time: %s", numberOfDates, p->time);
            numberOfDates++;
        }

        p = p->pNext;
        counter++;
    }

    if (numberOfDates == 1)
        printf("\nThere are no flights on this day");
    else
    {
        printf("\n\nEnter time: ");
        scanf(" %s", &str);

        p = schedules->head;
        counter = 0;

        while (p != NULL)
        {
            if (strcmp(strStartLocation, p->startLocation) == 0 &&
                strcmp(strFinishLocation, p->finishLocation) == 0 &&
                (strcmp(date, p->date) == 0 ||
                strcmp(concat(date, "\n"), p->date) == 0) &&
                strcmp(str, p->time) == 0)
            {
                p->numberOfTickets += 1;
                counter++;
                printf("Ticket ordered successfully!");
                break;
            }

            p = p->pNext;
        }

        if (counter == 0)
        {
            printf("Error!");
        }
    }
}

void handOverATicket(InformationAboutSchedule* schedules, InformationAboutSchedule schedulesSave)
{
    Node* p = schedules->head;
    int selectedNumber, index = 1;

    printAllTickets(schedulesSave);
    printf("\n\nChoose the number: ");
    scanf_s("%d", &selectedNumber);

    while (p != NULL)
    {
        if (p->numberOfTickets > 0)
            index++;

        if (selectedNumber == (index - 1))
        {
            p->numberOfTickets--;
            printf("\nTicket passed successfull!");
            break;
        }

        p = p->pNext;
    }
}

void menu()
{
    printf("\n\n0 - Add element to the list\n");
    printf("1 - Find (flightNumber)\n");
    printf("2 - Find (typeOfPlane)\n");
    printf("3 - Find (startLocation)\n");
    printf("4 - Find (finishLocation)\n");
    printf("5 - Find (place)\n");
    printf("6 - Find (time)\n");
    printf("7 - Find (day)\n");
    printf("8 - Find the nearest flight\n");
    printf("9 - Book a ticket\n");
    printf("10 - Hand over your ticket\n");
    printf("11 - Number of available seats\n");
    printf("12 - Print ticket\n");
    printf("Other - Save in data to the file and exit\n");
}

int main()
{
    char stringFromTheFile[200] = { 0 };
    char stringToFindSomething[20] = { 0 };
    char secondStringToFindSomething[20] = { 0 };
    char thirdStringToFindSomething[20] = { 0 };
    char convertStr[255] = { 0 };
    char fullStr[255] = { 0 };
    char* next = 0;
    int countFildsOFStructure = 0, numbMenu = 0, numbToFindSomething = 0;

    InformationAboutSchedule schedules = { NULL, NULL, NULL };
    Node* fileWriteOperation;

    FILE* filePrint;
    FILE* fileWrite;

    // open filePrint
    int errOpenFilePrint = fopen_s(&filePrint, "filePrint.txt", "r");

    if (errOpenFilePrint != 0)
        exit(1);

    // open fileWrite
    int errOpenFileWrite = fopen_s(&fileWrite, "fileWrite.txt", "w");

    if (errOpenFileWrite != 0)
        exit(1);

    // Fill the list from filePrint
    while (!feof(filePrint))
    {
        fgets(stringFromTheFile, 200, filePrint);

        char* s = strtok_s(stringFromTheFile, ",", &next);
        
        Node currant = { 0, 0, "", "", "", "", "", NULL, NULL };
        
        do {
            switch (countFildsOFStructure)
            {
            case 0:
                currant.flightNumber = atoi(s);
                break;
            case 1:
                currant.typeOfPlane = atoi(s);
                break;
            case 2:
                strcat(currant.startLocation, s);
                break;
            case 3:
                strcat(currant.finishLocation, s);
                break;
            case 4:
                strcat(currant.place, s);
                break;
            case 5:
                strcat(currant.time, s);
                break;
            case 6:
                strcat(currant.date, s);
                break;
            }

            countFildsOFStructure++;
        } while (s = strtok_s(0, ",", &next));

        countFildsOFStructure = 0;

        pushBack(&schedules, &currant);
    }
    
    // algorithm
    menu();

    while (1)
    {
        Node currant = { 0, 0, "", "", "", "", "", NULL, NULL };

        printf("\nChoose operation: ");
        scanf_s("%d", &numbMenu);

        switch (numbMenu)
        {
        case 0:
            printf("\nEnter flight number: ");
            scanf_s("%d", &numbToFindSomething);
            currant.flightNumber = numbToFindSomething;

            printf("\nEnter type of plane: ");
            scanf_s("%d", &numbToFindSomething);
            currant.typeOfPlane = numbToFindSomething;

            printf("\nEnter start location: ");
            scanf(" %s", &stringToFindSomething);
            strcat(currant.startLocation, stringToFindSomething);

            printf("\nEnter finish location: ");
            scanf(" %s", &stringToFindSomething);
            strcat(currant.finishLocation, stringToFindSomething);

            printf("\nEnter place: ");
            scanf(" %s", &stringToFindSomething);
            strcat(currant.place, stringToFindSomething);

            printf("\nEnter time: ");
            scanf(" %s", &stringToFindSomething);
            strcat(currant.time, stringToFindSomething);
            
            printf("\nEnter date: ");
            scanf(" %s", &stringToFindSomething);
            strcat(currant.date, stringToFindSomething);

            pushBack(&schedules, &currant);
            break;
        case 1:
            numbToFindSomething = 0;
            printf("\nEnter flight number: ");
            scanf_s("%d", &numbToFindSomething);
            findByFlightNumber(schedules, numbToFindSomething);
            break;
        case 2:
            numbToFindSomething = 0;
            printf("\nEnter type of plane: ");
            scanf_s("%d", &numbToFindSomething);
            findByTypeOfPlane(schedules, numbToFindSomething);
            break;
        case 3:
            printf("\nEnter start location: ");
            scanf(" %s", &stringToFindSomething);
            findByStartLocation(schedules, stringToFindSomething);
            break;
        case 4:
            printf("\nEnter finish location: ");
            scanf(" %s", &stringToFindSomething);
            findByFinishLocation(schedules, stringToFindSomething);
            break;
        case 5:
            printf("\nEnter place: ");
            scanf(" %s", &stringToFindSomething);
            findByPlace(schedules, stringToFindSomething);
            break;
        case 6:
            printf("\nEnter time: ");
            scanf(" %s", &stringToFindSomething);
            findByTime(schedules, stringToFindSomething);
            break;
        case 7:
            printf("\nEnter date: ");
            scanf(" %s", &stringToFindSomething);
            findByDate(schedules, stringToFindSomething);
            break;
        case 8:
            printf("\nEnter start location: ");
            scanf(" %s", &stringToFindSomething);
            printf("\nEnter finish location: ");
            scanf(" %s", &secondStringToFindSomething);
            findNearestFlight(schedules, stringToFindSomething, secondStringToFindSomething);
            break;
        case 9:
            printf("\nEnter start location: ");
            scanf(" %s", &stringToFindSomething);
            printf("\nEnter finish location: ");
            scanf(" %s", &secondStringToFindSomething);
            printf("\nEnter date: ");
            scanf(" %s", &thirdStringToFindSomething);
            bookATicket(&schedules, stringToFindSomething, secondStringToFindSomething, thirdStringToFindSomething);
            break;
        case 10:
            handOverATicket(&schedules, schedules);
            break;
        case 11:
            numberOfAvailableSeats(schedules);
            break;
        case 12:
            printAllTickets(schedules);
            break;
        default:
            // write the list to a file
            fileWriteOperation = schedules.head;

            while (fileWriteOperation != NULL)
            {
                strcpy(fullStr, "");
                strcpy(convertStr, "");

                _itoa(fileWriteOperation->flightNumber, convertStr, 10);
                strcat(fullStr, convertStr);
                strcat(fullStr, ",");

                strcpy(convertStr, "");
                _itoa(fileWriteOperation->typeOfPlane, convertStr, 10);
                strcat(fullStr, convertStr);
                strcat(fullStr, ",");

                strcat(fullStr, fileWriteOperation->startLocation);
                strcat(fullStr, ",");

                strcat(fullStr, fileWriteOperation->finishLocation);
                strcat(fullStr, ",");

                strcat(fullStr, fileWriteOperation->place);
                strcat(fullStr, ",");

                strcat(fullStr, fileWriteOperation->time);
                strcat(fullStr, ",");

                strcat(fullStr, fileWriteOperation->date);

                fprintf(fileWrite, fullStr);

                fileWriteOperation = fileWriteOperation->pNext;
            }

            fclose(filePrint);
            fclose(fileWrite);

            return 0;
        }

        menu();
    }
}