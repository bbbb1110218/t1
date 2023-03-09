#include <iostream>
#include <string>

using namespace std;


class Cpmv{
public:
	struct Info{
		std::string qcode;
		std::string zcode;
	};
private:
	Info* pi;
public:
	Cpmv();
	Cpmv(std::string q,std::string z);
	Cpmv(const Cpmv &cp);
	Cpmv(Cpmv && mv);
	~Cpmv();
	Cpmv& operator=(const Cpmv& vp);
	Cpmv& operator=(Cpmv&& mv);  //Move assign
	Cpmv operator+(const Cpmv&obj)const;
	void Display()const; 

};

int main(){
	std::string firstname{"min"};
	std::string lastname{"liang"};
	Cpmv mc{firstname,lastname};
	mc.Display();
	Cpmv mc2(mc);
	mc2.Display();
	Cpmv mc3(move(mc2));
	mc3.Display();
	mc2.Display();
	mc2=mc3;
	cout <<"after operator= \n";
	mc2.Display();
	Cpmv nObj{"fuck","you"};
	cout << " ------- " << endl;
	mc2=move(nObj);
	mc2.Display();
	nObj.Display();
	mc2=move(mc2);
	mc2.Display();
	auto fuck=mc2 +mc;
	fuck.Display();



	return 0;
}

Cpmv::Cpmv(){
	pi=new Info{};
}

Cpmv::Cpmv(std::string q,std::string z){
	pi=new Info{q,z};
}

Cpmv::Cpmv(const Cpmv &cp){
	pi=new Info{cp.pi->qcode,cp.pi->zcode};
}

Cpmv::Cpmv(Cpmv && mv){
	pi=mv.pi;
	mv.pi=nullptr;

}

Cpmv& Cpmv::operator=(const Cpmv& vp){
	if(this==&vp)
		return *this;
	delete pi;

	pi=new Info{vp.pi->qcode,vp.pi->zcode};

	return *this;
}
 
Cpmv& Cpmv::operator=(Cpmv&& mv){  //Move assign
	if(this ==&mv)					//避免自己赋值给自己
		return *this;
	// delete pi;				//不需要new
	// pi=new Info{mv.pi->qcode,mv.pi->zcode};
	pi=mv.pi;
	mv.pi=nullptr;
	return *this;
}


Cpmv Cpmv::operator+(const Cpmv&obj)const{
	
	return Cpmv(this->pi->qcode + " & " + obj.pi->qcode, 
				this->pi->zcode + " & " +obj.pi->zcode);
}


Cpmv::~Cpmv(){
	delete pi;
}

void Cpmv::Display()const{
	if(pi==nullptr)
		cout <<"No data" << endl;
	else
		cout << pi->qcode << "   "<<pi->zcode << endl;
} 



