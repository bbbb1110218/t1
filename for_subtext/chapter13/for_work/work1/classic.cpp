#include "classic.h"
#include <cstring>
 

Cd::Cd(const char *s1,const char *s2,int n,double x){
	strncpy(performers,s1,50);
	performers[50-1]='\0';
	strncpy(label,s2,20);
	label[19]='\0';
	selecions=n;
	playtime=x;

}

Cd::~Cd(){}

void Cd::Report()const  //show all data
{
	cout << endl;
	cout << "表演者:" <<performers << endl;
	cout << "称号  :" << label << endl;
	cout << "选择  :" << selecions << endl;
	cout << "时间  :" << playtime << endl;

}


Classic::Classic(const char *s1,const char *s2, 
	const char *sons,int n,double x):Cd(s1,s2,n,x){
	strncpy(song,sons,50);
	song[49]='\0';
}


Classic::Classic(const Cd &c,const char* sons):Cd(c){
	strncpy(song,sons,50);
	song[49]='\0';
}


void Classic::Report()const{
	Cd::Report();
	cout << "歌曲  :" << song << endl;
}