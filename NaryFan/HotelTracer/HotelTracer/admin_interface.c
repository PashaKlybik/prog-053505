#include "admin_interface.h"
#include "common_interface.h"
#include <pthread.h>

extern pthread_mutex_t mut;

//for editing specific website's lists, not all of them (security concern)
static int company_index;

void web_check(void)
{
	clrscr();
	short tries = 3;
	puts("Enter your website's name");
	char company_name[MAX_WEBNAME_LENGTH];
	while (1)
	{
		gets(company_name);
		for (int i = 1; i < NUM_OF_WEBS; i++)
		{
			if (!strcmp(company_name, web_names[i]))
			{
				company_index = i;
				return;
			}
		}
		printf("\nWrong website! %d attempts remaining!\n", --tries);
		fflush(stdin);
		if (tries == 0)
		{
			puts("No more attempts! Admin mode is blocked!");
			free_mem();
			Sleep(2000);
			exit(0);
		}
	}
}

void push_wrapper(void)
{
	puts("Print hotel name:");
	char h_name[30];
	gets(h_name);
	puts("Print city:");
	char ct[20];
	gets(ct);
	puts("Print Address:");
	char adr[50];
	gets(adr);
	puts("Print number of beds (2 by default):");
	unsigned int pl = 2;
	get_unsigned(&pl);
	puts("Choose room type:");
	puts("1. Economy\n2. Semilux\n3. Lux\n4. VIP");
	char rt = _getch();
	while ((rt < '1' || rt > '4') && rt != esc)
	{
		rt = _getch();
	}
	if (rt == esc)
		return;
	puts("Print cost (0 by default):");
	unsigned int cst = 0;
	get_unsigned(&cst);
	struct Node* nnd = (struct Node*)malloc(sizeof(struct Node));
	nnd->inf = (struct Info*)malloc(sizeof(struct Info));
	strcpy(nnd->inf->Address, adr);
	strcpy(nnd->inf->city, ct);
	strcpy(nnd->inf->hotel_name, h_name);
	nnd->inf->cost = cst;
	nnd->inf->places = pl;
	nnd->inf->type = rt;
	rewind_file(company_index, "a+b", nnd);
	free(nnd->inf);
	free(nnd);
}

void add_pos(void)
{
	header("Admin_Menu->Adding", "ESC -- return to previous menu (while choosing room type)");
	pthread_mutex_lock(&mut);
	push_wrapper();
	pthread_mutex_unlock(&mut);
	puts("Done! Returning to menu...");
	Sleep(2000);
}

void del_pos(void)
{
	header("Admin_Menu->Deleting", "ESC -- return to previous menu (while choosing room type)");
	puts("Print hotel name:");
	char h_name[30];
	gets(h_name);
	puts("Choose room type:");
	puts("1. Economy\n2. Semilux\n3. Lux\n4. VIP");
	char rt = _getch();
	while ((rt < '1' || rt > '4') && rt != esc)
	{
		rt = _getch();
	}
	if (rt == esc)
		return;
	pthread_mutex_lock(&mut);
	struct Node* nd_del = find(webs[company_index], h_name, (int)rt - 48);
	if (!nd_del)
	{
		puts("Such position doesn't exist! Returning to menu...");		
	}
	else
	{
		del(webs[company_index], nd_del);
		rewind_file(company_index, "wb", NULL);
		puts("Done! Returning to menu...");
	}
	pthread_mutex_unlock(&mut);
	Sleep(2000);
}

void del_all(void)
{
	header("Admin_Menu->Clearing", "1-2 -- make choice");
	puts("Are you sure you'd like to clear the full list?\n1. Yes\n2. No");
	char ch = '0';
	while (ch != '1' && ch != '2')
	{
		ch = _getch();
	}
	switch(ch)
	{
	case '1':
		pthread_mutex_lock(&mut);
		clear(webs[company_index]);
		rewind_file(company_index, "wb", NULL);
		pthread_mutex_unlock(&mut);
		puts("Done! Returning to menu...");
		break;
	case '2':
		puts("OK, returning to menu...");
		break;
	}
	Sleep(2000);
	return;
}

void watch_web(void)
{
	header("Admin_Menu->Viewering", "ESC -- return to previous menu");
	pthread_mutex_lock(&mut);
	if (!webs[company_index]->numof_nodes)
		puts("There aren't any positions on your website DB. Please, use the first function to add some");
	else
	{
		struct Node* curr = webs[company_index]->head;
		printf("                                         ");
		printf("== Hotels at www.%s.com ==\n", web_names[company_index]);
		while (curr)
		{
			printf("Name: %s\nCity: %s\nAdress: %s\nNum of places: %u\nRoom class: %u\nCost: %u\n\n",
				curr->inf->hotel_name, curr->inf->city, curr->inf->Address, curr->inf->places,
				curr->inf->type, curr->inf->cost);

			curr = curr->next;
		}	
	}
	pthread_mutex_unlock(&mut);
	while (1)
	{
		if (_getch() == esc)
			return;
	}
}

void edit_pos(void)
{
	header("Admin_Menu->Editing", "ESC -- return to previous menu (while choosing room type)");
	puts("Print old hotel name:");
	char h_name[30];
	gets(h_name);
	puts("Choose room type of old position:");
	puts("1. Economy\n2. Semilux\n3. Lux\n4. VIP");
	char rt = _getch();
	while ((rt < '1' || rt > '4') && rt != esc)
	{
		rt = _getch();
	}
	if (rt == esc)
		return;
	pthread_mutex_lock(&mut);
	struct Node* editable = find(webs[company_index], h_name, (int)rt - 48);
	if (!editable)
	{
		puts("Such position doesn't exist! Returning to menu...");
	}
	else
	{
		del(webs[company_index], editable);
		rewind_file(company_index, "wb", NULL);
		puts("Enter new data:");
		push_wrapper();		
		puts("Successfully edited! Returning to menu...");
	}
	pthread_mutex_unlock(&mut);
	Sleep(2000);
}

void admin_menu(void)
{
	web_check();
	while (1)
	{
		clrscr();
		header("Admin_Menu", "ESC -- exit the porgramm\n1-5 -- choose the option");
		puts("1. Add new hotel\n2. Delete single hotel\n3. Delete all hotels");
		puts("4. Watch full list of your website's hotels\n5. Edit a hotel\n6. Watch program info");
		char choice = _getch();
		switch (choice)
		{
		case '1':
			add_pos();
			break;
		case '2':
			del_pos();
			break;
		case '3':
			del_all();
			break;
		case '4':
			watch_web();
			break;
		case '5':
			edit_pos();
			break;
		case '6':
			program_info();
			break;
		case esc:
			return;
		}
	}
}