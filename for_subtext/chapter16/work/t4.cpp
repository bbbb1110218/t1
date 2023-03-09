/*
string 
	find method
*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

//const int NUM=26;
const char * filename="myword.txt";


// const string worldList[NUM]={"apiary","beetle","cereal",
// 					"danger","ensign","florid","grarge","health","insult",
// 					"jackal","keeper","loaner","manage","nonce","onset",
// 					"plaid","quilt","remote","stolid","train","useful",
// 					"valid","whence","xenon","yearn","zippy"};






int main(){
	vector<string>  worldList;
	string tempstring;

	ifstream fin;
	fin.open(filename);
	if(!fin.is_open()){
		cout << "can't open file :" << filename << endl;
		return -1;
	}


	while(fin){
		getline(fin,tempstring,',');
		worldList.push_back(tempstring);
	}

	fin.close();

	int NUM=static_cast<int>(worldList.size());


	char play;

	srand(time(0));
	cout <<"Will you play a game?<y/n>:";
	cin >> play;
	play=tolower(play);

	while(play == 'y'){
		


		string target=worldList[rand() % NUM];

		cout <<"target : " <<target << "\n";

		int LEN=target.length();

		string Guess(LEN,'-'); //for show

		cout << Guess << endl;

		string BadChars; //猜错的集合

		int Gtime=6;
		cout <<"Guess my secret worlds, is has " << LEN << " length letter,";
		cout <<"and you guess at a time,you get " << Gtime <<" time.\n";

		while(Gtime > 0 && Guess !=target){

			
			char letter;
			cout << "Guess a letter" << endl;
			cin >> letter;

			//没找到
			//string::npos 为定义的宏 这里是 -1
			if(BadChars.find(letter) != string::npos || Guess.find(letter) != string::npos){  
				cout << "You have already guess that,try again" << endl;
				continue;
			}

			int loc = target.find(letter);
			if(loc == string::npos){	//没找到
				cout << "oh,bad guess" << endl;
				Gtime--;					//机会剪掉1
				BadChars += letter;			//猜错的
			}else{								//else 找到了
				cout <<"ob,good guess" << endl;
				Guess[loc]=letter;					//放到 ----- 里面
				loc=target.find(letter,loc+1); //找下一个
				while(loc != string::npos){//循环找下一个
					Guess[loc]=letter;
					loc = target.find(letter,loc+1);			//find 函数有偏移量
				}

			cout <<"Your World:" << Guess << endl;
			if(Guess != target){
				if(BadChars.length() >0)
					cout << "BadChars:" << BadChars << endl;
				cout << Gtime << " Bad Guesses left" << endl;
			}
				
			}

		

		}




		cout <<"Will you play a game?<y/n>:";
		cin >> play;
		play=tolower(play);

	}







	return 0;
}