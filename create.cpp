#include <type.h>

Dormitory *createDormitory ( int buildYear, char *Commandant, char *Addres){
    Dormitory *dormitory = new Dormitory();
    strncpy(dormitory->Commandant, Commandant, SIZE_NAME);
    strncpy(dormitory->Addres, Addres, SIZE_ADDRES);
    dormitory->buildYear = buildYear;
    dormitory->arSize = 3;
    dormitory->blockarray = new Block[dormitory->arSize];
    dormitory->Countroom = 0;
    return dormitory;
}
int createRoot (void *){
    int BY = getInt("Enter build year(min 1900, max 2015): ",1900,2015);
    char *Com = getStr("Enter name commandant: ");
    if(strlen(Com)==0){
        cout << "Name was not changed\n";
    }
    char *Addr = getStr("Enter addres: ");
    if(strlen(Addr)==0){
        cout << "Addra was not changed\n";
    }
    root = createDormitory(BY,Com,Addr);
    log_file("Create root ");
    return 1;
}


Block *createBlock (int Numblock, char *Starosta, int Floor){
    Block *block = new Block();
    strncpy (block->Starosta,Starosta,SIZE_NAME);
    block->Numblock = Numblock;
    block->Floor = Floor;
    block->arSize = 3;
    block->pRoomArray = new Room*[block->arSize];
    block->countRoom = 0;
    return block;
}
Room *createRoom (int NumberRoom, int KilkistLizok, float Square){
    Room *room = new Room();
    room->NumberRoom = NumberRoom;
    room->KilkistLizok = KilkistLizok;
    room->Square = Square;
    room->firstInhab = NULL;
    return room;
}

Inhabitant *createInhabitant (char *name, int YeartoRoom, char *Facult){
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
