#ifndef __SALES_H__
#define __SALES_H__

#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>

using namespace std;


class Sales{
public:
	enum {MONTH=12};
	explicit Sales(int yy=0):year(yy){
		for(int i=0;i<MONTH;i++){
			gross[i]=0.0;
		}
	}

	Sales(int yy,const double *gr,int n);

	virtual ~Sales(){}
	int Year(){return year;}
	virtual double operator[](int i)const;//{return gross[i];}
	virtual double& operator[](int i); //可以修改数组里面的值

	class Bad_index:public logic_error
	{
	private:
		int bi;//索引编号
	public:
		explicit Bad_index(int i,const string& t="Index error in Sales Error"):bi(i),logic_error(t){}
		~Bad_index()_NOEXCEPT{}  // 或者 把_NOEXCEPT 修改成throw() 不会抛出任何异常
									//throw(int) 代表会抛出一个int 类型的异常
									//throw(int,char) 会抛出
									//throw(...) 会抛出任何异常

		int BiValue()const{return bi;}

		const char* what()const _NOEXCEPT{ //重写基类
			cout << Number() << " <<<<< ";
			return logic_error::what();
		}


	};


private:

	double gross[MONTH];
	int year;
};




class LabelSale:public Sales{
private:
	string label; //标签
public:
	explicit LabelSale(const string& lb="None",int y=0):Sales(y),label(lb){}
	LabelSale(const string& lb,int yy,const double *gr,int n):label(lb),Sales(yy,gr,n){}
	~LabelSale(){}

	const string& Label()const{return label;}

	virtual double operator[](int i)const;
	virtual double& operator[](int i);
	class nBad_index:public Sales::Bad_index{  //继承是Sales 里面的共有类 记得加上作用域
	private:
		string lbl;
	public:
		nBad_index(const string&lb,int ix,
			const string &s="Index error in Labelsale object")
			:lbl(lb),Sales::Bad_index(ix,s){} //类里面的类 也加上类的作用域
		~nBad_index()_NOEXCEPT{}
		const string& LableValue()const{return lbl;}


	};




};









#endif

