#include <iostream>
#include "structs.h"

using namespace std;

int main()
{
    int numOfFurniture, numOfArt, numOfFabric, numOfBook;

    Furniture *furniture = readFurniture(numOfFurniture);
    Art *art = readArt(numOfArt);
    Fabric *fabric = readFabric(numOfFabric);
    Book *book = readBook(numOfBook);

    while (true)
    {
        int choice;

        cout << "Select which option would you like to see" << endl;
        cout << "1. Print all Furniture" << endl;
        cout << "2. Print all Art" << endl;
        cout << "3. Print all Fabric" << endl;
        cout << "4. Print all Book" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        while (true)
        {
            cout << "Enter Option (1-5):";
            cin >> choice;

            if (choice>0 && choice<6)
                break;
            else
                cout << "Invalid input!" << endl;
        }

        if (choice==1)
            printFurniture(furniture, numOfFurniture);
        else if (choice==2)
            printArt(art, numOfArt);
        else if (choice==3)
            printFabric(fabric, numOfFabric);
        else if (choice==4)
            printBook(book, numOfBook);
        else
            break;
    }
    return 0;
}
