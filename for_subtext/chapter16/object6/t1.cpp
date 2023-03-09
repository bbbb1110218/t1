#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <typeinfo>
/*
* 	对字符串排列的所有的可能行
*/

using namespace std;


template<class PTR,class V>
PTR find2(PTR first,PTR last,const V& value){

	while(first !=last){
		if(*first ==value)
			return first;
		first++;
	}
	return first;

}



template<class PTR,class V>
PTR remove2(PTR first,PTR last,const V& value){
	
	while(*first !=value)
		first++;

	V temp=*(last-1);

	while(first !=last){
		*first=*(first+1);
		first++;

	}
	*first=temp;
	

	
	return first;
}

// template<class T>
// void Show(T* pt,int size){
// 	for(int i=0;i<size;i++){
// 		cout << pt[i] << " ";
// 	}
// 	cout << endl;
// }

void Show(int a){
	cout <<a << " ";
}

template<class PTR,class V>
void showptr(PTR first,PTR last,const V& value){
	
	while(first !=last){
		cout << static_cast<int>(first) <<" ";
		first++;
	}
	
}


__wrap_iter<int *>




int main(){
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	vector<int> va(arr,arr+10);
	showptr<>(va.begin(),va.end(),10);
}




