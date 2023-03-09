

#include "student2.h"


ostream& Student::arr_out(ostream& os)const{

	int i;
	int limit=ArrayDb::size();
	if(limit >0)
		for(i=0;i<limit;i++){
			os << ArrayDb::operator[](i) << " ";
		if(i % 5 ==4)
			os << endl;
	}else{
		os <<"Empty data" << "\n";
	}
	return os;
}

double Student::Average()const{
	if(ArrayDb::size() >0){
		return ArrayDb::sum()/ArrayDb::size();
	}
	else 
		return 0;
}

const string& Student::Name() const{

	return (const string& ) *this;

}


double& Student::operator[](int n){
	
		return ArrayDb::operator[](n);

}

double Student::operator[](int n)const{
	
		return ArrayDb::operator[](n);
}


istream& operator>>(istream &is, Student& stu){
	is >> (string &) stu;
	
	return is;
}

istream& getline(istream &is, Student& stu){
	getline(is,(string &) stu);
	return is;
}

ostream& operator<<(ostream& os,const Student &stu){
	//

	os << "the score of " << (const string &) stu <<":";
	stu.arr_out(os);
	return os;

}