//
// Created by macbookpro on 2023/1/17.
//


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace  std;

class Grad{
private:
    int hold;
public:
    explicit Grad(int h=0):hold(h){};
    virtual void Speak()const{cout <<"[1].I am a grand class \n";}
    int Value()const {return hold;}
};

class SuperB:public Grad{  //第二代派生类
public:
    explicit SuperB(int h=0):Grad(h){}
    void Speak()const {cout <<"[2].I am a SuperB class"<< endl;}
    virtual void Say()const {cout <<"in SuperB value is" << Value() << endl;}
};

class Magnificent:public SuperB{  //第三代派生类
private:
    char ch;
public:
    explicit Magnificent(int h=0,char c='A'): SuperB(h),ch(c){}
    void Speak()const {cout <<"[3].I am a Magnificent class"<< endl;}
    void Say()const{cout<< "I hold a character value:" << ch << " and I hold a int value"<< Value() <<" \n"; }

};

Grad *Get_one(){ //

    Grad *p= nullptr;

    switch (rand() %3) {
        case 0:{
            p= new Grad(rand() % 100);
            break;
        }case 1:{
            p=new SuperB(rand() % 100);
            break;
        }case 2:{
            p=new Magnificent(rand() % 100,'B');
            break;
        }

    }


    return p;
}



int main(){
    srand(time(nullptr));//随机数种子放在 main 函数里面

    Grad *pg= nullptr;
    SuperB *sp= nullptr;
    for(int i=0;i<5;i++){
        cout <<"----------------" << endl;
        pg= Get_one();
        pg->Speak();

        if((sp =dynamic_cast<SuperB *>(pg) )&& (sp !=NULL))
            sp->Say();
        else
            cout << "Error pointer[][][][][][][][]" << endl;



    }




    return  0;
}