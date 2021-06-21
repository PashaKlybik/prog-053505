#pragma once

enum RoomClass {
	economy = 1,
	semilux,
	lux,
	vip,
};

struct Node
{
	struct Node* next;
	struct Node* prev;
	struct Info* inf;
};

struct Info
{
	char hotel_name[30];
	char city[20];
	char Address[50];
	unsigned short places;
	enum RoomClass type;
	unsigned long cost;
};

struct List
{
	unsigned int numof_nodes;
	struct Node* head;
	struct Node* tail;
};

void push(struct List* curr_list, char h_name[30], char ct[20], char adr[50],
	unsigned short plcs, enum RoomClass tp, unsigned long cst);
void pop(struct List* curr_list);
void push_nd(struct List* curr_list, struct Node* nd);
void del(struct List* curr_list, struct Node* del_node);
void clear(struct List* curr_list);
struct Node* find(struct List* curr_list, char h_name[20], int tp);
void rewind_file(int i, char* mode, struct Node* addable);