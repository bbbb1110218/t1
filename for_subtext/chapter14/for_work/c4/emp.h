#include <iostream>
#include <string>

using namespace std;
class abstr_emp{
private:
	string fname;
	string lname;
	string job;
public:
	abstr_emp():fname("None"),lname("None"),job("None"){};
	abstr_emp(const string &fn,const string &ln,
		const string &j):fname(fn),lname(ln),job(j){}
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual ~abstr_emp(){};//纯虚函数
	friend ostream& operator<<(ostream&os,const abstr_emp& e);
};


class emloyee:public abstr_emp{
public:
	emloyee():abstr_emp(){};
	emloyee(const string &fn,const string &ln,
		const string &j):abstr_emp(fn,ln,j){}
	virtual void ShowAll()const;
	virtual void SetAll();
	~emloyee(){}
};


class manager:virtual public abstr_emp{
private:
	int inchargeof;//主管
protected:
	int InChargeOf()const {return inchargeof;}	//output
	int& InChargeOf(){return inchargeof;}	//input
public:
	manager():abstr_emp(),inchargeof(0){};
	manager(const string &fn,const string &ln,
		const string &j,int ico=0):abstr_emp(fn,ln,j),inchargeof(ico){}
	manager(const abstr_emp&e,int ico):abstr_emp(e),inchargeof(ico){}
	manager(const manager&m):abstr_emp(m),inchargeof(m.inchargeof){}  //TODO::
	virtual void ShowAll()const;
	virtual void SetAll();
	~manager(){}

};

class fink:virtual public abstr_emp{
private:
	string reportsto; //报告
protected:
	string ReportTo()const{return reportsto;}
	string& ReportTo(){return reportsto;}
public:
	fink():abstr_emp(),reportsto("None"){}
	fink(const string &fn,const string &ln,
		const string &j,const string &re):abstr_emp(fn,ln,j),reportsto(re){}
	fink(const abstr_emp&e,const string &re):abstr_emp(e),reportsto(re){}
	fink(const fink&e):abstr_emp(e),reportsto(e.reportsto){} //不知道有没有写错
	virtual void ShowAll()const;
	virtual void SetAll();
	~fink(){}
};

class highfink:public manager,public fink{
	public:
		highfink():abstr_emp(),manager(),fink(){}
		highfink(const string &fn,const string &ln,
			const string &j,const string &re,int ico):abstr_emp(fn,ln,j),
			manager(fn,ln,j,ico),fink(fn,ln,j,re){}
		highfink(const abstr_emp&e,const string &re,int ico):abstr_emp(e),manager(e,ico),fink(e,re){}
		highfink(const fink&f,int ico):abstr_emp(f),manager(f,ico),fink(f){}
		highfink(const manager&m,const string &re):abstr_emp(m),manager(m),fink(m,re){}
		highfink(const highfink&f):abstr_emp(f),manager(f),fink(f){}
		virtual void ShowAll()const;
		virtual void SetAll();
		~highfink(){}
};

