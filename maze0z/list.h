#ifndef DIVISION__LIST_H_
#define DIVISION__LIST_H_

#include <stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
};
struct node *node(int data, struct node *next, struct node *prev);

struct list{
    struct node *head;
    struct node *tail;
    // list is looped, we don't need tail because it is always before head :)
    int size;
};
struct list *list();
void push_back(struct list *l, int value);
void pop_back(struct list *l);
void push_front(struct list *l, int value);
void pop_front(struct list *l);
void free_list(struct list *l);

#endif //DIVISION__LIST_H_