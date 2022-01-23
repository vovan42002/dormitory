#include <type.h>

void growBlockAr (Dormitory *pD){
    int newSize = pD->arSize + pD->arSize;
    Block *newAr = new Block[newSize];
    memcpy (newAr, pD->blockarray, pD->arSize*sizeof (Block));
    pD->arSize = newSize;
    Block *oldAr = pD->blockarray;
    pD->blockarray = newAr;
    delete [] oldAr;
}
void growRoomAr (Block *pB){
    int newSize = pB->arSize + pB->arSize;
    Room* *newAr = new Room*[newSize];
    memcpy(newAr, pB->pRoomArray, pB->arSize * sizeof(Room));
    pB->arSize = newSize;
    Room* *oldAr = pB->pRoomArray;
    pB->pRoomArray = newAr;
    delete [] oldAr;
}
int cmpBlock (Block b1, Block b2){
    if (b1.Numblock != b2.Numblock)
        return b1.Numblock - b2.Numblock;
}
int cmpRoom (Room r1, Room r2){
    if (r1.NumberRoom != r2.NumberRoom)
        return r1.NumberRoom - r2.NumberRoom;
}

int cmpInhab (Inhabitant i1, Inhabitant i2){
    if (i1.YeartoRoom != i2.YeartoRoom)
        return i1.YeartoRoom - i2.YeartoRoom;
    return strcmp (i1.name , i2.name);
}

void addBlock (Dormitory *dormitory, Block *block){
    block->parent = dormitory;
    if (dormitory->arSize == dormitory->blockCount)
        growBlockAr (dormitory);
    int n = dormitory->blockCount;
    while ((n > 0) &&
           (cmpBlock(*&dormitory->blockarray[n-1],*block)>0)){
        n--;
    }
    memcpy (&dormitory->blockarray[n], block, sizeof(Block));
    dormitory->blockCount++;
    delete block;
}
int addBlockByMenu(void *){
    if(root==NULL){
        cout << "Dormitory was not created!\n";
        pause();
        return 0;
    }
    if(root->blockCount > 30){
        cout << "Block limit exceeded, you can no longer add new blocks\n";
        pause();
        return 0;
    }
    int NB = getInt("Enter number of new Block(max 30): ",1,30);
    char *NewStarosta = getStr("Enter new name starosta: ");
    if(strlen(NewStarosta)==0){
        cout << "The name has not changed\n";
    }
    int FL = getInt("Enter Floor of new Block(max 5 floor): ",1,5);
    Block *pB = createBlock(NB,NewStarosta,FL);
    addBlock(root,pB);
    string s;
    string f;
    f = "block ";
    s = IntToString(NB);
    f.append(s).append(" was add ");
    log_file(f);
    return 1;
}

void addRoom (Block *pB, Room *pR){
    pR->parent = pB;
    if (pB->arSize == pB->countRoom)
        growRoomAr (pB);
    int n = pB->countRoom;
    while (n>0 && cmpRoom (*pB->pRoomArray[n-1], *pR)>0){
        pB->pRoomArray[n] = pB->pRoomArray[n-1];
        n--;
    }
    pB->pRoomArray[n] = pR;
    pB->countRoom++;
}
int addRoomByMenu(void *ptr){
    Block *pB = (Block*)ptr;
    if(ptr==NULL){
        cout << "Block was not created! \n";
        pause();
        return 0;
    }
    if(pB->countRoom > 200){
        cout << "Number of rooms exceeded, you can no longer add new rooms\n";
        pause();
        return 0;
    }
    int NR = getInt("Enter number of new Room(max 200): ",1,200);
    int KL = getInt("Enter kilkist lizok(max 5): ",1,5);
    float SQ;
    cout << "Enter square(max 100): ";cin>>SQ;
    Room *r  = createRoom(NR,KL,SQ);
    addRoom(pB,r);
    string f = "Room ";
    string s = IntToString(NR);
    s.append(" was add");
    f.append(s);
    log_file(f);
    return 1;
}

void addInhab (Room *pR, Inhabitant *pIn){
    pIn->parent = pR;
    pIn->nextInhab = NULL;
    if (pR->firstInhab == NULL)
        pR->firstInhab = pIn;
    else if (cmpInhab (*pIn, *pR->firstInhab)<0){
        pIn->nextInhab = pR->firstInhab;
        pR->firstInhab = pIn;
    }
    else {
        Inhabitant *p = pR->firstInhab;
        while (p->nextInhab != NULL && cmpInhab (*pIn, *p->nextInhab)>=0)
            p = p->nextInhab;
        pIn->nextInhab = p->nextInhab;
        p->nextInhab = pIn;
    }
}
int addInhabByMenu(void *ptr){
    Room *pR = (Room*)ptr;
    if(ptr==NULL){
        cout << "Room was not created!\n";
        pause();
        return 0;
    }
    Inhabitant *p = pR->firstInhab;
    int x = 0;
    while(p!=NULL){
        x++;
        p = p->nextInhab;
    }
    if(x==pR->KilkistLizok){
        cout << "The maximum number of people lives in the room, you cannot add a new one\n";
        pause();
        return 0;
    }
    char *NewName = getStr("Enter new name inhabitant: ");
    if(strlen(NewName)==0){
        cout << "The name was not changed\n";
    }
    int YR = getInt("Enter year to room(min 2000, max 2020): ",2000,2020);
    char *NewFac = getStr("Enter facult of inhabitant: ");
    if(strlen(NewFac)==0){
        cout << "The faacult was not changed\n";
    }
    Inhabitant *i = createInhabitant (NewName,YR,NewFac);
    addInhab(pR,i);
    string s = "Inhabitant ";
    string f = NewName;
    f.append(" was add");
    s.append(f);
    log_file(s);
    return 1;
}
