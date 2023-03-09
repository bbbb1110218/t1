



类的六个成员函数
	//默认构造函数
	//拷贝构造函数
	//移动构造函数
	//拷贝运算符
	//移动运算符
	//析构函数

关键字default 只能用于6个成员函数
	
关键字delete 可以哟哦能够与任何成员函数
	delete 还有一种用法是禁止使用该方法

	class someclass{
		...;
	public:
		someclass(double );
		someclass(int)=delete; //参数为int 设置为禁用
	}


委托构造函数
	一个构造函数中允许调用其他构造函数

	class Note{
	private:
		int k;
		double x;
		string st;
	public:
		Note();
		Note(int n);
		Note(int n,double d);
		Note(int n,double d,string s);
	}

	Note::Note(int n,double d,string s):k(n),x(d),st(s){}
	Note::Note():Note(0,0.01,"No"){}// 调用其他构造函数
	Note::Note(int n):Note(n,0.01,"hello"){}// 调用其他构造函数
	Note::Note(int n,double d):Note(n,d,"kiitty"){}; //调用其他构造函数


继承构造函数

	可以在派生类里面使用基类的构造函数(默认构造函数,复制构造函数，和移动构造函数除外)



	



