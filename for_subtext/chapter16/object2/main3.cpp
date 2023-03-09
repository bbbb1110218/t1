#include <iostream>
#include <string>
#include <ctime>
#include <cstring>

#define GAME "想不想玩一个猜字母的游戏<y/n>:"

using namespace std;

const int NUM=26;

const string arr[NUM]={"apiary","beetle","cereal",
					"danger","ensign","florid","grarge","health","insult",
					"jackal","keeper","loaner","manage","nonce","onset",
					"plaid","quilt","remote","stolid","train","useful",
					"valid","whence","xenon","yearn","zippy"};


int main(){

	char choice;

	cout <<"想不想玩一个猜字母的游戏<y/n>:";
	cin >> choice;
	srand(time(0)); // 随机种子

	if(isalpha(choice)){
	choice =tolower(choice);
	while(choice =='y'){

		string result=arr[rand() % 25]; //答案
		int StrLen=result.size();

		string ShowStr(StrLen,'-');  //给看的
		string BadChars;

		cout << "这个英文单词一共有" << StrLen << "个单词\n";
		cout << "Your guess:"<< ShowStr << endl;

		int ChoiceCount=6;
		while(ChoiceCount && result !=ShowStr){  //
			//cout <<"正确的答案[" << result << "]" << endl;

			cout <<"Your Guess:";
			char GuessChar;
			cin >> GuessChar;
			if(!isalpha(GuessChar)){
				cout <<"猜数字啊，大佬"<< endl;
				continue;
			}

			if(result.find(GuessChar) == -1 || BadChars.find(GuessChar) == -1){
					BadChars +=GuessChar;	//没答对
					ChoiceCount--;		//机会减去1
					cout << "Your guess:"<< ShowStr << endl;
					cout <<"BadGuess:" << BadChars << endl;
					continue;
							
			}else if(BadChars.find(GuessChar) !=-1){
				cout << "大佬,这个已经猜过了" << endl;
				cout << BadChars << " 这些都猜过" <<endl;

			}else{
				int pos=result.find(GuessChar);
				ShowStr[pos]=GuessChar;
				while(result.find(GuessChar,pos+1) != -1){
					ShowStr[pos]=GuessChar;
					pos=result.find(GuessChar,pos+1);

				}


			cout << "Your guess:"<< ShowStr << endl;
			cout << "剩余"<<ChoiceCount << " 次机会" << endl;
				

			}




		}


	cout <<"想不想玩一个猜字母的游戏<y/n>:";
	cin >> choice;

	if(!isalpha(choice)){
		cout <<"Bye"<< endl;
		exit(-1);
	}

	choice =tolower(choice);



	}

	
	
		
	}else{

	}






	return 0;
}
