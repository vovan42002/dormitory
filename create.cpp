#include <type.h>

Dormitory *createDormitory (char *name, int Countroom, char *Commandant, char *Addres){
    Dormitory *dormitory = new Dormitory();
    strncpy(dormitory->Commandant, name, SIZE_NAME);
    strncpy(dormitory->Addres, Addres, SIZE_ADDRES);
    dormitory->arSize = 4;
    dormitory->blockarray = new Block[dormitory->arSize];
    dormitory->Countroom = 0;
    return dormitory;
}

Block *createBlock (int Numblock, char *Starosta, int Floor){
    Block *block = new Block();
    strncpy (block->Starosta,Starosta,SIZE_NAME);
    block->Floor = Floor;
    block->arSize = 3;
    block->pRoomArray = new Room*[block->arSize];
    block->NumRoom = 0;
    return block;
}

Room *createRoom (int NumberRoom, int KilkistLizok, int Square){
    Room *room = new Room();
    int *roomNumberRoom = new int;
    room->NumberRoom = NumberRoom;
    int *roomKilkistLizok = new int;
    room->KilkistLizok = KilkistLizok;
    int *roomSquare = new int;
    room->Square = Square;
    room->firstInhab = NULL;
    return room;
}
Inhabitant *createInhanitant (char *name, int YeartoRoom, char *Facult){
    Inhabitant *inhab = new Inhabitant();
    char *Inhabname = new char[SIZE_NAME];
    strncpy (Inhabname,name, SIZE_NAME);
    inhab->name = Inhabname;
    inhab->YeartoRoom = YeartoRoom;
    char *nameFacult = new char[SIZE_FACULT];
    strncpy (nameFacult, Facult, SIZE_FACULT);
    inhab->Facult = nameFacult;
    inhab->nextInhab = NULL;
    return inhab;
}
