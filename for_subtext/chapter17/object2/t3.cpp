#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;




int main(int argc,char *argv[]){  // a.out, t1,t2,t3

	if(argc ==1){
		cout <<"Need some file after " << argv[0] << endl;
		return -1;
	}

	int NUM=0;
	int blackNum=0;
	int digitNum=0;
	char ch;
	for(int i=1;i<argc;i++){
		ifstream fin;
		fin.open(argv[i]);
		if(!fin.is_open()){
			cout << argv[i] << " Not exist.\n";
			fin.clear();

			continue;
		}
		while(fin.get(ch)){
			if(isalpha(ch))
				NUM++;
			if(isblank(ch))
				blackNum++;
			if(isdigit(ch))
				digitNum++;

		}
			
		fin.close();
		fin.clear();
	}

	cout << "Total alpha characters:" << NUM << endl;
	cout << "total black characters:" << blackNum << endl;
	cout << "Total digitNum characters:" << digitNum << endl;


	return 0;

}