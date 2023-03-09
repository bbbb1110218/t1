//
// Created by macbookpro on 2022/12/25.
//

#ifndef FOR_CLION_STUDENT_H
#define FOR_CLION_STUDENT_H

#include <iostream>
#include <string>
#include <utility>
#include <valarray>
using namespace std;



class Student{
private:
    typedef valarray<double> ArrayDb;  //别名
    string name;
    ArrayDb scores;

public:
    Student():name("NUll student"),scores(){}   //初始化成员
    explicit Student(const string &s):name(s),scores(){}    //避免隐式转换
    explicit Student(int n):name("nully"),scores(n){}

    Student(const string & s,int n):name(s),scores(n){}
    Student(const string &s,ArrayDb & a):name(s),scores(a){}
    Student(const string &s,const double *pd,int n):name(s),scores(pd,n){}



    ~Student(){}

    double Average()const;
    const string& Name()const;

    double & operator[](int n);  //stu[0]=100;
    double operator[](int n)const;      //double a=stu[0];

    friend istream& operator>>(istream& is,Student &stu);
    friend istream& getline(istream&is,Student&stu);  //重载 getline
    friend ostream& operator<<(ostream&os,const Student& stu);





};








#endif //FOR_CLION_STUDENT_H
