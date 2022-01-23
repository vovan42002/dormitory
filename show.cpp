#include <type.h>

int showDormitoryInfo (void *){
    system("cls");
    cout << "---------Dormitory Information--------"<<endl;
    if (root == NULL)
        cout << "Tree was not created!\n";
    else{
        cout << " Dormitory addres is: ";
        cout << root->Addres<<endl;
        cout << " Build year: ";
        cout << root->buildYear<<endl;
        cout << " Commandant: ";
        cout << root->Commandant<<endl;
    }
    pause();
    return 0;
}

int showBlockInfo (void *ptr){
    Block *pB = (Block*)ptr;
    system("cls");
    cout << "--- Block Information ----\n";
    cout << " Number of Block: " << pB->Numblock<<endl;
    cout << " Floor of Block: " << pB->Floor<<endl;
    cout << " Starosta: " << pB->Starosta<<endl;
    pause();
    return 0;
}

int showRoomInfo (void *ptr){
    Room *pR = (Room*)ptr;
    system("cls");
    cout << "----- Block " << pR->parent->Numblock<<"----\n";
    cout << " Number of Room: " << pR->NumberRoom << endl;
    cout << " Kilkist lizok: " << pR->KilkistLizok << endl;
    cout << " Square: " << pR->Square << endl;
    pause ();
    return 0;
}

int showInhabInfo (void *ptr){
    if (ptr == NULL)return 1;
    Inhabitant *pI = (Inhabitant*)ptr;
    system("cls");
    cout << "---Block "<<pI->parent->parent->Numblock <<"---\n";
    cout << "---Room " << pI->parent->NumberRoom <<"---\n";
    cout << " Inhabitant name: " << pI->name << endl;
    cout << " Year to room: " << pI->YeartoRoom << endl;
    cout << " Facult: " << pI->Facult << endl;
    pause();
    return 0;
}

int showBlockList (void *ptr){
    system ("cls");
    cout << "----List of block ----"<<endl;
    printBlockList();
    pause();
    return 0;
}

int showRoomList (void *ptr){
    Block *pB = (Block*)ptr;
    system("cls");
    cout << "\tBlock "<< pB->Numblock << endl;
    cout << "\tList of Room\n";
    printRoomList(pB);
    pause();
    return 0;
}

int showInhabList (void *ptr){
    system("cls");
    Room *r = (Room*)ptr;
    cout <<"\tRoom " << r->NumberRoom <<endl;
    cout <<"\tList of inhabitant \n";
    printInhabList(r);
    pause();
    return 0;
}

























