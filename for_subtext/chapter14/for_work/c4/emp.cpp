#include "emp.h"




void abstr_emp::ShowAll()const{
	cout <<(*this) ;
	// cout << "------" << endl;
	// cout << "first_name :" << fname << endl;
	// cout << "last_name :" << lname << endl;
	// cout << "job :" << job <<  endl;
}

void abstr_emp::SetAll(){
	cout <<"please Enter the first_name:";
	cin >> fname;
	cout << "Please Enter the lase_name:";
	cin >> lname;
	cout <<"Please Enter the job:";
	cin >> job;
	//cin.get();  //不知道有没有错
}

ostream& operator<<(ostream&os,const abstr_emp& e){
	static int i=0;
	os << "------" << (++i) <<endl;
	os << "first_name :" << e.fname << endl;
	os << "last_name :" << e.lname << endl;
	os << "job :" << e.job <<  endl;
	return os;
}

void emloyee::ShowAll()const{
	abstr_emp::ShowAll();
}

void emloyee::SetAll(){
	abstr_emp::ShowAll();
}

void manager::ShowAll()const{
	abstr_emp::ShowAll();
	cout << "inchargeof :" << inchargeof <<  endl;
}

void manager::SetAll(){
	abstr_emp::SetAll();
	cout <<"please Enter the inchargeof|主管熟练";
	cin >> inchargeof;
	cin.get();//不知道有没有错

}


void fink::ShowAll()const{
	abstr_emp::ShowAll();
	cout << "reportsto :" << reportsto <<  endl;
}

void fink::SetAll(){
	abstr_emp::SetAll();
	cout <<"please Enter the reportsto|报告";
	getline(cin,reportsto);
	cin.get();//不知道有没有错
}


void highfink::ShowAll()const{
	abstr_emp::ShowAll();
	cout << "inchargeof :" << manager::InChargeOf() <<  endl;
	cout << "reportsto	:" <<fink::ReportTo() << endl;
}

void highfink::SetAll(){
	abstr_emp::SetAll();
	cout <<"please Enter the inchargeof|主管熟练";

	cin >> manager::InChargeOf();
	cin.get();//不知道有没有错

	cout <<"please Enter the reportsto|报告";
	getline(cin,fink::ReportTo());
	
}


