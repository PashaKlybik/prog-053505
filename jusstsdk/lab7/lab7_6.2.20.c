#define MAX 40
#include <cstdio>
#include <cstring>
#include <malloc.h>
#include <cstdlib>

struct Book
{
    char* author;
    char* title;
    char* note;
    int price;
};

struct DealDate
{
    int year;
    int month;
    int day;
};

struct Deal
{
    Book* book;
    DealDate* dealDate;
};

struct NodeBook
{
    NodeBook* next;

    Book* book;
    int quantity;
};

struct ListBook
{
    NodeBook* head;

    int size;
};

struct NodeDeal
{
    NodeDeal* next;

    Deal* deal;
};

struct ListDeal
{
    NodeDeal* head;

    int size;
};

struct Reader
{
    char* surname;
    char* name;
    int group;
    char* telephoneNumber;
    char* email;
    char* note;
    ListDeal* dealList;
    int penalty;
};

struct NodeReader
{
    NodeReader* next;

    Reader* reader;
};

struct ListReader
{
    NodeReader* head;

    int size;
};

struct CathLibrary
{
    ListBook* bookList;
    ListReader* readerList;
};

Book* CreateBook(char* author, char* title, int price, char* note);
int getline(char line[], int maxline);
Deal* CreateDeal(Book* book, DealDate* dealDate);
DealDate* CreateDealDate(int year, int month, int day);
void PrintMenu(int key);
void InitFromFile(CathLibrary* cathLibrary);
void ShowReaderInfo(Reader* reader);
void ShowReaders(ListReader* listReader);
void ShowBookInfo(NodeBook* node);
void ShowBooks(ListBook* bookList);
void ShowReaderBooks(ListDeal* dealList);
void BorrowBook(char* surname, int group, char* title, CathLibrary* lib, DealDate* dealDate);
void ReturnBook(char* surname, int group, char* title, CathLibrary* lib);
bool ReaderExists(char* surname, int group, ListReader* listReader);
bool BookExists(char* title, ListBook* listBook);
void LibReport(CathLibrary* lib);
void DeleteLibrary(CathLibrary* lib);
CathLibrary* CreateCathLibrary();
ListBook* CreateListBook();
void AddBook(ListBook* listBook, Book* book, int quantity);
Book* FindBook(ListBook* listBook, char* title);
void RemoveBook(Book* book, ListBook* listBook);
void AddDeal(ListDeal* dealList, Deal* deal);
Deal* FindDeal(ListDeal* listDeal, char* title);
void RemoveDeal(Deal* deal, ListDeal* listDeal);
void AddNewReader(ListReader* listReader);
ListReader* CreateListReader();
void AddReader(ListReader* listReader, Reader* reader);
Reader* FindReader(ListReader* listReader, char* surname, int group);
Reader* CreateReader(char* surname, char* name, int group, char* number, char* email, char* note);

