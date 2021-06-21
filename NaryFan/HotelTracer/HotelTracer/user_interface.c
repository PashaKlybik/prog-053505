#include "user_interface.h"
#include "common_interface.h"
#include <pthread.h>

extern pthread_mutex_t mut;

void booking_hotel(int k, struct Node* found_hotel)
{
	puts("Would you like to book this room?");
	puts("1. Yes\n2. No");
	char ch = '0';
	while (ch != '1' && ch != '2' && ch != esc)
	{
		ch = _getch();
	}
	if (ch == esc || ch == '2')
		return;
	if (ch == '1')
	{
		rewind_file(0, "a+b", found_hotel);
		del(webs[k], found_hotel);
		rewind_file(k, "wb", NULL);
		puts("Successfully booked! Returning to menu...");
		Sleep(2000);
	}
}

void search_hotel(void)
{
	header("Menu->Searching", "ESC -- return to previous menu (while choosing room type)\nENTER -- skip field");
	puts("Print preferable hotel name (if known): ");
	char h_name[30];
	gets(h_name);
	puts("Print preferable city: ");
	char ct[20];
	gets(ct);
	puts("Print preferable number of beds (2 by default):");
	unsigned int pl = 2;
	get_unsigned(&pl);
	puts("Choose preferable room type:");
	puts("1. Economy\n2. Semilux\n3. Lux\n4. VIP");
	char rt = _getch();
	while ((rt < '1' || rt > '4') && rt != esc)
	{
		rt = _getch();
	}
	if (rt == esc)
	{
		return;
	}
	puts("Print minimum cost (0 by default):");
	unsigned int min_cst = 0;
	get_unsigned(&min_cst);
	puts("Print maximum cost (no limit by default):");
	unsigned int max_cst = INT_MAX;
	get_unsigned(&max_cst);
	//35 for hotel, 65 for city, +-10 for beds, 20 for room type, +-20 for price
	short max_point = 30;
	struct Node* best_fit = NULL;
	int best_fit_pos = 0;
	pthread_mutex_lock(&mut);
	for (int i = 1; i < NUM_OF_WEBS; i++)
	{
		if (!webs[i]->numof_nodes)
		{
			continue;
		}
		struct Node* current = webs[i]->head;
		while (current)
		{
			short current_point = 1;
			if (!strcmp(current->inf->hotel_name, h_name))
				current_point += 35;
			if (!strcmp(current->inf->city, ct))
				current_point += 65;
			if (current->inf->places == pl)
				current_point += 10;
			else
				current_point -= 10;
			if (current->inf->type == rt)
				current_point += 20;
			if (current->inf->cost >= min_cst && current->inf->cost <= max_cst)
				current_point += 20;
			else
				current_point -= 20;
			if (current_point > max_point)
			{
				best_fit = current;
				best_fit_pos = i;
				max_point = current_point;
			}
			current = current->next;
		}
	}
	if (!best_fit)
	{
		pthread_mutex_unlock(&mut);
		puts("\nUnfortunately, we haven't found appropriate hotel. Either they are booked or not available at the moment.");
		puts("Press any button to get back...");
		_getch();
		return;
	}
	puts("\nHere's the best match we found:");
	printf("Name: %s\nCity: %s\nAdress: %s\nNum of places: %u\nRoom class: %u\nCost: %u$\n\n", best_fit->inf->hotel_name,
		best_fit->inf->city, best_fit->inf->Address, best_fit->inf->places, best_fit->inf->type, best_fit->inf->cost);
	booking_hotel(best_fit_pos, best_fit);
	pthread_mutex_unlock(&mut);
}

