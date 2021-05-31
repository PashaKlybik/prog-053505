//
//  main.c
//  7lab
//
//  Created by Дима Гузерчук on 18.05.21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
struct Car{
    char car_mark[20];
    int car_year;
    int car_engine;
    int car_price;
};

struct Car_Item{
    struct Car data;
    struct Car_Item* prev;
    struct Car_Item* next;
};
//====
struct Car_List{
    struct Car_Item* start;
    struct Car_Item* end;
};

struct client{
    char FIO[154];
    char phone_number[154];
    struct Car my_auto;
};

struct ClientListItem {
    struct ClientListItem *prev;
    struct ClientListItem *next;
    struct client data;
};

struct ClientList {
    struct ClientListItem *start;
    struct ClientListItem *end;
};
//===
struct deal{
    struct Car selled_auto;
    struct client buyer;
    int profit;
};

struct DealListItem {
    struct DealListItem *prev;
    struct DealListItem *next;
    struct deal data;
};

struct DealList {
    struct DealListItem *start;
    struct DealListItem *end;
};

void DealInit(struct DealList* list) {
    list->start = NULL;
    list->end = NULL;
}
void DealAdd(struct DealList* list,struct deal numb) {
    struct DealListItem* temp =(struct DealListItem*)malloc(sizeof(struct DealListItem));
    if(temp==NULL){
        printf("Memory error\n");
        exit(1);
    }
    temp->next = NULL;
    temp->prev = list->end;
    temp->data.selled_auto.car_price = numb.selled_auto.car_price;
    temp->data.selled_auto.car_year = numb.selled_auto.car_year;
    temp->data.selled_auto.car_engine = numb.selled_auto.car_engine;
    strcpy(temp->data.selled_auto.car_mark,numb.selled_auto.car_mark);
    temp->data.profit = numb.profit;
    temp->data.buyer.my_auto.car_price = numb.buyer.my_auto.car_price;
    temp->data.buyer.my_auto.car_year = numb.buyer.my_auto.car_year;
    temp->data.buyer.my_auto.car_engine = numb.buyer.my_auto.car_engine;
    strcpy(temp->data.buyer.FIO , numb.buyer.FIO);
    strcpy(temp->data.buyer.phone_number , numb.buyer.phone_number);
    strcpy(temp->data.buyer.my_auto.car_mark , numb.buyer.my_auto.car_mark);
    if (!list->start) {
        list->start = temp;
    }
    else {
        list->end->next = temp;
    }
    list->end = temp;
}


void DealClear(struct DealList* list) {
    struct DealListItem* li = list->start;
    struct DealListItem* temp;
    while (li)
    {
        temp = li;
        li = li->next;
        free(temp);
    }
    list->start = NULL;
    list->end = NULL;
}

//===
void ClientInit(struct ClientList* list) {
    list->start = NULL;
    list->end = NULL;
}
void ClientAdd(struct ClientList* list,struct client numb) {
    struct ClientListItem* temp =(struct ClientListItem*)malloc(sizeof(struct ClientListItem));
    if(temp==NULL){
        printf("Memory error\n");
        exit(1);
    }
    temp->next = NULL;
    temp->prev = list->end;
    strcpy(temp->data.FIO,numb.FIO);
    strcpy(temp->data.phone_number,numb.phone_number);
    temp->data.my_auto.car_price=numb.my_auto.car_price;
    temp->data.my_auto.car_engine=numb.my_auto.car_engine;
    temp->data.my_auto.car_year=numb.my_auto.car_year;
    strcpy(temp->data.my_auto.car_mark,numb.my_auto.car_mark);
    if (!list->start) {
        list->start = temp;
    }
    else {
        list->end->next = temp;
    }
    list->end = temp;
}

void ClientDelete(struct ClientList* list, struct ClientListItem* li) {
    if (!li)
        return;
    if (li->prev)
        li->prev->next = li->next;
    else {

    //deleting first item
        list->start = li->next;
        if (list->start)
        list->start->prev = NULL;

    }
    if (li->next)
        li->next->prev = li->prev;
    else {
        //deleting last item
        list->end = li->prev;
        if (list->end)
            list->end->next = NULL;

    }
    free(li);
}




void ClientPrint(struct ClientList* list) {
    struct ClientListItem* li = list->start;
    while (li) {
        printf("Человек\n");
        printf("ФИО: %s\n",li->data.FIO);
        printf("Контакт: %s\n",li->data.phone_number);
        printf("Марка: %s\n",li->data.my_auto.car_mark);
        printf("Год выпуска: %d\n",li->data.my_auto.car_year);
        printf("Цена: %d\n",li->data.my_auto.car_price);
        li = li->next;
    }
}

struct ClientListItem* ClientFind(struct ClientListItem* li,struct client numb) {
    while (li) {
       if((!(strcmp(li->data.FIO,numb.FIO)))&&(!(strcmp(li->data.phone_number,numb.phone_number)))&&(!(strcmp(li->data.my_auto.car_mark,numb.my_auto.car_mark)))&&li->data.my_auto.car_price == numb.my_auto.car_price&&li->data.my_auto.car_year == numb.my_auto.car_year&&li->data.my_auto.car_engine == numb.my_auto.car_engine){
        return li;
       }
       li = li->next;
    }
    return NULL;
}



struct ClientListItem* ClientMarkFind(struct ClientListItem* li,struct client numb) {
    while (li) {
       if (!(strcmp(li->data.my_auto.car_mark,numb.my_auto.car_mark)))
        return li;
        li = li->next;
    }
    return NULL;
}


