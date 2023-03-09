

/*


*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){

	string filename;
	cout << "Enter the file name:";
	cin >> filename;


	ifstream fin;
	fin.open(filename);
	char ch;
	cout << "here is the content of " << filename << endl;
	while(fin.get(ch))
		cout.put(ch);

	fin.close();

	return 0;


}