int main()
{
    CathLibrary *cathLibrary = CreateCathLibrary();

    InitFromFile(cathLibrary);

    while (true)
    {
        PrintMenu(0);

        int choice = 0;
        int choice1 = 0;
        char surname[MAX];
        char title[MAX];
        int group = 0;
        int year;
        int month;
        int day;

        scanf_s("%d", &choice);

        switch (choice)
        {
            case 1:
                PrintMenu(1);

                scanf_s("%d", &choice1);

                if (choice1 == 1)
                {

                    while (getchar() != '\n');

                    printf("Enter surname of reader ");
                    getline(surname, MAX);

                    printf("Enter group ", surname);
                    scanf_s("%d", &group);

                    if (ReaderExists(surname, group, cathLibrary->readerList))
                        ShowReaderInfo(FindReader(cathLibrary->readerList, surname, group));
                    else
                        printf("This reader is not registered in library\n\n");
                }

                else if (choice1 == 2)
                {
                    ShowReaders(cathLibrary->readerList);
                }

                while (getchar() != '\n');

                printf("Press enter to continue...");
                getchar();

                break;

            case 2:
                ShowBooks(cathLibrary->bookList);

                while (getchar() != '\n');

                printf("Press enter to continue...");
                getchar();

                break;

            case 3:
                while (getchar() != '\n');

                printf("Enter surname of reader ");
                getline(surname, MAX);

                printf("Enter group ", surname);
                scanf_s("%d", &group);

                while (getchar() != '\n');

                if (ReaderExists(surname, group, cathLibrary->readerList))
                {
                    if (FindReader(cathLibrary->readerList, surname, group)->penalty < 2)
                    {
                        printf("Enter title of book you want to borrow ");
                        getline(title, MAX);

                        if (BookExists(title, cathLibrary->bookList))
                        {
                            printf("Enter year of returning the book ");
                            scanf_s("%d", &year);
                            printf("Enter month of returning the book ");
                            scanf_s("%d", &month);
                            printf("Enter day of returning the book ");
                            scanf_s("%d", &day);

                            DealDate* dealDate = CreateDealDate(year, month, day);

                            BorrowBook(surname, group, title, cathLibrary, dealDate);

                            printf("You successfully borrowed the book from library!\n");
                            printf("Dont forget to bring it back on %d.%d.%d\n\n", dealDate->year, dealDate->month, dealDate->day);

                            while (getchar() != '\n');

                            printf("Press enter to continue...");
                            getchar();
                        }
                        else
                        {
                            printf("This book doesnt exist in library\n\n");

                            printf("Press enter to continue...");
                            getchar();
                        }
                    }
                    else
                    {
                        printf("Unfortunately, this reader cant borrow books due to too many penalties\n\n");

                        printf("Press enter to continue...");
                        getchar();
                    }
                }
                else
                {
                    printf("This reader is not registered in library");

                    printf("\n\nPress enter to continue...");
                    getchar();
                }
                break;

            case 4:
                while (getchar() != '\n');

                printf("Enter surname of reader ");
                getline(surname, MAX);

                printf("Enter group ", surname);
                scanf_s("%d", &group);

                while (getchar() != '\n');

                if (ReaderExists(surname, group, cathLibrary->readerList)) // Если существует читатель на учете
                {
                    Reader* reader = FindReader(cathLibrary->readerList, surname, group); // Достаем читателя

                    printf("Enter title of book you want to return back ");
                    getline(title, MAX);

                    if (FindDeal(reader->dealList, title)) // Если нашлась книга у читателя
                    {
                        Deal* deal = FindDeal(reader->dealList, title); // Достаем сделку читателя

                        printf("Enter current year ");
                        scanf_s("%d", &year);

                        while (getchar() != '\n');

                        if (year <= deal->dealDate->year)
                        {
                            printf("Enter current month ");
                            scanf_s("%d", &month);

                            while (getchar() != '\n');

                            if (month <= deal->dealDate->month)
                            {
                                printf("Enter current day ");
                                scanf_s("%d", &day);

                                while (getchar() != '\n');

                                if (day <= deal->dealDate->day);
                                else
                                {
                                    printf("\nYou had to return book on %d.%d.%d\n", deal->dealDate->year, deal->dealDate->month, deal->dealDate->day);
                                    printf("Next time return book in time! I give you +1 penalty");
                                    reader->penalty++;
                                }
                            }
                            else
                            {
                                printf("\nYou had to return book on %d.%d.%d\n", deal->dealDate->year, deal->dealDate->month, deal->dealDate->day);
                                printf("Next time return book in time! I give you +1 penalty");
                                reader->penalty++;
                            }
                        }
                        else
                        {
                            printf("\nYou had to return book on %d.%d.%d\n", deal->dealDate->year, deal->dealDate->month, deal->dealDate->day);
                            printf("Next time return book in time! I give you +1 penalty");
                            reader->penalty++;
                        }

                        ReturnBook(surname, group, title, cathLibrary);
                        printf("\nThe book was successfully returned!\n\n");

                        printf("Press enter to continue...");
                        getchar();
                    }
                    else
                    {
                        printf("This reader doesnt have such book\n\n");

                        printf("Press enter to continue...");
                        getchar();
                    }
                }

                else
                {
                    printf("This reader is not registered in library");

                    printf("\n\nPress enter to continue...");
                    getchar();
                }

                break;

            case 5:
                AddNewReader(cathLibrary->readerList);
                break;

            case 6:
                LibReport(cathLibrary);

                while (getchar() != '\n');
                printf("Press enter to continue...");
                getchar();
                break;

            case 7:
                DeleteLibrary(cathLibrary);
                return 0;
                break;
        }
    }
}