struct ClientListItem* ClientPriceFind(struct ClientListItem* li,struct client numb) {
    while (li) {
       if (li->data.my_auto.car_price == numb.my_auto.car_price)
        return li;
        li = li->next;
    }
    return NULL;
}


struct ClientListItem* ClientYearFind(struct ClientListItem* li,struct client numb) {
    while (li) {
       if (li->data.my_auto.car_year == numb.my_auto.car_year)
        return li;
        li = li->next;
    }
    return NULL;
}


struct ClientListItem* ClientEngineCapacityFind(struct ClientListItem* li,struct client numb) {
    while (li) {
       if (li->data.my_auto.car_engine == numb.my_auto.car_engine)
        return li;
        li = li->next;
    }
    return NULL;
}


struct ClientListItem* ClientFIOFind(struct ClientListItem* li,struct client numb) {
    while (li) {
       if ((!(strcmp(li->data.FIO,numb.FIO))))
        return li;
        li = li->next;
    }
    return NULL;
}


struct ClientListItem* ClientPhoneNumberFind(struct ClientListItem* li,struct client numb) {
    while (li) {
       if (!(strcmp(li->data.phone_number,numb.phone_number)))
        return li;
        li = li->next;
    }
    return NULL;
}




void ClientDeleteItem(struct ClientList* list, struct client numb) {
    struct ClientListItem* li = ClientFind(list->start, numb);
    ClientDelete(list, li);
}
void ClientClear(struct ClientList* list) {
    struct ClientListItem* li = list->start;
    struct ClientListItem* temp;
    while (li)
    {
        temp = li;
        li = li->next;
        free(temp);
    }
    list->start = NULL;
    list->end = NULL;
}

//====
void Init(struct Car_List* list){
    list->start = NULL;
    list->end = NULL;
}

void Car_Add(struct Car_List* list, struct Car numb){
    struct Car_Item* temp = (struct Car_Item*)malloc(sizeof(struct Car_Item));
    if (temp == NULL){
        printf("Memory error");
        exit(1);
    }
    temp->next = NULL;
    temp->prev = list->end;
    temp->data.car_price = numb.car_price;
    temp->data.car_engine = numb.car_engine;
    temp->data.car_year = numb.car_year;
    strcpy(temp->data.car_mark, numb.car_mark);
    if (!list->start)
        list->start = list->end = temp;
    else{
        struct Car_Item *temp1 = list->end;
        list->end = temp;
        temp1->next = temp;
        temp->prev = temp1;
    }
  
}

void Car_Print(struct Car_List* list){
    struct Car_Item* li = list->start;
    while (li) {
        printf("======Car======\n");
        printf("Mark -> %s \n", li->data.car_mark);
        printf("Price -> %d EURO\n", li->data.car_price);
        printf("Engine -> %d (sm/cube)\n", li->data.car_engine);
        printf("Year -> %d year\n", li->data.car_year);
        printf("===============\n");
        li = li->next;
    }
}


void AutoClear(struct Car_List* list) {
    struct Car_Item* li = list->start;
    struct Car_Item* temp;
    while (li)
    {
        temp = li;
        li = li->next;
        free(temp);
    }
    list->start = NULL;
    list->end = NULL;
}

int AutoLength(struct Car_List *list){
    struct Car_Item* li = list->start;
    int average=0;
    while(li){
        average++;
        li=li->next;
    }
    return average;
}

void AutoDelete(struct Car_List* list, struct Car_Item* li) {
    if (!li)
        return;
    if (li->prev)
        li->prev->next = li->next;
    else {
        list->start = li->next;
        if (list->start)
        list->start->prev = NULL;

    }
    if (li->next)
        li->next->prev = li->prev;
    else {
        list->end = li->prev;
        if (list->end)
            list->end->next = NULL;

    }
    free(li);
}

struct Car_Item* AutoFind(struct Car_Item* li,struct Car numb) {
    while (li) {
       if ((!(strcmp(li->data.car_mark, numb.car_mark))) && li->data.car_price == numb.car_price && li->data.car_year == numb.car_year && li->data.car_engine == numb.car_engine){
        return li;
       }
       li = li->next;
    }
    return NULL;
}

struct Car_Item* AutoMarkFind(struct Car_Item* li,struct Car numb) {
    while (li) {
       if (!(strcmp(li->data.car_mark,numb.car_mark))){
            return li;
       }
        li = li->next;
    }
    return NULL;
}

struct Car_Item* AutoPriceFind(struct Car_Item* li,struct Car numb) {
    while (li) {
       if (li->data.car_price == numb.car_price)
        return li;
        li = li->next;
    }
    return NULL;
}

struct Car_Item* AutoYearFind(struct Car_Item* li,struct Car numb) {
    while (li) {
       if (li->data.car_year == numb.car_year)
        return li;
        li = li->next;
    }
    return NULL;
}

struct Car_Item* AutoEngineFind(struct Car_Item* li,struct Car numb){
    while (li) {
       if (li->data.car_engine == numb.car_engine)
        return li;
        li = li->next;
    }
    return NULL;
}

