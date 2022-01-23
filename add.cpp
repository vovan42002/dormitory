#include <type.h>

void growBlockAr (Dormitory *pD){
    int newSize = 1.5 * pD->arSize +0.5;
    Block *newAr = new Block[newSize];
    memcpy (newAr, pD->blockarray, pD->arSize*sizeof (Block));
    pD->arSize = newSize;
    Block *oldAr = pD->blockarray;
    pD->blockarray = newAr;
    delete [] oldAr;
}
void growRoomAr (Block *pB){
    int newSize = 1.5 * pB->arSize + 0.5;
    Room * newAr = new Room[newSize];
    memcpy (newAr , pB->pRoomArray , pB->arSize*sizeof(Room));
    pB->arSize = newSize;
    Room *oldAr = *pB->pRoomArray;
    *pB->pRoomArray - newAr;
    delete [] oldAr;
}
int cmpBlock (Block b1, Block b2){
    if (b1.Numblock != b2.Numblock)
        return b1.Numblock - b2.Numblock;
    return b1.Numblock = b2.Numblock;
}
int cmpRoom (Room r1, Room r2){
    if (r1.NumberRoom != r2.NumberRoom)
        return r1.NumberRoom - r2.NumberRoom;
    return r1.NumberRoom = r2.NumberRoom;
}
int cmpInhab (Inhabitant i1, Inhabitant i2){
    if (i1.YeartoRoom != i2.YeartoRoom)
        return i1.YeartoRoom - i2.YeartoRoom;
    return strcmp (i1.name , i2.name);
}
void addBlock (Dormitory *dormitory, Block *block){
    block->parent = dormitory;
    if (dormitory->arSize == dormitory->dormitoryCount)
        growBlockAr (dormitory);
    int n = dormitory->dormitoryCount;
    while ((n > 0) &&
           (cmpBlock(&dormitory->blockarray[n-1],block)>0)){
        n--;
    }
    memcpy (&dormitory->blockarray[n], block, sizeof(Block));
    delete block;
}
void addRoom (Block *pB, Room *pR){
    pR->parent = pB;
    if (pB->arSize == pB->countBlock)
        growRoomAr (pB);
    int n = pB->countBlock;
    while (n>0 && cmpRoom (pB->pRoomArray[n-1], pR)>0){
        pB->pRoomArray[n] = pB->pRoomArray[n-1];
        n--;
    }
    pB->pRoomArray[n] = pR;
    pB->countBlock++;
}
void addInhab (Room *pR, Inhabitant *pIn){
    pIn->parent = pR;
    pIn->nextInhab = NULL;
    if (pR->firstInhab == NULL)
        pR->firstInhab = pIn;
    else if (cmpInhab (pIn, pR->firstInhab)<0){
        pIn->nextInhab = pR->firstInhab;
        pR->firstInhab = pIn;
    }
    else {
        Inhabitant *p = pR->firstInhab;
        while (p->nextInhab != NULL && cmpInhab (pIn, p->nextInhab)>=0)
            p = p->nextInhab;
        pIn->nextInhab = p->nextInhab;
        p->nextInhab = pIn;
    }
}