Book* CreateBook(char* author, char* title, int price, char* note)
{
    Book* book = (Book*)malloc(sizeof(Book));

    book->author = _strdup(author);
    book->title = _strdup(title);
    book->price = price;
    book->note = _strdup(note);

    return book;
}

int getline(char line[], int maxline)
{
    int c;
    int i;

    for (i = 0; i < 30 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

Deal* CreateDeal(Book* book, DealDate* dealDate)
{
    Deal* deal = (Deal*)malloc(sizeof(Deal));

    deal->book = book;
    deal->dealDate = dealDate;

    return deal;
}

DealDate* CreateDealDate(int year, int month, int day)
{
    DealDate* dealDate = (DealDate*)malloc(sizeof(DealDate));

    dealDate->year = year;
    dealDate->month = month;
    dealDate->day = day;


    return dealDate;
}

void PrintMenu(int key)
{
    printf("\t\tLibrary menu");
    printf("\n\n 1. Show readers");
    if (key == 1)
    {
        printf("\n\t1.1 Show by surname & group");
        printf("\n\t1.2 Show all");
    }
    printf("\n 2. Show books");
    if (key == 2)
    {
        printf("\n\t2.1 Show by title");
        printf("\n\t2.2 Show all");
    }
    printf("\n 3. Borrow book");
    printf("\n 4. Return book");
    printf("\n 5. Add new reader");
    printf("\n 6. Report");
    printf("\n 7. Exit");
    printf("\n\n ");
}

CathLibrary* CreateCathLibrary()
{
    CathLibrary* cathLibrary = (CathLibrary*)malloc(sizeof(CathLibrary));

    cathLibrary->bookList = nullptr;
    cathLibrary->readerList = nullptr;

    return cathLibrary;
}
void InitFromFile(CathLibrary* cathLibrary)
{
    FILE* file;

    fopen_s(&file, "readersInput.txt", "r");
    ListReader* listReader = CreateListReader();

    while (!feof(file))
    {
        char singleLine[MAX];
        char name[MAX];
        char surname[MAX];
        int group;
        char telephone[MAX];
        char email[MAX];
        char note[MAX];

        fgets(singleLine, MAX, file);
        strcpy_s(surname, singleLine);

        fgets(singleLine, MAX, file);
        strcpy_s(name, singleLine);

        fgets(singleLine, MAX, file);
        group = atoi(singleLine);

        fgets(singleLine, MAX, file);
        strcpy_s(telephone, singleLine);

        fgets(singleLine, MAX, file);
        strcpy_s(email, singleLine);

        fgets(singleLine, MAX, file);
        strcpy_s(note, singleLine);

        fgets(singleLine, MAX, file);

        Reader* reader = CreateReader(surname, name, group, telephone, email, note);

        AddReader(listReader, reader);
    }

    fclose(file);

    cathLibrary->readerList = listReader;

    fopen_s(&file, "booksInput.txt", "r");
    ListBook* bookList = CreateListBook();

    while (!feof(file))
    {
        char singleLine[MAX];
        char author[MAX];
        char title[MAX];
        char note[MAX];
        int price;
        int quantity;

        fgets(singleLine, MAX, file);
        strcpy_s(author, singleLine);

        fgets(singleLine, MAX, file);
        strcpy_s(title, singleLine);

        fgets(singleLine, MAX, file);
        price = atoi(singleLine);

        fgets(singleLine, MAX, file);
        strcpy_s(note, singleLine);

        fgets(singleLine, MAX, file);
        quantity = atoi(singleLine);

        fgets(singleLine, MAX, file);

        Book* book = CreateBook(author, title, price, note);

        AddBook(bookList, book, quantity);
    }

    fclose(file);
    cathLibrary->bookList = bookList;
}

void ShowReaderInfo(Reader* reader)
{
    int k = 0;

    while (true)
    {
        if (reader->name[k] != '\n')
            printf("%c", reader->name[k]);
        else
            break;
        ++k;
    }

    printf(" %s", reader->surname);
    printf("group: %d", reader->group);

    printf("\ncontact: ");
    k = 0;

    while (true)
    {
        if (reader->telephoneNumber[k] != '\n')
            printf("%c", reader->telephoneNumber[k]);
        else
            break;

        ++k;
    }
    printf(", %s", reader->email);
    printf("books: ");

    ShowReaderBooks(reader->dealList);
    printf("\npenalties: ");
    if (reader->penalty < 1)
    {
        printf("no penalties");
    }
    else if (reader->penalty == 1)
    {
        printf("yellow card");
    }
    else
    {
        printf("red card :(");
    }
    printf("\nnote: %s", reader->note);
    printf("\n\n");
}

void ShowReaders(ListReader* readerList)
{
    NodeReader* node = readerList->head;

    for (int i = 0; i < readerList->size; ++i)
    {
        ShowReaderInfo(node->reader);

        node = node->next;
    }
}

void ShowBookInfo(NodeBook* node)
{
    int k = 0;

    while (true)
    {
        if (node->book->title[k] != '\n')
            printf("%c", node->book->title[k]);
        else
            break;
        ++k;
    }

    printf(" by %s", node->book->author);
    printf("\tamount: %d  price: %d$", node->quantity, node->book->price);
    printf("\n\tnote: %s", node->book->note);
    printf("\n");
}

void ShowBooks(ListBook* bookList)
{
    NodeBook* node = bookList->head;

    for (int i = 0; i < bookList->size; ++i)
    {
        ShowBookInfo(node);

        node = node->next;
    }
}

void ShowReaderBooks(ListDeal* dealList)
{
    NodeDeal* node = dealList->head;

    for (int i = 0; i < dealList->size; ++i)
    {
        int k = 0;

        while (true)
        {
            if (node->deal->book->title[k] != '\n')
                printf("%c", node->deal->book->title[k]);
            else
                break;

            ++k;
        }

        if (k != 0)
            printf(", ");

        node = node->next;
    }
}

void BorrowBook(char* surname, int group, char* title, CathLibrary* lib, DealDate* dealDate)
{
    Reader* reader = FindReader(lib->readerList, surname, group);
    Book* book = FindBook(lib->bookList, title);
    Deal* deal = CreateDeal(book, dealDate);

    AddDeal(reader->dealList, deal);
    RemoveBook(book, lib->bookList);
}

void ReturnBook(char* surname, int group, char* title, CathLibrary* lib)
{
    Reader* reader = FindReader(lib->readerList, surname, group);
    Deal* deal = FindDeal(reader->dealList, title);

    AddBook(lib->bookList, deal->book, 1);
    RemoveDeal(deal, reader->dealList);
}

bool ReaderExists(char* surname, int group, ListReader* listReader)
{
    Reader* reader = FindReader(listReader, surname, group);

    if (reader != nullptr)
        return true;
    else
        return false;
}

bool BookExists(char* title, ListBook* listBook)
{
    Book* book = FindBook(listBook, title);

    if (book != nullptr)
        return true;
    else
        return false;
}


void LibReport(CathLibrary* lib)
{
    int libBooks = 0;
    int readBooks = 0;
    int sumBooks = 0;

    NodeBook* nodeBook = lib->bookList->head;

    for (int i = 0; i < lib->bookList->size; ++i)
    {
        libBooks += nodeBook->quantity;

        sumBooks += nodeBook->book->price * nodeBook->quantity;

        nodeBook = nodeBook->next;
    }

    NodeReader* nodeReader = lib->readerList->head;

    for (int i = 0; i < lib->readerList->size; ++i)
    {
        readBooks += nodeReader->reader->dealList->size;

        NodeDeal* nodeDeal = nodeReader->reader->dealList->head;

        for (int k = 0; k < nodeReader->reader->dealList->size; ++k)
        {
            sumBooks += nodeDeal->deal->book->price;

            nodeDeal = nodeDeal->next;
        }

        nodeReader = nodeReader->next;
    }

    printf("\nAmount of books in library: %d", libBooks);
    printf("\nAmount of readers books: %d", readBooks);
    printf("\nAmount of readers: %d", lib->readerList->size);
    printf("\nTotal sum of books: %d $\n\n", sumBooks);
}

void DeleteLibrary(CathLibrary* lib)
{
    NodeBook* temp = lib->bookList->head;

    for (int i = 0; i < lib->bookList->size; ++i)
    {
        free(temp);

        temp = temp->next;
    }

    NodeReader* tempR = lib->readerList->head;

    for (int i = 0; i < lib->readerList->size; ++i)
    {
        free(tempR);

        tempR = tempR->next;
    }
}
ListBook* CreateListBook()
{
    ListBook* temp = (ListBook*)malloc(sizeof(ListBook));

    temp->size = 0;
    temp->head = nullptr;

    return temp;
}

void AddBook(ListBook* listBook, Book* book, int quantity)
{
    if (listBook->head == nullptr)
    {
        NodeBook* nodeBook = (NodeBook*)malloc(sizeof(NodeBook));

        nodeBook->book = book;
        nodeBook->next = nullptr;
        nodeBook->quantity = quantity;

        listBook->head = nodeBook;
        listBook->size++;
    }
    else
    {
        NodeBook* currNodeBook = listBook->head;

        while (currNodeBook->next != nullptr)
        {
            currNodeBook = currNodeBook->next;
        }

        NodeBook* nodeBook = (NodeBook*)malloc(sizeof(NodeBook));

        nodeBook->book = book;
        nodeBook->next = nullptr;
        nodeBook->quantity = quantity;

        currNodeBook->next = nodeBook;
        listBook->size++;
    }
}

Book* FindBook(ListBook* listBook, char* title)
{
    NodeBook* node = listBook->head;

    for (int i = 0; i < listBook->size; ++i)
    {
        if (strcmp(title, node->book->title) == 0)
            return node->book;

        node = node->next;
    }

    return nullptr;
}

void RemoveBook(Book* book, ListBook* listBook)
{
    NodeBook* currNode = listBook->head;

    while (true)
    {
        if (currNode->book == book)
        {
            if (currNode->quantity == 1)
            {
                if (currNode == listBook->head)
                {
                    NodeBook* temp = listBook->head;
                    listBook->head = listBook->head->next;

                    free(temp);

                    listBook->size--;
                    break;
                }
                else
                {
                    NodeBook* previous = listBook->head;
                    for (int i = 0; i < listBook->size; ++i)
                    {
                        if (previous->next->book == book)
                            break;
                        previous = previous->next;
                    }
                    NodeBook* toDelete = previous->next;

                    previous->next = toDelete->next;

                    free(toDelete);
                    listBook->size--;
                    break;
                }
            }
            else
            {
                currNode->quantity--;
                break;
            }
        }
        currNode = currNode->next;
    }
}
void AddDeal(ListDeal* dealList, Deal* deal)
{
    if (dealList->head == nullptr)
    {
        NodeDeal* nodeDeal = (NodeDeal*)malloc(sizeof(NodeDeal));

        nodeDeal->deal = deal;
        nodeDeal->next = nullptr;

        dealList->head = nodeDeal;
        dealList->size++;
    }
    else
    {
        NodeDeal* currNodeDeal = dealList->head;

        while (currNodeDeal->next != nullptr)
        {
            currNodeDeal = currNodeDeal->next;
        }

        NodeDeal* nodeDeal = (NodeDeal*)malloc(sizeof(NodeDeal));

        nodeDeal->deal = deal;
        nodeDeal->next = nullptr;

        currNodeDeal->next = nodeDeal;
        dealList->size++;
    }
}

Deal* FindDeal(ListDeal* listDeal, char* title)
{
    NodeDeal* node = listDeal->head;

    for (int i = 0; i < listDeal->size; ++i)
    {
        if (strcmp(title, node->deal->book->title) == 0)
            return node->deal;

        node = node->next;
    }

    return nullptr;
}

void RemoveDeal(Deal* deal, ListDeal* listDeal)
{
    NodeDeal* currNode = listDeal->head;

    while (true)
    {
        if (currNode->deal == deal)
        {
            if (currNode == listDeal->head)
            {
                NodeDeal* temp = listDeal->head;
                listDeal->head = listDeal->head->next;

                free(temp);

                listDeal->size--;
                break;
            }

            else
            {
                NodeDeal* previous = listDeal->head;

                for (int i = 0; i < listDeal->size; ++i)
                {
                    if (previous->next->deal == deal)
                        break;

                    previous = previous->next;
                }

                NodeDeal* toDelete = previous->next;

                previous->next = toDelete->next;

                free(toDelete);
                listDeal->size--;
                break;
            }
        }

        currNode = currNode->next;
    }
}
void AddNewReader(ListReader* listReader)
{
    system("cls");

    while (getchar() != '\n');

    char name[MAX];
    char surname[MAX];
    int group;
    char telephone[MAX];
    char email[MAX];
    char note[MAX];

    printf("Enter name: ");
    getline(name, MAX);

    printf("Enter surname: ");
    getline(surname, MAX);

    printf("Enter group: ");
    scanf_s("%d", &group);

    while (getchar() != '\n');

    printf("Enter telephone number: ");
    getline(telephone, MAX);

    printf("Enter email: ");
    getline(email, MAX);

    printf("Enter note: ");
    getline(note, MAX);


    Reader* reader = CreateReader(surname, name, group, telephone, email, note);
    AddReader(listReader, reader);
}

ListReader* CreateListReader()
{
    ListReader* temp = (ListReader*)malloc(sizeof(ListReader));

    temp->size = 0;
    temp->head = nullptr;

    return temp;
}

void AddReader(ListReader* listReader, Reader* reader)
{
    if (listReader->head == nullptr)
    {
        NodeReader* nodeReader = (NodeReader*)malloc(sizeof(NodeReader));

        nodeReader->reader = reader;
        nodeReader->next = nullptr;

        listReader->head = nodeReader;
        listReader->size++;
    }
    else
    {
        NodeReader* currNodeReader = listReader->head;

        while (currNodeReader->next != nullptr)
        {
            currNodeReader = currNodeReader->next;
        }

        NodeReader* nodeReader = (NodeReader*)malloc(sizeof(NodeReader));

        nodeReader->reader = reader;
        nodeReader->next = nullptr;

        currNodeReader->next = nodeReader;
        listReader->size++;
    }
}

Reader* FindReader(ListReader* listReader, char* surname, int group)
{
    NodeReader* node = listReader->head;

    for (int i = 0; i < listReader->size; ++i)
    {
        if ((strcmp(surname, node->reader->surname) == 0) && (node->reader->group == group))
            return node->reader;

        node = node->next;
    }

    return nullptr;
}
Reader* CreateReader(char* surname, char* name, int group, char* number, char* email, char* note)
{
    Reader* reader = (Reader*)malloc(sizeof(Reader));

    ListDeal* listDeal = (ListDeal*)malloc(sizeof(ListDeal));
    listDeal->head = nullptr;
    listDeal->size = 0;

    reader->surname = _strdup(surname);
    reader->name = _strdup(name);
    reader->group = group;
    reader->telephoneNumber = _strdup(number);
    reader->email = _strdup(email);
    reader->note = _strdup(note);
    reader->penalty = 0;
    reader->dealList = listDeal;

    return reader;
}