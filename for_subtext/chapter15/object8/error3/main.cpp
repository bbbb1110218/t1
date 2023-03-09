#include <iostream>
#include <exception>
#include <cstring>
using namespace std;

class Myerror:public exception{
private:
    char * msg;
public:
    explicit Myerror(const char * s="None"):exception(){
        msg=new char[strlen(s)+1];
        strcpy(msg,s);
        msg[strlen(s)]='\0';
    }

    ~Myerror()_NOEXCEPT override{
        delete []msg;
    }

    //类方法不用写virtual
    //出错，有时候你以为重载了，却没有重新载入 用clion 看一下，左边有箭头
    const char* what() const noexcept override{

        return msg;

    }

};

void func(const int& n);

int main(){
    // func(1);

    try{
        func(10);
    }

    catch(exception &e){
        cout << e.what() << endl;
    }

    return 0;
}


void func(const int& n){
    if(n == 1)
        throw Myerror("something wrong");
    if( !(n %2) )
        throw Myerror("argument cant rmode 2");
    cout << "n+1 value: "<< n+1 << endl;

}



