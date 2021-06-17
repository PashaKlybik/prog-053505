#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct service {
    int timeRequired;
    int number;
    struct serivce* next;
    struct serivce* prev;
} Service;

void Sort(Service* serv) {
    Service* temp = serv;
    Service* tempNext = temp->next;
    int ended = 1;
    while (ended) {
        ended = 0;
        while (serv->next)
        {
            if (serv->timeRequired > tempNext->timeRequired) 
            {
                ended = 1;
                int tempTR = serv->timeRequired;
                int tempNumber = serv->number;
                serv->timeRequired = tempNext->timeRequired;
                serv->number = tempNext->number;
                tempNext->timeRequired = tempTR;
                tempNext->number = tempNumber;
            }
            serv = serv->next;
            tempNext = serv->next;
        }
        while (serv->prev)
        {
            serv = serv->prev;
        }
        tempNext = serv->next;
    }
}

void NewService(Service* serv, int number) {
    Service* p = (Service*)malloc(sizeof(Service));
    p->timeRequired = rand() % 100;
    p->prev = serv;
    p->next = NULL;
    p->number = number;
    serv->next = p;
}

int main()
{
    int error = 0;
    int exit = 0;
    int serviceNum = 0;
    int timeGot = 0;
    int routeCount = 0;
    Service* servce = (Service*)malloc(sizeof(Service));;
    servce->timeRequired = rand() % 100;
    servce->next = NULL;
    servce->prev = NULL;
    servce->number = 0;
    Service* start = servce;
    printf("Number of services is : \n");
    scanf_s("%d", &serviceNum);
    while (serviceNum > 10 || serviceNum<=0) 
    {
        error = rand() %4 + 1;
        switch (error)
        {
        case 1:
            printf("Nah too much services, so unrealistic, zero services are unrealistic too\n");
            break;
        case 2:
            printf("What are all these huge amount of services about?! maybe you tried to enter 0? :) \n");
            break;
        case 3:
            printf("Output will be ugly with such a huge number of services\n");
            break;
        case 4:
            printf("cmon too much services that is not interesting or you entered 0\n");
            break;
        default:
            break;
        }
        scanf_s("%d", &serviceNum);
    }
    printf("Write how much time you have (in minutes)\n");
    scanf_s("%d", &timeGot);
    while (timeGot <= 0 || timeGot >=400) 
    {
        printf("enter your time correctly please\n");
        scanf_s("%d", &timeGot);
    }
    
    for (int i = 1; i < serviceNum; i++) 
    {
        NewService(servce, i);
        servce = servce->next;
    }
    for (int i = 0; i < serviceNum; i++) 
    {
        printf("Num | time  ");
    }
    printf("\n");
    servce = start;
    while (servce) {
        printf("%d      %d   ", servce->number, servce->timeRequired);
        servce = servce->next;
    }
    servce = start;
    printf("\n\nNow to your perfect route: \n");
    Sort(servce);
    servce = start;
    for (int i = 0; i < serviceNum; i++)
    {
        printf("Num | time  ");
    }
    printf("\n");
    servce = start;
    while (servce) {
        printf("%d      %d    ", servce->number, servce->timeRequired);
        servce = servce->next;
    }
    printf("\n\nSo you can visit services in an order like this:\n");
    servce = start;
    while (servce) {
        routeCount += servce->timeRequired;
        if (routeCount < timeGot) {
            printf("Service Num %d\n", servce->number);
        }
        else {
            break;
        }
        servce = servce->next;
    }
    while (servce->prev) {
        servce = servce->prev;
        free(servce->next);
    }
    free(servce);
}