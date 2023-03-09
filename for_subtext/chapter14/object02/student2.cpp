

#include "student2.h"

const string& Student::Name() const{
	return name;
}


double& Student::operator[](int n){
	//if(scores.size() >0 )
		return scores[n];

}

double Student::operator[](int n)const{
	//if(scores.size() >0 )
		return scores[n];
}


istream& operator>>(istream &is, Student& stu){
	is >>stu.name;
	return is;
}

istream& getline(istream &is, Student& stu){
	getline(is,stu.name);
	return is;
}

ostream& operator<<(ostream& os,const Student &stu){
	int k=stu.scores.size();

	os << "the score of " << stu.name <<":";


	if(k>0){
	int i;
	for(i=0;i<k;i++){
		os << stu.scores[i] <<" ";
		if (i %5 ==4) os << endl;
	}
	}else{
		os <<"No data\n";
	}

	return os ;

}