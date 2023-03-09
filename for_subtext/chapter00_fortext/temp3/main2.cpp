#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(){

    string arr[3]={string("hello"),string("kitty"),string("fuckyou,bitch")};
    string temp;
    char tempc[20];
    int tempi;
    char None='\0';

    ofstream fout("temp.dat",ios_base::out|ios_base::binary|ios_base::trunc);
    for(int i=0;i<3;i++){
        int size=arr[i].length();
        fout.write((char *)&size,sizeof(int));
        fout.write(&None,1);
        fout.write((char *)&arr[i],size+1);
    }
    fout.close();


    ifstream fin;
    fin.open("temp.dat",ios_base::in|ios_base::binary);

    for(int i=0;i<3;i++){
        fin.read((char*)&tempi,sizeof(int));
        fin.read(&None,1);
        fin.read(tempc,tempi+1);
        tempi[tempc+1]='\0';
        cout << "Size : " << tempi << " ,value : " << tempc << endl;
    }
    fin.close();
    return 0;




}