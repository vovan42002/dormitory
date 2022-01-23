#include <type.h>

Inhabitant *delInhab (Inhabitant *pDel){
    Room *pR = pDel->parent;
    if (pDel == pR->firstInhab) {
        pR->firstInhab = pR->firstInhab->nextInhab;
        return pDel;
    }
    Inhabitant *pPred = pR->firstInhab;
    while (pPred->nextInhab!=NULL){
        if (pPred->nextInhab == pDel){
            pPred->nextInhab = pPred->nextInhab->nextInhab;
            return pDel;
        }
        pPred = pPred->nextInhab;
    }
    return NULL;
}
int delInhabByMenu (void *ptr){
    Inhabitant *pI = (Inhabitant*)ptr;
    Room *pR = pI->parent;
    string s = "Inhabitant ";
    string f = pI->name;
    f.append(" was deleted");
    s.append(f);
    if (delInhab(pI)!=NULL){
        delete pI->name;
        delete pI;
        pI = NULL;
    }
    showInhabList (pR);
    log_file(s);
    return 1;
}
void delAllInhab (Room *pRoom){
    Inhabitant *pI = pRoom->firstInhab;
    while (pI!=NULL){
        Inhabitant *toDel = pI;
        pI = pI->nextInhab;
        delete toDel->name;
        delete toDel;
    }
    pRoom->firstInhab = NULL;
}
int delAllInhabByMenu (void *ptr){
    Room *pR = (Room*)ptr;
    delAllInhab(pR);
    showInhabList(pR);
    log_file("Delete all inhabitant ");
    return 0;
}

Room *delRoom (Room *pDel){
    Block *pB = pDel->parent;
    delAllInhab(pDel);
    for (int delIdx = 0;delIdx < pB->countRoom ; delIdx++){
        if (pB->pRoomArray[delIdx] == pDel){
            for (int i = delIdx; i < pB->countRoom-1;i++)
                pB->pRoomArray[i] = pB->pRoomArray[i+1];
            pB->countRoom--;
            return pDel;
        }
    }
    return NULL;
}
int delRoomByMenu (void *ptr){
    Room *pR = (Room*)ptr;
    Block *pB = pR->parent;
    string s = "Room ";
    string f = IntToString(pR->NumberRoom);
    f.append(" was deleted");
    s.append(f);
    if (delRoom(pR)!=NULL){
        delete pR;
        pR = NULL;
    }
    showRoomList(pB);
    log_file(f);
    return 1;
}

void delAllRoom (Block *pB){
    for (int i =0; i<pB->countRoom;i++){
        delRoom(pB->pRoomArray[i]);
    }
    pB->countRoom = 0;
}
int delAllRoomByMenu (void *ptr){
    Block *pB = (Block*)ptr;
    delAllRoom(pB);
    showRoomList(pB);
    log_file("Delete all room");
    return 0;
}

Block *delBlock (Block *pB){
    Dormitory *pD = pB->parent;
    Block *delB = new Block();
    memcpy (delB, pB, sizeof(Block));
    for (int delIdx = 0; delIdx < root->blockCount; delIdx++){
        if (&pD->blockarray[delIdx] == pB){
            delAllRoom(pB);
            delete pB->pRoomArray;
            for (int i = delIdx; i<(pD->blockCount - 1);i++)
                pD->blockarray[i] = pD->blockarray[i+1];
            pD->blockCount--;
            return delB;
        }
    }
    return NULL;
}
int delBlockByMenu (void *ptr){
    Block *pB = (Block*)ptr;
    string s = "Block ";
    string f = IntToString(pB->Numblock);
    f.append(" was deleted");
    s.append(f);
    Dormitory *pD = pB->parent;
    Block *delB = delBlock(pB);
    if (delB!=NULL){
        delete delB;
        delB = NULL;
    }
    showBlockList(pD);
    log_file(s);
    return 1;
}

void delAllBlock (Dormitory *pD){
    for (int i = 0;i<pD->blockCount;i++){
        delAllRoom(&(pD->blockarray[i]));
    }
    root->blockCount = 0;
}

int delAllBlockByMenu (void *ptr){
    delAllBlock(root);
    showBlockList(root);
    log_file("Delete all block ");
    return 0;
}

int delTree (void *){
    if (root!=NULL){
        delAllBlock (root);
        delete []root->blockarray;
        delete root;
        root = NULL;
    }
    log_file("Delete tree ");
    return 0;
}
