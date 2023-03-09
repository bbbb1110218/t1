#ifndef __STUDENT2_H__
#define __STUDENT2_H__


#include <iostream>
#include <string>
#include <valarray>

using namespace std;

class Student{

private:
	typedef valarray<double> Array;
	string name;
	Array scores;
public:
	Student():name("None"),scores(0){}
	explicit Student(const string &s):name(s),scores(){}
	explicit Student(int n):name("None"),scores(n){}
	Student(const string &s,int n):name(s),scores(n){}
	~Student(){}

	const string& Name() const;
	double& operator[](int n);
	double operator[](int n)const;

	friend istream& operator>>(istream &is, Student& stu);
	friend istream& getline(istream &is, Student& stu);
	friend ostream& operator<<(ostream& os,const Student &stu);




};






#endif