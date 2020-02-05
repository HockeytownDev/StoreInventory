#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

typedef struct Furniture
{
    std::string name;
    std::string color;
    int amt;
    std::string month, day, year;
    double price;
} Furniture;

typedef struct Art
{
    std::string name;
    double price;
    int amt;
    std::string month, day, year;
    std::string height, width, depth;
} Art;

typedef struct Fabric
{
    std::string name;
    std::string color;
    int amt;
    double price;
} Fabric;

typedef struct Book
{
    std::string name;
    bool hardcover;
    int pages;
    double price;
    int amt;
    std::string month, day, year;
} Book;

Furniture* readFurniture (int&);
Art* readArt (int&);
Fabric* readFabric (int&);
Book* readBook (int&);

void printFurniture(Furniture*, int);
void printArt(Art*, int);
void printFabric(Fabric*, int);
void printBook(Book*, int);
#endif // STRUCTS_H_INCLUDED
