#include <type.h>

int findBiggestBlockByInhab (void *){
    system ("cls");
    cout << "------- Finding the block with the highest number of inhabitans -----\n";
    if (root == NULL) {
        cout<< "Tree does not exist \n";
        pause();
        return 0;
    }
    Block *pB = root->blockarray;
    int x = 0,y = 0;
    for (int i=0; i < root->blockCount; i++) {
        Room **rpAr = pB[i].pRoomArray;
        for (int j =0; j< pB[i].countRoom ; j++) {
            Inhabitant *pI = rpAr[j]->firstInhab;
            while (pI != NULL) {
                pI = pI->nextInhab;
                x++;
            }
        }
        if(x>y)
            y = x;
        x = 0;
    }
    for (int i = 0; i < root->blockCount; i++){
        Room **rpAr = pB[i].pRoomArray;
        for (int j = 0; j < pB[i].countRoom; j++){
            Inhabitant *pI = rpAr[j]->firstInhab;
            while (pI != NULL){
                x++;
                pI = pI->nextInhab;
            }
        }
        if(x == y)
              cout << "\nBlock: "<<pB[i].Numblock<<" have the highest number of inhabitant"<<endl;
        x = 0;
    }
    pause();
    return 1;

}

int findRoomForInfor (void *){
    system ("cls");
    cout << "___Finding information by number room ____\n";
    if (root == NULL) {
        cout<< "Tree does not exist \n";
        pause();
        return 0;
    }
    int x = 0;
    cout << "Enter number of room for finding information(1 - 200): ";
    cin >> x;
    bool ok = true;
    Block *bAr = root->blockarray;
    for (int i=0; i < root->blockCount; i++) {
        Room **rpAr = bAr[i].pRoomArray;
        for (int j =0; j< bAr[i].countRoom ; j++) {
            if(rpAr[j]->NumberRoom == x){
                ok = false;
                cout <<"\n\tNumber of room: "<<rpAr[j]->NumberRoom <<"  Kilkist lizok: "<<rpAr[j]->KilkistLizok << "  Square: "<<rpAr[j]->Square<<endl;
            }
        }
    }
    if(ok == true){
        cout << "\n No number was found for this room\n";
    }
    pause();
    return 1;
}

int findInhabByName (void *){
    system ("cls");
    cout << "___Finding information about inhbitant by his name ____\n";
    if (root == NULL) {
        cout<< "Tree does not exist \n";
        pause();
        return 0;
    }
    string s;
    cout << "Enter name for finding information by this name: ";
    getline(cin,s);
    bool ok = true;
    Block *bAr = root->blockarray;
    for (int i=0; i < root->blockCount; i++) {
        Room **rpAr = bAr[i].pRoomArray;
        for (int j =0; j< bAr[i].countRoom ; j++) {
            Inhabitant *pI = rpAr[j]->firstInhab;
            while (pI != NULL) {
                if(s == pI->name){
                    ok = false;
                    cout << "\t\t\tName: "<<pI->name <<" Year to room: "<<pI->YeartoRoom<<" Facult: "<<pI->Facult<<endl;
                }
                pI = pI->nextInhab;
            }
        }
    }
    if(ok == true){
        cout << "\n Nothing was found by that name\n";
    }
    pause();
    return 1;
}

int  findInhabByYear (void *){
    system ("cls");
    cout << "___Finding information about inhbitant by year to room ____\n";
    if (root == NULL) {
        cout<< "Tree does not exist \n";
        pause();
        return 0;
    }
    int x = 0;
    cout << "Enter the year to find information about the occupants of this year : ";
    cin >> x;
    bool ok = true;
    Block *bAr = root->blockarray;
    for (int i=0; i < root->blockCount; i++) {
        Room **rpAr = bAr[i].pRoomArray;
        for (int j =0; j< bAr[i].countRoom ; j++) {
            Inhabitant *pI = rpAr[j]->firstInhab;
            while (pI != NULL) {
                if(pI->YeartoRoom == x){
                    ok = false;
                    cout << "\t\t\tName: "<<pI->name <<" Year to room: "<<pI->YeartoRoom<<" Facult: "<<pI->Facult<<endl;
                }
                pI = pI->nextInhab;
            }
        }
    }
    if(ok == true){
        cout << "\n No residents were found this year \n";
    }
    pause();
    return 1;
}
