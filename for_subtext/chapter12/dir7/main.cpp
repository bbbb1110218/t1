//
// Created by macbookpro on 2022/12/6.
//
#include <iostream>
using namespace  std;
#include "string2.h"

int main(){
    String s1(" and I am a c++ student.");
    String s2="please enter your name:";
    String s3;
    cout << s2;
    cin >> s3;
    s2="My name is " + s3;
    cout << s2 <<".\n";

    s2=s2+s1;  //TODO::这步骤错了

    s2.stringup();
    cout <<"The string\n" << s2 << "\n contains " << s2.has('A')
        <<" \'A\' Characters in it .\n";

    s1="red";

    String rgb[3]={String(s1),String("green"),String("blue")};
    cout <<"Enter the name of a primary color for mixing lights:";
    String ans;
    bool succeed= false;
    while(cin >> ans){
        ans.stringlow();
        int i;
        for(i=0;i<3;i++){
            if(ans == rgb[i]){
                cout <<"That's right~\n";
                succeed=true;   //跳出双层循环 好语法
                break;
            }
        }
        if(succeed)
            break;
        else
            cout <<"Try again!\n";
    }
    cout <<"Bye\n";
    return 0;



}