void booked(void)
{
	header("Menu->Booked", "0 + ENTER -- return to previous menu");
	pthread_mutex_lock(&mut);
	struct Node* current = webs[0]->head;
	int i = 1;
	while (current)
	{
		printf("%d) Name: %s\nCity: %s\nAdress: %s\nNum of places: %u\nRoom class: %u\nCost: %u$\n\n", i,
			current->inf->hotel_name, current->inf->city, current->inf->Address, 
			current->inf->places, current->inf->type, current->inf->cost);
		current = current->next;
		i++;
	}
	if (!webs[0]->numof_nodes)
	{
		pthread_mutex_unlock(&mut);
		puts("No room booked yet. Returning to menu...");
		Sleep(2000);
		return;
	}
	puts("Which hotel would you like to unbook (print number from the list)?");
	unsigned int ubook;
	while (1)
	{
		get_unsigned(&ubook);
		if (ubook == 0)
		{
			pthread_mutex_unlock(&mut);
			return;
		}
		if (ubook <= webs[0]->numof_nodes)
		{
			break;
		}
		puts("Wrong input, please, re-enter");
		continue;
	}
	current = webs[0]->head;
	for (unsigned int i = 1; i < ubook; i++)
	{
		current = current->next;
	}
	int k = rand() % NUM_OF_WEBS + 1;
	rewind_file(k, "a+b", current);
	del(webs[0], current);
	rewind_file(0, "wb", NULL);
	pthread_mutex_unlock(&mut);
	puts("Unbooked successfully! Returning to menu...");
	Sleep(2000);
}

void watch_list(void)
{	
	header("Menu->Full_List", "ESC -- return to previous menu");
	pthread_mutex_lock(&mut);
	for (int i = 1; i < NUM_OF_WEBS; i++)
	{
		if (!webs[i]->numof_nodes)
			continue;
		struct Node* curr = webs[i]->head;
		printf("                                         ");
		printf("== Hotels at www.%s.com ==\n", web_names[i]);
		while (curr)
		{
			printf("Name: %s\nCity: %s\nAdress: %s\nNum of places: %u\nRoom class: %u\nCost: %u$\n\n",
				curr->inf->hotel_name, curr->inf->city, curr->inf->Address, 
				curr->inf->places, curr->inf->type, curr->inf->cost);

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

void watch_hotel(void)
{
	header("Menu->Watch_Hotel", "ESC -- return to previous menu (after entering hotel name)");
	puts("Print the name of the hotel:");
	char h_name[30];
	gets_s(h_name, 30);
	puts("Choose a room type:");
	puts("1. Economy\n2. Semilux\n3. Lux\n4. VIP");
	char ch = _getch();
	while (ch < '1' || ch > '4' && ch != esc)
	{
		ch = _getch();
	}
	if (ch == esc)
		return;
	pthread_mutex_lock(&mut);
	struct Node* found_hotel;
	for (int i = 1; i < NUM_OF_WEBS; i++)
	{
		if (!webs[i]->numof_nodes)
			continue;

		if (found_hotel = find(webs[i], h_name, (int)ch - 48))
		{
			printf("== Hotel found at www.%s.com ==\n", web_names[i]);
			printf("Name: %s\nCity: %s\nAdress: %s\nNum of places: %u\nRoom class: %u\nCost: %u$\n\n", h_name,
				found_hotel->inf->city, found_hotel->inf->Address, found_hotel->inf->places,
				found_hotel->inf->type, found_hotel->inf->cost);
			booking_hotel(i, found_hotel);
			pthread_mutex_unlock(&mut);
			return;
		}
	}
	pthread_mutex_unlock(&mut);
	puts("No match found. Returning to previous menu...");
	Sleep(2000);
}

void menu(void)
{
	while (1)
	{
		clrscr();
		header("Menu", "ESC -- exit the porgramm\n1-5 -- choose the option");
		puts("1. Find a hotel by your preferences\n2. Find specific hotel by name\n3. Watch booked rooms");
		puts("4. Watch full list of hotels\n5. Watch program info");
		char choice = _getch();
		while ((choice < '1' || choice > '5') && choice != esc)
			choice = _getch();
		switch (choice)
		{
		case '1':
			search_hotel();
			break;
		case '2':
			watch_hotel();
			break;
		case '3':
			booked();
			break;
		case '4':
			watch_list();
			break;
		case '5':
			program_info();
			break;
		case esc:
			return;
		}
	}
}