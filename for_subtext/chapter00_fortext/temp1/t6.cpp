#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

typedef int ttt;


int main(){
	string arr[4]={"hello","kitty","fuck","you"};

	vector<string> words(4);

	copy(arr,arr+4,words.begin());

	for_each(words.begin(),words.end(),[](string s){static int i=1;if(i==1) cout <<"lambda func: "<< s <<" ";else cout << s << " ";i--;});



	//auto f=[](std::string &s){std::cout << s << ",";};

	//for_each(arr,arr+4,[](std::string &s){std::cout << s << " ";});

	return 0;
}