//void AutoYearSort_info(struct Car_List *list) {
//    struct Car_Item *t = NULL;
//    struct Car_Item  *t1;
//    struct Car r;
//    do {
//        for (t1=list->start; t1->next != t; t1 = t1->next)
//            if (t1->data.car_year->t1->next->data.car_year)  {
//                    r.car_price=t1->data.car_price;
//                    r.car_engine=t1->data.car_engine;
//                    r.car_year=t1->data.car_year;
//                strcpy(r.car_mark,t1->data.car_mark);
//                    t1->data.car_price=t1->next->data.car_price;
//                    t1->data.car_engine=t1->next->data.car_engine;
//                    t1->data.car_year=t1->next->data.car_year;
//                strcpy(t1->data.car_mark,t1->next->data.car_mark);
//                    t1->next->data.car_price=r.car_price;
//                    t1->next->data.car_engine=r.car_engine;
//                    t1->next->data.car_year=r.car_year;
//                strcpy(t1->next->data.car_mark,r.car_mark);
//            }
//            t = t1;
//    } while (list-> start -> next != t);
//}
//void AutoPriceSort_info(struct Car_List *list) {
//    struct Car_Item *t = NULL;
//    struct Car_Item *t1;
//    struct Car r;
//    do {
//        for (t1=list->start; t1 -> next != t; t1 = t1-> next)
//            if (t1-> data.car_price > t1-> next -> data.car_price)  {
//                    r.car_price=t1->data.car_price;
//                    r.car_engine=t1->data.car_engine;
//                    r.car_year=t1->data.car_year;
//                strcpy(r.car_mark,t1->data.car_mark);
//                    t1->data.car_price=t1->next->data.car_price;
//                    t1->data.car_engine=t1->next->data.car_engine;
//                    t1->data.car_year=t1->next->data.car_year;
//                strcpy(t1->data.car_mark,t1->next->data.car_mark);
//                    t1->next->data.car_price=r.car_price;
//                    t1->next->data.car_engine=r.car_engine;
//                    t1->next->data.car_year=r.car_year;
//                strcpy(t1->next->data.car_mark,r.car_mark);
//            }
//            t = t1;
//    } while (list-> start -> next != t);
//}

void AutoEdit(struct Car_Item *li, struct Car numb){
    while (li) {
        if ((!(strcmp(li->data.car_mark,numb.car_mark)))&&li->data.car_price == numb.car_price&&li->data.car_year == numb.car_year&&li->data.car_engine == numb.car_engine){
            int n=0;
            printf("Для редактирования марки автомобиля введите 1\n");
            printf("Для редактирования года выпуска автомобиля введите 2\n");
            printf("Для редактирования цены автомобиля введите 3\n");
            printf("Для редактирования объёма двигателя автомобиля введите 4\n");
            printf("\n");
            if(!scanf("%d",&n)){
                printf("Вы ввели что-то не то\n");
                fflush(stdin);
                return;
            }
            switch(n){
                case 1:
                printf("Введите марку\n");
                scanf("%s",li->data.car_mark);
                return;
                case 2:
                printf("Введите год выпуска\n");
                scanf("%d",&(li->data.car_year));
                return;
                case 3:
                printf("Введите цену\n");
                scanf("%d",&(li->data.car_price));
                return;
                case 4:
                printf("Введите объём двигателя\n");
                scanf("%d",&(li->data.car_engine));
                return;
                default: return;
            }
        }
        li = li->next;
    }
    printf("Такого автомобиля нет\n");
}

void AutoDeleteItem(struct Car_List* list, struct Car numb) {
    struct Car_Item* li = AutoFind(list->start, numb);
    AutoDelete(list, li);
}


