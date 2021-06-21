#include "user_interface.h"
#include "common_interface.h"
#include "admin_interface.h"
#include <pthread.h>

#define THREAD_ERR 1
#define MEMORY_ERR 2
#define USER 1
#define ADMIN 2

//first in list of names, flags and webs always goes DB of booked hotels
struct List* webs[NUM_OF_WEBS];
const char web_names[][MAX_WEBNAME_LENGTH] = { "booked", "TravelWeb", "opodo", "hotels", "orbitz", "AllHotels", "TravelWorm", "HotelQuest" };
short file_flags[NUM_OF_WEBS];
pthread_mutex_t mut;
char path[BUFSIZ];

void error_term(int type)
{
	clrscr();
	switch (type)
	{
	case 1:
		puts("Thread error! Terminating programm...");
		break;
	case 2:
		puts("Not enough memory! Terminating programm...");
		break;
	}
	free_mem();
	Sleep(2000);
	exit(-1);
}

int file_check(FILE** files, int i, char* pt)
{	
	strcpy(pt, path);
	strcat(pt, web_names[i]);
	strcat(pt, ".bin");
	files[i] = fopen(pt, "rb");
	if (files[i] == NULL)
		return 0;
	return 1;
}

void* update_db(void* args)
{
	FILE* files[NUM_OF_WEBS];
	char fullpath[BUFSIZ];
	for (int i = 0; i < NUM_OF_WEBS; i++)
	{
		if (!file_check(files, i, fullpath))
			printf("Warning! DataBase %s.bin is removed. Ask your sysadmin to restore it.\n", web_names[i]);
	}
	while (1)
	{
		pthread_mutex_lock(&mut);
		for (int i = 0; i < NUM_OF_WEBS; i++)
		{
			file_check(files, i, fullpath);
			if (files[i] != NULL && file_flags[i] == 1)
			{
				clear(webs[i]); 
				while (!feof(files[i]))
				{
					struct Node* current = (struct Node*)malloc(sizeof(struct Node));
					current->inf = (struct Info*)malloc(sizeof(struct Info));
					if (!current || !current->inf)
						error_term(MEMORY_ERR);
					if(fread(current->inf, sizeof(struct Info), 1, files[i]) == 1)
						push_nd(webs[i], current);
				}
				file_flags[i] = 0;
				fclose(files[i]);
			}
		}
		pthread_mutex_unlock(&mut);
		Sleep(60000);
	}
}

void boot_menu(int md)
{	
	pthread_t dwnldr;
	GetCurrentDirectory(BUFSIZ, path);	
	strcat(path, FOLDER_NAME);
	for (int i = 0; i < NUM_OF_WEBS; i++)
	{
		file_flags[i] = 1;
		webs[i] = (struct List*)malloc(sizeof(struct List));
		webs[i]->head = webs[i]->tail = NULL;
		webs[i]->numof_nodes = 0;
	}
	clrscr();
	puts("Hi and welcome to HotelTracer!");
	puts("Please, wait untill databases are updating...");
	puts(delimetr);
	puts("HotelTracer V 1.2.\nSimple tool created to help travelers and hotel company's promoters");
	puts("To share feedback or get the source code, visit https://github.com/AVPa1ly/");
	puts("Contact mail: andrewvorobiov@gmail.com");
	puts("--\nCopyright C 2020 by AVPa1ly. All rights reserved.");
	puts(delimetr);
	//they return 0 ON SUCCESS
	if (pthread_mutex_init(&mut, NULL))
		error_term(THREAD_ERR);
	if (pthread_create(&dwnldr, NULL, update_db, NULL))
		error_term(THREAD_ERR);
	pthread_detach(dwnldr);
	Sleep(3000);
	srand(time(0));
	if (md == USER)
	{
		menu();
	}
	else
	{
		admin_menu();
	}
	pthread_mutex_destroy(&mut);
	pthread_cancel(dwnldr);
	return;
}

void boot_admin(void)
{
	clrscr();
	short tries = 3;
	char pass[9];
	puts("Enter password:");
	gets(pass);
	while (strcmp(pass, PASSWORD) && tries)
	{
		printf("\nWrong password! %d attempts remaining!\n", --tries);
		fflush(stdin);
		if (tries == 0)
		{
			puts("No more attempts! Admin mode is blocked!");
			free_mem();
			Sleep(2000);
			exit(0);
		}
		puts("Re-enter password:");
		gets(pass);
	}
	boot_menu(ADMIN);
}

int main(void)
{
	puts("Choose a boot mode:");
	puts("1. User\n2. Admin\n0. Exit");
	char ch = ' ';
	while (ch != '1' && ch != '2' && ch != '0')
	{
		ch = _getch();
	}
	switch (ch)
	{
	case '0':
		exit(0);
		break;
	case '1':
		boot_menu(USER);
		break;
	case '2':
		boot_admin();
		break;
	}
	free_mem();
}