#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sum=0;

void SumAdd(int n){
	sum +=n;
}

struct SS{
	string name;
	int age;
};

int main(){

	vector<SS> Myss;
	Myss.push_back({"a",3});
	Myss.push_back({"v",8});
	Myss.push_back({"c",5});
	Myss.push_back({"d",4});

	// bool(*pf1)(const SS s1) =[](const SS s1){cout << s1.name << "\t" << s1.age << endl;};

	
	for(auto temp:Myss)
		f1(temp);

	auto f2=[](const SS s1,const SS s2){return s1.name < s2.name;};

	sort(Myss.begin(),Myss.end(),f2);

	for_each(Myss.begin(),Myss.end(),f1);



	return 0;

}