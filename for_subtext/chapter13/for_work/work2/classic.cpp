#include "classic.h"
#include <cstring>
 

Cd::Cd(const char *s1,const char *s2,int n,double x){
	int l1,l2;
	l1=strlen(s1);
	l2=strlen(s2);
	performers=new char[l1+1];
	strcpy(performers,s1);
	label=new char[l2+1];
	strcpy(label,s2);
	selecions=n;
	playtime=x;
}

Cd::Cd(const Cd &c){
	int l1=strlen(c.performers);
	int l2=strlen(c.label);
	performers=new char[l1+1];
	strcpy(performers,c.performers);
	label=new char[l2+1];
	strcpy(label,c.label);
	selecions=c.selecions;
	playtime=c.playtime;
};


Cd::~Cd(){
	delete []performers;
	delete []label;
}


Cd& Cd::operator=(const Cd&c){
	if(this ==&c)
		return *this;

	delete []performers;
	delete []label;

	int l1=strlen(c.performers);

	int l2=strlen(c.label);

	performers=new char[l1+1];
	strcpy(performers,c.performers);
	label=new char[l2+1];
	strcpy(label,c.label);
	selecions=c.selecions;
	playtime=c.playtime;
	return *this;

}




void Cd::Report()const  //show all data
{
	cout << endl;
	cout << "表演者:" << performers << endl;
	cout << "称号  :" << label << endl;
	cout << "选择  :" << selecions << endl;
	cout << "时间  :" << playtime << endl;

}


Classic::Classic(const char *s1,const char *s2, 
	const char *sons,int n,double x):Cd(s1,s2,n,x){
	int l1=strlen(sons);
	song=new char[l1+1];
	strcpy(song,sons);
}


Classic::Classic(const Cd &c,const char* sons):Cd(c){
	song=new char[strlen(sons)+1];
	strcpy(song,sons);
}

Classic::Classic(const Classic&c):Cd(c){
	song=new char[strlen(c.song)+1];
	strcpy(song,c.song);
}


Classic& Classic::operator=(const Classic&c){
	if(this ==&c){
		return *this;
	}

	Cd::operator=(c);
	delete []song;
	song= new char[strlen(c.song)+1];
	strcpy(song,c.song);
	return *this;
	
}


void Classic::Report()const{
	Cd::Report();
	cout << "歌曲  :" << song << endl;
}

Classic::~Classic(){
	delete []song;
}