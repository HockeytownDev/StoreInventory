#include <iostream>
#include <fstream>
#include "structs.h"

using namespace std;

Furniture* readFurniture (int &n)
{
    ifstream inFile;
    inFile.open("Furniture.txt");
    inFile >> n;
    Furniture *arr = NULL;
    arr = new Furniture[n];
    string date;
    for (int i=0;i<n;++i)
    {
        inFile >> arr[i].name >> arr[i].color >> arr[i].amt >> date >> arr[i].price;

        int colon1=-1, colon2=-1;

        for (int j=0;j<(int)(date.length());++j)
            if (colon1==-1 && date[j]==':')
                colon1 = j;
            else if (date[j]==':')
                colon2 = j;

        arr[i].month = date.substr(0,colon1);
        arr[i].day = date.substr(colon1+1, colon2-colon1-1);
        arr[i].year = date.substr(colon2+1);
    }
    return arr;
}

Art* readArt(int &n)
{
    ifstream inFile;
    inFile.open("Art.txt");
    inFile >> n;
    Art *arr = NULL;
    arr = new Art[n];
    string date, dimension;
    for (int i=0;i<n;++i)
    {
        inFile >> arr[i].name >> arr[i].price >> arr[i].amt >> date >> dimension;

        int colon1=-1, colon2=-1;

        for (int j=0;j<(int)(date.length());++j)
            if (colon1==-1 && date[j]==':')
                colon1 = j;
            else if (date[j]==':')
                colon2 = j;

        arr[i].month = date.substr(0,colon1);
        arr[i].day = date.substr(colon1+1, colon2-colon1-1);
        arr[i].year = date.substr(colon2+1);

        colon1 = colon2 = -1;

        for (int j=0;j<(int)(dimension.length());++j)
            if (colon1==-1 && dimension[j]==':')
                colon1 = j;
            else if (dimension[j]==':')
                colon2 = j;

        arr[i].height = dimension.substr(0,colon1);
        arr[i].width = dimension.substr(colon1+1, colon2-colon1-1);
        arr[i].depth = dimension.substr(colon2+1);
    }
    return arr;
}

Fabric* readFabric(int &n)
{
    ifstream inFile;
    inFile.open("Fabric.txt");
    inFile >> n;
    Fabric *arr = NULL;
    arr = new Fabric[n];
    string date, dimension;
    for (int i=0;i<n;++i)
        inFile >> arr[i].name >> arr[i].color >> arr[i].amt >> arr[i].price;
    return arr;
}

Book* readBook (int &n)
{
    ifstream inFile;
    inFile.open("Book.txt");
    inFile >> n;
    Book *arr = NULL;
    arr = new Book[n];
    string date;
    for (int i=0;i<n;++i)
    {
        inFile >> arr[i].name >> arr[i].hardcover >> arr[i].pages >> arr[i].price >> arr[i].amt >> date;

        int colon1=-1, colon2=-1;

        for (int j=0;j<(int)(date.length());++j)
            if (colon1==-1 && date[j]==':')
                colon1 = j;
            else if (date[j]==':')
                colon2 = j;

        arr[i].month = date.substr(0,colon1);
        arr[i].day = date.substr(colon1+1, colon2-colon1-1);
        arr[i].year = date.substr(colon2+1);
    }
    return arr;
}

void printFurniture (Furniture *furniture, int n)
{
    cout << "====================================================================" << endl;
    cout << "                             Furniture                              " << endl;
    cout << "====================================================================" << endl;
    cout << "\t\tName| Color | Inventory | Date Created | Cost" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (int i=0; i<n; ++i)
    {
        cout.width(20);
        cout << std::left << furniture[i].name << "| ";
        cout.width(6);
        cout << furniture[i].color << "|     ";
        cout.width(6);
        cout << furniture[i].amt << "|  ";
        cout << furniture[i].month << ":" << furniture[i].day << ":" << furniture[i].year << "  |  ";
        cout << std::right << furniture[i].price << endl;
    }
    cout << endl << endl;
    return;
}

void printArt (Art* art, int n)
{
    cout << "====================================================================" << endl;
    cout << "                                Art                                 " << endl;
    cout << "====================================================================" << endl;
    cout << "\t\tName| Cost  | Inventory | Date Created | Dimension" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (int i=0; i<n; ++i)
    {
        cout.width(20);
        cout << std::left << art[i].name << "| ";
        cout.width(6);
        cout << art[i].price << "|     ";
        cout.width(6);
        cout << art[i].amt << "|  ";
        cout << art[i].month << ":" << art[i].day << ":" << art[i].year << "  |  ";
        cout << std::right << art[i].height << ":" << art[i].width << ":" << art[i].depth << endl;
    }
    cout << endl << endl;
    return;
}

void printFabric (Fabric *fabric, int n)
{
    cout << "====================================================================" << endl;
    cout << "                              Fabric                                " << endl;
    cout << "====================================================================" << endl;
    cout << "\t\tName| Color | Inventory | Cost" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (int i=0; i<n; ++i)
    {
        cout.width(20);
        cout << std::left << fabric[i].name << "| ";
        cout.width(6);
        cout << fabric[i].color << "|     ";
        cout.width(6);
        cout << fabric[i].amt << "|  ";
        cout << std::right << fabric[i].price<< endl;
    }
    cout << endl << endl;
    return;
}

void printBook (Book *book, int n)
{
    cout << "====================================================================" << endl;
    cout << "                               Book                                 " << endl;
    cout << "====================================================================" << endl;
    cout << "\t\tName| Hardcover | Pages | Cost | Inventory | Date Created" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (int i=0; i<n; ++i)
    {
        cout.width(20);
        cout << std::left << book[i].name << "|      ";
        cout.width(5);
        cout << book[i].hardcover << "|  ";
        cout.width(5);
        cout << book[i].pages << "| ";
        cout.width(5);
        cout << book[i].price << "|     ";
        cout.width(6);
        cout << book[i].amt << "|  ";
        cout << std::right << book[i].month << ":" << book[i].day << ":" << book[i].year << endl;
    }
    cout << endl << endl;
    return;
}
