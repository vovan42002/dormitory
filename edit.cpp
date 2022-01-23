#include <type.h>

void sortBlock (Dormitory *pD){
    int n = pD->blockCount;
    Block *ar = pD->blockarray;
    for (int i =1; i<n;i++){
        if(cmpBlock(*&ar[i-1],*&ar[i])>0){
            int j=i; Block b = ar[j];
            do{
                ar[j] = ar[j-1];
                j--;
            }while(j>0 && cmpBlock(*&ar[j], *&b)>0);
            ar[j] = b;
        }
    }
}

void sortRoom (Block *pB){
    int k = pB->countRoom;
    Room **arr = pB->pRoomArray;
    for (int i=1; i<k;i++){
        if (cmpRoom(**&arr[i-1],**&arr[i])>0){
            int j=i;Room *r = arr[j];
            do{
                arr[j] = arr[j-1];
                j--;
            }while(j>0 && cmpRoom(**&arr[j],**&r)>0);
            arr[j] = r;
        }
    }
}

void sortInhab(Room *pR){
    Inhabitant *pN = pR->firstInhab;
    pR->firstInhab = NULL;
    while (pN!= NULL){
        Inhabitant *oldNext =  pN->nextInhab;
        addInhab (pR,pN);
        pN = oldNext;
    }
}
void editDormitory (Dormitory *pD, char *newNameCommandant, char *newAddres, int buildYear){
    strncpy (pD->Commandant, newNameCommandant, SIZE_NAME);
    strncpy (pD->Addres, newAddres, SIZE_ADDRES);
    pD->buildYear = buildYear;
}
int editDormitoryByMenu(void *){
    if(root == NULL)return 1;
    system("cls");
    cout << "---- Dormitory information editing -----\n";
    cout << "Old name commandant is: "<<root->Commandant<<endl;
    char *NewName = getStr("New name commndant is: ");
    if(strlen(NewName) == 0){
        cout << "The name has not been changed\n";
        NewName = root->Commandant;
    }
    cout << "Old addres is: "<<root->Addres<<endl;
    char *NewAddres = getStr("New addres is: ");
    if(strlen(NewAddres)==0){
        cout << "The addres has not changed\n";
        NewAddres = root->Addres;
    }
    cout << "Old build year is: "<<root->buildYear<<endl;
    int Year = getInt("New build year(min 1900, max 2020) is: ",1900,2020);
    editDormitory(root,NewName,NewAddres,Year);
    showDormitoryInfo(root);
    log_file("Edit dormitory ");
    return 0;
}

void editBlock (Block *pB, char *newNameStarosta, int Numblock, int Floor){
    strncpy(pB->Starosta, newNameStarosta, SIZE_NAME);
    pB->Numblock = Numblock;
    pB->Floor = Floor;
    sortBlock (pB->parent);
}
int editBlockByMenu(void *ptr){
    if(ptr == NULL)return 1;
    Block *pB = (Block*)ptr;
    string s = "Block ";
    string f = IntToString(pB->Numblock);
    f.append(" was edited");
    s.append(f);
    system("cls");
    cout << "---- Block information editting ----\n";
    cout << "Old name starosta is: "<<pB->Starosta<<endl;
    char *NameStarosta = getStr("New name starosta is: ");
    if(strlen(NameStarosta)==0){
        cout << "The name has not changed\n";
        NameStarosta = pB->Starosta;
    }
    cout << "Old number of block is: "<<pB->Numblock<<endl;
    int NB = getInt("New number of block(max 30) is: ",1,30);
    cout << "Old floor is: "<<pB->Floor<<endl;
    int FL = getInt("New floor is(max 5): ",1,5);
    editBlock(pB,NameStarosta,NB,FL);
    sortBlock(root);
    showBlockList(pB);
    cout << "\n Please return to main menu for updates \n";
    pause();
    log_file(s);
    return 0;
}

void editRoom (Room *pR, int NumberRoom, int KilkistLizok, float Square){
    pR->NumberRoom = NumberRoom;
    pR->KilkistLizok = KilkistLizok;
    pR->Square = Square;
    sortRoom(pR->parent);
}

int editRoomByMenu(void *ptr){
    if(ptr == NULL ){
        return 1;
    }
    Room *pR = (Room*)ptr;
    string s = "Room ";
    string f = IntToString(pR->NumberRoom);
    f.append(" was edited");
    s.append(f);
    system("cls");
    cout << "---- Room  information editing ----\n";
    cout << " Old number room is: "<<pR->NumberRoom<<endl;
    int NR = getInt("New number of room(max 200) is: ",1,200);
    cout << " Old kilkist lizok is: "<<pR->KilkistLizok<<endl;
    int KL = getInt("New kilkist lizok is(max 5): ",1,5);
    cout << " Old square is: "<< pR->Square<<endl;
    float SQ;
    cout << "New square is(max 100): ";
    cin >> SQ;
    editRoom(pR,NR,KL,SQ);
    showRoomInfo(pR);
    cout << "\n Please return to main menu for updates \n";
    pause();
    log_file(s);
    return 0;
}

void editInhabitant (Inhabitant *pI, char *newName, char *newFacult, int YeartoRoom){
    strncpy (pI->name, newName, SIZE_NAME);
    strncpy (pI->Facult, newFacult, SIZE_FACULT);
    pI->YeartoRoom = YeartoRoom;
    sortInhab(pI->parent);
}
int editInhabitantByMenu (void *ptr){
    if(ptr == NULL)return 1;
    Inhabitant *pI = (Inhabitant*)ptr;
    string s = "Inhabitant ";
    string f = pI->name;
    f.append(" was edited");
    s.append(f);
    system("cls");
    cout << "-------Inhabitant information editing----------\n";
    cout << "Old name inhabitant is: "<<pI->name<<endl;
    char *NewName = getStr("New name inhabitant is: ");
    if(strlen(NewName)==0){
        cout << "The name has not changed\n";
        NewName = pI->name;
    }
    cout << "Old name faculty is: "<<pI->Facult<<endl;
    char *NewFac = getStr("New facult is: ");
    if(strlen(NewFac)==0){
        cout << "The faculty has not changed\n";
        NewFac = pI->Facult;
    }
    cout << "Old year to room is: "<<pI->YeartoRoom<<endl;
    int YR = getInt("New year to room(min 2000, max 2020) is: ",2000,2020);
    editInhabitant(pI,NewName,NewFac,YR);
    showInhabInfo(pI);
    cout << "\n Please return to main menu for updates \n";
    pause();
    log_file(s);
    return 0;
}
