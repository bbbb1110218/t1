//
//  main.cpp
//  obj1
//
//  Created by macbookpro on 2023/1/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct SS{
    string name;
    int age;
};

typedef vector<SS> Vs;

bool FillStruct(SS &s);

void ShowStruct(SS& s);

bool fuck(const SS&s1,const SS &s2);



int main(int argc, const char * argv[]) {
    Vs Varr;
    SS temp;
    while(FillStruct(temp))
        Varr.push_back(temp);
     
    int length=static_cast<int>(Varr.size());
    
    if(length >3){
        cout << "----first show------\n";
        for_each(Varr.begin(), Varr.end(), ShowStruct);
        // cout << "----aftee erase------\n";
        // Varr.erase(Varr.begin()+1,Varr.begin()+3);

        // for_each(Varr.begin(), Varr.end(), ShowStruct);

        cout << "----After soring-----\n";
        sort(Varr.begin(),Varr.end(),fuck);
        for_each(Varr.begin(), Varr.end(), ShowStruct);
        
    }
    
   
};


bool FillStruct(SS &s){
    cout <<"please enter the name:";
    cin >>s.name;
    if(s.name=="q"){
        return false;
    }
    cout <<"please enter the age:";
    cin >> s.age;
    
    if(!cin)
        return false;
    
    while(cin.get() !='\n');
    return true;
    
}

void ShowStruct(SS& s){
    cout <<s.name <<"\t" << s.age<<endl;
}

bool fuck(const SS&s1,const SS &s2){
    return s1.age > s2.age;

}

