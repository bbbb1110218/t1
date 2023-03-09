#include <vector>
#include <string>
#include <iostream>
#include <memory>
using namespace std;

struct Review
{
	string title;
	int rating;
	double price;

};

bool FillReview(Review& r);
void ShowReview(const Review&r);

int main(){

	vector<Review> books;
	Review temp;
	while(FillReview(temp)){
		books.push_back(temp); //进入容器
	}
	int num=books.size(); //返回数量

	if(num >0 ){
		cout << "books list:"<< endl;
		for_each(books.begin(),books.end(),ShowReview);
		random_shuffle(books.begin(),books.end());
		for_each(books.begin(),books.end(),ShowReview);

	}
	cout << "------line to cut--------------\n";
	vector<Review>::iterator pd;

	for(pd=books.begin();pd!=books.end();pd++){
		ShowReview(*pd);
	}

	vector<Review> oldlist(books);

	if(num > 3){
		books.erase(books.begin()+1,books.begin()+3);
		cout << "after erase--" << endl;
		vector<Review>::iterator pd;
		for(pd=books.begin();pd!=books.end();pd++){
			ShowReview(*pd);
		}
		cout << "after insert--" << endl;
		books.insert(books.begin(),oldlist.begin()+1,oldlist.begin()+2);
		for(pd=books.begin();pd!=books.end();pd++){
			ShowReview(*pd);
		}


	}

	cout << "books swap--" << endl;
	books.swap(oldlist);
	for(pd=books.begin();pd!=books.end();pd++){
	ShowReview(*pd);
}








	return 0;
}

bool FillReview(Review& r){
	cout <<"Enter book title<q to quit>:";
	getline(cin,r.title);
	if(r.title =="quit"){
		return false;
	}
	cout <<"Enter book rating:";
	cin >>r.rating;
	while(!cin)
		return false;

	while(cin.get() !='\n');
	return true;

}


void ShowReview(const Review&r){
	cout << r.rating <<"\t"<< r.title << endl;
}