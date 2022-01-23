#include <type.h>

int createDefaultTree (void *) {
    if(root != NULL) delTree(NULL);
    root = createDormitory (1999, "Viktoria Vasylivna", "Shevchenka 99") ;
    Block *block1 = createBlock (1,"Vasya",1);
    Block *block2 = createBlock (2, "Volodya", 1);
    Block *block3 = createBlock (3, "Vlad", 2);
    Block *block4 = createBlock (5, "Valera", 4);
    addBlock (root, block1);
    addBlock (root, block2);
    addBlock (root, block3);
    addBlock (root, block4);
    Room *r1 = createRoom (1, 3, 54.1);
    Room *r2 = createRoom (2, 2, 45.2);
    Room *r3 = createRoom (44, 3, 20.3);
    Room *r4 = createRoom (144, 2, 25.5);
    addRoom (&root->blockarray[0],r4);
    addRoom (&root->blockarray[1],r3);
    addRoom (&root->blockarray[2],r2);
    addRoom (&root->blockarray[3],r1);
    Inhabitant *i1 = createInhabitant("Vova Bohdan",2019, "KI");
    Inhabitant *i2 = createInhabitant ("Valera Kravchenko", 2019, "KI");
    Inhabitant *i3 = createInhabitant ("Vlad Krivoshey", 2019, "VT");
    Inhabitant *i4 = createInhabitant ("Evgeniy ", 2018, "KB");
    Inhabitant *i5 = createInhabitant ("Vadim Kotenko", 2018, "EM");
    addInhab (r1,i1);
    addInhab (r1,i5);
    addInhab (r4,i4);
    addInhab (r2,i2);
    addInhab (r3,i3);
    showTree(NULL);
    log_file("Create default tree ");
    return 0;
}
int showTree (void *) {
    system ("cls");
    cout << "___Tree structure ____\n";
    if (root == NULL) {
        cout<< "Tree does not exist \n";
        pause();
        return 0;
    }
    cout << " Commandant: " << root->Commandant <<"  Year build: "<< root->buildYear << " Addres: "<<root->Addres<<endl;
    Block *bAr = root->blockarray;
    for (int i=0; i < root->blockCount; i++) {
        printf("\nBlock: %-3d Floor: %-5d Starosta: %-8s \n", bAr[i].Numblock,bAr[i].Floor,bAr[i].Starosta);
        Room **rpAr = bAr[i].pRoomArray;
        for (int j =0; j< bAr[i].countRoom ; j++) {
            cout <<"\n\tNumber of room: "<<rpAr[j]->NumberRoom <<"  Kilkist lizok: "<<rpAr[j]->KilkistLizok << "  Square: "<<rpAr[j]->Square<<endl;
            Inhabitant *pI = rpAr[j]->firstInhab;
            while (pI != NULL) {
                cout << "\t\t\tName: "<<pI->name <<" Year to room: "<<pI->YeartoRoom<<" Facult: "<<pI->Facult<<endl;
                pI = pI->nextInhab;
            }
        }
    }
    pause();
    return 0;
}
void storeTree (FILE *f){
    fwrite(root, sizeof(Dormitory),1,f);
    Block *bAr = root->blockarray;
    for (int i =0; i<root->blockCount;i++){
        fwrite(&bAr[i],sizeof(Block),1,f);
        Room **pfAr = bAr[i].pRoomArray;
        for (int j =0; j <bAr[i].countRoom; j++){
            fwrite(pfAr[j],sizeof(Room),1,f);
            Inhabitant *pI = pfAr[j]->firstInhab;
            while(pI!=NULL){
                fwrite(pI,sizeof(Inhabitant),1,f);
                int len = strlen(pI->name)+1;
                fwrite(&len,sizeof(int),1,f);
                fwrite(pI->name,sizeof(char),len,f);
                len = strlen(pI->Facult)+1;
                fwrite(&len,sizeof(int),1,f);
                fwrite(pI->Facult,sizeof(char),len,f);
                pI = pI->nextInhab;
            }
        }
    }fclose(f);
}
int storeTreeByMenu(void *){
    system("cls");
    cout << "\t--- Restoring the tree from a file ---\n";
    char* fileName = getStr("Enter file name: ");
    FILE *f=fopen(fileName,"wb");
    storeTree(f);
    string s;
    s = "Tree store to file ";
    s.append(fileName);
    log_file(s);
    pause();
    return 0;
}
void restoreFromFile (FILE *f){
    if(root == NULL){
        delTree(NULL);
    }
    root = new Dormitory();
    fread(root,sizeof(Dormitory),1,f);
    root->blockarray = new Block[root->arSize];
    for(int i=0;i < root->blockCount;i++){
        fread(&root->blockarray[i],sizeof(Block),1,f);
        Block *un = &root->blockarray[i];
        un->parent = root;
        un->pRoomArray = new Room*[un->arSize];
        for(int j=0;j < un->countRoom; j++){
            Room *fc = new Room();
            fread(fc,sizeof(Room),1,f);
            fc->parent = un;
            un->pRoomArray[j] = fc;
            if(fc->firstInhab!=NULL){
                Inhabitant *dp = new Inhabitant();
                fread(dp,sizeof(Inhabitant),1,f);
                dp->parent = fc;
                fc->firstInhab = dp;
                int len;
                fread(&len,sizeof(int),1,f);
                char *dName = new char[len];
                fread(dName,sizeof(char),len,f);
                dp->name = dName;
                fread(&len,sizeof(int),1,f);
                char *dFac = new char[len];
                fread(dFac,sizeof(char),len,f);
                dp->Facult = dFac;
                while(dp->nextInhab!=NULL){
                    Inhabitant *dpnxt = new Inhabitant();
                    fread(dpnxt,sizeof(Inhabitant),1,f);
                    dp->parent = fc;
                    dp->nextInhab = dpnxt;
                    dp = dpnxt;
                    int len;
                    fread(&len,sizeof(int),1,f);
                    char *dName = new char[len];
                    fread(dName,sizeof(char),len,f);
                    dp->name = dName;
                    fread(&len,sizeof(int),1,f);
                    char *dFac = new char[len];
                    fread(dFac,sizeof(char),len,f);
                    dp->Facult = dFac;
                }
            }
        }
    }
    fclose(f);
}

int restoreTreeByMenu(void *){
    system("cls");
    cout << "\t--- Restoring the tree from a file ---\n";
    char* fileName = getStr("Enter file name: ");
    FILE *f;
    if((f = fopen(fileName, "rb")) == NULL){
        cout << " Error opening file " << fileName << endl;
        pause();
        return 1;
    }
    restoreFromFile(f);
    string s = "Tree restore from file ";
    s.append(fileName);
    log_file(s);
    showTree(NULL);
    return 0;
}
void log_file(string s)
{
    time_t t = time(NULL);
    ofstream fout;
    fout.open( "Log.txt", ofstream::app);
    if (!fout.is_open())
        cout << "Could not open the file!";
    else
    {
        fout << s << " at " << ctime(&t);
    }
    fout.close();
}
int showLogFile(void *){
    cout << "show log file\n";
    ifstream fin;
    fin.open ( "Log.txt", ofstream::app);
    if (!fin.is_open())
        cout << "Could not open the file!\n";
    else
    {
        cout << "File is open\n";
        char ch;
        while (fin.get(ch))
        {
            cout << ch;
        }
    }
    pause();
    return 1;
}