int main() {
    struct DealList DEAL;
    DealInit(&DEAL);
    struct Car_List AUTO;
    struct ClientList CLIENT;
    Init(&AUTO);
    ClientInit(&CLIENT);
    FILE* onauto;
    FILE* onclient  = fopen("clients.txt", "r");
    onauto = fopen("automobiles.txt", "r");
    char line[256], line2[256];
    while(fgets(line2, sizeof(line2), onclient)){
        struct client temp;
        fscanf(onclient,"%s",temp.FIO);
        fscanf(onclient,"%s",temp.phone_number);
        fscanf(onclient,"%s",temp.my_auto.car_mark);
        fscanf(onclient,"%d",&(temp.my_auto.car_year));
        fscanf(onclient,"%d",&(temp.my_auto.car_price));
        fscanf(onclient,"%d",&(temp.my_auto.car_engine));
        ClientAdd(&CLIENT,temp);
    }
    while(fgets(line, sizeof(line), onauto)){
        struct Car temp;
        fscanf(onauto,"%s",temp.car_mark);
        fscanf(onauto,"%d",&(temp.car_year));
        fscanf(onauto,"%d",&(temp.car_price));
        fscanf(onauto,"%d",&(temp.car_engine));
        Car_Add(&AUTO,temp);
    }
    fclose(onauto);
    fclose(onclient);
    int k = 0, action = 0;
    while(1){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("Для входа в режим редактирования базы автомобилей введите 1\n");
        printf("Для входа в режим совершения сделки введите 2\n");
        printf("Для выхода из программы введите 0\n");
        scanf("%d",&action);
        switch (action) {
            case 1:{
                int action2;
                    while (1) {
                        if(k==54){
                            k=0;
                            break;
                        }
                        printf("Добро пожаловать в режим редактирования базы автомобилей\n");
                        printf("Для просморта всей базы автомобилей введите 1\n");
                        printf("Для поиска по базе введите 2\n");
                        printf("Для выхода из режима введите 0\n");
                        if(!scanf("%d",&action2)){
                            printf("Ошибка\n");
                            fflush(stdin);
                            action2=54;
                        }
                        switch (action2) {
                            case 1:{
                                Car_Print(&AUTO);
                            }break;
                            case 2:{
                                int action3 = 0;
                                while (1) {
                                    printf("Добро пожаловать в режим поиска по базе автомобилей\n");
                                    printf("Для поиска кокретного автомобиля введите 1\n");
                                    printf("Для поиска всех автомобилей определенной марки введите 2\n");
                                    printf("Для поиска всех автомобилей определенного года выпуска введите 3\n");
                                    printf("Для поиска всех автомобилей определенной цены введите 4\n");
                                    printf("Для поиска всех автомобилей с определенным объёмом двигателя введите 5\n");
                                    printf("Для выхода из режима введите 0\n");
                                    if(!scanf("%d",&action3)){
                                        printf("Ошибка\n");
                                        fflush(stdin);
                                        action3=54;
                                    }
                                    switch (action3) {
                                        case 1:{
                                            struct Car temp;
                                            printf("Введите марку автомобиля\n");
                                            scanf("%s",temp.car_mark);
                                            printf("Введите год выпуска автомобиля\n");;
                                            if(!scanf("%d",&(temp.car_year))){
                                                printf("Вы ввели что-то не то\n");
                                                fflush(stdin);
                                                break;
                                            }
                                            printf("Введите цену автомобиля\n");
                                            if(!scanf("%d",&(temp.car_price))){
                                                printf("Вы ввели что-то не то\n");
                                                fflush(stdin);
                                                break;
                                            }
                                            printf("Введите вместимость двигателя автомобиля\n");
                                            if(!scanf("%d",&(temp.car_engine))){
                                                printf("Вы ввели что-то не то\n");
                                                fflush(stdin);
                                                break;
                                            }
                                            struct Car_Item* from = AutoFind(AUTO.start, temp);
                                            if(from==NULL){
                                                printf("Автомобилей не найдено\n");
                                            }
                                            while (from) {
                                                printf("%s\n",from->data.car_mark);
                                                printf("%d\n",from->data.car_year);
                                                printf("%d\n",from->data.car_price);
                                                printf("%d\n",from->data.car_engine);
                                                printf("\n");
                                                from = AutoFind(from->next, temp);
                                            }
                                        }break;
                                        case 2:{
                                            struct Car temp;
                                            printf("Введите марку автомобиля\n");
                                            scanf("%s",temp.car_mark);
                                            struct Car_Item* from = AutoMarkFind(AUTO.start, temp);
                                            if(from==NULL){
                                                printf("Автомобилей не найдено\n");
                                            }
                                            while (from) {
                                                printf("%s\n",from->data.car_mark);
                                                printf("%d\n",from->data.car_year);
                                                printf("%d\n",from->data.car_price);
                                                printf("%d\n",from->data.car_engine);
                                                printf("\n");
                                                from = AutoMarkFind(from->next, temp);
                                            }
                                        }break;
                                        case 3:{
                                            struct Car temp;
                                            printf("Введите год автомобиля\n");
                                            if(!scanf("%d",&(temp.car_year))){
                                                printf("Автомобилей не найдено\n");
                                                fflush(stdin);
                                                break;
                                            }
                                            struct Car_Item* from = AutoYearFind(AUTO.start, temp);
                                            if(from==NULL){
                                                printf("Автомобилей не найдено\n");
                                            }
                                            while (from) {
                                                printf("%s\n",from->data.car_mark);
                                                printf("%d\n",from->data.car_year);
                                                printf("%d\n",from->data.car_price);
                                                printf("%d\n",from->data.car_engine);
                                                printf("\n");
                                                from = AutoYearFind(from->next, temp);
                                            }
                                            break;
                                        }
                                        case 4:{
                                            struct Car temp;
                                            printf("Введите цену автомобиля\n");
                                            if(!scanf("%d",&temp.car_price)){
                                                printf("Автомобилей не найдено\n");
                                                fflush(stdin);
                                                break;
                                            }
                                            struct Car_Item* from = AutoPriceFind(AUTO.start, temp);
                                            if(from==NULL){
                                                printf("Автомобилей не найдено\n");
                                            }
                                            while (from) {
                                                printf("%s\n",from->data.car_mark);
                                                printf("%d\n",from->data.car_year);
                                                printf("%d\n",from->data.car_price);
                                                printf("%d\n",from->data.car_engine);
                                                printf("\n");
                                                from = AutoPriceFind(from->next, temp);
                                            }
                                            break;
                                        }
                                            break;
                                        case 5:{
                                            struct Car temp;
                                            printf("Введите объем двигателя автомобиля\n");
                                            if(!scanf("%d",&(temp.car_engine))){
                                                printf("Автомобилей не найдено\n");
                                                fflush(stdin);
                                                break;
                                            }
                                            struct Car_Item* from = AutoEngineFind(AUTO.start, temp);
                                            if(from==NULL){
                                                printf("Автомобилей не найдено\n");
                                            }
                                            while (from) {
                                                printf("%s\n",from->data.car_mark);
                                                printf("%d\n",from->data.car_year);
                                                printf("%d\n",from->data.car_price);
                                                printf("%d\n",from->data.car_engine);
                                                printf("\n");
                                                from = AutoEngineFind(from->next, temp);
                                            }
                                        }break;
                                        default:break;
                                    }
                                }
                            }break;
//                            case 3:{
//                                printf("Введите автомобиль для редактирования");
//                                struct Car temp;
//                                printf("Введите марку автомобиля\n");
//                                scanf("%s",temp.car_mark);
//                                printf("Введите год выпуска автомобиля\n");
//                                if(!scanf("%d",&(temp.car_year))){
//                                    printf("Вы ввели что-то не то\n");
//                                    fflush(stdin);
//                                    break;
//                                }
//                                printf("Введите цену автомобиля\n");
//                                if(!scanf("%d",&(temp.car_price))){
//                                    printf("Вы ввели что-то не то\n");
//                                    fflush(stdin);
//                                    break;
//                                }
//                                printf("Введите вместимость двигателя автомобиля\n");
//                                if(!scanf("%d",&(temp.car_engine))){
//                                    printf("Вы ввели что-то не то\n");
//                                    fflush(stdin);
//                                    break;
//                                }
//                                AutoEdit(AUTO.start,temp);
//                                break;
//                            }break;
                            case 0: k=54; break;
                            default:break;
                        }
                    }
                }break;
            case 2:{
                int action44;
                while (1) {
                    printf("Добро пожаловать в режим совершения сделок\n");
                    printf("Для просморта всей базы покупателей введите 1\n");
                    printf("Для поиска по базе покупателей введите 2\n");
                    printf("Для совершения сделки введите 3\n");
                    printf("Для выхода из режима введите 0\n");
                    if(!scanf("%d",&action44)){
                        printf("Вы ввели что-то не то\n");
                        action44=54;
                    }
                    switch (action44) {
                        case 1: ClientPrint(&CLIENT); break;
                        case 2:{
                            int action5;
                            while(1){
                                printf("Добро пожаловать в режим поиска по базе покупателей\n");
                                printf("Для поиска кокретного покупателя введите 1\n");
                                printf("Для поиска покупателя с опедленным ФИО введите 2\n");
                                printf("Для поиска покупателя с опредленным номером номером телефона введите 3\n");
                                printf("Для поиска всех покупатлей на автомобили определенной марки введите 4\n");
                                printf("Для поиска всех покупателей на автомобили определенного года выпуска введите 5\n");
                                printf("Для поиска всех покупателей на автомобили определенной цены введите 6\n");
                                printf("Для поиска всех автомобили с определенным объёмом двигателя введите 7\n");
                                printf("Для выхода из режима введите 0\n");
                                scanf("%d",&action5);
                                switch(action5){
                                case 1:{
                                    printf("Введите покупателя\n");
                                    struct client temp;
                                    printf("Введите ФИО покупателя\n");
                                    scanf("%s",temp.FIO);
                                    printf("Введите контакт покупателя\n");
                                    scanf("%s",temp.phone_number);
                                    printf("Введите марку автомобиля, нужно для покупателя\n");
                                    scanf("%s",temp.my_auto.car_mark);
                                    printf("Введите год выпуска автомобиля, нужно для покупателя\n");
                                    if(!scanf("%d",&(temp.my_auto.car_year))){
                                        printf("Вы ввели что-то не то\n");
                                        fflush(stdin);
                                        break;
                                    }
                                    printf("Введите цену автомобиля, нужно для покупателя\n");
                                    if(!scanf("%d",&(temp.my_auto.car_price))){
                                    printf("Вы ввели что-то не то\n");
                                    fflush(stdin);
                                    break;
                                    }
                                    printf("Введите вместимость двигателя автомобиля, нужно для покупателя\n");
                                    if(!scanf("%d",&(temp.my_auto.car_engine))){
                                    printf("Вы ввели что-то не то\n");
                                    fflush(stdin);
                                    break;
                                    }
                                    struct ClientListItem* from = ClientFind(CLIENT.start, temp);
                                    if(from==NULL){
                                    printf("Покупателей не найдено\n");
                                    }
                                    while (from) {
                                        printf("%s\n",from->data.FIO);
                                        printf("%s\n",from->data.phone_number);
                                        printf("%s\n",from->data.my_auto.car_mark);
                                        printf("%d\n",from->data.my_auto.car_year);
                                        printf("%d\n",from->data.my_auto.car_price);
                                        printf("%d\n",from->data.my_auto.car_engine);
                                        printf("\n");
                                        from = ClientFind(from->next, temp);
                                    }
                                    break;
                                }
                                case 2:{
                                    struct client temp;
                                    printf("Введите имя покупателя\n");
                                    scanf("%s",temp.FIO);
                                    struct ClientListItem* from = ClientFIOFind(CLIENT.start, temp);
                                    if(from==NULL){
                                        printf("Покупателей не найдено\n");
                                    }
                                    while (from) {
                                        printf("%s\n",from->data.FIO);
                                        printf("%s\n",from->data.phone_number);
                                        printf("%s\n",from->data.my_auto.car_mark);
                                        printf("%d\n",from->data.my_auto.car_year);
                                        printf("%d\n",from->data.my_auto.car_price);
                                        printf("%d\n",from->data.my_auto.car_engine);
                                        printf("\n");
                                        from = ClientFIOFind(from->next, temp);
                                    }
                                    break;
                                }
                                case 3:{
                                    struct client temp;
                                    printf("Введите контакт покупателя\n");
                                    scanf("%s",temp.phone_number);
                                    struct ClientListItem* from = ClientPhoneNumberFind(CLIENT.start, temp);
                                    if(from==NULL){
                                        printf("Покупателей не найдено\n");
                                    }
                                    while (from) {
                                        printf("%s\n",from->data.FIO);
                                        printf("%s\n",from->data.phone_number);
                                        printf("%s\n",from->data.my_auto.car_mark);
                                        printf("%d\n",from->data.my_auto.car_year);
                                        printf("%d\n",from->data.my_auto.car_price);
                                        printf("%d\n",from->data.my_auto.car_engine);
                                        printf("\n");
                                        from = ClientPhoneNumberFind(from->next, temp);
                                    }
                                    break;
                                }
                                case 4:{
                                    struct client temp;
                                    printf("Введите марку автомобиля\n");
                                    scanf("%s",temp.my_auto.car_mark);
                                    struct ClientListItem* from = ClientMarkFind(CLIENT.start, temp);
                                    if(from==NULL){
                                        printf("Покупателей не найдено\n");
                                    }
                                    while (from) {
                                        printf("%s\n",from->data.FIO);
                                        printf("%s\n",from->data.phone_number);
                                        printf("%s\n",from->data.my_auto.car_mark);
                                        printf("%d\n",from->data.my_auto.car_year);
                                        printf("%d\n",from->data.my_auto.car_price);
                                        printf("%d\n",from->data.my_auto.car_engine);
                                        printf("\n");
                                        from = ClientMarkFind(from->next, temp);
                                    }
                                    break;
                                }
                                case 5:{
                                    struct client temp;
                                    printf("Введите год выпуска автомобиля\n");
                                    if(!scanf("%d",&(temp.my_auto.car_year))){
                                        printf("Вы ввели что-то не то\n");
                                        fflush(stdin);
                                        break;
                                    }
                                    struct ClientListItem* from = ClientYearFind(CLIENT.start, temp);
                                    if(from==NULL){
                                        printf("Покупателей не найдено\n");
                                    }
                                    while (from) {
                                        printf("%s\n",from->data.FIO);
                                        printf("%s\n",from->data.phone_number);
                                        printf("%s\n",from->data.my_auto.car_mark);
                                        printf("%d\n",from->data.my_auto.car_year);
                                        printf("%d\n",from->data.my_auto.car_price);
                                        printf("%d\n",from->data.my_auto.car_engine);
                                        printf("\n");
                                        from = ClientYearFind(from->next, temp);
                                    }
                                    break;
                                }
                                case 6:{
                                    struct client temp;
                                    printf("Введите цену автомобиля\n");
                                    if(!scanf("%d",&(temp.my_auto.car_price))){
                                        printf("Вы ввели что-то не то\n");
                                        fflush(stdin);
                                        break;
                                    }
                                    struct ClientListItem* from = ClientPriceFind(CLIENT.start, temp);
                                    if(from==NULL){
                                        printf("Покупателей не найдено\n");
                                    }
                                    while (from) {
                                        printf("%s\n",from->data.FIO);
                                        printf("%s\n",from->data.phone_number);
                                        printf("%s\n",from->data.my_auto.car_mark);
                                        printf("%d\n",from->data.my_auto.car_year);
                                        printf("%d\n",from->data.my_auto.car_price);
                                        printf("%d\n",from->data.my_auto.car_engine);
                                        printf("\n");
                                        from = ClientPriceFind(from->next, temp);
                                    }
                                    break;
                                }
                                case 7:{
                                    struct client temp;
                                    printf("Введите вместимость двигателя автомобиля\n");
                                    if(!scanf("%d",&(temp.my_auto.car_engine))){
                                    printf("Вы ввели что-то не то\n");
                                    fflush(stdin);
                                    break;
                                }
                                struct ClientListItem* from = ClientEngineCapacityFind(CLIENT.start, temp);
                                if(from==NULL){
                                    printf("Покупателей не найдено\n");
                                }
                                while (from) {
                                    printf("%s\n",from->data.FIO);
                                    printf("%s\n",from->data.phone_number);
                                    printf("%s\n",from->data.my_auto.car_mark);
                                    printf("%d\n",from->data.my_auto.car_year);
                                    printf("%d\n",from->data.my_auto.car_price);
                                    printf("%d\n",from->data.my_auto.car_engine);
                                    printf("\n");
                                    from = ClientEngineCapacityFind(from->next, temp);
                                }
                                break;
                                }
                                    case 0:action5 = 54;break;
                                }
                                }
                                break;
                            }
                        }
                        case 3:{
                        printf("Введите покупателя, с которым возможно будет совершена сделка\n");
                        struct client temp;
                        printf("Введите ФИО покупателя\n");
                        scanf("%s",temp.FIO);
                        printf("Введите контакт покупателя\n");
                        scanf("%s",temp.phone_number);
                        printf("Введите марку автомобиля, нужно для покупателя\n");
                        scanf("%s",temp.my_auto.car_mark);
                        printf("Введите год выпуска автомобиля, нужно для покупателя\n");
                        if(!scanf("%d",&(temp.my_auto.car_year))){
                        printf("Вы ввели что-то не то\n");
                        fflush(stdin);
                        break;
                        }
                        printf("Введите цену автомобиля, нужно для покупателя\n");
                        if(!scanf("%d",&(temp.my_auto.car_price))){
                        printf("Вы ввели что-то не то\n");
                        fflush(stdin);
                        break;
                        }
                        printf("Введите вместимость двигателя автомобиля, нужно для покупателя\n");
                        if(!scanf("%d",&(temp.my_auto.car_engine))){
                        printf("Вы ввели что-то не то\n");
                        fflush(stdin);
                        break;
                        }
                        struct ClientListItem* potential_client=ClientFind(CLIENT.start,temp);
                        if(potential_client!=NULL){
                        printf("Введите по какому полю подбирать наиболее подходящий покупателю автомобиль\n");
                        printf("Для подбора по марке введите 1\n");
                        printf("Для подбора по году выпуска введите 2\n");
                        printf("Для подбора по цене введите 3\n");
                        int action6;
                        if(!scanf("%d",&action6)){
                            printf("Вы ввели что-то не то\n");
                            fflush(stdin);
                        }
                            switch (action6) {
                                case 1:
                                {
                                    struct Car good_auto;
                                    strcpy(good_auto.car_mark,temp.my_auto.car_mark);
                                    struct Car_Item* from = AutoMarkFind(AUTO.start, good_auto);
                                    if(from!=NULL){
                                        printf("Найден подходящий автомобиль!\n");
                                        double addedprice=250;
                                        if(2020-from->data.car_year<=3){
                                            addedprice=0.6*from->data.car_engine;
                                        }
                                        else if(2020-from->data.car_year>3&&2020-from->data.car_year<=10){
                                            if(from->data.car_engine<2500){
                                                addedprice=0.35*from->data.car_engine;
                                            }
                                            else {
                                                addedprice=0.6*from->data.car_engine;
                                            }
                                        }
                                        else if(2020-from->data.car_year>10&&2020-from->data.car_year<=14){
                                            addedprice=0.6*from->data.car_engine;
                                        }
                                        else {
                                            addedprice=2*from->data.car_engine;
                                        }
                                        printf("Конечная стоимость автомобиля:%f\n",from->data.car_price*1.15+addedprice);
                                        int chance=rand()%2;
                                        if(chance!=0){
                                            printf("Сделка состоялась\n");
                                            struct deal purchase;
                                            purchase.selled_auto.car_price = from->data.car_price;
                                            purchase.selled_auto.car_year = from->data.car_year;
                                            purchase.selled_auto.car_engine = from->data.car_engine;
                                            strcpy(purchase.selled_auto.car_mark,from->data.car_mark);

                                            purchase.buyer.my_auto.car_price = temp.my_auto.car_price;
                                            purchase.buyer.my_auto.car_year = temp.my_auto.car_year;
                                            purchase.buyer.my_auto.car_engine = temp.my_auto.car_engine;
                                            strcpy(purchase.buyer.FIO , temp.FIO);
                                            strcpy(purchase.buyer.phone_number , temp.phone_number);
                                            strcpy(purchase.buyer.my_auto.car_mark , temp.my_auto.car_mark);
                                            purchase.profit=(int)(from->data.car_price*015);
                                            DealAdd(&DEAL,purchase);
                                            AutoDeleteItem(&AUTO,from->data);
                                            ClientDeleteItem(&CLIENT,temp);
                                            break;
                                        }
                                        else {printf("К сожалению, сделка с покупателем не состоялась\n");break;}
                                    }
                                    else {printf("Подходящий автомобиль не найден\n");break;}
                                }break;
                                case 2:{
                                    struct Car_Item* t=AUTO.start;
                                    struct Car_Item*from=AUTO.start;
                                    int min=abs(from->data.car_year-temp.my_auto.car_year);
                                    while(t){
                                        if(abs(t->data.car_year-temp.my_auto.car_year)<min){
                                            min=abs(t->data.car_year-temp.my_auto.car_year);
                                            from=t;
                                        }
                                        t=t->next;
                                    }
                                    printf("Найден подходящий автомобиль!\n");
                                    double addedprice=250;
                                    if(2020-from->data.car_year<=3){addedprice=0.6*from->data.car_engine;}
                                    else if(2020-from->data.car_year>3&&2020-from->data.car_year<=10){
                                        if(from->data.car_engine<2500){addedprice=0.35*from->data.car_engine;}
                                        else {addedprice=0.6*from->data.car_engine;}
                                    }
                                    else if(2020-from->data.car_year>10&&2020-from->data.car_year<=14){addedprice=0.6*from->data.car_engine;}
                                    else {addedprice=2*from->data.car_engine;}

                                    printf("Конечная стоиомть автомобиля:%f\n",from->data.car_price*1.15+addedprice);
                                    int chance=rand()%2;
                                    if(chance!=0){
                                        printf("Сделка состоялась\n");
                                        struct deal purchase;
                                        purchase.selled_auto.car_price = from->data.car_price;
                                        purchase.selled_auto.car_year = from->data.car_year;
                                        purchase.selled_auto.car_engine = from->data.car_engine;
                                        strcpy(purchase.selled_auto.car_mark,from->data.car_mark);

                                        purchase.buyer.my_auto.car_price = temp.my_auto.car_price;
                                        purchase.buyer.my_auto.car_year = temp.my_auto.car_year;
                                        purchase.buyer.my_auto.car_engine = temp.my_auto.car_engine;
                                        strcpy(purchase.buyer.FIO , temp.FIO);
                                        strcpy(purchase.buyer.phone_number , temp.phone_number);
                                        strcpy(purchase.buyer.my_auto.car_mark , temp.my_auto.car_mark);
                                        purchase.profit=(int)(from->data.car_price*015);
                                        DealAdd(&DEAL,purchase);
                                        AutoDeleteItem(&AUTO,from->data);
                                        ClientDeleteItem(&CLIENT,temp);
                                    }
                                    else {printf("Сделка no состоялась");}
                                }break;
                                case 3:{
                                    struct Car_Item* t=AUTO.start;
                                    struct Car_Item*from=AUTO.start;
                                    double addedprice=250;
                                    if(2020-from->data.car_year<=3){
                                        addedprice=0.6*from->data.car_engine;
                                    }
                                    else if(2020-from->data.car_year>3&&2020-from->data.car_year<=10){
                                        if(from->data.car_engine<2500){
                                            addedprice=0.35*from->data.car_engine;
                                        }
                                        else {
                                           addedprice=0.6*from->data.car_engine;
                                        }
                                    }
                                    else if(2020-from->data.car_year>10&&2020-from->data.car_year<=14){
                                        addedprice=0.6*from->data.car_engine;
                                    }
                                    else {
                                        addedprice=2*from->data.car_engine;
                                    }
                                    int min=(int)(0.85*from->data.car_price+addedprice-temp.my_auto.car_price);
                                    while(t){
                                        double addedpricet=250;
                                        if(2020-t->data.car_year<=3){
                                            addedpricet=0.6*t->data.car_engine;
                                        }
                                        else if(2020-t->data.car_year>3&&2020-t->data.
                                                car_year<=10){
                                            if(t->data.car_engine<2500){
                                                addedpricet=0.35*t->data.car_engine;
                                            }
                                            else {
                                                addedpricet=0.6*t->data.car_engine;
                                            }
                                        }
                                        else if(2020-t->data.car_year>10&&2020-t->data.car_year<=14){
                                            addedpricet=0.6*t->data.car_engine;
                                        }
                                        else {
                                            addedpricet=2*t->data.car_engine;
                                        }
                                        if((int)(0.85*t->data.car_price+addedpricet-temp.my_auto.car_price)<min){
                                            min= 0.85*t->data.car_price+addedpricet-temp.my_auto.car_price;
                                            from=t;
                                        }
                                        t=t->next;
                                        addedprice=addedpricet;
                                    }
                                    printf("Найден подходящий автомобиль!\n");
                                    printf("Конечная стоиомть автомобиля:%d\n",(int)(from->data.car_price+addedprice));
                                    int chance=rand()%2;
                                    if(chance!=0){
                                        printf("sdelka\n");
                                        struct deal purchase;
                                        purchase.selled_auto.car_price = from->data.car_price;
                                        purchase.selled_auto.car_year = from->data.
                                        car_year;
                                        purchase.selled_auto.car_engine = from->data.car_engine;
                                        strcpy(purchase.selled_auto.car_mark,from->data.car_mark);

                                        purchase.buyer.my_auto.car_price = temp.my_auto.car_price;
                                        purchase.buyer.my_auto.car_year = temp.my_auto.car_year;
                                        purchase.buyer.my_auto.car_engine = temp.my_auto.car_engine;
                                        strcpy(purchase.buyer.FIO , temp.FIO);
                                        strcpy(purchase.buyer.phone_number , temp.phone_number);
                                        strcpy(purchase.buyer.my_auto.car_mark , temp.my_auto.car_mark);
                                        purchase.profit=(int)(from->data.car_price*015);
                                        DealAdd(&DEAL,purchase);
                                        AutoDeleteItem(&AUTO,from->data);
                                        ClientDeleteItem(&CLIENT,temp);
                                        break;
                                    }
                                    else {printf("no sdelka\n");}
                                }break;
                                default:break;
                            }
                        }
                    }
                        break;
                    }
                }
            break;
            case 0:{
                FILE* inclient  = fopen("clients.txt", "w");
                FILE* inauto  = fopen("automobiles.txt", "w");
                FILE* indeal = fopen("deals.txt", "a");
                struct DealListItem* dealli=DEAL.start;
                while(dealli){
                    fprintf(indeal,"%s\n",dealli->data.selled_auto.car_mark);
                    fprintf(indeal,"%d\n",dealli->data.selled_auto.car_year);
                    fprintf(indeal,"%d\n",dealli->data.selled_auto.car_price);
                    fprintf(indeal,"%d\n",dealli->data.selled_auto.car_engine);
                    fprintf(indeal,"\n");
                    fprintf(indeal,"%s\n",dealli->data.buyer.FIO);
                    fprintf(indeal,"%s\n",dealli->data.buyer.phone_number);
                    fprintf(indeal,"%s\n",dealli->data.buyer.my_auto.car_mark);
                    fprintf(indeal,"%d\n",dealli->data.buyer.my_auto.car_year);
                    fprintf(indeal,"%d\n",dealli->data.buyer.my_auto.car_price);
                    fprintf(indeal,"%d\n",dealli->data.buyer.my_auto.car_engine);
                    fprintf(indeal,"\n");
                    fprintf(indeal,"Стоимость авто: %d\n",dealli->data.profit);
                    fprintf(indeal,"\n");
                    dealli=dealli->next;
                }
                struct ClientListItem* clientli=CLIENT.start;
                while(clientli){
                    fprintf(inclient,"%s\n",clientli->data.FIO);
                    fprintf(inclient,"%s\n",clientli->data.phone_number);
                    fprintf(inclient,"%s\n",clientli->data.my_auto.car_mark);
                    fprintf(inclient,"%d\n",clientli->data.my_auto.car_year);
                    fprintf(inclient,"%d\n",clientli->data.my_auto.car_price);
                    fprintf(inclient,"%d",clientli->data.my_auto.car_engine);
                    if(clientli->next!=NULL){
                        fprintf(inclient,"\n\n");
                    }
                    clientli=clientli->next;
                }
                struct Car_Item* autoli=AUTO.start;
                while(autoli){
                    fprintf(inauto,"%s\n",autoli->data.car_mark);
                    fprintf(inauto,"%d\n",autoli->data.car_year);
                    fprintf(inauto,"%d\n",autoli->data.car_price);
                    fprintf(inauto,"%d",autoli->data.car_engine);
                    if(autoli->next!=NULL){
                        fprintf(inauto,"\n\n");
                    }
                    autoli=autoli->next;
                }
                DealClear(&DEAL);
                ClientClear(&CLIENT);
                AutoClear(&AUTO);
                return 0;
            }
        }
    }
    return 0;
}
