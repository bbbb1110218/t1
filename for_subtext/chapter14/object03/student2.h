#ifndef __STUDENT2_H__
#define __STUDENT2_H__


#include <iostream>
#include <string>
#include <valarray>

using namespace std;



class Student:private string,private valarray<double>{

private:
	typedef valarray<double> ArrayDb;
	ostream& arr_out(ostream& os)const;
public:
	Student():string("None"),ArrayDb(0){}

	explicit Student(const string &s):string(s),ArrayDb(){}
	explicit Student(int n):string("None"),ArrayDb(n){}
	Student(const string &s,int n):string(s),ArrayDb(n){}
	Student(const string& s,const double &pd,int n):string(s),ArrayDb(pd,n){}
	~Student(){}

	double Average()const;

	const string& Name() const;
	double& operator[](int n);
	double operator[](int n)const;


	friend istream& operator>>(istream &is, Student& stu);
	friend istream& getline(istream &is, Student& stu);
	friend ostream& operator<<(ostream& os,const Student &stu);




};






#endif