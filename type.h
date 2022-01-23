#ifndef TYPE_H
#define TYPE_H
                                        //Bohdan V.O. KI-191 //
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;
#define SIZE_NAME 40
#define SIZE_ADDRES 40
#define SIZE_FACULT 10                                        //Structure of the project //
struct Dormitory;
struct Block;
struct Room;
struct Inhabitant;
struct Dormitory {
    char Commandant[SIZE_NAME];
    char Addres[SIZE_ADDRES];
    int Countroom;
    int buildYear;
    int arSize;
    int dormitoryCount;
    Block *blockarray;
};
struct Block {
    int Floor;
    int Numblock;
    char Starosta[SIZE_NAME];
    int arSize;
    int NumRoom;
    int countBlock;
    Room* *pRoomArray;
    Dormitory *parent;
};
struct Room {
    int NumberRoom;
    int KilkistLizok;
    int Square;
    int countRoom;
    Inhabitant *firstInhab;
    Block *parent;
};
struct Inhabitant {
    char *name;
    int YeartoRoom;
    char *Facult;
    Inhabitant *nextInhab;
    Room *parent;
};
                                    //Type of functions for menu items//
typedef int MenuFunc(void*);
                    //element struct//
struct MenuUnit {
    string text;
    MenuFunc *func;
};
            //extern variables//
extern Dormitory *root;
extern char *logFileName;
                                    //    Prototypes for all .cpp  //

                    // add.cpp //
void addBlock (Dormitory *dormitory,Block *block);
void addRoom (Block *pB, Room *pR);
void addInhab (Room *pR, Inhabitant *pIn);

void growBlockAr(Dormitory *pD);
void growRoomAr (Block *pB);

int cmpBlock (Block b1, Block b2);
int cmpRoom (Room r1, Room r2);
int cmpInhab (Inhabitant i1, Inhabitant i2);

int addBlockByMenu (void*);
int addRoomByMenu (void*);
int addInhabByMenu (void*);

                                                    // create.cpp //
Dormitory *createDormitory(char *name, int Countroom,
                           char Commandant[SIZE_NAME],char Addres[SIZE_ADDRES]);

Block *createBlock (int Numblock,
                    char *Starosta, int Floor);
Room *createRoom (int NumberRoom,
                  int KilkistLizok, int Square);
Inhabitant *createInhab (char *name,
                         int YeartoRoom, char *faculty);
int createDefaultTree (void*);

// del.cpp //
Block *delBlock(Block *pB);
Room *delRoom (Room *pR);
Inhabitant *delInhab (Inhabitant *pI);
//First group
int delBlockByMenu (void*);
int delRommByMenu (void*);
int delInhabitant (void*);
//second group
int delAllBlockByMenu (void *ptr);
int delAllRoomByMenu (void *ptr);
int delAllInhabotant (void *ptr);
// edit.cpp  //
void sortBlock (Dormitory *pD);
void sortRoom (Block *pB);
void sortInhab(Room *pR);

void editDormitory(Dormitory *pD, char *newName,
                   int Countroom);
void editBlock (Block *pB, char *newName, int Numblock);
void editRoom (Room *pR, char *newName, int Numberroom);
void editInhabitant (Inhabitant *pI, char *newName,
                     char *name);
int editDormitoryByMenu (void*);
int editBlockByMenu (void*);
int editRoomByMenu (void*);
int editInhabitantByMenu (void*);


// menu.cpp  //
int mainMenu (void*);
int menutree (void*);
int menuQueries (void*);
int menuDormitory (void*);
int menuQuery (void*);
int menuBlock (void*);
int menuRoom (void*);
int menuInhabitant (void*);

// query.cpp  //

Block *findBiggestBlockByInhab ();
Room *findRoomForInfor (int);
Inhabitant *findInhabByName (char *);
Inhabitant * findInhabByYear (int);

// show.cpp  //
//First group
int showDormitoryInfo (void*);
int showBlockInfo (void*);
int showRoomInfo (void*);
int showInhabitantInfo (void*);
//Second group
int showBlockList (void*);
int showRoomList (void*);
int showInhabitantList (void*);

// tree.cpp  //
int createDefaultTree (void*);
int showTree(void*);
int delTree (void*);
void storeToFile (FILE *f);
void restoreFromFile (FILE *f);
int showLogFile (void*);

//  util.cpp  //
Block *selectBlock ();
Room *selectRoom (Block *);
Inhabitant *selectInhabitant (Room *);
void openLogFile (string message);
void printToLog (string message);
void pause();
#endif // TYPE_H
