#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

char foglaltsagArray[15][20];
char kategoriaArray[15][20];

void t2(){
    int rowNum = 0;
    int chairNum = 0;

    cout<<"Adjon meg egy sorszamot: ";
    cin>>rowNum;
    cout<<"Adjon meg egy szekszamot: ";
    cin>>chairNum;

    rowNum--;
    chairNum--;

    if(foglaltsagArray[rowNum][chairNum] == 'x'){
        cout<<"Foglalt"<<endl;
    }else{
        cout<<"Ures"<<endl;
    }
}
void t3(){
    double allTickets = 300;
    double purchasedTickets = 0;

    for(int row=0; row<15; row++){
        for(int chair=0; chair<20; chair++){
            if(foglaltsagArray[row][chair] == 'x'){
                purchasedTickets++;
            }
        }
    }
    double percentage = round((purchasedTickets/allTickets)*100);
    cout<<"Az eloadasra eddig "<<purchasedTickets<<" jegyet adtak el, ez a nezoter "<<percentage<<"%-a."<<endl;
}
void t4(){
    int cat[5];
    for(int row=0; row<15; row++){
        for(int chair=0; chair<20; chair++){
            char temp = kategoriaArray[row][chair];
            if(temp == '1'){
                cat[0]++;
            }else if(temp == '2'){
                cat[1]++;
            }else if(temp == '3'){
                cat[2]++;
            }else if(temp == '4'){
                cat[3]++;
            }else if(temp == '5'){
                cat[4]++;
            }
        }
    }

    int maxHely = 0;
    for(int i=0; i<5; i++){
        if(cat[i]>cat[maxHely]){
            maxHely=i;
        }
    }
    cout<<"A legtobb jegyet a(z) "<<maxHely+1<<". arkategoriaban ertekesitettek."<<endl;
}
void t5(){
    int sum = 0;

    for(int row=0; row<15; row++){
        for(int chair=0; chair<20; chair++){
            if(foglaltsagArray[row][chair] == 'x'){
                char temp = kategoriaArray[row][chair];
                if(temp == '1'){
                    sum+=5000;
                }else if(temp == '2'){
                    sum+=4000;
                }else if(temp == '3'){
                    sum+=3000;
                }else if(temp == '4'){
                    sum+=2000;
                }else if(temp == '5'){
                    sum+=1500;
                }
            }
        }
    }

    cout<<"Jelenlegi bevetel: "<<sum<<"Ft."<<endl;
}
void t6(){
    int sum = 0;

    for(int row=0; row<15; row++){
        for(int chair=0; chair<20; chair++){
            if(foglaltsagArray[row][chair] == 'o'){
                if(foglaltsagArray[row][chair-1] == 'x' && foglaltsagArray[row][chair+1] == 'x'){
                    sum++;
                }
            }
        }
    }
    cout<<"Egyedulallo szekek szama: "<<sum<<endl;
}
void t7(){
    ofstream fileOutput("szabad.txt");

    char szabadArray[15][20];
    for(int row=0; row<15; row++){
        for(int chair=0; chair<20; chair++){
            szabadArray[row][chair] = foglaltsagArray[row][chair];
        }
    }

    for(int row=0; row<15; row++){
        for(int chair=0; chair<20; chair++){
            if(szabadArray[row][chair] == 'o'){
                szabadArray[row][chair] = kategoriaArray[row][chair];
            }
        }
    }

    for(int row=0; row<15; row++){
        for(int chair=0; chair<20; chair++){
            fileOutput<<szabadArray[row][chair];
        }
        fileOutput<<"\n";
    }
}

int main(){
    ifstream foglaltsagInp("foglaltsag.txt");
    ifstream kategoriaInp("kategoria.txt");

    int lineNum1 = 0;
    int lineElement1 = 0;
    if(foglaltsagInp.is_open()){
        while(!foglaltsagInp.eof()){
            if(lineElement1>19){
                lineElement1 = 0;
                lineNum1++;
            }else{
                foglaltsagInp>>foglaltsagArray[lineNum1][lineElement1];
                lineElement1++;
            }
        }
    }else{ cout<<"Unable to open file."<<endl; }

    int lineNum2 = 0;
    int lineElement2 = 0;
    if(kategoriaInp.is_open()){
        while(!kategoriaInp.eof()){
            if(lineElement2>19){
                lineElement2 = 0;
                lineNum2++;
            }else{
                kategoriaInp>>kategoriaArray[lineNum2][lineElement2];
                lineElement2++;
            }
        }
    }else{ cout<<"Unable to open file."<<endl; }

    cout<<"1. Feladat"<<endl;
    cout<<"Adatok beolvasva."<<endl;
    cout<<endl;
    cout<<"2. Feladat"<<endl;
    t2();
    cout<<endl;
    cout<<"3. Feladat"<<endl;
    t3();
    cout<<endl;
    cout<<"4. Feladat"<<endl;
    t4();
    cout<<endl;
    cout<<"5. Feladat"<<endl;
    t5();
    cout<<endl;
    cout<<"6. Feladat"<<endl;
    t6();
    cout<<endl;
    cout<<"7. Feladat"<<endl;
    t7();
    cout<<"Fajl elmentve."<<endl;
    cout<<endl;
    return 0;
}
