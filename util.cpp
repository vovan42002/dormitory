#include <type.h>

void pause(){
    cout <<"Press any key to continue! \n" ;
    getch();
}
int getInt  (string promt, int min, int max){
    int num;string s;
    do {
        cout << promt;
        getline(cin,s);
        num = atoi(s.c_str());
    }while(num<min || num>max);
    return num;
}

float getFloat  (string promt, float min, float max){
    float num;string s;
    do {
        cout << promt;
        getline(cin,s);
        num = atoi(s.c_str());
    }while(num<min || num>max);
    return num;
}

char *getStr (string promt){
    cout << promt;
    string s;
    getline(cin,s);
    char *cStr = new char[s.length() +1];
    strcpy(cStr,s.c_str());
    return cStr;
}

string IntToString(int a){
    string temp;
    int i = 0;
    while (a != 0){
        int b = a/10;
        int c = a - b*10;
        a /= 10;
        char s = 48+c;
        temp += s;
        i++;
    }
    for (int i = 0, j = temp.size()-1; i < temp.size()-1; i++, j--){
        char s = temp[i];
        temp[i] = temp[j];
        temp[j] = s;
        if (i-j == 0){
            break;
        }
    }
    return temp;
}
