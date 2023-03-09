#include "dma.h"
#include "cstring"



baseDMA::baseDMA(const char *l,int r){
	label=new char[strlen(l)+1];
	strcpy(label,l);
	rating=r;
}

baseDMA::baseDMA(const baseDMA&rs){
	label=new char[strlen(rs.label) +1];
	strcpy(label,rs.label);
	rating=rs.rating;
}

baseDMA::~baseDMA(){
	
	delete []label;
}

baseDMA& baseDMA::operator=(const baseDMA& rs){
	if(this == &rs)
		return *this;
	delete []label;
	label=new char[strlen(rs.label)+1];
	strcpy(label,rs.label);
	rating=rs.rating;
	return *this;
} 

ostream& operator<<(ostream&os,const baseDMA&rs){
	os <<"\n";
	os << "Label :" << rs.label <<endl;
	os << "rating :" << rs.rating << endl;
	return os;
}


lacksDMA::lacksDMA(const char *l,int r,const char*c):baseDMA(l,r){
	strncpy(color,c,COL_LEN-1);
	color[COL_LEN-1]='\0';
}


lacksDMA::lacksDMA(const baseDMA& rs,const char* c):baseDMA(rs){
	strncpy(color,c,COL_LEN-1);
	color[COL_LEN-1]='\0';
}


ostream& operator<<(ostream&os,const lacksDMA& rs){
	os << (const baseDMA &) rs;
	os << "color :" << rs.color <<endl;
	return os;
}




hasDMA::hasDMA(const char *l,int r,const char *s):baseDMA(l,r){
	style =new char[strlen(s)+1];
	strcpy(style,s);

}

hasDMA::hasDMA(const baseDMA&ba,const char *s):baseDMA(ba){
	style =new char[strlen(s)+1];
	strcpy(style,s);
}


hasDMA::hasDMA(const hasDMA& hs):baseDMA(hs){

	style =new char[strlen(hs.style)+1];
	strcpy(style,hs.style);
}


hasDMA::~hasDMA(){
	delete []style;		//释放派生类 开辟的空间
}


hasDMA& hasDMA::operator=(const hasDMA& hs){
	if(this ==&hs)
		return *this;

	//需要用函数表示法
	baseDMA::operator=(hs);  //这行语句的意思是把hs拷贝给this指针指向的对象
						     //指定使用基类的赋值运算符
	delete []style;
	style=new char[strlen(hs.style)+1];
	strcpy(style,hs.style);
	return *this;
}

ostream& operator<<(ostream&os,const hasDMA& hs){
	os << (const baseDMA &) hs ;			//把派生类转换成基类
	os << "style :" << hs.style << endl;
	return os;
}














