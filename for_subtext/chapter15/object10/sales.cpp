#include "sales.h"


Sales::Sales(int yy,const double *gr,int n):year(yy){
	
	int nn=n<MONTH?n:MONTH;

	int i;

	for(i=0;i < nn;i++)
		gross[i]=gr[i];
		

	for(;i<MONTH;i++)
		gross[i]=0.0;


}

double Sales::operator[](int i)const{
	if(i >= MONTH || i < 0 )
		throw(Bad_index(i));
	return gross[i];
}

double& Sales::operator[](int i){
	if(i >= MONTH || i < 0 )
		throw(Bad_index(i));
	return gross[i];
}


double LabelSale::operator[](int i)const{
	if(i >= MONTH || i < 0 )
		throw(nBad_index(Label(),i));
	return Sales::operator[](i);
}



double& LabelSale::operator[](int i){
	if(i >= MONTH || i < 0 )
		throw(nBad_index(Label(),i));
	return Sales::operator[](i);
}