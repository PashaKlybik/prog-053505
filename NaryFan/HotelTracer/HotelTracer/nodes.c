#define _CRT_SECURE_NO_WARNINGS

#include "nodes.h"
#include "common_interface.h"

extern char path[BUFSIZ];

void push(struct List* curr_list, char h_name[30], char ct[20], char adr[50],
	unsigned short plcs, enum RoomClass tp, unsigned long cst)
{	
	struct Node* dd = (struct Node*)malloc(sizeof(struct Node));
	dd->inf = (struct Info*)malloc(sizeof(struct Info));
	if (dd == NULL)
	{
		puts("No more memory, terminating...");
		_getch();
		exit(-1);
	}
	dd->next = NULL;
	strcpy(dd->inf->hotel_name, h_name);
	strcpy(dd->inf->Address, adr);
	strcpy(dd->inf->city, ct);
	dd->inf->places = plcs;
	dd->inf->type = tp;
	dd->inf->cost = cst;
	if (curr_list->numof_nodes == 0)
	{
		dd->prev = NULL;
		curr_list->head = dd;
	}
	else
	{
		dd->prev = curr_list->tail;
		curr_list->tail->next = dd;
	}
	curr_list->tail = dd;
	curr_list->numof_nodes++;
}

void push_nd(struct List* curr_list, struct Node* nd)
{
	nd->next = NULL;
	if (curr_list->numof_nodes == 0)
	{
		nd->prev = NULL;
		curr_list->head = curr_list->tail = nd;
	}
	else
	{
		nd->prev = curr_list->tail;
		curr_list->tail->next = nd;
	}
	curr_list->tail = nd;
	curr_list->numof_nodes++;
}

void del(struct List* curr_list, struct Node* del_node)
{
	if (curr_list->tail == del_node)
		curr_list->tail = del_node->prev;

	if (curr_list->head == del_node)
		curr_list->head = del_node->next;

	if (del_node->prev)
		del_node->prev->next = del_node->next;

	if (del_node->next)
		del_node->next->prev = del_node->prev;

	free(del_node->inf);
	free(del_node);
	curr_list->numof_nodes--;
}

void pop(struct List* curr_list)
{
	struct Node* temp = curr_list->tail;
	curr_list->tail = temp->prev;
	free(temp->inf);
	free(temp);
}

void clear(struct List* curr_list)
{	
	if (!curr_list)
		return;

	for (unsigned int i = 0; i < curr_list->numof_nodes; i++)
		pop(curr_list);

	curr_list->head = curr_list->tail = NULL;
	curr_list->numof_nodes = 0;
}

struct Node* find(struct List* curr_list, char h_name[20], int tp)
{	
	if (!curr_list)
		return NULL;

	struct Node* temp = curr_list->head;
	while (temp)
	{
		if (!strcmp(temp->inf->hotel_name, h_name) && (enum RoomType)temp->inf->type == tp)
			return temp;

		temp = temp->next;
	}
	return NULL;
}

void rewind_file(int i, char* mode, struct Node* addable)
{
	char fullpath[BUFSIZ];
	strcpy(fullpath, path);
	strcat(fullpath, web_names[i]);
	strcat(fullpath, ".bin");

	FILE* fw = fopen(fullpath, mode);
	if (!strcmp(mode, "wb"))
	{
		struct Node* current = webs[i]->head;
		while(current)
		{
			fwrite(current->inf, sizeof(struct Info), 1, fw);
			current = current->next;
		}
	}
	else
	{
		fwrite(addable->inf, sizeof(struct Info), 1, fw);
	}
	file_flags[i] = 1;
	fclose(fw);
}