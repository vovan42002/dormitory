#include <type.h>

int mainMenu (void *ptr){
    //create and run menu
    MenuUnit menu[]= {
        {"Dormitory operation", menuDormitory},
        {"Block operation", menuBlock},
        {"Room operation", menuRoom},
        {"Inhabitant operation", menuInhabitant},
        {"Tree operation", menuTree},
        {"Query operation", menuQuery},
        {"Exit",NULL} };
    runMenu(menu, "\n  --- Main menu ----",ptr);
    return 0;
}
int menuDormitory (void *){
    MenuUnit menu [] = {
        {"Create root", createRoot},
        {"Show dormitory informtion", showDormitoryInfo},
        {"Edit dormitory information", editDormitoryByMenu},
        {"Add block",addBlockByMenu},
        {"Show list of block",showBlockList},
        {"Delete all block",delAllBlockByMenu},
        {"Return to main menu",NULL} };
    runMenu(menu,"\n ------ Dormitory operation ------",NULL);
    return 0;
}
int menuBlock (void *){
    MenuUnit menu [] = {
        {"Show block information",showBlockInfo},
        {"Edit block information",editBlockByMenu},
        {"Delete block",delBlockByMenu},
        {"Add room",addRoomByMenu},
        {"Show list of room",showRoomList},
        {"Delete all rooms",delAllRoomByMenu},
        {"Return to main menu",NULL}
    };
    Block *pB = selectBlock();
    if (pB == NULL)return 1;
    string menuName = " ---- block ";
    string dop = IntToString(pB->Numblock);
    menuName.append(dop).append(" ----");
    runMenu(menu,menuName,pB);
    return 0;
}
int menuRoom (void *){
    Block *pB = selectBlock();
    if(pB == NULL)return 1;
    Room *pR = selectRoom(pB);
    if(pR == NULL)return 1;
    MenuUnit menu[] = {
        {"Show Room information",showRoomInfo},
        {"Edit Room information",editRoomByMenu},
        {"Delete Room",delRoomByMenu},
        {"Add Inhbitant", addInhabByMenu},
        {"Show list of Inhabitant",showInhabList},
        {"Delete all Inhabitant",delAllInhabByMenu},
        {"Return to main menu",NULL}
    };
    string menuName = "\n ---room ";
    string dop = IntToString(pR->NumberRoom);
    menuName.append(dop).append(" ------");
    runMenu(menu,menuName,pR);
    return 0;
}

int menuInhabitant (void *){
    Block *pB = selectBlock();
    if(pB == NULL)return 1;
    Room *pR = selectRoom(pB);
    if(pR == NULL)return 1;
    Inhabitant *pI = selectInhabitant(pR);
    if(pI == NULL)return 1;
    string menuName = "\n ---- Inhabitant ";
    menuName.append(pI->name).append(" -----");
    MenuUnit menu[] = {
        {"Show Inhabitant information",showInhabInfo},
        {"Edit Inhabitant information",editInhabitantByMenu},
        {"Delete Inhabitant",delInhabByMenu},
        {"Return to main menu",NULL}
    };
    runMenu(menu,menuName,pI);
    return 0;
}
int menuTree (void *ptr){
    MenuUnit menu[] = {
        {"Create default Tree",createDefaultTree},
        {"Show Tree",showTree},
        {"Store to file",storeTreeByMenu},
        {"Restore Tree from file",restoreTreeByMenu},
        {"Show log file",showLogFile},
        {"Return to main menu",NULL}};
    runMenu(menu, "\n ---- Tree operation ---- ",ptr);
    return 0;
}
int menuQuery (void *){
    MenuUnit menu[] = {
        {"Find block with biggest number of inhbitant",findBiggestBlockByInhab},
        {"Find room by number and output information",findRoomForInfor},
        {"Find inhabitant by name",findInhabByName},
        {"Find inhabitant by Year to room",findInhabByYear},
        {"Return to main menu",NULL}
    };
    runMenu(menu, "\n ---- Query Operation ----",NULL);
    return 0;
}
Block *selectBlock (){
    system("cls");
    cout << "\n ----- Block selection ----\n";
    int nBlock = printBlockList();
    cout << " " << nBlock +1 << " Exit.\n";
    int num = getInt("Enter your choice: ",1,nBlock + 1);
    if (num == nBlock + 1)
        return NULL;
    return root->blockarray + num - 1;
}
Room *selectRoom (Block *pB){
    system("cls");
    cout << "\n --- Block " <<pB->Numblock << " -----\n";
    cout << " ---- Room selection ----\n";
    int nRoom = printRoomList (pB);
    cout << " " << nRoom + 1 << " Exit."<<endl;
    int num = getInt (" Enter your choice: ",1, nRoom + 1);
    if (num == nRoom + 1)
        return NULL;
    return pB->pRoomArray[num -1];
}
Inhabitant *selectInhabitant (Room *pR){
    system("cls");
    cout << "\n ---- Block "<<pR->parent->Numblock <<" ----\n";
    cout << " ----- Room " << pR->NumberRoom << " -----\n";
    cout << "------ Inhabitant selection -----\n";
    int nInhab = printInhabList(pR);
    cout << " " << nInhab + 1 << " Exit.\n";
    int num = getInt(" Enter your choice: ",1,nInhab + 1);
    if (num == nInhab + 1)
        return NULL;
    Inhabitant *pI = pR->firstInhab;
    for (int i = 1; i<num; i++)
        pI = pI->nextInhab;
    return pI;
}

int printBlockList (){
    if (root == NULL)
        return 0;
    Block *pB = root->blockarray;
    int n = root->blockCount;
    if (n ==0)
        cout << "   Block list is empty! \n";
    else
        for(int i = 1; i<=n;i++,pB++){
        cout << " " <<  i << " Number of Block: "
                <<pB->Numblock<<" Starosta: "
                <<pB->Starosta<<"   Floor: "<<pB->Floor<<endl;
    }
    return n;
}
int printRoomList (Block *pB){
    int n = pB->countRoom;
    Room ** pR = pB->pRoomArray;
    for (int i=1;i<=n;i++,pR++){
        cout <<" "<<i <<" Number of room: " << (*pR)->NumberRoom
                <<"  Kilkist lizok: " <<(*pR)->KilkistLizok
                <<"  Square: "<<(*pR)->Square<<endl;
    }
    return n;
}
int printInhabList (Room *pR){
    int n = 1;
    Inhabitant *pI = pR->firstInhab;
    for (;pI!=NULL;n++){
        cout <<" "<<n <<" Name: " << pI->name <<"  Year to room: " <<pI->YeartoRoom << "  Facult: " << pI->Facult<<endl;
        pI = pI->nextInhab;
    }
    return n-1;
}

void runMenu (MenuUnit menu[],string menuName,void *ptr){
    while(true){
        system("cls");
        cout << menuName << endl;
        int cnt = 0;
        for(;; cnt++){
            cout << " " << cnt + 1 <<". "
                    << menu[cnt].text<<endl;
            if(menu[cnt].func == NULL)
                break;
        }
        int v = getInt(" Enter your choice number: ",
                       1, cnt + 1);
        if(menu[v - 1].func == NULL)
            break;
        int result = menu[v - 1].func(ptr);
        if( result != 0){
            break;
        }
    }
}
