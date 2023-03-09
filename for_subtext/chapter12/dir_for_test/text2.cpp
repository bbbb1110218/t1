#include <iostream> 
using namespace std;int main(){for(int x=1;x<100;x++)for(int y=1;y<=x;y++){cout << y <<"*" << x <<"=" <<x*y<<" ";if (x==y)cout <<endl;}return 0;}