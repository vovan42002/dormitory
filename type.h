#ifndef TYPE_H
#define TYPE_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <ctime>

using namespace std;
#define SIZE_NAME 40
#define SIZE_ADDRES 40
#define SIZE_FACULT 10
struct Dormitory;
struct Block;
struct Room;
struct Inhabitant;
struct Dormitory {
    char Commandant[SIZE_NAME];
    char Addres[SIZE_ADDRES];
    int buildYear;
    int Countroom;
    int arSize;
    int blockCount;
    Block *blockarray;
};
struct Block {
    int Floor;
    int Numblock;
    char Starosta[SIZE_NAME];
    int arSize;
    int countRoom;
    Room* *pRoomArray;
    Dormitory *parent;
};
struct Room {
    int NumberRoom;
    int KilkistLizok;
    float Square;
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
int createRoot(void*);
Dormitory *createDormitory( int buildYear,char *Commandant,char *Addres);
Block *createBlock (int Numblock,char *Starosta, int Floor);
Room *createRoom (int NumberRoom, int KilkistLizok, float Square);
Inhabitant *createInhabitant (char *name,int YeartoRoom, char *faculty);
int createDefaultTree (void*);
int addDormitoryByMenu (void *ptr);
                                                        // del.cpp //
void delAllInhab (Room *pRoom);
void delAllRoom (Block *pB);
void delAllBlock (Dormitory *pD);
Block *delBlock(Block *pB);
Room *delRoom (Room *pDel);
Inhabitant *delInhab (Inhabitant *pDel);
//First group
int delBlockByMenu (void*);
int delRoomByMenu (void*);
int delInhabByMenu (void*);
//second group
int delAllBlockByMenu (void *ptr);
int delAllRoomByMenu (void *ptr);
int delAllInhabByMenu (void *ptr);
                                                    // edit.cpp  //
void sortBlock (Dormitory *pD);
void sortRoom (Block *pB);
void sortInhab(Room *pR);

void editDormitory(Dormitory *pD, char *newNameCommandant, char *newAddres, int builYear);
void editBlock (Block *pB, char *newNameStarosta, int Numblock, int Floor);
void editRoom (Room *pR, char *newName, int Numberroom);
void editInhabitant (Inhabitant *pI, char *newName, char *newAddres, int buildYear);
int editDormitoryByMenu (void*);
int editBlockByMenu (void*);
int editRoomByMenu (void*);
int editInhabitantByMenu (void*);


                                        // menu.cpp  //
int mainMenu (void*);
int menuDormitory (void*);
int menuQuery (void*);
int menuBlock (void*);
int menuRoom (void*);
int menuInhabitant (void*);
int menuTree (void *ptr);
void runMenu (MenuUnit menu[],string menuName,void *ptr);

                                                // query.cpp  //

int findBiggestBlockByInhab (void*);
int findRoomForInfor (void *);
int findInhabByName (void *);
int  findInhabByYear (void *);

                                            // show.cpp  //
//First group
int showDormitoryInfo (void*);
int showBlockInfo (void *ptr);
int showRoomInfo (void*);
int showInhabInfo (void*);
//Second group
int showBlockList (void*);
int showRoomList (void*);
int showInhabList (void*);

                                                            // tree.cpp  //
int createDefaultTree (void*);
int showTree(void*);
int delTree (void*);
int storeTreeByMenu(void*);
int restoreTreeByMenu (void*);
int showLogFile (void*);
void log_file(string s);
void storeToFile (FILE *f);
void restoreFromFile (FILE *f);
Block *selectBlock ();
Room *selectRoom (Block *);
Inhabitant *selectInhabitant (Room *);


                                                    //  util.cpp  //

int printBlockList ();
int printRoomList (Block *pB);
int printInhabList (Room *pR);
int getInt  (string promt, int min, int max);
char *getStr (string promt);
string IntToString(int a);
float getFloat  (string promt, float min, float max);
void pause();
#endif // TYPE_H
