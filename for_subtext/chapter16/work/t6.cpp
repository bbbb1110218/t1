#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    const int limit =	1000000;

    clock_t start =clock();
    vector<int> vi0;
    for(int i=0;i<limit;i++){
        vi0.push_back(rand()%100);
    }

    cout <<clock()-start << endl;

    vector<int> vi(vi0);
    list<int> li(vi0.begin(),vi0.end());

    start=clock();
    //sort(vi.begin(),vi.end());
    std::sort(vi.begin(), vi.end());

    cout << "Vi need time :" << double(clock() -start) /CLOCKS_PER_SEC << "秒"<<endl;

    start=clock();
    li.sort();
    cout << "Li need time :" << double(clock() -start) /CLOCKS_PER_SEC << "秒"<<endl;

    copy(vi0.begin(),vi0.end(),li.begin());

    start=clock();
    copy(li.begin(),li.end(),vi.begin());
    sort(vi.begin(),vi.end());
    copy(vi.begin(),vi.end(),li.begin());
    cout << "new method need time :" << double(clock() -start) /CLOCKS_PER_SEC << "秒"<<endl;





    return 0;
}