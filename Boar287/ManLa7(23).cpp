#include "Functions.h"

int main()
{
    bool Proccess = true;
    bool CommentProcess = true;
    int SIZE = 4;
    DataBaseElement *dataBase=(DataBaseElement*)malloc(sizeof(DataBaseElement)*SIZE);
    char SourceCode[256]="";
    char Statement[256] = "";

    char filename1[100] = "D:\\ProjectC\\Laba7\\C++\\SourceCode1.txt";
    char filename2[100] = "D:\\ProjectC\\Laba7\\C#\\SourceCode2.txt";
    char filename3[100] = "D:\\ProjectC\\Laba7\\C++\\SourceCode3.txt";
    char filename4[100] = "D:\\ProjectC\\Laba7\\Java\\SourceCode4.txt";

    char Statefilename1[100] = "D:\\ProjectC\\Laba7\\C++\\Statements1.txt";
    char Statefilename2[100] = "D:\\ProjectC\\Laba7\\C#\\Statements2.txt";
    char Statefilename3[100] = "D:\\ProjectC\\Laba7\\C++\\Statements3.txt";
    char Statefilename4[100] = "D:\\ProjectC\\Laba7\\Java\\Statements4.txt";
    
    FillSourceInfo(&dataBase[0], "C++\n", "\"Hello World\"\n",23,04,2021, filename1);
    FillStateInfo(&dataBase[0], 0, "C++", "C++ Introduction",12,01,2018);
    FillStatementCode(&dataBase[0], Statefilename1);
    FillComInfo(&dataBase[0],0,"Rather difficult language with huge resource managmanet potential");
     
    FillSourceInfo(&dataBase[1], "C#\n", "\"Hello World\"\n",05,03,2021, filename2);
    FillStateInfo(&dataBase[1], 0, "C#", "C# Introduction",03,02,2021);
    FillStatementCode(&dataBase[1], Statefilename2);
    FillComInfo(&dataBase[1], 0, "Good language for beginners");
    FillComInfo(&dataBase[1], 1, "Universal and demanded in the market language");

    FillSourceInfo(&dataBase[2], "C++\n", "Buble Sort\n",16,05,2020, filename3);
    FillStateInfo(&dataBase[2], 0, "C++", "Sorting Options",05,11,2019);
    FillStateInfo(&dataBase[2], 1, "C++", "Qucik Sort",28,12,2020);
    FillStatementCode(&dataBase[2], Statefilename3);
    FillComInfo(&dataBase[2], 0, "The easiest way of array sort");
     
    FillSourceInfo(&dataBase[3],"Java\n", "Class Initialization\n",14,07,2020, filename4);
    FillStateInfo(&dataBase[3], 0,"Java", "OOP",21,12,2020);
    FillStateInfo(&dataBase[3], 1,"C++", "Classes in Java",19,11,2020);
    FillStatementCode(&dataBase[3], Statefilename4);

    int Choice = -1;
    int Number = -1;
    int ComChoice = -1;
    GetAllInfo(dataBase, SIZE);
    Functionality(&Choice);
    while (Proccess)
    {
        switch (Choice)
        {
        case 0:
            Proccess = false;
            break;
        case 2:
            CommentProcess = true;
            printf("Enter index of element:");
            scanf_s("%d", &Number);
            if (Number<1 || Number>SIZE)
            {
                printf("Wrong number was entered");
                free(dataBase);
                return 0;
            }
            system("cls");
            GetElemInfo(dataBase[--Number], Number);
            CommnetFunctionality(&ComChoice);
            if (ComChoice < 0 || ComChoice>3)
            {
                printf("Wrong entered value....");
                return 0;
            }
            while (CommentProcess)
            {
                switch (ComChoice)
                {
                case 0:
                    system("cls");
                    GetAllInfo(dataBase, SIZE);
                    Functionality(&Choice);
                    CommentProcess = false;
                    break;
                case 2:
                    system("cls");
                    AddComment(&dataBase[Number]);
                    system("cls");
                    GetElemInfo(dataBase[Number], Number);
                    CommnetFunctionality(&ComChoice);
                    continue;
                    break;
                case 1:
                    DeleteComment(&dataBase[Number]);
                    system("cls");
                    GetElemInfo(dataBase[Number], Number);
                    CommnetFunctionality(&ComChoice);
                    continue;
                    break;
                case 3:
                    RedactComment(&dataBase[Number]);
                    system("cls");
                    GetElemInfo(dataBase[Number], Number);
                    CommnetFunctionality(&ComChoice);
                    continue;
                    break;
                }
            }
            break;
        case 1:
            CommentProcess = true;
            system("cls");
            GetAllInfo(dataBase,SIZE);
            Functionality(&Choice);
            break;
        case 3:
            CommentProcess = true;
            SortByTheme(dataBase, SIZE);
            Functionality(&Choice);
            break;
        case 4:
            CommentProcess = true;
            SortByLanguage(dataBase, SIZE);
            Functionality(&Choice);
            break;
        default:
            printf("Wrong info entered...");
            free(dataBase);
            return 0;
        }
    }
    free(dataBase);
    return 0;
}
