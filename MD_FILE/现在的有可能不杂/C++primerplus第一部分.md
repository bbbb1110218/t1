 ## 目录

[toc]

## chapter :一些说明

> `g++`编辑指令
>
> ```c++
> g++ -E file_name //激活预处理  预编译 不生成文件 
> 	-可以找typedef 数据类型
> g++ -c cpp_file //
> ```
>
> 
>
> path: 在苹果的笔记本里面
>
> ```c++
> /Users/macbookpro/Nas_Data/C++/OnVisualCodeC++/
> ```
>
> 用G++ 调试不用每次都输入密码
>
> 中断防止那啥
>
> ```c++
> system("pause");
> or
> cin.get()
> ```
>
> **Error**
>
> ```c++
> 段错误：
>   segmentation fault(core dumped) 分段错误 核心转储 
>   一般是指针出错
> ```
>
> 
>
> 
>
> gcc gcc 生成的列表 在 task.json 里面
>
> ```json
> 
> {
> "tasks": [
>  {
>      "type": "cppbuild",
>      "label": "C/C++: g++ 生成活文件",
>      "command": "/usr/bin/g++",
>      "args": [
>          "-fdiagnostics-color=always",
>          "-g",
>          "${file}",
>          "-o",
> 
>          //"${fileDirname}/${fileBasenameNoExtension}" 这行注释了
>        "main"
>      ],
>      "options": {
>          "cwd": "${fileDirname}"
>      },
>      "problemMatcher": [
>          "$gcc"
>      ],
>      "group": {
>          "kind": "build",
>          "isDefault": true
>      },
>      "detail": "调试器生成的任务。"
>  }
> ],
> "version": "2.0.0"
> }
> 
> DEbug  launch.json
> --------------------------------------------------------------------
> {
> "version": "0.2.0",
> "configurations": [
> {
> "name": "C/C++ Runner: Debug Session",
> "type": "cppdbg",
> "request": "launch",
> "args": [],
> "stopAtEntry": true,
> "externalConsole": false,
> "cwd": "/Users/macbookpro/Nas_Data/C++/OnVisualCodeC++",
> "program": "/Users/macbookpro/Nas_Data/C++/OnVisualCodeC++/build/Debug/outDebug",
> "MIMode": "gdb",
> "miDebuggerPath": "gdb"
> }
> ]
> }
> ```

## 头文件函数 标准库

>  
>
>  ### 标准库
>
>  
>
>  ```
>  
>  ⚠️算法	
>   <algorithm>, <cstdlib>, <numeric>
>  ⚠️原子操作	
>   <atomic>11
>  ⚠️C 库包装器	
>   <cassert>、<ccomplex>11 a b、<cctype>、<cerrno>、<cfenv>11、
>   <cfloat>、<cinttypes>11、<ciso646>b、<climits>、		
>   <clocale>、<cmath>、<csetjmp>、<csignal>、<cstdalign>11 a b、
>   <cstdarg>、<cstdbool>11 a b、<cstddef>、<cstdint>11、<cstdio>、
>   <cstdlib>、<cstring>、<ctgmath>11 a b、
>   <ctime>、<cuchar>11、<cwchar>、<cwctype>
>  ⚠️概念	
>   <concepts>20
>  ⚠️容器	
>   序列容器	
>     	<array>11、<deque>、<forward_list>11、<list>、<vector>
>   有序的关联容器	
>     	<map>, <set>
>   无序的关联容器	
>     	<unordered_map>11、<unordered_set>11
>   容器适配器	
>    	 	<queue>, <stack>
>   容器视图	
>   	<span>20
>  ⚠️错误和异常处理	
>  		<cassert>、<exception>、<stdexcept>、<system_error>11
>  ⚠️常规实用工具	
>  		<any>17、<bit>20、
>  		<bitset>、<cstdlib>、
>  		<execution>17、<functional>、
>  		<memory>、<memory_resource>17、
>  		<optional>17、<ratio>11、<scoped_allocator>11、<tuple>11、
>  		<type_traits>11、<typeindex>11、<utility>、<variant>17
>  ⚠️I/O 和格式设置	
>  			<cinttypes>11、<cstdio>、<filesystem>17、<fstream>、<iomanip>、<ios>、<iosfwd>、<iostream>、
>  			<istream>、		<ostream>、<sstream>、<streambuf>、<strstream>c、<syncstream>20
>  ⚠️迭代器	
>  			<iterator>
>  ⚠️语言支持	
>  			<cfloat>、<climits>、<codecvt>11 a、<compare>20、<contract>20、<coroutine>20、
>  			<csetjmp>、<csignal>、<cstdarg>、<cstddef>、<cstdint>11、<cstdlib>、
>  			<exception>、<initializer_list>11、<limits>、<new>、<typeinfo>、<version>20
>  ⚠️本地化	
>  			<clocale>、<codecvt>11 a、<cvt/wbuffer>、<cvt/wstring>、<locale>
>  ⚠️数学和数字	
>  			<bit>20、<cfenv>11、<cmath>、<complex>、<cstdlib>、<limits>、<numeric>、<random>11、<ratio>11、<valarray>
>  ⚠️内存管理	
>  			<allocators>、<memory>、<memory_resource>17、<new>、<scoped_allocator>11
>  ⚠️多线程处理	
>  			<atomic>11、<condition_variable>11、<future>11、<mutex>11、<shared_mutex>14、<thread>11
>  ⚠️范围	
>  			<ranges>20
>  ⚠️正则表达式	
>  			<regex>11
>  ⚠️字符串和字符数据	
>  			<charconv>17、<cctype>、<cstdlib>、<cstring>、
>  			<cuchar>11、<cwchar>、<cwctype>、<regex>11、<string>、<string_view>17
>  ⚠️时间	
>  			<chrono>11、<ctime>
>  
>  			注意<headfile> 11 11说明是c++11
>  ```
>
>  
>
>  
>
>  ### iostream
>
>  ```c++
>  cin >> fuck;							//读取键盘流，知道遇到空格或者制表符
>  													// “min liang”  只会读取“min”
>  
>  cin.get();								//没有参数 只读取一个字符
>  cin.get(ch);							//只读取一个字符，并且复制给变量ch ch为char类型
>  
>  cin.get(char *,size); 		//函数会在换行符之前加入'\0' 但是还有一个换行符															//号'\n' 留在缓冲区 再.get()一下
>  												//cin.get(char *,size).get()
>  												//只要输入的内容不超过size,知道遇到'\n'为止，中间													有空格没关系直接把内容加上“\0”
>  												//超过了size个 截取前面的size个,后面截取掉的会被														流在缓存区域
>  
>  cin.getline(char *,size);//遇到空格不中断，两个参数 数组名字符个数 最多输入size-1 个字符 
>  												//还有其他问题，暂时没解决
>  
>  cin.clear();					//cin的功能坏了 可以用 if(!cin) 判断，然后用cin.clear 恢复
>  cout << fixed; 		//不显示科学计数法;
>  
>  getline(cin,string_object)	//对象是string 的时候 
>  												//getline(cin,string_object)
>  
>  cin >> 变量；   		//cin会跨过空白字符遇到下一个空白字符截断赋值给变量
>  						 //键盘输入" min liang" 变量=min，liang会留在缓存区域
>  cin.fail() ==false
>  //#检测当前输入是否为EOF end of file
>  //#windows 用ctrl+z
>  //#mac 系统用ctrl+d
>  cin.clear()							//可以清除 cin.fail() 清除EOF
>  cin.eof()							//当
>  
>  std::cout.setf(std::ios_basic::fixed,std::ios_basic::floatfield); //不使用科学记数法
>  
>  std::cout.percision(3);//保留三位小数
>  
>  cout.width(2);// 设置 cout宽度
>  
>  //标准错误输出
>  
>  标准输出 可以输出到屏幕 也可以重定向到文件;
>  标准错误输出 只能输出到屏幕
>  
>  //cin 说明;
>  double d; cin >> d ;  键盘输入的是字符，然后cin转换成 double 赋值给 d
>  
>  
>  
>  ```
>
>  #### new
>
>  ```c++
>  指定内存，不另外新开辟
>  char buff[512];
>  int *p=new(buff) int;
>  classname * pclass=new(buff) classname;
>  ```
>
>  
>
>  #### cstring
>
>  ```c++
>  strlen() ; 	//返回字符串的数量 
>  strcpy(char *a,char *b);		//拷贝b指针的内容 到 指针a里面
>  strcat(char *a,char *b);  //添加b 到a的结尾
>  strcmp(char *a,char *b); //比较两个字符串，相等结果为0，用第一个减第二个
>  
>  
>  ```
>
>  #### string
>
>  ```c++
>  string 类
>  string.size()  //返回字符串长度
>  string.length()  //返回字符串长度
>  string.empty()  //返回字符串长度是否为空
>  
>  ```
>
>  ### climits
>
>  ```c++
>  CHAR_BIT //char的位数
>  CHAR_MAX  //char的最大值
>  CHAR_MIN //char的最小值
>  SCHAR_MAX //signed char的最大值
>  SCHAR_MIN //signed char的最小值
>  UCHAR_MAX //unsigned char的最大值
>  SHRT_MAX  //short的最大值
>  SHRT_MIN  //short的最小值
>  USHRT_MAX  //unsigned short的最大值
>  INT_MAX  //int的最大值
>  INT_MIN //int的最小值
>  UNIT_MAX //unsigned int的最大值
>  
>  
>  ```
>
>  ### cstring
>
>  ```c++
>  C风格
>  strcpy_s(char *a1,char *a2); //a2 拷贝到 a1 
>  strcpy(s2,s1);	//s1拷贝到2 
>  strncpy(目标指针，源指针，拷贝的字符个数);
>  strcat（）
>  strcat
>  ```
>
>  ### ctime
>
>  ```c++
>  c库中
>  clock() ;;	//返回当前时间戳  返回clock_t 时间类型的别名
>  CLOCK_PER_SEC;  //常量 CPU每秒执行的次数 
>  
>  void sleep(double n){
>  	time_t start=clock();
>  	while(((clock() - start) < (n*CLOCKS_PER_SEC)));
>  }
>  
>  clock_t start=clock();  //开始时间
>  	func();
>  clock_t now =clock();
>  double(now-start) / CLOCK_PER_SEC   //才是func函数执行的时间
>  ```
>
>  ### CCTYPE
>
>  ```c++
>  isalpha();
>  islow();
>  isputc();  //是否为字母
>  isprint();	//是否为可以打印的 
>  tolower(); //转换成小写
>  toupper() ;	//转换成大写
>  
>  ```
>
>  ### **fstream** 文件流
>
>  ```c++
>  ofstream fout; //创建文件流对象   Out put file stream   //文件输出流
>  fout.open("temp.log");  // 添加路径
>  fout.close();			//
>  ```
>
>  ### iomanip
>
>  ```c++
>  setpercision(2);精确到点2位
>  setw(15)		;输出位宽15
>  ```
>
>  
>
>  ### utility
>
>  ```c++
>  std::move  函数 明确使用右值,生成的临时对象 不销毁，直接转染使用权
>  
>  ```
>
>  ### cmath
>
>  ```c
>  INFINITY 宏无穷大
>  ```
>
>  
>
>  
>
>  ### cstdlib 标准库
>
>  ```c++
>  //C库的函数
>  EXIT_FAILURE;   //exit(EXIT_FAILURE);退出程序的返回值 
>  srand();//随机数种子。//srand(time(NULL));
>  rand();//返回随机数，一般 % n 返回 0～(n-1)  
>  
>  //宏
>  EOF 文件尾巴
>  ```

## 符号的优先级

> ![](/Users/macbookpro/Nas_Data/MD_FILE/pic/FireShot Capture 003 - (18条消息) C语言运算符优先级（超详细）_yuliying的博客-CSDN博客_c 符号优先级 - blog.csdn.net.png)

## chapter :一些说明2 寄存器

> ```
> OV = 0  UP = 0   EI = 1    PL = 0 ZR = 1  AC = 0   PE = 1   CY = 0 
> 溢出OV 	 增量UP   允许中断EI  正PL		零ZR		辅助进位AC  偶校验PE	 进位CY
>
> 溢出OV（overflow，OF＝1）
> 无溢出NV（no overflow，OF＝0）
> 减量DN（direction down，DF＝1）
> 增量UP（direction up，DF＝0）
> 允许中断EI（enable interrupt，IF＝1）
> 进制中断DI（disable interrupt，IF＝0）
> 负NG（negative，SF＝1）
> 正PL（plus，SF＝0）
> 零ZR（zero，ZF＝1）
> 非零NZ（no zero，ZF＝0）
> 辅助进位AC（auxiliary carry，AF＝1）
> 无辅助进位NA（no auxiliary carry，AF＝0）
> 偶校验PE（even parity，PF＝1）
> 奇校验PO（odd parity，PF＝0）
> 进位CY（carry，CF＝1）
> 无进位NC（no carry，CF＝0）
>
>
> ```
>
> |           | of | df | if | sf | zf | af | pf | cf |
> | --------- | -- | -- | -- | -- | -- | -- | -- | -- |
> | 标志位为1 | ov | dn | ei | ng | zr | ac | pe | cy |
> | 标志位为0 | nv | up | di | pl | nz | na | po | nc |

## chapter1:命名空间

> ```c++
> using std::cin; //只使用这一个
> using namespace std;//使用std一下的所有
>
> ```
>
> ```c++
> #include <iostream>
> #define SIZE 10
>
> using std::cin;  //指出单独的命名空间 不要加namespace
> using std::cout;	//或者使用全局：using namespace std
>
> int main(){
>    int age;
>    char temp[SIZE*20]=" so fucking crazy";
>    std::cout << "How old are you" << std::endl;
>    cin >> age;
>    std::cout << "OH you are " << age;
>    cout << temp <<  std::endl;
>    cin.get();   								//控制进程那啥
>    return 0;
>
> }
> ```
>
> ```c++
> int count;
> cin >> count; //cin已经知道count 的数据类型
> ```


## Chapter3  :数据类型

> **整型**：unsigned long、long、unsigned int、int、 unsigned short、short、char、unsigned char、signed char和bool，unsigned long long和long long。新增char16_t,char32_t
>
> **浮点型：**float、double和long double。

### C++ 新赋值方式

> ```c++
> int i=666;	//c语言
> int i(666);  //c++可以这样定义
> int i= {666};
> int i={}; //i 初始化 为0 
> int i{}; //i 初始化为0 
>
> ```

### 显示16进制或者8进制

> ```c++
>   int i = 12; //数字使用多少进制 在前面提前加 oct or hex 就可以了
>   cout << i << ":" << " 10进制 " << i << " 16进制" << hex << i << " 8进制 " << oct << i << endl;
> ```

### 数字后面跟字母类型

> ```c++
> 2000L; //long 类型
> 2000UL； //unsigned long 类型
> 2000ULL； //unsigned long long类型
> ```

### 打印char

> ```c++
> char ch='M';
> int i=ch;
> cout << ch ;  // 打印为M  因位数据类型是char
> cout << i ;   // 打印为77 因为数据类型是int
>   						//可以用 cout.put(i); 打印为 M 要另外起一行  不可以单独注入
> ```

### wchar_t  char16_t char32_t

> ```c++
> 表示国外字
> wchar_t bob= L'p'; //前面加大写的L
> int nbob=bob;
> wcout << bob << endl;  //打印P
> cout << nbob << endll;	//打印 数字 112
>
> wchar_t ；16位 两个字节
> char16_t ；16位 两个字节
> char32_t ；32位 四个字节
>
> ```

### bool 类型

> ```c++
> true ; 占1个字节。0000 0001
> false ;					0000 0001
> ```

### 浮点数

> ```c++
> float ;字节 4				//float只保证6，7位有效位 
> double ; 字节 8 
> long double; 字节 16 
>
> 2.0	 ;double类型
>  2.0f ;float 类型
> 2.0L ;long double 类型  
>
> cout << sizeof(float) << " " << sizeof(double) << " " << sizeof(long double) <<endl;
> 4 8 16
> ```

### 强制类型转换

> ```c++
> int(value);
> (int)value;
> static_cast<转换类型> (value)
> ```

### auto

**编译器自动匹配类型**

> ```c++
> 数据类型是初始化的值
> auto a=0; a is int
> auto b=0.0; a is double //没用f结尾的都会被默认为double 类型
>
> ```

## Chapter4 :复合类型

### 数组赋初值

> 只有在定义数组的时候才能初始化，以后就不能用了了，也不能讲一个数组赋值给李ing外一个数组：
>
> ```c++
> int array[3]={1,2,4};  //数组赋值
>   											//在函数内不赋值，内容随机 在函数外都会被初始化
> int array[10]={0};			//数组内的元素都被赋值0；
>   											//再用arrary[10] 是指的是他的第10个元素所以不能在												赋予值
> short things[]={1,4,5,6} //编译器会计算元素个数
> sizeof array   <==> //
> ```
>
> 在c++11 中也可以这样
>
> ```asm
> double arr[4]{1.2,	1.3,	1.6,	3.4}; //省略等号
> unsigned int counts[10]={};						//全部初始化为0
> flat balance[100]{};					//all elements set to 0
> ```

### 字符串

> c++使用指针，而不是数组来处理字符串
>
> ```c++ 
> char shirt_size='S';			//是一个字符
> char shirt_size= "S";			// 是一个内存地址,char 数组 {'S','\0'}
> cout << "hello"  " " "kitty" <<endl; //字符串拼接会忽略空白 空格 制表符和换行符号
> char name[15] ="min";//实际存储 {'m','i','n','\0'}
>   										//	sizeof(name)=15 整个数组的长度
>   								   	// strlen(name) =8 不包括 ‘\0’
> -------------
> char d=cin.get(name,arSize).get();
> cout << static_cast<int>(d) <<endl;	//当d 为10的时候，说明 get()是换行符号，要不然就数组就满了
> -------------
> cin >> year;			//一般输入完后 就会带一个 换行符号
> cin.get();					//读取换行符 没保存，丢弃
> (cin >> year).get(); //也可以这样 或者(cin >> year).get(char);
> -----------
> ```

### string 类简介

> #### string 类
>
> > ```c++
> > string 类；
> > 在std 命名空间中 要加using namespace std;
> > 只能用 cin 或者cout 输入输出
> > 初始化：
> >  string temps="hello,kitty";
> > string temps={"hello,kitty"};
> > string temps{"hello,kitty"}
> > string s;
> > ```
>
>
> > cout << s;
> > cout << s.length() or s.size(); 获取字符串长度
>
>
> > cin >> s;  //输入字符类
> > getline(cin,s);//输入字符类
> > //getline 是istream的一个类方法
> > //cin 是 istream的一个类对象
>
>
> > ```c++
> > //string 对象可以直接加
> > string fuck=“hello”
> > fuck +=“ ，”
> > fuck +=“kitty”
> > fuck=“helloo ,kitty”
> > ```
>
>
> > ```c++
> > 数字的写入方法
> > cin >> 变量；		 // ‘\n’会被留在缓冲区 如果下一个也是数字就没关系
> > (cin >> 变量).get()//如果下一个是其他变量得这样写,清除缓存不留给其他字符
> >  								//cin 会忽略前面的空白符 和之后的空白符
> >  								//如果char 数组中间有空格 就不能这样写
>
> > 
>
> > ```c++
> > //字符数组和string的写入方法
> > cin.getline(str_array,length); //or  cn.get(str_array,length).get()
> > 
> > string 对象写入方法
> > getline(cin,string obj)
> > 
> > cin.get(ch),ch=cin.get() 一样只读取一个字符
>
>
> > ##### 其他字符串字面量
>
>
> > ```c++
> > wchar_t title[]=L"chief astrogator" ;//wchar_t string
> > char16_t name[] =u"felonia rropova" ; //char16_t string
> > char32_t car[= U"humber Supper Snipe";//char32_t string
> > ```
>
>
> > ##### 用R“()”来表示原始字符串
>
>
> > ```c++
> > cout << R"(your content)" << endl;
> > cout << R"(Jim "king" Tutt uses "\n" instead of endl.)" << endl;
> > 输出：Jim "king" Tutt uses "\n" instead of endl.
> > 如果也包含"(" and ")" 
> > 用 cout <<R"+*( your_content )+*" << endl;
> > ```
>

### 结构类型 struct

> 申明结构
>
> ```c++
> struct struct_name{
> char name[20];	//分号
> float volume;		//分号
> double price;			//分号。每一个成员都要加分号
> };				//分号结束结构
> ------------------------------------------------
> struct_name guest={  //初始化结构   有些实现用 static struct guest
> "Glorious Gloria",	//用逗号
> 1.88,								//用逗号
> 29.99
> };								//结尾用分号
> --------------------------------------------
> struct_name guest{  "Glorious Gloria",1.88,29.99};
> //初始化结构的另外一种方式
> struct_name guest{};//结构成员的每个字节都变成0；
> --------------------------------------------
> //用string类作为成员
> #include <string>
> struct infatable{
> std::string_name;
> float volume;
> double price
> };
> --------------------------------------------
> 结构数组
> struct_name array[100];//一百个 struct的数组
> --------------------------------------------
> 结构可以直接复制相同类型结构;
> struct_name1 = struct_name2
> 
> 
> 使用结构
> struct_name your_name; //新建结构变量,c++可以不使用关键字struct c要用
> struct_name hat; //新建另外一个结构
> 
> 用成员运算符来访问结构里面的成员
> 比如 hat.volume 
> //ps:cin.getline()的方式是访问结构成员变量衍生出来的
> ```
>
> **结构体模版**
>
> 结构不只是可以放数据 也可以放函数
>
> ```c++
> #include <iostream>
> using namespace std;
> 
> template<class T> //结构题模版
> struct Node{
> 	T data;
> 	Node<T> *next;
> 	void show(){std::cout <<"data:"<< data << std::endl;}
> 
> };
> 
> int main(){
> 	Node<int> *fuck=new Node<int>;
> 	Node<int> *temp=fuck;
> 	Node<int> *tt; 
> 
> 	for(int i=10;i<24;i++){
> 		fuck->data=i;
> 		fuck->next=new Node<int>;
> 		fuck=fuck->next;
> 	}
> 
> 	while(temp !=fuck){
> 		tt=temp;
> 		temp->show();
> 		temp=temp->next;
> 		delete tt;
> 	}
> 
> 	return 0;
> }
> ```
>
> 
>
> 
>
> 结构中的段字位
>
> ```c++
> struct torgle_register   //位啥占用四个内存空间看不懂
> {
> unsigned int SN:4;			//占用四个位
> unsigned int :4;				//占用四个位 空洞 没存名字，不使用
> bool goodIn:1;
> bool goodTorgle:1;		//占用1个位
> };
> 
> torgle_register tr={14,true,false};
> 
> if(tr.goodTorgle){
> do something...
> }
> ```



### 共用体 union

> ```c++
> union one4all{							//共用体的长度为其最大成员的内存
> int int_val;								//设置设置了一个成员，最好值访问这一个成员
> long long_val;							//因为是几个成员之间共用内存
> double double_val;					//再重新赋值别的成员,会覆盖之前的成员
> };
>
>
> one4all union_name;		//声明结构体
> union_name.int_val=22;
> cout << "union_name.int_val = " << union_name.int_val << endl;
>   				      //大爷
>
>
> ```
>
> union的用法：节省内存空间
>
> ```c++
> union id {
>    long id_num;
>    char id_char[20];
> };
>
> struct widget{
>    char brand[20];
>    int type;
>    id id_val;  //共用体放结构里面
> };
>
> widget temp;		//声明结构
>
> if(temp.type ==1)
>  cout << temp.id_val.id_num;
> else 
>  cout << temp.id_val.id_char;
> --------------------------------------------使用匿名结构
>  struct widget{
>    char barnd[20];
>    int type;
>    union {
>      long id_num;
>      char id_char[20]
>    			};
>  }
>
> widget temp;		//声明结构
>
> if(temp.type ==1)
>  cin >> temp.id_num;
> else 
>  cin >> temp.id_char;
>
> //由于共用体是匿名的，因此id_num和id_char被视为prize的两个成 员，它们的地址相同，所以不需要中间标识符id_val。程序员负责确定 当前哪个成员是活动的。
>
> ```

### 枚举类型 enum

> ```c++
> 在函数外 
> enum temp{red,green,yellow,blue,white,black};
>   				{0,1,2,3,4,5,6}
>
> main(){
>  temp color; //声明引用 temp枚举类型
>  color=red;  // color等于 red 等于0 
>
> }
> enum temp{red,green,yellow=1,blue,white,black};
> blue会等于2 
>   
> ```
>
> ```c++
> --------------------------------------------枚举类型
> enum spectrum {red,orange,yellow,green,blue,violt,indigo,ultraviole};
> 1）spectrum 称为 枚举类型
> 2）red,orange,yellow... 符号常量，他们对于整数1-7
>  
>  
>  
> #include <stdio.h>
>
> int main(){
>    enum week{ Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun } day;
>    scanf("%d", &day);
>    switch(day){
>        case 1: puts("Monday"); break;
>        case 2: puts("Tuesday"); break;
>        case 3: puts("Wednesday"); break;
>        case 4: puts("Thursday"); break;
>        case 5: puts("Friday"); break;
>        case 6: puts("Saturday"); break;
>        case 7: puts("Sunday"); break;
>        default: puts("Error!");
>    }
>    return 0;
> }
>
> ```

### 指针类型 pointer

> `<img src="/Users/macbookpro/Nas_Data/MD_FILE/pic/截屏2022-10-13 10.41.38.png" style="zoom:40%;" />`

> **c++中会要求指针初始化**
>
> **Int *p= new int;	//分配 适合存储 int 类型地址的内存空间 在堆空间（自由空间）**
>
> **delete p;**	    //释放内存,不指向任何一个内存地址了
>
> ``` c++
> int* ptr; //系统分配一个随机的内存空间
> *ptr=1235；		//随机的内存空间是不让读取的内存空间
>  						//好比买家电 留了一个没有房子的地址
>  						//所以家电放不进去房子里面
>
> ```
>
> 一定要在对指针应用解除引用运算符(*)之前，将指针初始化为一个确定的、适当的地址。 这是关于使用指针的金科玉律。
>
> 32位系统 指针是4个字节
>
> 64位系统 指针式8个字节
>
> ```
> 能对地址操作的就是 取出里面的内容
> ```
>
> **new**
>
> ```c++
> int *ptr=new int;
> //开辟一个可以存放int类型的内存空间，new 找到一个合适的地方并且把该空间的首地址存放到ptr中
> //由编译器实现的
>
> type_name *p =new type_name 
> // 编译器开辟一个足够放该数据类型的内存空间，找到之后把首地址存放到指针 p中
> //type_name 可以是别的数据结构，struct 等等
> ```
>
> **delete**
>
> ```c++
> int *pt=new int ;   //开辟堆中的内存
> 。。。
> delete pt;//把pt指向的内容清空，交回给操作系统
> 并且把pt的值;并且把pt的指向别处；所以所以不能用两次delete
> delete 只能释放new 开辟出来的内存空间，不能用他释放声明的变量 比如 （int a=6;）这种
>  
> int a=5;
> int *p_a=&a;
> delete a;//不允许这样
>
> ❎ 不要用两个指针指向同一一块内存空间
>  int *pt=new int;
>   int *pt2=pt;
>   delete pt2 ;;// 会释放一块内存两次；
> ```
>
> **new和delete使用动态数组**
>
> ```c++
> int *p_some=new int[10];
> delete [] psome; //释放整个数组
>   								//delete psome 是释放数组的第一个元素
>
> 开辟的是数组空间,delete的时候要加上 []
> 开辟的不是数组空间 不要用[]
>
> int* p_a=new int[100];
> delete [] pa;
>
> or
> int *p_v=new int;
> delete p_v;
>
>
>
> ```
>
> **指针其他**
>
> ```c++
> 数组名是 数组里面第一个元素的地址;
>   								//当使用sizeof(数组名)的时候，不会把数组名解释为第一个元素的地址
>   								//而且是整个数组
>
> int array[4]={1,2,3,4};
> int &pa=array;	//<==> int &pa= &array[0];
>
> sizeof(pa); <==> //指针自己所占用的空间
> sizeof(*pa); <==> // sizeof  *(&(pa+0))
>
> ```
>
> **数组的地址:重要概念**
>
> ```c++
>
> short tell[10];
> cout << tell << endl;   <<==>>  等于取第一个元素的地址 &tell[0]
>  											<<==>> 取出是两个字节内存块的地址
>  											tell +1 = tell +2个字节
> cout << &tell << endl;   <<==>>  等于取整个数组的地址 
>  											 <<==>>  取出是二十个字节内存块的地址 
>  											&tell + 1 = tell +20个字节
>   							//从数字上来说，&tell[0] 是两个字节块的的地址
>  							//&tell 是20个字节快的地址
>
>  
> short *p[20];// 是一个数组 数组每个元素都是short * 类型
> ```
>
> **数组指针:容易混淆的概念**
>
> ```c++
> short *p[20];
>   			//优先级(p[20])是一个数组，数组里面每一个都是short 类型的指针
> short (*p1)[20];
>   			//优先级(*p1) 这是一个指针,指向一个数组，数组里面啊有20个元素,每一个元素都是short类型
> ```
>
> ![](/Users/macbookpro/Nas_Data/MD_FILE/pic/截屏2022-10-13 23.54.09.png)

笔记

```c
int *pax[2];  //这是一个数组,包含两个指针 pax是数组的组名字
*(pax[0])=12;       //pax[0] 是数组的第一个元素
*(pax[0] +1)=13;    //pax[0] +1 是数组的第二个元素

cout << sizeof(pax) << endl;    //16
cout << sizeof(pax[0]) << " " << pax[0] << endl;
8          0x7ff7bfeff2f0

```

> 星靠近字母 就是一个指针，星不靠近字母就是是个指针

```c++
int *p[10];  //一个含有10个指针的数组；
for(int i=0;i<10;i++){
  p[i]=new int;  //为每个指针分配内存
  *p[i]=i+1;
}
```

```c++
int hello[10]={1,2,3,4,5};
int (*p)[10]=&hello;  //好像不能初始化  p还是数组名 p+1 = +40

for(int i=0;i<10;i++){
  (*p)[i]=i+1;
}

```

### 指针和字符串

> **重点**
>
> **char name[10]="min"**; // name 是字符串的首地址
>
> **Cout << (int *)name << endl; //cout** 遇到char 数组的时候，会打印内容，要强制转成 非char 类型指针
>
>> ```c++
>> char flower[10]="rose"; // flower 是 “rose” 第一个元素 ‘r’的地址
>>  											//数组名字 是元素的首地址
>> cout << flower << "\‘ 都很香"			//首地址
>> ```
>>
>> ```c++
>> char *p_str;
>> cin  >> p_str;  //错误，不能把字符串输入到连指向什么地方去的指针都没有的地方去；
>>  							//指针没有地方指，输入不进去字符串 
>>  							//应该先给字符串分配一些内存
>> ```
>>
>> ```c++
>> 打印字符数组的地址
>> char animal[20]="bear";
>> cout << "animal addr is= " << (double *)animal << endl; 
>>  													//cout 打印 char 类型的地址 会打印内容
>>  													//需要转成其他类型的地址 (int *) (double *)都ok
>> ```
>>

### new创建动态结构

> **访问结体成员**
> 1.结构体指针 ->结构体成员
> 2.结构体名称.结构体成员
> 3.(*结构体).结构体成员
>
> ---
>
> ```c++
> struct temp{				c++中可以省略struct c不可以
> char hello[10];
>   int name;
> };
> temp *p_struct =new temp; 
> p_struct->hello;    <==>  结构体
> ```
>
> **访问结构体的三种方式**
>
> ```c++
> struct struct_name{
>    char name[10];
>    int bad;
> };
>
> int main(void){
>    struct_name temp{"minliang",44};
>    struct_name *p=&temp;
>    //访问结构体的三种方式
>    cout << "结构.结构成员       " << temp.name << " " << temp.bad << endl;
>    cout << "(结构指针)->结构成员 "<< p->name << " " << p->bad << endl;
>    cout << "(*结构指针).结构成员 "<< (*p).name << " " << (*p).bad << endl;
>   
>    return 0;
> }
>
> ---------------
>
> ```
>
> ```c++
> //数据写入结构
>
> struct temp{
>    char name[20];
>    float value;
>    double price;
> };
>
> int main(){
>    temp *ps =new temp;
>    cout <<"Please enter the name:";
>    cin.get(ps->name,20);                   //字符串用cin.get（）
>    cout <<"please enter the value:";
>    cin >> (*ps).value;
>    cout <<"Please enter the peice:";
>    cin >> (*ps).price;
>    
>    cout <<"Name: " << ps->name << endl;
>    cout <<"value: " << (*ps).value << endl;
>    cout <<"price: " << (*ps).price << endl;
>    return 0;
> }
> ```
>
> ⚠️**重要概念,在函数里面要有返回值 得在函数里面新申请内存空间:然后返回地址**
>
> ⚠️**用函数里面的数组 不可以，必须得申请新的空间**
>
> ```c++
> #include <iostream>
> #include <cstring>
>
> using namespace std;
>
> char* get_char();
>
> struct temp{
>    char* name;
>        float value;
>        double price;
>    };
>
> int main(){
>    temp * ps=new temp;
>    cout << "Please enter the name:";
>        ps->name=get_char();
>        cout << "Please enter the value:";
>        cin >> ps->value;
>        cout << "Please enter the price:";
>        cin >> ps->price;
>    
>        cout <<"name:"<<ps->name <<endl;
>        cout <<"value:"<<ps->value <<endl;
>        cout <<"price:"<<ps->price <<endl;
>    
>        return 0;
>    }
>    
>    char* get_char(){
>        char name[200];
>        cin.get(name,200);
>    
>    size_t size=strlen(name);   //查询输入的长度
>    size++;                     //size+1；
>        char *fuck=new char[size];  //分配 size个字节
>        strncpy(fuck,name,size);  //从数组复制到指针中分配的空间中
>        //fuck[size]='\0';            //最后一个为 '\0' 证明是字符串
>        return fuck;                //返回分配空间的地址
> }
>    
> ```

### 重要概念：自动存储,静态存储和动态存储

> **自动存储 **
>
>> ```
>> 在函数内部创建的变量，在运行完函数之后，会被释放掉，不能返回给被调用的函数
>> 或者在{}里面创建的，比如for 循环 while 循环里面创建的变量 离开{}后就无效
>> 自动存储的变量放在栈中，先进后出来
>> {
>> {int a=1;}
>> a离开创建的{}内 无效了
>> }```
>>
>**静态存储**
> 
>> 静态存储 在整个程序执行期间都会存在
>
>>> 暂时可以定义为全局变量
>
>>
>**动态存储**
> 
>> new 和 delete 运算符提供了一种比自动存储和静态存储更灵活的方式
>
>>> 他们管理了一个内存池，在c++中叫做自由存储空间，或者叫堆
>
>>> 他们可以在一个函数中被分配，在另外一个函数中被释放
>
>>> 数据的生命周期不受程序和函数控制,要用delete释放掉，数据才会消失
>
>>
>> 内存泄漏：用new 申请的内存空间，没有用delete删除
>

### 组合类型

> **⚠️注意**
>
> **->** 比 * 的优先级高！！！ 记得多加括号
>
> 优先级。[]  -> *
>
> ```c++
> struct antrctica_years_end {
>  int year;
> };
>
> antrctica_years_end s01,s02,s03;//创建三个结构体；
> s01.year=1988	; 			//成员运算符访问他的成员
> antrctica_years_end *pa=&s01;
> pa->year=1989;								//指针访问他的成员
>
> antrctica_years_end trio[3];	//创建一个结构数组
>
> trio[0].years=2003;
>
> (trio +1).years= 2018； 			//也可以。trio[1].year=2018;
>  
> const antrctica_years_end *arp[3] ={&s01,&s02,&s03};
>   														//创建指针数组
>   														//指针数组访问成员
> cout << arp[1]->year << endl;
>
> //创建结构题指针数组的指针
> antrctica_years_end **ppa=arp;  //ppa 是 arp的首地址
>
> ```

### 数组的替代品 vector array

> **vector和 array**
>
> **vector**
>
> 头文件  vector
>
> 定义： vector `<type>` name(count);  vector<type_name> vt(n_elem);
>
> 长度不固定 用new 和 delete 管理内存空间，数据放在堆空间
>
> ```c++
> vector<int> vi(n); // 名称为vi  数量为n个int 类型;n必须得是变量或者常量
> vector<int> vi	; //长度为0
> 数据放在堆空间
>
> vi[index] 取值或者赋值
>
> ```
>
> **array**
>
> 头文件 array
>
> 定义的数组 长度大小是固定的，不可以用变量
>
> 定义 array<int,count> name;
>
> ```c++
> array <int,n> ar1; // 名称为ar1 的array的对象 内含n个int 类型的数据 
> array[index] 取值或者赋值
> ```
>
> 视频4.15
>
> **指针的一些重要概念**
>
> ```c++
> struct *pt= new struct[5];
> pt[1]			// *(pt+1)  第二个整个结构
> (pt+1)		//第二个结构的首地址
> (pt+1)->name		//第二个结构的首地址 访问成员 name
> *(pt+1)    //通过第二个结构的首地址 得到整个第二个结构
> (*(pt+1)).name //通过第二个结构的首地址 得到整个第二个结构,访问成员name
>  
> ```

## chapter5: 循环

> ```c++
> int i=0;
> for(int i=0;i<5;i++)
>   ...;
> cout << i << endl; i=100,这是循环体外面的i；
> //变量i 作用域只在循环体
> ```
>
> **表达式**
>
> ```c++
> //赋值左值为表达式的值
> ```
>
> **cout.setf(ios::boolalpha);**
>
> ```c++
> cout.setf(ios::boolalpha);
> //把布尔标志设置为 true 和 false 而不是1 和0
> ```

### 指针与 ++ -- 自增

> ```c++
> * ++ 优先级是一样的，从右到左的顺序
> *++pt;  //*(pt+1)  指针先加1 然后取值
>
> ++*pt;// 先去 pt里面的值，然后值先加1
>
> (*pt)++; //先取值，然后给值 加1
>
> *pt++; //先用pt 取值，然后给值加1
>
> ```

### 变量的作用域

> ```c++
> int main(void)
> {
>  int x=40;
>  {															// 也可以单独一个{ } ,被认作是一条语句；
>    cout << x << endl;					// 使用原来的的x;
>    int x=21;										//定义一个新的x
>    cout << x << endl;				 //使用的是新定义的x，离开被定义的作用域就失效
>  }
>   cout << x << endl;						 //使用原来的x；
> }
> ```

### 逗号运算符

> ```c++
> int x=5,y=4;			//如果在 逗号运算符前面加上了类型，逗号起到了分隔符
>
>   							//逗号分隔符						逗号运算符		
> for(unsigned long x=0,y=word.size()-1;x<y;x++,y--){
>  
> i=20，y=i*2;  //编译器会看看成一个表达式，该表达式的结果为第二个表达式
>  
>  int x,y;
> cout << (x=6,y=x+x) << endl; //结果为12
>  
>  所有的符号来说， 逗号的运算符是最低的
> cat=17,240; //看成两个表达式 
>  
> ```
>
> 视频5-

### clock 函数

> ```c++
> //要实现类似python里面的time.sleep(1)
> #include<ctime>
> int main(void){
> clock_t n_sec = 1* CLOCKS_PER_SEC; //CLOCKS_PER_SEC  每秒CPU运行的频率
> clock_t start=clock();//CPU已经运行的时间
> while(clock() -start < n_sec ); // 让程序空循环，获得time.sleep()的时间
> }
> ```
>
> 可以直接写成函数
>
> ```c++
> void time_sleep(float n){
>    time_t secs=n*CLOCKS_PER_SEC;
>    time_t start=clock();
>    while(clock() -start < secs);
> }
> ```

### 类型别名

> ```c++
> #define BYTE char
> typedef char byte;
>
> #define float_pointer float *; 小心使用
> float_pointer pa,pb;<==>//会变成 pa是指针类型 pb是float类型 
>  
> typedef float * f_pointer;
> f_pointer pa,pb ;//pa pb 都会变成指针
>
> ```

### do while 循环

> do while 最少会执行一次
>
> ```c++
> do{
> 	code_body;//最少循环一次
> }while(测试条件);    //常用于输入验证;
> ```

> ### c++11 for循环
>
> **新循环方式**
>
> ```c++
> double price[5]={4.66,4.66,45.66,3.44,2};
> for(double x:price)  //基于范围; 
> cout << x << endl;
> ```
>
> **要改变数组里面的数值**
>
> ```c++
> double price[5]={4.66,4.66,45.66,3.44,2};
> for(double &x:price)  //基于范围;   //&是引用变量 可以修改 不加& 只能访问
>   x=x * 0.8;
> ```
>
> **or**
>
> ```c++
> for(int x:{1,3,4,5,6})		//无名数组 {1,2,3,4,5,6}
>   cout << x << " ";
> cout << endl;
> ```

### 函数重载

```
什么叫函数重载？
函数重载允许创建多个同名函数,条件是他们的参数列表不一样

多个相关的函数，是用同样的函数名称;编译器会匹配
cin.get(char *,int);
cin.get(char);
cin.get(void);

```

### 文件尾条件

```c++
检测文件尾 EOF 
一般都是ctrl+Z

while(cin.fail() ==false) 
  #检测当前输入是否为EOF end of file
  #windows 用ctrl+z
  #mac 系统用ctrl+d
while(!cin.fail())				//也是检测是否为EOF
or
while(cin) 								//也是检测是否为EOF
  
while(cin.get(ch))
```

### 嵌套循环和二维数组

> ```c++
> 如下图所示：理解二维数组的指针
> int arr[10][5];		//arr[0]是6个int组成的数组
> int (*pa)[5]=arr; //10是行，多少行没关系，问题是每行有多少列；步长
> ```

`<img src="/Users/macbookpro/Nas_Data/MD_FILE/pic/截屏2022-10-19 04.57.57.png" style="zoom:50%;" />`

    `<img src="/Users/macbookpro/Nas_Data/MD_FILE/pic/截屏2022-10-19 05.28.30.png" style="zoom:50%;" />`

```c++
//操作三维度数组
#include <iostream>
#include <ctime>
//三维度数组 *(*(*(pa+index)+col)+fuck) 
//or pa[index][col][fuck]取值都可以

using namespace std;

void time_sleep(int n);

int main(void){
    float arr[10][3][3];
    float (*pa)[3][3]=arr;
    float temp=1.2;
    float total[30]={};
    int i=0;
    float f_total=0;
    float ff_total=0;
  
  
    for(int index=0;index<10;index++){
        for(int col=0;col<3;col++){
            total[i]=0;
    
            for(int fuck=0;fuck<3;fuck++){
                time_sleep(1);
                *(*(*(pa+index)+col)+fuck) = ++temp;
                total[i] +=pa[index][col][fuck];
                f_total +=pa[index][col][fuck];
                cout<< "pa[" << index <<"]["<< col << "][" <<fuck<<"]="<<pa[index][col][fuck]<<endl;
        
            }
            ff_total +=total[i];
            i++;
        }
    }
  
    return 0;
}

void time_sleep(int n){
    time_t now=clock();
    time_t temp=n*CLOCKS_PER_SEC;
    while(clock() -now < temp);
}

```

#### string类数组

```c++
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
int main(void){
     string pa[5]={
        "hello,kitty",
        "hello,mitth",
        "avc",
        "dddd",
        "aaaa"
    };


    for(int i=0;i<5;i++){
        cout <<pa[i] << " addr: "<<&pa[i]<< endl;
    }
    cout << endl;
  
    return 0;
}

```

### char* 数组注意

```c++
const char *pa[5]={  //记得加const ，要不然编译报错
        "January",
        "February",
        "March",
        "April",
        "May"
    }
```

## chapter6:条件语句

### 逻辑表达式

> ```c++
> && 	<==> 与 and	左边条件为假 就不判断右边
> ||  <==> 或	or   两个条件任意一个为真 就为真 左边为真,不判断右边 条件直接为真
> !   <==> 非	not
>
> ```
>
>> ⚠️注意
>>
>
>> ```c++
>> char ch=a;
>> cout << ch+1; // 会输出int类型
>> //应该这样写
>> cout << ++ch;
>> cout << char(ch+1);
>> ```
>>

### switch 语句

> ```c++
> switch(结果为整数的表达式)
> {
> case label1:代码;break;			//label1 为整数或者char类型常量的表达式
> case label1:代码;break;			//只是跳转到标签处
> default:都不匹配					//default 后面不用加 break 因为语句跳转到这里完
> }
> ```
>
> ```c++
> char ch;
> cin.get(ch);  //For input
> switch(ch){
> case 'a':					//'a'没有代码，讲执行和‘A’一样的选择
> case 'A': func();
> break;
> case 'b':
> case 'B': func(2);
> break;
>
> }
> ```

### 读取数字的循环

> ```c++
> int a,b;
> cout << "Enter number" << endl;
> cin >> a;					//假如输入的是abc,cin功能失效不在有输入的意义
> cin.clear();			//用cin.clear()输入功能，但是还会有abc继续留在缓冲区
> while(cin.get() !='\n'); //空循环语句，清除缓存取的abc
>
>
> ```
>
> ```c++
> //当要循环输入的时候;
> int arr[5];
> for(int i=0;i<5;i++){
> cout << "Please enter number #" << i+1<< ":"
> while(!(cin >>arr[i])){  //输入错误了；
>   	cin.clear();				//重置cin 要不然cin失效
>   	while(cin.get() !='\n');		//清除缓存
>   	cout << "Please enter number #" << i+1<< ":"	//提示再输入
> }
> }
> ```

### 简单的文件 IO

> **文件指针和cin的方法一样**
>
> ifstream fp;	   ofstream fp;  //fp.open(file_name) 之后
>
> fp >> 变量 和cout >> 变量 用法一样;
>
> 读取用ifstream 写入用ofstream;
>
>> #### 写入文本
>>
>
>> ```c++
>> #include <fstream> //文件流   需要用 ofstream
>> ofstream outfile;//创建对象
>> outfile.open("name.txt");
>> ```
>>
>> ```c++
>> outfile << fixed; //用小数点的方式显示
>> outfile <<percision(2);//显示小数点后两位
>> outfile.setf(ios_base::showpoint);//显示小数点读取文本
>> ```
>>
>> ```c++
>> #include <fstream> //文件流   需要用 ifstream
>> ifstream fp;			//实例类
>> fp.open(filename);	//读取文件   //filename 为一个连续的12 小数点
>> if(!fp.is_open()){   //判断文件是否打开 
>>        cout <<"FILE OPEN ERROR:"<<filename<< endl//提示文件打开失败
>>        exit(EXIT_FAILURE); //退出
>>    }
>> float value;  //读取文件的一些变量
>> float sum=0;
>> int count=0;
>> fp >> value;  //写入到变量中
>> while(fp.good()){    //循环读取
>>  sum +=value;
>>  count++;
>>  fp >> value;
>>    }
>> if(fp.eof())									//判断文件是否读完 
>>  cout << "End of file." << endl;
>> else if(fp.fail())						//文件失败
>>  cout << "Input terminated by data mismachted." << endl;
>> else		
>>  cout << "Error by unknow reason" <<endl;
>> if(count ==0)				//文件读取失败，个数没有加加
>>        cout << "No data" << endl;
>>    else{
>>        cout <<"Items read  :" << count << endl;
>>        cout << "Sum        : " << sum << endl;
>>        cout << "Average    : " <<sum/count << endl;
>>    }
>>    fp.close();    //关闭文件
>>    return 0;
>> }
>> ```
>>
>
>> ### 示例用法
>>
>
>> ```c++
>> 可以用
>> char ch;
>> while( fp.get(ch))... //遇到EOF 直接退出
>> 或者
>> if(!fp.open()){判断文件没打开....}
>> while(!fp.eof()){循环判断不是文件尾巴}
>> ```
>>
>
>> ```c++
>> using namespace std;
>> int main() {
>>    const char *filename="temp.txt";
>>    ifstream file_p;
>>    file_p.open(filename);
>>    char ch;
>>    while((ch=file_p.get()) && (ch !=EOF))   //file_p.get() 和 cin.get() 用法一样
>>        cout << ch;
>>    if(file_p.eof())
>>        cout<<endl <<"End of file" << endl;
>>    file_p.close();
>>    return 0;
>>    }
>> ```
>>
>
>> **cin捕获各种类型**
>>
>
>> ```c++
>>>//如果输入的是下面这行: 
>> //38.5 19.2  
>> char ch;
>> cin >> ch;  //ch为3的ascii码，其他在缓冲区 跳过空白字符
>> cin.get(ch);	//捕获任意字符
>> int n;
>> cin >>n;  //n为38的二进制编码  其他丢在缓冲区
>> double x;
>> cin >> x;  //n为38.5 ，空格19。2 都在留在缓冲区 
>> char word[50];
>> cin >> word;  //不断读取，遇到空白字符就结束 加上‘\0’（先越过空白字符）
>> char word[50];
>> cin.getline(word,50);//不断读取，知道不遇到换行符，并在结尾上空白字符，并将													缓冲区 换行符丢弃掉 
>> string_object: 
>> cin.getline(string_object);
>> ```
>>

## chapter7:函数

> 返回值必须和函数申明的一样
>
> 返回值类型，不能是数组,可以是指针,结构体，或者对象都可以
>
> 函数返回值放到寄存器或者指定的内存空间里面

> 对数组名字 sizeof 得到的是整个数组的长度
>
> ```c++
> int arr[5]={1,2,3,4,5};
> func(arr,5); //arr 传递进去的只是数组的第一个元素的首地址,
> ```

> ### const
>
> ⚠️**使用const的时候，必须在创建的时候进行初始化；**
>
> ```c++
> const 数据值只用 const指针,没有const的指针 不能指向带const的数据
> 所以要尽量用带const的指针
> ```
>
> ```c
> void func(const int arr[]);  //const 作用，不希望通过arr修改里面的值
> ----
> iny n=10;
> const int *p=&n; //不能通过 p修改指向的内容，但是指针可以指向别的地方 ，
>   								//可以n=20修改
>   								//*p是只读的 作用是const(*p)  *p是指向的值 
>   								//const int *p=&n <=等价于=> int const *p=&n;
> *pt +=1；//不允许
> cin >>	*pt; //不允许
> ----
> int n=10;
> int *const p=&n;	//p是只读的 不可以让p指向别的地方,可以通过*p修改n的值
>   								 //作用是*（const p）	 p是指针
> ---
> int n=10;
> const int * const p=&n;  //不能修改p指向的内容，也不能让p指向别的地方；
>
> ---
> // C++禁止 将const 地址 赋值给非const 指针
> const float f=1.2;
> const float * pf=&f;// 允许这样
> float *bf =&f;				//不允许这样
>
>
> ```
>
> ### **尽量的使用const**
>
> ```c++
> //避免由于无意间修改数据而导致的编程错误
> //const使得哈暗示能够处理const 和非const的实参数，否则值能接受非const数据
>
> ```
>
> ### **函数和二维数组**
>
> ⚠️牢记！！！数组名称是其第一个元素的地址
>
> ```c++
> 牢记！！！数组名称
> ```
>
> ```c++
> int data[3][4]={{1,2,3,4},{5,6,7,8},{2,4,5,8}};
> //此时 data是一个二维数组:  是{1,2,3,4} 的的地址
>
> int (*pt)[4] = data;
> //pt 是一个指针 指向一个一维数组 该一维数组里面有4个int 类型的指针
>
>
> ```
>
> ```c++
> //一维数组在函数传递参数的时候，有两个参数，1 第一个元素的首地址，数组的个数
>
> //因此二位数组传参数的时候，也要传递 首个元素的地址，还有数组的个数
> int arr[3][4]={{1,2,3,4},{5,6,7,8},{2,4,5,8}};
>
> //函数 原型
> int sum(int (*arr)[4], int size)；
>   					//int (*arr)[4] 是一个指针，指向一个数组，数组里面有四个int类型元素
>
>
>
> int (*arr)[4];//四个int 类型的数组所组成的数组
>   						//arr是指针，指向一个数组，数组里面4个元素都是int 类型
>
> 还有一种更好记的： int sum(int arr[][4],int size);
>
> ============================================================
>
> int *arr2[4]; //定义的是数组
>   							//数组里面有四个元素
>   					   //每个元素都是int * 雷曦ing的指针
>
> -------------
>
> 在函数里面取值 可以把指针当作数组名来使用
> ar2[r][c]   <=======>.   *(*(ar2+r)+c)
>
> ```

### 函数和C风格的字符串

> 简单 不写了

### 函数与结构

> 结构被看作是一个整体，一个结构可以赋值给另外一个结构
>
> 用函数是用的函数的副本

### 函数与string对象

> Sting 对象 可以直接赋值给另外一个string
>
> ```c++
> #include <iostream>
>
> using namespace std;
> const int size=5;
> void show(const string temp[],int n);
>
> int main(){
>    string list[size];
>    cout << "Please enter 5 your favourite food:" <<endl;
>    for(int i=0;i<size;i++){
>        cout << i+1<<":";
>        getline(cin,list[i]);
>    }
>    show(list,size);
>    return 0;
> }
>
> void show(const string temp[],int n){
>    for(int i=0;i<size;i++){
>        cout << "favourite food #" <<i+1 << ":" <<  temp[i] << endl;
>    }
> }
> ```

### 函数与array对象

> #### ⚠️⚠️
>
> ```c++
> //array 要当参数传递给函数的时候，会拷贝整个array对象的副本给函数使用，如果
> //要修改array对象里面的值,并且在函数里面要取指针得到整个array原始结构；
>
> void fill_arr(array<float,5> *pa);
> void show_arr(array<float,5> pd);
>
> int main(){
> 	array<float,5> arr_name;
> }
>
> void fill_arr(array<float,5> *pa){
>  for(int i=0;i<5;i++){
>    cin >> (*pa)[i] ;; //要取pa里面的array对象；
>  }
> }
> void show_arr(array<float,5> pd){
>  ...; //pd只是原始array的拷贝;
> }
>
> ```
>
> #### Array 对象初始化
>
> ```c++
> array<string,Seasons> Sname={"Spring","Summer","Fall","Winter"};
> ```
>
> #### 传递array对象指针
>
> ---
>
> ```c++
> #include <iostream>
> #include <array>
> using namespace std;
> const int Seasons=4;
>
> array<string,Seasons> Sname={"Spring","Summer","Fall","Winter"};
> void fill(array<float,Seasons> *ps);  //
> void show(array<float,Seasons> pa);
>
>
> int main(){
>  array<float,Seasons> expense={}; //arrary 对象声明的时候要 初始化啊
>
>  fill(&expense);
>  show(expense);
>  return 0;
> }
>
> void fill(array<float,Seasons> *ps){  //要用声明的数据类型,要传递整个array结构
>
> for(int i=0;i<Seasons;i++){
>   cout <<"Enter " << Sname[i] << " Expense :" << endl;
>   cin >> (*ps)[i];            //⚠️array对象的指针转换成array对象; *取指针的值
> 															//然后才能操作array 像操作数组一样；
>                               //Not ps[i];
> }
> }
>
> void show(const array<float,Seasons> pa){
> float total=0;
> for(int i=0;i<Seasons;i++){
>   cout << Sname[i] <<" Expense :" << pa[i] << endl;
>   total +=pa[i];
> }
>
> cout <<"Expense Total:" << total << endl;
> }
> ```

### 递归

> 在数据结构二叉树里面用的比较多o
>
> 函数自己调用自己，要添加终止条件，要不然会无限循环
>
> ```c++
> //结构
> void func(argmentlist){
>  statement1;
>  if(test)
>   		func(arguments);
>  statement2;
> }
>
> ```
>
> 循环后递归
>
> ```c++
> //
> // Created by macbookpro on 2022/10/27.
> //
>
> #include <iostream>
> using namespace  std;
>
> const int size=65;
> const char sign='|';
> const int range=6;
>
> void cut_down(char *temp,int left,int right,int size);
>
>
> int main(){
>    char temp[size]={};
>    for (int i=0;i<size;i++){
>        temp[i]=' ';
>    }
>    temp[0]=sign;
>    temp[size-2]=sign;
>    temp[size-1]='\0';
>    cout << temp <<endl;
>    for(int i=1;i<=range;i++){
>        cut_down(temp,0,size-2,i);
>        cout << temp << endl;
>    }
>    return 0;
>
> }
>
> void cut_down(char *temp,int left,int right,int size){
>    if(size==0)
>        return;
>    int mid=(left +right) /2;
>    temp[mid]=sign;
>    cut_down(temp,left,mid,size-1);
>    cut_down(temp,mid,right,size-1);
> }
>
> ```

### 函数指针

> **函数的参数是一个函数**
>
> 1. 获取函数的地址
> 2. 声明一个函数指针
> 3. 使用函数指针来调用函数

> **获取函数的地址**
>
> ```c++
> 如果think是一个函数
> process（think）；   //函数名字就是函数的地址
> thought(think());		//得到函数运行的结构
> ```
>
> **声明一个函数指针**
>
> ```
> 声明函数指针需要知道函数的参数，还有返回值
> double pam(int);			//函数原型
>   						
> double (*pf)(int) ;			//声明函数指针，要加括号优先级
>   											//函数名换成指针类型
>   											//pf智能指向 函数参数只有1个int类型并且返回值														是double的类型
> ```
>
> ```c++
> //声明的一些函数
> double add(double x,double y); 
> double sub(double x,double y);
> double mul(double x,double y);
>
>
> double use_func(double (*pf)(double,double) ,double x,double y);
> //声明一个水用函数的函数
> //double (*pf)(double,double) 函数指针，调用直接输入函数名就行了
> //double x,y为参数
>
> ```
>
> ❌错误示例
>
> ```c++
> double (*pf)(int);  //函数指针
> double* pf(int);		//是一个函数，返回类型是double *
>
> ---------
> double ned(double);
> int ted(int);
> double (*pf)(int);//只能指向参数为int 类型，返回值为double类型的函数
> pf=ned;			❌l
> pf=ted;			❌
>
>
> ```
>
> **调用函数**
>
> ```c++
> double pam(int);
> double (*pf)(int);
> pf=pam;
> double x=pam(4);
> //调用函数
> double y=(*pf)(4);  		// (*pf)是函数  不好看，但是是强有力的提示
> double z=pf(4);					//  pf是函数指针
>
> ```

### 深入理解函数指针

> **把函数放数组里面**
>
> ```c++
> double add(double x,double y);
> double sub(double x,double y);
> double mul(double x,double y);
> double pow(double x,double y);
>
> double (*func_arr[4])(double,double)={add,sub,mul,pow};
>   																			//函数数组
>
> auto fuck=&pf;									//整个指针数组
>   															// (*fuck) 取到该数组
>   															// (*fuck)[0]  == add;
>   															// (*fuck)[0](3,3)==add(3,3)
> ```

### typedef

> 用在函数类型里面
>
> ```c++
> typedef int real;  //定义简单的
>
> typedef const double* (*p_func)(const double *,int);
> //p_func  此时 p_func 编程类型
> //p_func new_name = 指向函数;
> //p_func new_arr[3];
>
> p_fun pa[3]={f1,f2,f3};	//有三个函数
> p_func (*pd)[3]=&pa;//有一个指针,指向三个元素，每个元素都是函数指针类型
>   		
>
>
> ```

## chapter8:函数的探幽

### C++内联函数

> **使用方法：在函数的声明 和定义前面都加上inline**
>
> 当代码量太大，或者使用递归的时候，加上inline 编译器也不会生成内联函数
>
> ```c++
>
> //内联和普通函数的关系：c++的编译器如何处理常规函数和如何处理常规函数
> //普通函数在调用的时候，会从主函数跳转到另外一个函数的内存地址中，执行完再跳回来
> //内联函数不会跳转到的函数中，直接在主函数中重写(优点：执行速度相对更快，缺点：占用内存相对较多一点)
> ```
>
> ```c++
> inline double square(double x){return x*x;}
> ```

### 内联函数与宏

> 定义宏有时候会出现错误，宏只是进行文本替换
>
> ```c++
> #define SQUARE(X) X*X
>
> a= SQUARE(5.0);==> a=5.0*5.0
> b= SQUARE(5.0 +7.5);==> b=5.0 +7.5*5.0 +7.5 ==》❌了
> d= SQUARE(c++); ==> d=c++ * c++;
>
> 应该写成 
> #define SQUARE(X) (X)*(X)
>  
> ```

### 引用变量

> **变量还是那个变量，就是起了个别名,主要用途是用作函数的形参，通过引用遍变量**
> **函数将使用原属数据而不是其副本**

#### 创建引用变量

> ```c++
> int rate;
> int &rdodents=rate;  	//引用变量永远效忠初始化的值,和初始化的地址
>   										//&不代表地址运算符，而是类型标识符的一部分
>   										//rdodents 是rate的别名，他们指向相同的值，和内存单元
> ⚠️//必须在声明变量的时候进行初始化；
> int rat;
>   int &rodent;
>   rodent =rat; ❌ //错误的的用法;
> ---------------------------------------
> int &b=a;	//实际上是下述代码的位伪装表示
> int* const b=&a; //不能引用别的变量；
> ---------------------------------------
> int fomefunc(int &a);
> int a=6;
> fomefunc(5); ❌//不能不能传递常量
> fomefunc(5+a); ❌//也不能不能传递常量+变量的表达式
> ---------------------------------------
> int fomefunc2(const int &a);  //不允许修改引用的值
> int a=6;
> fomefunc2(5); OK//和函数定义的参数不匹配的时候，参数带const 可以使用
> fomefunc2(5+a);//会计算表达式的结果，传递给一个临时变量，然后和形参关联起来
>  
> ```

#### 尽量多用const

> 1. **避免修改应用的值**
> 2. **加const可以使用带const和不带const的参数，要不然只能使用非const 参数**
> 3. **使用const 使用函数能正确生成并且，使用临时变量** 可以使用表达式,例如 func（a+5）

#### 将引用用作函数的形参

> ```c++
> 函数原型
> void myfunc(int & a,int &b);// 引用是数据类型加 &
> ```
>
> ```c++
> void swapr(int &a,int &b); //引用的函数申明
> void swapp(int *a,int *b);  //使用指针声明
> void swapi(int a,int b);   //使用拷贝
>
> int main(){
>  int wallet1=350;
>  int wallet2=300;
>  
>  swapr(wallet1,wallet2); //使用引用
>  //now wallet1=300;wallet2=350;
>  
>  swapp(&wallet1,&wallet2); //使用指针
>  //now wallet1=350;wallet2=300;
>  
>  swapi(wallet1,wallet2);
>  //wallet1 and wallet2 value no change;
>  return 0;
> }
>
> void swapr(int &a,int &b){		//引用函数原型
>  int temp;
>  temp=a;
>  a=b;
>  b=temp;
> }
>
> void swapp(int *a,int *b) //使用指针函数
> {	int temp;
> temp=*a;
> *a=*b;
> *b=temp; 
> }
>
> void swapi(int a,int b){ //使用拷贝
>  int temp;
>  temp=a;
>  a=b;
>  b=temp;
> }
> ```

### 将引用用于结构

> **引用通常用于结构体和类**
>
> ```c++
> struct free_throws{
> std::string name;
> int made;
> int attempts;
> float percent;
> }
> void set_pc(free_throws & ft);//引用结构
> void set_pc(const free_throws & ft);//引用结构不修改结构题
> free_throws & set_pet(const free_throws& ft);//可以返回操作后的结构
> ```

#### 将引用用于类对象

> 在函数里面声明的变量，不可以做为函数的返回值，因为函数作业完之后，所产生的变量会被销毁
>
> 同样也不可以把变量的引用做位返回值传递出去，变量不在了，引用也不在；

#### 对象 继承和引用

> 一般传递参数的时候，传递参数本身只是传递副本
> 当数据类型比较大的时候，比如结构，结构比较大，会影响程序运行速度，传递引起可以提高运行速度，而且传递的是数据本身
>
> ```c++
> //fstream 是是继承自 ostream
> 需要编写一个函数。在cout 和文件指针一同输出的时候,编写函数的时候可以引用父类
> 父类的引用,可以指向父类的对象，也可以指向子类的对象
>
> void file_it(ostream &os,...);  //函数原型 
> file_it(cout,...)	       //控制台输出
> file_it(fp,...)		//写入文件，
> ```

#### 如何传递参数，传递什么参数 （值，指针，引用）

> 不修改内容
>
> * 如果数据对象很小，如内置的数据类型，或者小型结构,传递值
> * 如果数据对象是数组，则使用指针,因为这是唯一的选择
> * 如果数据对象比较大的时候，使用const指针 或者const 引用
> * 如果数据对象是类对象，则使用const 引用
>
>  修改内容
> * 如果数据对象是内置数据类型，使用指针
> * 如果数据对象是数组，则使用指针
> * 如果数据对象是结构，用指针或者引用
> * 入股0哦数据对象是类对象，则使用引用=+

### 函数的默认参数

>示例,**带有默认值的都放在右边**
>
>```c++
>char *left(const char *str,int n=1); //在函数原型中写
>```

### c++ 左值右值 左值引用 右值引用  && 
>```c++
>左值引用：int &a=aa;    //aa可以取地址
>右值引用：int &&b=10;   //10不可以取地址
>```
>**可以取地址的叫做左值，不能取地址的叫右值**
>**引用必须和变量关联起来**
>
>```c++
>int a=10;     //10放寄存器里面
>int b=a;			//a只读，b可以读写
>int c= a+b;   //a和b是左值，a+b是右值
>							//可以取地址的叫做左值，不能取地址的叫右值？
>int *p=&a;		//可以取地址，左值
>```
>
>```c++
>a=10;
>int &b=a;  //左值引用
>int &c=10; //错误引用必须得是个左值
>```
>```c++
>int a=1;
>int b=2;
>int &c=10;   		  // ❌ not ok 右边必须取内存地址的变量
>int &c=(a+b); 	  //❌
>const &a =10;   	 //👌 const会让10在内存中生成临时变量
>const &c=(a+b);    //👌
>
>const 会让生成临时变量
>引用必须和变量关联起来//
>```
>

### 函数重载

>**函数名字一样，参数不一样**
>
>由函数的**参数类型，参数的个数,参数的排列顺序** 确定使用那个函数⚠️不看**返回值**
>
>函数的多种形式，函数允许有多种形式的存在，可以允许有多种名字
>
>函数多态和函数重载实际是一个样子

#### 两个函数名一样，参数名是两个，按照参数传值

>```c++
>//两个函数名一样，参数名是两个，按照参数传值
>void print(const char *str,int width); //#1
>void print(double d,int width);					//#2
>void print(long l,int width);						//#3
>void print(int i,int width);						//#4
>void print(const char *str);						//#5
>
>print("pancakes",15);	  //use #1
>print("Syrup");				  //use #5
>print("1990.0,10");			//use #2
>print(1999,12);				  //use #4
>print(1999L,15);        //#use #
>
>unsigned int year=3210;
>print(year,6);		//有二义性，只有一个函数，编译器会强制类型转换
>									//有三个同名函数，编译器不知道该转换哪种类型,会报错
>```

#### double和double引用，编译器看做同一种特征

>```c++
>double cube(double x); //double和double引用，编译器看做同一种特征
>double cube(double &x);
>cout << cube(x); //会出错，不知道调用那个函数
>```

#### 函数重载不区分const 和非const 变量;

>```c++
>函数重载不区分const 和非const 变量;
>
>//不带const的参数，可以传给参数为const的函数；
>//带const的参数，不可以传递给参数为非const的函数；
>```

#### 函数重载不看返回值

>```c++
>long grnok(int n,float m);
>double grnok(int n.float m); ⚠️//函数重复定义，不是重载
>-------------------------------------------------------
>long grnok(int n,float m);
>double grnok(float m.int n); //参数顺序不一样，即使返回值不一样，
>															//也会被认为是函数重载
>
>```

#### 参数为表达式 定义 &&

>```c++
>参数为表达式 定义 &&
>void func(double &&r1);  //参数为表达式，或者右边值
>--------------------------------------------------------
>void stove(double &r1);          //#1
>void stove(const double &r2);    //#2
>void stove(double &&  r3);       //#3
>
>const double y=55.0;
>double x=32.0;
>stove(x);                   //use #1
>stove(y);                   //use #2
>stove(120);                 //use #3  如果没定义#3 会用#2
>stove(x+y);                 //use #3  如果没定义#3 会用#2 
>														//右值引用
>
>```
>

#### 什么时候使用函数重载

>```c++
>//当函数基本执行相同的任务；但是用不同的形式的数据，才应该采用函数重载
>
>```
>
>

### 函数模版

函数模版不是函数！！

>在用函数的时候，编译器根据调用的形参生成新的函数供你使用
>
>
#### 交换函数
>
>```c++
>//交换函数,如果要交换三种数据类型，double 等，需要写三个差不多的函数
>//这个时候应该用函数模版
>void swap(int x,int y);
>void swap(int x,int y){
>	int temp;
>	temp=x;
>	x=y;
>	y=temp
>}
>
>```
>
#### 定义函数模版
>
>```c++
>template <typename AnyType> //AnyType 是函数模版名字
>														//写成 template <class AnyType> 
>                   		//函数被使用的时候，会生成新的函数
>void swap(AnyType &a,AnyType &b){
>	AnyType temp;
>	temp=a;
>	a=b;
>	b=temp;                              
>}                         
>```
>
#### 使用函数模版
>
>```c++
>#include <iostream>
>
>using namespace std;
>
>template <typename  T>  // 函数原型的时候要用函数模版 typename T 之间不要逗号
>void exchange(T &a,T &b);
>
>int main(){
>
>int i=10;
>
>int j=20;
>
>cout << "i,j = "<<i<<","<<j<< endl;
>exchange(i,j);
>cout << "after exchange i,j = "<<i<<","<<j<< endl;
>double x=24.5;
>double y=45.6;
>cout << "x,y = "<<x<<","<<y<< endl;
>exchange(x,y);
>cout << "after exchange x,y = "<<x<<","<<y<< endl;
>
>}
>
>template <typename T>   // 函数定义的时候也要用函数模版
>void exchange(T &a,T &b){
>T temp;
>temp=a;
>a=b;
>b=temp;
>}
>
>```
>
#### 函数模版的其他用法
>
>```c++
>#include <iostream>
>using namespace std;
>
>template <typename  T>  // 函数原型的时候要用函数模版 
>void func(const T &a,int b=1);  //默认参数卸载
>
>int main(){
>    int hello=56666;
>    func("hello",2);    //T 变成 template  char*
>    func(6,4);          //参数类型是常量,必须加上const或者函数参数 
>  													//为引用右边值
>    func(hello);           //只有一个参数，会使用默认参数
>    return 0;
>
>}
>
>template <typename  T>  // 函数原型的时候要用函数模版 typename T 之间不要逗号
>void func(const T &a,int b){
>    while(b--){
>        cout << a<< " ";
>    }
>    cout << endl;
>}
>```

#### 重载的模版

>**再多个函数同名的时候，由参数决定用那个模版，再由数据类型，模版决定生成那个函数**
>
>```c++
>#include <iostream>
>using namespace std;
>
>template <typename  T>  // 函数原型的时候要用函数模版 typename T 之间不要逗号
>void exchange(T &a,T &b);
>
>template <typename T>                   // 第二个函数模版  两个函数名字一样
>void exchange(T a[],T b[],int n);       // 编译器看参数决定用什么模版
>
>void show(int arr[],int n);
>const int LIMIT=8;
>
>int main(){
>
>    int i=10;
>    int j=20;
>  
>    cout << "i,j = "<<i<<","<<j<< endl;
>    exchange(i,j);
>    cout << "after exchange i,j = "<<i<<","<<j<< endl;
>    double x=24.5;
>    double y=45.6;
>    cout << "x,y = "<<x<<","<<y<< endl;
>    exchange(x,y);
>    cout << "after exchange x,y = "<<x<<","<<y<< endl;
>
>    int d1[LIMIT]={1,7,6,5,4,3,1,2};
>    int d2[LIMIT]={2,2,2,2,2,2,2,2};
>    cout <<"Origianl arrays:" << endl;
>    show(d1,LIMIT);
>    show(d2,LIMIT);
>    exchange(d1,d2,LIMIT);
>    cout <<"exchange later arrays:" << endl;
>    show(d1,LIMIT);
>    show(d2,LIMIT);
>}
>
>template <typename T>   // 函数定义的时候也要用函数模版
>void exchange(T &a,T &b){
>    T temp;
>    temp=a;
>    a=b;
>    b=temp;
>}
>
>template <typename T>			
>void exchange(T a[],T b[],int n){
>    T temp;
>    for(int i=0;i<n;i++){
>        temp=a[i];
>        a[i]=b[i];
>        b[i]=temp;
>    }
>}
>
>void show(int arr[],int n){
>    for(int i=0;i<n;i++){
>        cout <<arr[i] <<" ";
>    }
>    cout<< endl;
>}
>```
>
>

### 模版的局限性 显式具体化

>相同名称函数的优先级：
>
>**普通函数**  大于 **显式具体化的函数** 大于 **普通模版函数**
>
>```c++
>//普通函数，优先级最高
>void Swap(job&,job&);
>
>//显式具体化函数，优先级第2名
>template<>
>void Swap<job>(job& j1,job &j2);
>
>//普通函数模版,优先级最低
>template<class T>
>void Swap(T& t1,T&t2);
>
>
>
>
>```
>
>
>
>显示具体化 函数原型
>
>**template <>void Swap<job>(job &j1,job &j2)；**
>
>**template<>为空，job为特殊处理的函数类型**
>
>```c++
>struct job{
>name char[20];
>double salary;
>int age;
>}
>
>template <typename T>   // 函数定义的时候也要用函数模版
>void exchange(T &a,T &b){
>T temp;
>temp=a;
>a=b;
>b=temp;
>}
>
>job minliang={"minlang",1000,33};
>job minrui={"minrui",3,6};
>
>当用交换函数交换  结构minliang 和 minrui的时候
>所有的都会被交换，名字，年龄，工资
>这个时候要用显示具体化
>
>template <>void Swap<job>(job &j1,job &j2){
>	float temp_salary;
>	int temp_age;
>	temp_salary=j1.salary;
>	j1.salary=j2.salary;
>	j2.salary=temp_salary;
>	temp_age=j1.age;
>j1.age=j2.age;
>j2.age=temp_age;
>
>}
>
>
>```
>
>```c++
>#include <iostream>
>using namespace std;
>
>
>struct job{
>char name[20];
>float salary;
>int age;
>};
>
>template <typename T>
>void Swap(T &a,T &b);
>
>template <>   //特殊的数据类型，再重新编写一个函数 <>留空
>void Swap<job>(job &a,job &b); //特殊的数据类型 卸载函数后面 job
>
>
>
>int main(){
>int a=30;
>int b=20;
>job minliang={"minliang",3,5};
>job minrui={"minrui",3000,35};
>cout <<"a = " << a << endl;
>cout <<"b = " << b << endl;
>cout <<"minliang:" << minliang.name <<" " << minliang.salary << " " << minliang.age << endl;
>cout <<"minrui:" << minrui.name <<" " << minrui.salary << " " << minrui.age << endl;
>
>Swap(a,b);
>cout <<"a = " << a << endl;
>cout <<"b = " << b << endl;
>Swap(minliang,minrui);
>
>cout <<"minliang:" << minliang.name <<" " << minliang.salary << " " << minliang.age << endl;
>cout <<"minrui:" << minrui.name <<" " << minrui.salary << " " << minrui.age << endl;
>
>
>
>return 0;
>}
>
>template <typename T>
>void Swap(T &a,T &b){
>T temp;
>temp=a;
>a=b;
>b=temp;
>}
>
>template <>
>void Swap<job>(job &a,job &b){
>float temp_f;
>int temp_i;
>temp_f=a.salary;
>a.salary=b.salary;
>b.salary=temp_f;
>temp_i=a.age;
>a.age=b.age;
>b.age=temp_i;
>}
>
>
>```
>
>

### 显式具体化与显式实例化

>显示具体化的用法，不知道对不对
>
>>```c++
>>//file_name: main.cpp
>>#include <iostream>
>>#include "head.h"
>>>using namespace std;
>>>extern template void Swap(int &a,int &b); //引入外部的Swap 生成 void Swap(char m)
>
>>int main(){
>>char a='a';
>>	char b ='b';
>>	swap(a,b);
>>	cout << a << " "<<b << endl;
>>	return 0;
>>
>>>}
>
>>using namespace std;
>>extern template void Swap(int &a,int &b); //引入外部的Swap 生成 void Swap(char m)
>
>>int main(){
>>	char a='a';
>>	char b ='b';
>>	swap(a,b);
>>	cout << a << " "<<b << endl;
>>	return 0;
>>}
>
>>```
>
>>```c++
>>//file_name:head.h
>>#ifndef __HEAD__H__
>>#define __HEAD__H__
>>>template<class T>
>>>void Swap(T&t1,T&t2);
>
>>>#endif
>
>
>
>>```
>
>>```c++
>>//file_name:head.cpp
>>#include "head.h"
>>template<class T>
>>void Swap(T&t1,T&t2){
>>	T temp=t1;
>>	t1=t2;
>>	t2=temp;
>>}
>
>
>
>>```
>
>
>
>
>
>显示具体化是为特殊的数据类开辟一个特殊的通道，不让其使用通用模版，不调用不生成具体函数定义
>
>显示实力化，无论该函数是否要被使用，编译器都会生成函数
>
>```c++
>template void Swap(int &a,int &b); //显示实力化 不代 <>
>															//调用不调用都先生成 函数定义
>											//链接其他文件 调用函数之前要有生成的函数定义？
>											//多次生成的函数定义，函数地址也不一样
>											//要写在用的地方
>---------------------------------------------------------------
>
>template <> void Swap<int>(int &,int &);
>template <> void Swap(int &,int &);// 两个具体化其实一样
>													//函数名后面<>里面的数据类型可以省略
>
>
>```
>
>```c++
>template <class T>    #1 函数通用模版
>void Swap(T &,T&);
>
>template<>void Swap<job><job &,job &>; #2 显示具体化
>
>template void Swap<char>(char&,char&);  #3 char的显式实例化  //
>
>int main(void){
>
>short a,b;
>...
>swap(a,b);//调用通用的模版去处理
>job n,m; 
>...
>swap(n,m); //job显示具体化 #2 去处理
>char g,h;
>...
>swap(g,h);//使用 #3  char的显式实例化去处理
>...
>}
>
>```

### 多个重名函数，编译器会匹配哪个？
>**编译器会优先匹配最符合参数定义的函数，最简单，最直接，最能匹配 就是最佳的**
>
> ```c++
> 一共有7个函数，或者函数的模版
> void may(int);								//#1
> float may(float,float=3);			//#2
> void may(char);								//#3
> char * may(const char *);			//#4
> char may(const char &);				//#5
> template <class T> void may(const T&);//#6
> template <class T> void may(T *);			//#7
> 
> may('B');//该调用哪个函数？
> 				//排除#4 和#7 因为参数为指针类型 其他都是可行的
> //  #1 优于 #2
> //	#3 #5 #6优于 #1和 #2
> //  #3 #5 优于 #6 普通函数 优于函数模版
> 
> ```
>
> ```c++
> 假如有一下的函数代码;
> struct blot{
>   int a;
>   char b[10];
> }
> 
> blot ink={25,"spots"};
> 
> recycle(ink);//使用recycle 函数
> 
> //下面的函数原型都是完全匹配的
> void reecycle(blot)	;				//#1 	blot to blot
> void reecycle(const blot);	//#2 	blot to (const blot)
> void reecycle(blot &);			//#3	blot to (blot &)
> void reecycle(const blot &);//#4 	blot to (const blot &)
> 
> //如果有多个匹配原型，编译器不知道匹配哪个函数
> //此时编译器会生成错误的消息，例如“ambiguous (二义性)
> 
> recycle(ink);只有函数#1和#2的时候，就不知道匹配那个函数了
> recycle(ink);只有函数#3和#4的时候，优先匹配#3
> 非const参数 优先匹配非const函数，找不到了，再匹配conss函数（限于指针和引用）
> 
> ```
>
> 

### 自己自己选择要调用的同名函数

> 一般函数模版是由编译器决定，可以明确告诉编译器 使用指定的函数*
>
> func<>(参数)；<> 表示告诉编译器使用模版函数
>
> func<int>(参数);<> 表示告诉编译器将参数类型转换成int 类型,然后使用模板函数
>
> ```c++
> template <typename T>    //模板函数
> T lesser(T a,T b )；
> 
> int lesser(int a,int b)；//普通函数，编译器优先使用普通函数
> 
> int m=20;
> int n=-30;
> double x=15.6;
> double y=23.6;
> 
> lesser(m,n);  //和普通函数类型匹配，优先使用普通函数
> lesser<>(m,n);	// <> 表示 明确告诉编译器使用模版函数
> lesser(x,y);		//和普通函数类型不匹配，编译器会使用模版函数
> lesser<int>(x,y);// <int>表示,将参数强制类型转换为int,然后使用模板函数
> 
> ```
>
> 

### 模版函数有多个值的时候，函数里面不确定数据类型的时候

>**template <class T1,class T2>**
>**Void func(T1 &a,T2&b);  //用多种数据类型分别起名字**
>
>⚠️**新关键字 decltype **（c++11） 也包括const 限定字符
>
>decltype(x) y;  // y 声明为和x一样的数据类型
>
>```c++
>int x=5;
>decltype(x) y;  // y 声明为和x一样的数据类型
>decltype(x+y) z; //
>
>decltype(函数(x,y)) z; //z的数据类型和函数的返回值相同
>											//不会调用函数，直接看返回值
>
>double xx=5.5;
>decltype((xx)) r2=xx; //rr是double & 引用
>decltype(xx) w=xx;		//w是double 类型
>```
>
>
>
>
>```c++
>template <class T1,class T2>
>void ft(T1 &a,T2 &b){
>...
>?which_type? xpy=a+b;  //❌xpy不知道何种数据类型
>decltype(x+y) xpy=a+b; //应该这样写
>...
>}
>
>```
>
>**通用模版返回值的问题**
>
>```c++
>template <class T1,class T2>
>decltype(x+y) ft(T1 &a,T2 &b)；❌用法错误
>  
>//应该写成
>template <class T1,class T2>
>auto func(T1 &a,T2 &b) ->decltype(x+y){ 
>  ...
>  return x+y;
>}				//decltype(x+y) 是推断返回值，函数声明和原型都要写
>```
>
>

## chapter9:内存模型和名称空间

### 单独编译

>File1.cpp  file2.cpp 
>
>会生成目标代码文件。file1.o file2.o
>
>然后生成可以执行文件 a.out
>
>⚠️**g++ file.cpp file2.cpp  注意 编译的时候，不要包含头文件**
>
>头文件 
>
>#ifndef 任意名
>
>#define 任意名
>
>#endif
>
>

**⚠️头文件**

>函数原型
>
>使用#define 或者 const 定义的符号常量
>
>结构声明  (不会开辟内存空间,只是告诉编译器该干啥)
>
>类声明
>
>模版声明和定义，分开定义会出错;
>
>内联函数
>
>⚠️如果有名称空间应该全部包裹在名称空间中

⚠️**函数实现文件**

>⚠️如果有名称空间应该全部包裹在名称空间中
>
>

⚠️**包含main函数的源代码**

>
>
>如果有名称空间应该using namespace 名称空间;
>
>or
>
>using 名称空间::变量，或者函数吧；



### 存储持续性 作用域和链接性

**存储数据**

>**1.自动存储持续性：**在函数定义中声明的变量，在函数或者块中创建，执行完函数，内存会被释放。
>
>**2.静态存储持续性：**在函数外创建的变量，或者使用关键字static创建的变量，在整个程序运行过程中都存在（也叫全局变量）
>
>**3.线程存储持续性：**
>
>**4.动态存储持续性：**用new运算符分配的内存一直都存在，直到使用delete运算符将其释放，这种内存的存储持续性为动态，有的时候会被称为自由存储（free store）或者堆（heap）；
>
>

**作用域**

>函数中定义的变量，只能在函数的内部使用，不能载其他函数中使用，而在文件
>
>>1.cpp中的变量不可以在2.cpp中使用 可以在2.cpp中声明  extern 1.cpp中的变量；
>
>

**自动存储持续性**

>自动存储持续性：**在函数定义中声明的变量，在函数或者块中创建，执行完函数，内存会被释放。

**auto 关键字** 寄存器 变量

>中间都没讲 有时间补充一下 #TODO：

**extern 关键字 双冒号:: 在函数内使用全局变量**

>编译命令 g++  external.cpp support.cpp
>
>```c++
>//file_name:   external.cpp 
>//主文件 包含 main函数
>
>#include <iostream>
>#include "support.h"   //包含头文件 
>
>using namespace std;
>
>double warming=0.3; //全局变量
>
>int main(){
>    cout <<"Global warming is " << warming <<"\n";
>    update(0.2);
>    cout <<"Global warming is " << warming <<"\n";
>    local();
>    cout <<"Global warming is " << warming <<"\n";
>
>    return 0;
>}
>```
>
> ```c++
> //file_name: support.h
> 
> #ifndef __SUPPORT_H
> #define __SUPPORT_H
> 
> #include <iostream>
> 
> extern double warming; //引用全局变量  加上extern 关键字
> 
> void update(double dt);			
> 
> void local(void); // 
> #endif  
> ```
>
>```c++
>//file_name: support.cpp
>
>#include "support.h"  //包含头文件
>
>using namespace std;   //使用命名空间
> 
>void update(double dt){
>    warming +=dt;      //使用全局变量 warming 
>    cout <<"Update global warming to " << warming << " degrees\n";
>
>}
>
>void local(void){
>    double warming =0.8;
>    cout <<"Local Warming is " << warming << " degrees\n";
>    cout <<"But global Warming =" << ::warming <<" degrees\n"; // ::表示使用全局变量
>
>}
>```
>
>

**静态持续性，静态链接性**

>Static 限定符 用于作用域做为整个文件的变量时,该变量的链接性将为内部的，只能用于定义的文件内
>
>常规的外部变量可以被别的文件使用，static 不可以
>
>```c++
>//file1
>int errors=20;
>int main(){};
>--------------
>//file2
>int errors=5; //❌重复定义  可以加上static 限定符  
>								//static int errors=5; 可以这样写 
>
>```
>
>```c++
>//file1
>int errors=20;
>int main(){};
>--------------
>//file2
>static int errors=5; //static 的连接性为内部，不给外部使用   使用就近原则
>											//可以供给定义文件中的其他函数使用
>
>
>```
>
>>编译命令 g++ file1.cpp file2.cpp && ./a.out
>
>>```c++
>>//file_name:file1.cpp
>>#include <iostream>
>>using namespace std;
>>
>>int tom=3;
>>int dick=30;
>>static int harry=300;
>>
>>void remote_access(void);  //链接两个文件还是要加函数声明；
>>
>>int main(){
>>cout <<"main() reports the following address:"<<endl;
>>cout <<"&tom=" <<&tom <<" ,&dick=" << &dick  <<" ,&harry=" << &harry <<endl;
>>remote_access();  //外部函数
>>return 0;
>>} 
>
>>>```c++
>>//file_name:file1.cpp
>>#include <iostream>
>>using namespace std;
>>extern int tom;  //声明要引用外部变量 tom
>>static int dick=10;
>>int harry=300;
>>
>>void remote_access(void){
>>cout <<"remote_access() reports the following address:"<<endl;
>>cout <<"&tom=" <<&tom <<" ,&dick=" << &dick  <<" ,&harry=" << &harry <<endl;
>>}
>
>>```shell
>>main() reports the following address:
>>&tom=0x10dc790c0 ,&dick=0x10dc790c4 ,&harry=0x10dc790c8   //tom 是同一个变量，其他不是
>>remote_access() reports the following address:
>>&tom=0x10dc790c0 ,&dick=0x10dc790d0 ,&harry=0x10dc790cc
>>```
>
>

**静态存储持续性，无链接性** static在函数内用法

>**static 在代码块里面创建的变量，存储特定为静态的，程序运行就存在**
>初始化 静态局部变量只会被初始化一次,
>
>```c++
> void GetSize(char *st){
>    static int size=0;   //只会被初始化一次
>    size +=(int)strlen(st);
>    cout <<"characters size total =  " << size << endl;
>    }
>```
>
>

### 说明符和限定符号

**const**

>在c++中,const的全局变量的连接性为内部的，也就是说在其他文件中不可以看到(和c不一样)
>
>```c++
>//如果在头文件定义两个const 变量
>const int fingers=10;
>const char * warning="Walk!";
>//如果有多个变量包含这个头文件，多个文件一起编译的时候，就会出错，定义了多个重名变量
>
>```
>
>

**auto**

>

**register**

>

**mutable**

>即使结构被定义为const,其成员也是可以被修改的
>
>```c++
>struct data {
>  char name[20];
>  mutable int accesses; 
>}
>const data veep ={"hello",1};
>strcpy(veep.name ,"fuck")// not allow ❌
>data.accesses++ ; //allow
>```
>
>

**extern**

>

**static**

>

**thread_local** 

>

**volatile**

>容易变的

### 函数的连接性

>
>
>不允许在函数中定义另外一个函数，所有的函数都是静态的
>
>可以在函数原型中用关键字**extern**来声明函数是在另一个文件中被定义的
>
>可以使用关键字static将函数的链接性设置为内部的，只能在定义的文件中使用，其他文件可以定义同名函数，使用static关键字，即使外部有同名函数，文件也只会使用内部的用static修饰过的函数



### 存储方案和动态分配

使用new运算符初始化

>**new 初始化 int double**
>
>```c++
>int *pi=new int(6); 					// *pi set to 6 
>double *pd= new double (99.99);// *pd set to 99.99
>
>int *pi=new int{5}; 			//用花括号初始化也可以；
>double *pd= new double {99.99};
>```
>
>**New  初始化结构**
>
>```c++
>struct where{
>  double x;
>  double y;
>  double z;
>};
>
>where * one=new where{2.3，34.4，23.4}；//初始化结构  用“{}”
>```
>
>**New 初始化数组**
>
>```c++
>int *p=new int[10]{1,2,3,4,5,5};  //p指向含有10个int类型的数组
>
>
>```

**new 初始化失败**

>请求内存失败会返回空指针
>
>现在请求失败会促发异常.    **std::bad_alloc**

**定位new 运算符**

>New 负责在堆（heap）找到一个足够满足条件的内存块
>
>一般来说new分配的内存都是由系统自动分配
>
>**可以指定new分配的特定的内存地址 需要包含头文件 new**
>
>```c++
>#include <iostream>
>#include <new>         //new头文件
>struct temp{        //结构
>char name[20];
>int age;
>};
>char buffer[500];   //全局变量  开辟的内存空间
>
>int main(){
>std::cout << &buffer << std::endl;  //查看char 内存地址
>temp *pa=new(buffer) temp{"minliang",30}; //分配指定的内存，并且初始化
>std::cout << pa << std::endl;  //查看new 分配的内存地址
>std::cout << &pa->name << std::endl;  //查看结构的内存地址
> delete pa;//错误，pd指向的是静态内存空间，delete只能删除动态内存空间（堆空间）
>return 0;
>}
>
>```
>
>```shell
>0x10c026040  #运行结果全是一样的
>0x10c026040
>0x10c026040
>```
>
>

### 名称空间



>**自定义名称名称空间 函数头和函数的实现方法都要用namespace space_name{}包裹起来**
>
>```c++
>void SALES::Sales::reset()；
>函数原型：
>  命名空间SALES 
>  类名称SALES；
>  函数名称 reset；
>```
>
>```c++
>// head_file.h
>namespace 空间名{
>const 变量；
>struct 结构体;
>	函数原型;
>}
>
>//func_file.h. 函数实现文件
>namespace 空间名{
>函数的实现;
>}
>
>//main文件
>using namespace 空间名；
>int main(){
>using namespace 空间名；//定义在这里也ok;
>}
>
>```
>
>
>
>**两个名称空间**
>
>```c++
>namespace Jack{
>double pail;
>void fetch();
>int pal;
>struct well{...};
>};
>
>namespace Jill{
>double backet(double n){...};
>double fetch;
>int pal;
>stuct Hill{...};
>};
>```
>
>**添加至名称空间**
>
>```c++
>#include <iostream>
>
>namespace std{      //加入到std 空间中   //
>int hello=6;
>int *p_hello=&hello;
>}
>
>int main(){
>*std::p_hello=9;  //取命名空间里面的值;
>std::cout <<std::hello<< std::endl;
>
>return 0;
>}
>```
>
>匿名名称空间作用域当前文件
>
>```c++
>namespace {
>y=6
>}
>void some func(){
>cout << y << endl; //使用当前文件匿名空间y
>}
>```
>
>
>
>**访问名称空间：：**
>
>没加：： 未限定的名称空间
>
>```c++
>Jack::pail=12.34;  //use a variable
>Jill::hill mole;   //create a teype hill struct;
>Jack::fetch();		//use a function;
>```
>
>using 声明和using编译指令
>
>```c++
>using namespace std;
>
>using std::cin; 
>
>```
>
>```c++
>namespace Jill{
>double backet(double){};
>double fetch;
>struct Hill{...};
>}
>
>char fetch;
>
>int main(){
>using Jill::fetch;
>double fetch ;//error
>cin >>fetch ;			// cin into Jill::fetch
>cin >> ::fetch;    // into 全局 fetch
>}
>```
>
>```c++
>namespace Jill{
>double backet(double){};
>double fetch;
>}
>
>using jill::fetch;// 把局部变量 放到全局变量中
>int main(){
>cin >>fetch ;//read a value into Jill::fetch;
>
>}
>void other(){
>cout << fetch;//display Jill:fetch;
>}
>```
>
>```c++
>namespace Jill{
>double backet(double){};
>double fetch;
>}
>char fetch;
>int main(){
>---------------------------------
>using Jill::fetch;
>double fetch; //❌，not allow，已经定义好 不允许有两个相同名称的变量
>
>---------------------------------
>
>using namespace Jill;
>int fetch; 					//不会冲突，会隐藏Jill::fetch;
>cin >> fetch;  			//local fetch
>cin >> ::fetch; 		//global fetch;
>cin >> Jill::fetch;	// Jill::fetch;
>}
>```
>
>```c++
>#include <iostream>
>
>using namespace std;
>
>namespace min{
>char name[20]="minliang";
>}
>
>namespace min2{
>char name[20]="minliang2";
>}
>
>int main(){
>using namespace min;
>using namespace min2;
>cout << min2::name <<endl;  //有相同名称的时候，必须指定名称空间
>
>return 0;
>}
>```
>





### ⚠️多个名称空间例子 待补充 本章最后一节



>编译命令：g++ namesp.cpp  namessp.cpp
>
>```c++
>//file_name: namesp.h 
>#include <iostream>
>#include "namesp.h"
>
>int main()  //main 函数
>{
>    using debts::Debt;
>    using debts::show_Debt;
>    Debt golf = {{"min", "liang"}, 120.0};
>    show_Debt(golf);
>    return 0;
>}
>
>```
>
>头文件
>
>```c++
>#include <string>
>
>namespace pers{
>    struct Person
>    {
>        std::string fname;
>        std::string lname;
>    };
>
>    void getPerson(Person &rp);
>    void showPerson(const Person &rp);
>}
>
>namespace debts{
>    using namespace pers;  //使用空间在头文件中定义
>    struct Debt{
>        Person name;
>        double amount;
>    };
>    void getDebt(Debt & rd);
>    void show_Debt(const Debt&rd);
>    double sumDebts(const Debt ar[],int n);
>}
>```
>
>方法文件
>
>```c++
>//file_name:namessp.h 
>
>#include <iostream>
>#include "namesp.h"
>
>namespace pers{             //名称空间
>    using std::cout;
>    using std::cin;
>
>    void getPerson(Person &rp){
>        cout <<"Enter your first name:";
>        cin >> rp.fname;
>        cout <<"Enter your last name:";
>        cin >> rp.lname;
>    }
>
>    void showPerson(const Person &rp){
>        cout << rp.lname << " ," <<rp.fname;
>    }
>}
>
>namespace debts{    //名称空间               
>    void getDebt(Debt & rd){
>        getPerson(rd.name);
>        std::cout << "Enter your amount:";
>        std::cin >>rd.amount;
>    }
>
>    void show_Debt(const Debt&rd){
>        showPerson(rd.name);
>        std::cout <<"$ : "<< rd.amount <<"\n";
>
>    }
>
>    double sumDebts(const Debt ar[],int n){
>        double total=0;
>        for(int i=0;i<n;i++){
>            total +=ar[i].amount;
>        }
>        return total;
>    }
>
>}
>```
>

## chapter10:对象和类

### 类

> 类里面有数据之外，也有操作数据的方法
>
> 类成员 由两个部分组成
>
> >**类声明（头文件）：以数据成员的方式描述数据部分，以成员函数（方法）的方式描述共有接口**
> >
> >**类方法定义（源代码）：描述如何实现类成员的函数**
>
> ⚠️**类的对象可以互相拷贝**
>
> ⚠️**初始化 类的私有数组  int arr[20]{};//加上{}为初始化数组**

#### 示例用法


>**头文件**
>
>```c++
>
>#include <string>
>
>class Stock{
>private://私有的，不能访问，只能通过public访问，数据隐藏
>std::string company;
>long shares;
>double  share_val;
>double total_val;
>
>void set_tot(){ total_val = share_val * shares;}//私有函数,属于内联函数分号写里面
>                                                    //也可以写内联函数定义，定义																											写在头文件里面class外
>public://公有的
>	void acquire(const std::string &co,long n,double pr);  //类方法
>  void buy(long num,double pr);
>  void sell(long num,double pr);
>  void update(double price);
>  void show();
>  std::string * show_name();// 这个有返回值，返回名字指针；
>
>};
>
>//set_total 内联函数的定义写在class 外面
>//inline void Stock::set_tot(){
>// total_val=share_val*shares;
>// }
>
>```
>**函数定义**
>
>```c++
>#include "stock00.h"
>#include <iostream>
>
>		//每个函数都要加上类的作用域
>void Stock::acquire(const std::string &co,long n,double pr){
>company =co; // 类函数都可以直接可以直接访问成员变量,不需要加上类名
>if(n<0){
>    std::cout <<"Number of share can't be negative:" <<company <<" set to be zero";
>    shares=0;
>}
>else{
>    shares=n;
>}
>share_val=pr;
>set_tot(); 		//可以直接访问私有函数
>}
>
>void Stock::buy(long num,double pr){
>if(num <0){
>    std::cout <<"Number of share can't be negative:交易失败";
>    return;
>}
>else{
>    shares +=num;
>    share_val=pr;
>    set_tot();
>}
>}
>
>void Stock::sell(long num,double pr){
>using std::cout;
>if(num < 0){
>    cout <<"卖出股票不能小于0"<<std::endl;
>    return;
>}
>else if(num >shares){
>    cout <<"不能超过卖出的数量\n";
>    return;
>
>}else{
>    shares -=num;
>    share_val=pr;
>    set_tot();
>}
>}
>
>void Stock::update(double price) {
>share_val=price;
>set_tot();
>}
>
>void Stock::show() {
>std::cout <<"Company: " << company << std::endl;
>std::cout <<"Count: " << shares<<std::endl;
>std::cout <<"Value: " << share_val<<std::endl;
>std::cout <<"Total: " << total_val <<".$" << std::endl;
>}
>
>std::string *  Stock::show_name(){
>    return &company;
>}
>```
>使用类
>```c++
>#include <iostream>
>#include "stock00.h"
>
>int main(){
>   Stock shanghai;  //shanghai是类的对象，or 类的变量
>   shanghai.acquire("上海机场",1000,45.4);// 初始化 类
>   shanghai.show();				//使用类方法;
>   shanghai.buy(100,120);
>   shanghai.show();
>
>    shanghai.sell(2100,120);
>  	std::string * name=shanghai.show_name(); //有返回值的类函数，返回指针
>    std::cout << "Name is "<< *name << std::endl; //打印指针取值；
>   
>
>
>   return 0;
>
>}
>```
>
>
>
>

### 类的构造

>⚠️构造函数可以重栽，**没有返回值 连void都没有**
>
>构造函数：初始化，构造函数要和类名重名；
>
>```c++
>类的私有变量是隐藏的，所以不能直接初始化数据，应该用一个函数进行初始化；
>c++提供了一个特殊的成员函数，类的构造函数，对类的数据进行初始化
>构造函数 相当于python 里面的init
>
>```
>
>**构造函数用法**
>
>头文件 
>
>​	class_name(....);
>
>函数实现
>
>​	class_name::class_name(arguments){.....};
>
>```c++
>//头文件
>class Stock{
>private:
>std::string company;
>long shares;
>double  share_val;
>double total_val;
>
>public:
>	Stock(const std::string &co,long n,double pr);
>}   //只要
>
>
>//函数 没有返回值 void都不用加
>Stock::Stock(const std::string &co,long n,double pr){
>...
>}
>
>//函数使用
>
>------
>Stock shanghai=Stock{"shanghai",100,10};   //显示   用（）or {} 都 OK
>shanghai.show();
>----
>Stock zhongguo{"中国平安",4555,23.4};    //隐式
>zhongguo.show();
>----
>auto * minliang=new Stock{"日",20,33.3};  //动态分配  用 auto
>minliang->show();
>------
>```
>
>**默认构造函数**
>
>有默认初始值：如果没有提供任何构造函数，c++自动默认构造函数，写在声明里就可以了
>
>```c++
>
>class Stock{
>	...
>public://公有的
>	Stock(const std::string &co="error",long n=0,double pr=0.0); //默认值
>
>//使用
>Stock temp1；
>or
>Stock temp2=Stock();//没有参数
>
>```
>
>```c++
>class stock{
>private:
>std::string company;
>long shares;
>double  share_val;
>double total_val;
>		void set_tot(){ total_val = share_val * shares;}
>public:
>	Stock(); 
>}
>//函数实现
>Stock::Stock(){
>company="No Name";
>shares=0;
>share_val=0;
>total_val=0;
>set_tot(); //直接调用私有变量
>}
>```
>
>

### 析构函数

>清理工作
>
>如果没有写析构函数函数，编译器会自动默认声明一个析构函数
>
>delete 可以释放空指针 NULL nullptr
>
>```c++
>如果在构造函数中使用new来分配内存，则需要在析构中 delete 来释放这些内存
>没有返回值;也没有参数
>
>函数原型
>~函数名称();   //~stock();
>函数实现：
>函数名称::~函数名称(){...};    //Stock::~Stock(){};  
>
>```

### const成员函数

>在函数原型，和函数定义后面加上const；
>
>说明 不会用修改当前使用的对象
>
>```c++
>const Stock land={"stock_name"};
>
>land.show();  //出错,show里面没有办法保证不修改值
>//因此要在 类定义 和函数实现的后面加上const  保证成员不被修改
>
>class Stock{
>  ...
>    public:
>  void show() const;
>}
>
>函数定义
>  void Stock::show() const{
>  ...;
>}
>```
>
>

### this指针

>**返回被调用的成员函数的对象。** 相当于python里面的self
>
>```c++
>
>//this为调用对象的地址
>*this 为整个对象；
>this ->类成员变量；
>  
>```
>
>如果要返回整个对象 应该*this 

### 对象数组
>
>
>```c++
>const int STK=10;
>
>Stock stock[STK]={
>            Stock{"中国平安",100,3},
>            Stock{"上海机场",10,3.5},
>            Stock{"中国茅台",35,6.3},
>            Stock{"五粮液",100,3.6} //剩下的都会用默认构造函数生成
>    };
>
>int i;
>for(i=0;i<2;i++){
>  arr[i].show();
>}
>```
>
>```c++
>int main(){
>  	int STK=4;
>    Stock stocks[STK]={
>            Stock{"中国平安",100,3},
>            Stock{"上海机场",10,3.5},
>            Stock{"中国茅台",35,6.3},
>            Stock{"五粮液",100,3.6}
>    };
>
>    int i;
>    for(i=0;i<STK;i++){
>        stocks[i].show();
>    }
>
>    std::cout <<"产生最大的价值\n";
>
>    const Stock * pmax=&stocks[0];   //指针指向值，但是不能通过指针修改值
>
>    for(i=0;i<STK;i++){
>        pmax = &pmax->top_val(stocks[i]);
>      					成员比较 另外一个成员 返回比较大的成员 然后取地址 然后用指针指向该地址
>    }
>
>   pmax->show();  //类对象的指针 取函数调用
>}
>
>
>```
>
>

### 类的作用域

>```c++
>成员运算符 [.]
>间接成员运算符 [->]
>作用域解析运算符 [::]
>```
>
>
>
>>```c++
>>Stock name("Exclusice. ore",100,0.25);
>>name.show();	///类的对象访问成员函数
>>show();//不允许的；
>>定义成员函数的时候，必须使用作用域解析符号
>>  void Stock::show(){
>>  ..... 
>>	}
>>```

**类中的常量**

> ```c++
> class My{
>     private:
>     const int Month=12;         //这种方式不行  类嗨没有被实例，没有在内存中
>     double costs[Month];  
> }
> ```
>
> **解决的办法:用枚举类型enum**
>
> ```c++
> class My{
>     private:
>    enum{Month=12} ;        //Month是常量，不是变量
>     double costs[Month];  
> }
> ```
>
> 用static const. 静态只读
>
> ```c++
> class My{
>     private:
>    	static const int Months=12 ;        //Month是常量，不是变量
>     double costs[Month];  								//static 被编译的时候，编译器就开辟内存了
> }
> ```
>
> 

**类实现：抽象数据类型**

>示例：栈
>
>``` c++
>//头文件  stack.h
>
>
>typedef unsigned long Item;   //定义一个栈元素的数据类型
>
>class Stack{
>private:
>    static const int MAX=10;
>    Item items[MAX]{};       //{}初始化元素都为0;
>    int tpp;
>public:
>    Stack();
>
>    bool isempty() const;
>    bool isfull()const;
>    bool push(Item &item);
>    bool pop(Item &item);
>    void show();
>
>};
>
>```
>
>函数定义
>
>```c++
>//file_name: stack.cpp
>
>#include "stack.h"
>Stack::Stack() {
>    tpp=0;}
>
>bool Stack::isempty()const  {  //判断栈是否为空
>    if(tpp == 0)
>        return true;
>    else
>        return false;}
>
>bool Stack::isfull() const  {		//const 是不修改成员变量
>    if(tpp == MAX)
>        return true;
>    else return false;
>}
>
>bool Stack::push(Item &item) {		//入栈
>    if(tpp < MAX){
>        items[tpp]=item;
>        tpp++;
>        return true;
>    }
>    else
>        return false;
>}
>
>bool Stack::pop(Item &item) {  //出栈
>    if(tpp >0){
>        item=items[--tpp];
>        return true;
>    }
>    return false;
>}
>
>void Stack::show() {			//显示栈里面的内容
>    int i;
>    std::cout << "Stack: [";
>    for(i=0;i<tpp;i++){
>        std::cout << items[i] <<" ";
>    }
>    std::cout << "]" << std::endl;
>}
>
>```
>
>main文件
>
>```c++
>#include "stack.h"
>#include <cctype>
>using namespace std;
>
>int main(){
>    Stack stack;  //声明那啥
>    Item num;      //元素的数据类型，已经包含头文件，元素类型在头文件中已经定义好了
>    char choice;
>    cout <<"Press A to push to stack,Press P to pop to stack:";
>    while(cin >> choice && toupper(choice) !='Q')   //toupper 是不是大写都为大写
>    {
>        while(cin.get()!='\n') continue;  //消耗那啥多余的输入
>        switch (choice) {
>            case 'A':
>            case 'a':
>                    cout <<"Enter a number you what to push to stack:";
>                    cin >>num;
>                    cin.get();
>                    if (!stack.isfull()) {  //如果栈不为空,可以入栈
>                        stack.push(num);
>                    }
>                    else {
>                        cout <<"Stack full\n";
>                    }
>                    stack.show();
>                    break;
>    
>            case 'p':
>            case 'P':
>                    if(stack.isempty()){
>                        cout <<"Empty stack"<< endl;
>                    }
>                    else{
>                        stack.pop(num);
>                        cout <<"出栈："<< num << endl;
>                    }
>                    stack.show();
>                    break;
>            default:continue;
>    }
>        cout <<"Press A to push to stack,Press P to pop to stack:";
>    };
>    
>    return 0;
>}
>```
>
>
>

### 初始化const变量：类成员初始化列表

> #### 成员初始化列表
>
> - **这种格式只能用于构造函数**
> - **必须必须用这种格式来初始化非静态 const数据成员**.   静态不在类里面，已经提前分配好内存了；
> - **必须用这种格式来初始化引用数据成员** 定义一个引用的时候，必须同时给他赋值
>
> ```c++
> #类头
> class Queue{
>   private:
>     enum{default_val=10};
>     const int size;
>   public:
>   	Queue(int n=default_val;)
> }
> 
> #类实现
> Queue::Queue(int n):size(n) //size(n)成员初始化列表
> {
>  //函数后面加size(n); 初始化的值为n
> }
> ```
>
> #### 多个成员初始化列表
>
> ```c++
> Queue::Queue(int n):size(n),front(NULL),rear(NULL),items(0){
>   //size front rear items 为Queue类的私有变量
>   
>   //函数体
>   ...
>     
> }
> ```
>
> 

## chapter11:使用类

### 运算符重载

>*可以是乘法 也可以指针取值；
>
>**operatorOP(argument-list);** //OP是运算符 也就是。+ - * / 等
>
>⚠️如果调用了赋值运算符，
>
>
>
>```c++
>operator + 运算符(参数);//  不能写成 oprtator @ 没有@运算符
>
>//如果a1,a2,a3 都是某个类的对象
>a1 =a2+a3; 
>//编译器会翻译成
>a1 =a2.operator+（a3）;
>
>
>int a,b,c;
>Time A,B,C; //Time 为自定义类
>
>c =a+b;// 编译器看运算的数据类型，决定进行那种操作
>C =A+b; // 都为自定义类行
>

> 函数返回值为引用的情况
>
> ⚠️**不要返回临时变量的引用**
>
> ```c++
> int sum(int a,int b){
>   int c;  //临时变量，不能当作引用传递出去，因为临时变量，用完会被销毁,引用会引用被销毁的值;
>   c=a+b;	//变量会拷贝一份 返回给函数；
>   return c;
> }
> a=5;b=4;
> c=sum(5,4);
> 
> 
> ```
>
> 

### 重载运算符的限制

>1.⚠️**至少有一个是用户定义的数据类型（类的实例）**
>
>2⚠️.不能违反运算符原来的句法规则，不能讲求模运算符重载成使用一个操作数？？
>
>​	不会改变原来运算符的优先级
>
>3.⚠️不能创建新的运算符 比如不能定义operater**（）函数表示求幂;
>
>​	不能重载下面的运算符
>
>```c++
>sizeof:sizeof运算符。
>.:成员运算符。
>. *:成员指针运算符。
>:::作用域解析运算符。
>?::条件运算符。
>typeid:一个RTTI运算符。 
>const_cast:强制类型转换运算符。 
>dynamic_cast:强制类型转换运算符。 
>reinterpret_cast:强制类型转换运算符。
>static_cast:强制类型转换运算符。
>```
>
>可以重载的运算符
>
><img src="/Users/macbookpro/Nas_Data/MD_FILE/pic/截屏2022-11-18 12.57.17.png" alt="!" style="zoom:90%;" />
>
>```c++
>成员函数：类里面的函数
>Class Num{
>....
>public:
>		Num& operator+(const Num & anther_Num);//成员函数 函数原型
>}
>Num& Num::operator+(const Num & anther_Num){...}; //成员函数，加上了类名作用域
>Num a1,a2,a3;
>a3=a1+a2; // ok
>
>非成员函数：不是类里面的函数
>Num operato+(const num & a1,const Num& a2);//非成员函数，没有加上了类名作用域
>Num a1,a2,a3;
>a3=a1+a2; //要把私有变量改成共有的，或者用别的方法啊，把私有变量通过函数 return 出来
>
>```
>**默认 赋值运算符 =号 重载功能**
>
>=右边的值，会调用右边值相匹配的构造函数，右边的值当作构造函数的实参，很容易生成新的类 ⚠️
>
>```c++
>
>class Num {
>private:
>int num;
>   int num2;
>public:
>Num() {
>       num = 0;
>        num2=0;
>        cout << "Hello,kitty\n";
>    };
>   Num(int n,int m) {
>       num = n;
>        num2=m;
>        cout << "good morning\n";
>    };
>};
>
>int main() {
>Num a;
>a = {20, 30};  //会调用与 右值 相匹配的 构造函数  右值为 20，30  与 Num(int n,int m) 匹配
>   return 0;
>}
>```
>显示结果
>```shell
>Hello,kitty
>good morning
>```
>



### 友元函数

>**非类函数可以访问类的私有变量 ** 叫做友元函数,
>
>类的声明要放在类的声明里面 并在前面加上关键字 **friend**,  在类的定义不需要加上**friend** ；
>
>定义**友元函数**的时候，函数名 **不需要加上 类名::  类的作用域**；
>
>友元函数并不是成员函数，但是和成员函数一样可以访问类的访问权限一样（包括成员变量和成员函数？）
>
>友元函数要使用类函数的时候，应该指明哪个类在用；
>
>
>
>```c++
>class Time{
>	private:
>		int Hours;
>  	int Mintues;
>  	void reset(){  //超过60分钟 加进小时里面；
>      if(Minutes >60){
>        Hours +=  Minutues /60;
>        Mintues %=60;
>      }
>    }
>  public:
>  	Time(int h,int m){Hours=h;Mintues=m};
>  	Time operator*(double m)    ⚠️// 只能 类*num  不能 num*类
>    {
>      Time temp;
>      temp.Hours *=m;
>      temp.Mintues *=m;
>      return temp;
>    }
>  	friend Time operrator*(double n,const Time &t1);//定义友元函数
>}
>
>Time operrator*(double n,const Time &t1){
>  Time temp;
>  temp.Hours = n * t1.Hours;
>  temp.Mintunes = n * t2.Hours;
>  temp.reset();//用私有函数 加上是谁用的；
>  return temp;
>  
>}
>
>
>```
>
>

### 常用的友元：重载 cout <<  cin >> 

>```c++
>重载cin;
>class Number{
>  private:
>  	double real;
>  	double image;
>  public:
>  		...
>   friend istream& operator>>(istream &is,Number &n){ 
>        cout << "Please enter the real and image :"<< endl;
>        is >> n.real >> n.image;
>  			return is;
>			}     
>}
>
>```
>
>
>
>```c++
>cout << 类的实例;//想要自定义打印类
>//cout 是ostream 的对象
>
>友元函数
>friend ostream& operator<<(ostream& os,Time &t)
>
>返回值ostream 重新载入 << 操作对象两个 ostream 的引用 ，类实例的引用
>ostream& operator<<(ostream& os,const Time &t){  //⚠️ 不改变参数要多加const 要不然容易报错
>os <<"["<<t.Hours <<":"<< t.Mintues <<"]\n";
>return os;
>}
>
>//使用
>cout <<"t1:" << t1;
>
>```



### 重载运算符：做位成员函数和非成员函数

>
>
>```c++
>class Time{
>  ...
>}
>
>Time operator+(const Time&t1) const;//成员函数版本
>
>//要访问Time里面的私有变量必须是友元函数
>friend Time operatir+(const Time&t1,const Time&t2); //友元函数 
>
>两种重载选一种，要不然编译器不知道选哪种，有二义性;/
>```
>



### 容易出错的地方

>
>
>⚠️：类的默认参数写在 函数原型里面,在函数定义上面不用写
>
>⚠️：类的方法的默认参数:在方法啊定义的时候，默认参数不用写作用域，当在外面使用的时候，要加上作用域; 要不然参数不知道是啥
>
>⚠️：类用默认构造函数的时候，不用加括号，直接   类名 类就行;
>
>⚠️:  类方法返回的值是类的时候，用一个类去接收他 ,是用返回值拷贝，不要去用引用
>
>⚠️:类方法返回的类，不要使用引用去接收，因为离开函数的作用域，变量已经消失了；

### 书中例题

>头文件
>
>```c++
>#include <iostream>
>using namespace std;
>
>namespace VECTOR{
>
>
>	class Vector{
>	public:
>					enum TYPE{RECT,POL};
>	private:
>          double x;
>          double y;
>          double abs;
>          double angel;
>          TYPE type;
>          void set_x();
>          void set_y();
>          void set_abs();
>          void set_angel();
>
>	public:
>          Vector(){x=y=abs=angel=0;type=RECT;}; //默认设置,初始化的使用不用加（）
>          Vector(const double &n1,const double &n2,TYPE _type=RECT); //	默认值写在函数定义里
>
>          void rect_mode(){type=RECT;};   //记得加逗号
>          void pol_mode(){type=POL;};		//直接定义好了，使用的时候，会当作内联函数
>
>    
>          void reset(const double &n1,const double &n2,TYPE _type=RECT)	//参数是类的公有枚举类型
>            																												// 在类里面用 变量名就行
>            																									//类外面加上名称空间::类名::变量名称
>            	
>          double get_abs()const{return abs;};	//内联方法,记得在{}中加上分号
>          double get_angel()const{return angel;};
>          double get_x()const {return x;};
>          double get_y()const {return y;};
>
>          Vector operator+(const Vector & v1) const;		//函数重载入 +号就是 +号 不可以+=
>          Vector operator-(const Vector & v1) const;			//可以为，-class
>          Vector operator-();											
>          Vector operator*(const double &n); //加上const 可以用左值右值。左值可以取地址 右值不可以
>																								//变量是左值 ，  a+5,5 ,5+5 都是右
>          friend ostream& operator<<(ostream& os,const Vector&v);
>    															//友元函数,在类中要加上friend 关键字，可以访问参数里面的私有变量
>    															//需要有返回值
>
>	};	//和结构一样，类最后要加上分号
>}
>```
>
>类方法
>
>```c++
>#include "vector.h"
>#include <cmath>
>
>namespace VECTOR{   // 加上命名称空间
>	
>  const double Rad_to_reg=45.0/tan(1.0);
>
>	void Vector::set_x(){
>		x=abs * cos(angel);
>	}
>
>	void Vector::set_y(){
>		y=abs * sin(angel);
>	}
>
>	void Vector::set_abs(){
>		abs=sqrt(x*x+y*y);
>	}
>
>	void Vector::set_angel(){
>		if(x==0.0 && y==0.0)
>			angel=0;
>		else
>			angel=atan2(y,x); //TODO:有可能是错的
>	}
>
>  //自定义构造函数
>	Vector::Vector(const double &n1,const double &n2,TYPE _type){  
>		type=_type;
>		if(type==RECT){
>			x=n1;
>			y=n2;
>			set_abs();
>			set_angel();
>		}else if(type ==POL){
>			abs=n1;
>			angel=n2/Rad_to_reg;
>			set_x();
>			set_y();
>		}else{
>			cout <<"in 构造函数 ERROR" << endl;
>		}
>	}
>
>
>	void Vector::reset(const double &n1,const double &n2,TYPE _type){
>		type=_type;							//可以简化为 *this = Vector(n1,n2,_type);
>		if(type==RECT){						//this 为使用 实例话后的指针。*this 重新赋值
>			x=n1;
>			y=n2;
>			set_abs();
>			set_angel();
>		}else if(type ==POL){
>			abs=n1;
>			angel=n2/Rad_to_reg;
>			set_x();
>			set_y();
>		}else{
>			cout <<"in 构造函数 ERROR" << endl;
>		}
>	}
>
>
>	Vector Vector::operator+(const Vector & v1) const{
>		return Vector(x+v1.x,y+v1.y,type);  
>		//返回一个新的类的实例，而且使用自定义初始结构,返到外面变量会拷贝一份
>    //函数里面新申明的变量，类实例，不要用引用接收他，因为离开作用域会被销毁
>	}
>
>
>
>	Vector Vector::operator-(const Vector & v1) const{
>		return Vector(x-v1.x,y-v1.y,type);
>    	//返回一个新的类的实例，而且使用自定义初始结构,返到外面变量会拷贝一份
>    //函数里面新申明的变量，类实例，不要用引用接收他，因为离开作用域会被销毁
>	}
>
>
>	Vector Vector::operator-(){
>		return Vector(-x,-y,type);
>	}
>
>	//
>	Vector Vector::operator*(const double &n){
>		return Vector(x*n,y*n,type);
>	}
>
>
>
>//友元函数，类外面的函数，不用加上类名作用域，能访问参数里面的私有变量，不属于参数里面的类
>	ostream& operator<<(ostream& os,const Vector&v){
>		if(v.type == Vector::RECT){
>			os << "type:"<< v.type <<"[ x:"<<v.x <<",y: "<<v.y;
>			os << ", abs:"<< v.abs <<",angel: "<< v.angel <<"]"<< endl;
>		}else if(v.type==Vector::POL){
>			os << "type:"<< v.type <<"[abs:"<< v.abs <<",angel: "<< v.angel;
>			os <<" ,x:"<<v.x <<",y: "<<v.y <<"]" << endl;
>
>		}else{
>			os << "Type error" <<endl;
>		}
>		return os;
>	}
>
>
>}
>```
>
>main 文件
>
>```c++
>#include "vector.h"
>#include <cmath>
>#include <cstdlib>
>
>int main(){
>	using namespace VECTOR;  //std 名称空间已经包含在 VECTOR名称空间里面
>	srand(time(NULL));  //随机数种子
>
>	Vector result(3,3);  //用自定义构造函数初始化的类
>  											//两个类开辟的空间都是一样的 40个字节，有点不明白这个
>	Vector temp;				//默认参数 类实例，可以接收 返回Vector类的
>	int count=0;
>
>	cout << "请输入绝对距离:" << endl;
>	int sum_miles;
>	int step;
>
>	double ang;
>	while(cin >> sum_miles){
>		cout << "请输入要每步的距离:";
>
>		if(!(cin >> step)){
>				break;
>		}
>
>		while(result.get_abs() < sum_miles){
>			ang=rand() % 360;  //随机角度
>			temp.reset(step,ang,Vector::POL);
>      //也可以 temp=Vector(step,ang,Vector::POL); 类外面，使用类共有变量要加上类的作用域，该参数在类里
>			result = result + temp;  //重载 + 号码
>			count++;
>		}
>    
>		cout <<"一共用了" << count << "到达目的距离" << sum_miles <<"\n";
>		result.reset(0,0);
>		count=0;
>		cout << "请输入绝对距离:" << endl;
>	}
> 
>	cout << count << endl;
>	return 0;
>}
>```
>
>
>
>

### 类的自动转换和强制类型转换

>
>
>```c++
>class Stonewt{...};
>Stonewt myCat;
>myCat=19.6; //使用构造函数对类初始化
>						//使用19.6,转换成int(19.6) 创建一个类的实例，然后拷贝到myCat中
>Stonewt::Stonewt(int stn,double lbs);//不能用这个构造函数
>Stonewt::Stonewt(int stn,double lbs=0.0);//不能用这个构造函数
>
>Stonewt wolfe(285.7);  //使用一个参数的构造函数，不能有二议性
>Stonewt taft(21, 8);		//使用两个参数的构造函数，不能有二议性
>
>myCat=22;//用22生成没有名字的函数传递给myCat；
>myCat = Stonewt(22);
>myCat = (stonewt)22
>
>```
>
>**关闭自动转换**
>
>​	在构造函数前面加上关键字 **explicit**
>
> 	**explicit** 关闭隐式转换
>
>```c++
>class Stonewt{
>  public:
>  	explicit Stonewt(int temp){...}; //构造函数关闭自动类型转换
>}
>
>```
>
>**转换函数**
>
>**operator Typename();**	转换函数
>
>1. 转换函数必须是类方法；
>2. 转寒函数不能有参数;
>3. 转换函数不能有返回值;
>4. 可以加上关键字 explicit，**explicit operator typename()** 声明必须是显示转换,只需要在类声明中加
>5. 应该谨慎使用转换函数;尽量用显式
>
>```c++
>
>class Stonewt{
>  private:
>  	double some;
>  public:
>  	operator int() const;   //把类转换成int 类型
>  	explicit operator double() const;	//把类转换double 类型 定义不要有返回类型
>  																  //explicit 是声明必须用显示转换 bitu 
>  
>  	explicit operator string()const;// 转换成string 类型
>             };
>
>
>
>Stonewt::operator int(){   //⚠️explicit 关键字不用在函数定义的地方写，写在函数原型就行
>  return (int)(some+0.5);//四舍五入;
>}
>
>Stonewt::operator double(){				//需要有返回值
>  return some;
>}
>
>Stonewt::operator string(){
>  string temp ="[some的值为:" + to_string(some) +"]";
>  return temp;
>}
>
>
>Stonewt temp(28.6);  
>int temp1= temp; // 把类转换了成int 类型了  operator int() const;
>double temp2=temp;  //把类转换成了double 类型 
>
>cout << (string) temp << endl;  // 打印结果 [stone的值为:28.6]
>```
>
>

## chapter12:类和动态内存分配

### 动态内存和类

>动态分配内存：在程序运行的时候，决定分配的内存是多少

>**按值传递的时候，编译器会复制使用复制构造函数，复制构造函数并没有开破新的内存空间，但是会调用析构函数函数释放内存**
>
>```c++
>//main() 函数
>#include "stringbad.h"
>
>void show1(StringBad &rsb);
>void show2(StringBad sb);  //编译器会拷贝类，不是使用默认的构造函数,但是会使用析构函数
>							//从类拷贝类，StringBad(const StringBad& copy);
>
>int main(){
>
>	StringBad headline1("hello.kitty");
>	StringBad headline2("Good morning");
>	StringBad headline3("I love you,rick");
>	cout <<headline1 << endl;
>	cout <<headline2 << endl;
>	cout <<headline3 << endl;
>	show1(headline2);
>	show2(headline2); //编译器会拷贝类，不是使用默认的构造函数,但是会使用析构函数
>					  //从类拷贝类，StringBad(const StringBad& copy); 解决办法
>	
>	return 0;
>}
>
>void show1(StringBad &rsb){
>	cout <<"by re引用:" << rsb <<endl;
>}
>
>void show2(StringBad sb){
>	cout <<"by 不引用:" << sb <<endl;
>}
>```
>
>```c++
>//file_name "stringbad.h"
>#ifndef __STRING_BAD_H__
>#define __STRING_BAD_H__
>
>#include <iostream>
>using namespace std;
>
>class StringBad{
>private:
>	char *str;				//字符串的地址;
>	int len;				//字符串的长度
>	static int num_strings;	//静态int，无论创建多少个对象，都共用一个静态变量
>							//不属于任何类的对象，独立于所有的类的对象
>							//对所有类的对象都是可见的
>  						//如果是只读的 const 类型，可以在类声明中初始化
>public:
>	StringBad();
>	StringBad(const char*s);
>	~StringBad();	//析构函数，没有参数没有返回值
>
>	friend ostream& operator<<(ostream&os,const StringBad &st);
>};
>
>#endif
>```
>
>```c++
>#include "stringbad.h"
>#include <cstring>
>
>
>int StringBad::num_strings=0;   //不放在头文件中，避免多次被赋值修改引发错误
>								//初始化类里面的静态变量
>								//什么描述如何分配内存，但是并不分配内存
>								//单独存储，不是类的组成部分
>								//不使用关键字 static
>
>
>StringBad::StringBad(const char *s){   //StringBad("hello,kitty");
>	len=strlen(s);
>	str=new char[len + 1 ]; //开辟内存空间
>	strcpy(str,s);
>	int i;
>	num_strings++;//静态变量++，统计创建了多少个变量
>	cout <<num_strings <<" :"<< num_strings <<": \""<<str <<"\" be Created" << endl;
>
>}
>
>
>StringBad::StringBad(){
>	len =4;
>	str=new char[4];
>	str[len-1]='\0';
>	strcpy(str,"C++");
>	num_strings++;
>	cout << num_strings <<": \""<<str <<"\" be Created" << endl;
>}
>
>StringBad::~StringBad(){
>	cout <<"\"" << str <<"\" be Delete" << endl;
>	delete []str;  					//构造函数开辟的内存空间，析构函数删除
>	num_strings--;
>	cout << num_strings <<" left.\n";
>
>} 
>
>ostream& operator<<(ostream &os,const StringBad&st){
>	os << st.str ;
>	return os;
>}
>
>```
>
>

### 特殊成员函数

>**c++会自动提供的函数**
>
>- **默认构造函数，如果没有定义构造函数** 初始化的时候用，不是赋值的时候用
>- **默认析构函数，如果没有定义**
>- **复制构造函数，如果没有定义**
>- **赋值运算符，如果没有定义**
>- **地址运算符，如果没有定义**

>**默认复制构造函数**
>
>Typename(const Typename &temp);
>
>```c++
>从类复制到另外一个类
>用于初始化的过程，不是复制的过程
>函数按值传递类 或者 函数返回类
>
>class Stringbad{...};
>Stringbad 类1=类2； //等效于
>Stringbad 类1=StringBad(类2); //复制构造函数
>会有潜在问题,应该加上 StringBad(const StringBad &n1);自定义复制构造函数
>
>```
>
>```c++
>//⚠️默认构造函数
>classname(); //or classname(args=default args){...} 有默认值
>
>
>//⚠️复制构造函数
>classname(const classname&);//从另外一个类复制
>
>classname class1(class2);
>classname class1=class2;								//这两种
>classname class1= classname(class2);	//这两种
>classname * pclass = new classname(class1);
>//中间两种  可能 1).先使用默认构造函数，然后用复制构造函数  （多了一步使用默认构造函数）
>//.      也可能 2).也可能直接使用复制构造函数 
>
>```
>
>

### 类的静态变量(不属于成员，属于类)

>
>
>两点说明
>
>```c++
>//head.h
>class String{
>	private:
>	char * pstr;
>	static int num1; //属于类 ，不属于成员，在函数定义中初始化，这里只是声明，不开辟内存
>  									//在一个代码块里面 重新初始化一次;
>	static const int LIMITLEN=80;//也是一样，只读
>private:
>	...
>static int get_numl();//返回静态变量
>friend istream& operator>>(istream& is,String &st);
>}
>```
>
>```c++
>//head.cpp 类函数实现
>int String::num1=80;   //初始化类的静态变量，值会初始化一次
>
>istream& operator>>(istream& is,String &st){
>char temp[String::LIMILEN];//使用类的静态变量
>	....;
>}
>
>int String::get_numl(){return numl;};//返回静态变量在声明中加static 就可以了
>
>```
>
>```c++
>int main(){
>cout <<"尽量变量前面加类的作用域 的值是 :" << String::get_num1() << endl;
>}
>```
>



### 在构造函数中使用new的注意的事项 


>- **如果在构造函数中使用new来初始化成员，应该在西沟函数中使用delete**
>- **new 和 delete 必须相互兼容 new和delete 是一对，new[]和delete[]是一对**
>- **如果有多个构造函数，必须用相同的new ，析构函数只有一个，必须相互兼容**
>- **应该定义一个复制构造函数，深度复制讲一个对象初始化为另外一个对象**,
>- c++ 定义空指针用nullptr
>- 应该也定义一个赋值运算符，也是通过深度复制把一个对象复制给另外一个对象
>
>```c++
>//复制构造函数与下面类似
>String::String(const String& st){
>  num_string++;
>  len=st.len;
>  str =new char[len+1];
>  strcpy(str,st.str);
>}
>```
>
>```c++
>//赋予运算符
>String& String::operator=(const String& st){
>  if(this==&st)
>    return *this;
>  delete []str;
>  len=st.len;
>  str=new char[len+1];
>  strcpy(str,st.str);
>  return *this;
>}
>```
>
>
>
>### NULL,0还是nullptr
>
>⚠️**delete 可以用于空指针**
>
>```c++
>c语言中NULL 表示空指针
>传统的c++通常用0 
>新标准的c++通常用nullptr
>```

### 有返回对象的说明

>1.返回指向const对象的引用
>
>  ```c++
>  Vector MAX(Vector & v1,Vector& v2);// 返回对象讲调用复制构造函数,
>  const Vector &MAX(const Vector & v1,const Vector& v2//返回引用，效率更高
>                    																	//参数为const 返回值也应该是const;
>  ```
>
>2.返回指向非const对象的引用
>
>```c++
>返回值是允许被修改的
>operator=()
>  String s1("hello,kitty");
>String s2,s3;
>s2=s3=s1;
>或者cout << ;//只能返回ostream & 需要连续输出
>  
>```
>
>3.返回对象
>
>```
>如果返回的对象是调用函数中的局部变量，则不应该使用局部变量
>算数运算符最好返回对象，别返回引用；//比如vector 类
>```
>
>4.返回const对象
>
>```c++
>const 对象只能被初始化一次;/
>```
>
>

### 使用指向对象的指针

> 
>
> ```c++
> String temp("fuck,you");
> String *ps=new String;//使用 默认构造函数  String::String();
> String *ps=new String("hello,kiitty");//使用字符串构造函数   String::String(const char * st);
> String *ps3=new String(temp) ;// 使用拷贝构造函数 Strring::String(const String& s);
> ```
>
> 
>
> ```c++
> String arr[2];  //会使用默认构造函数 讲数组里面类初始化
> String *ps=new String(arr[1]);  //会触发两个动作,开辟堆空间,调用响应的构造函数初始化堆空间的类
> *ps="hello,kitty.";     //*ps 可以当实例 用
> cout << *ps << endl;
> cout <<"ps的地址：" << ps << endl;   //=》         ps的地址：0x6000018cc050
> cout <<"arr[1]的地址:" <<&arr[1] << endl;//=》arr[1]的地址:0x7ff7b14b07d0
> 
> String *pstr= new String("my my my");//也是开辟堆空间，调用响应的构造函数 进行初始化;
> ```
>
> <img src="/Users/macbookpro/Nas_Data/MD_FILE/pic/截屏2022-12-01 13.38.32.png" style="zoom:50%;" />

### 如果对象是用new创建出来的，需要显示delete释放内存，对象才会调用析构函数

>**String \*pst=new String(...);**
>
>//需要delete pst 才会调用析构函数
>
>//用new开辟出来的类实例，用delete释放内存的时候，类实例才会自动调用析构函数
>
>```c++
>const int bufsize=512;
>int main(){
>				//char temp[bufsize];//如果定位到这里，不需要删除
>        char *buff=new char[bufsize];  //两个类没有开辟新内存空间，只是把内存空间定位到这里而已
>        JustTesting *pc1,*pc2;
>        pc1=new(buff) JustTesting("pc1",1); //没有开辟出新的内存空间，不需要delete
>        pc2=new(buff+sizeof(JustTesting)) JustTesting("pc2",2);     //delete 只是要释放new 开辟出来的空间，new(定位到已经																									存在的空间，不需要释放)
> 				
>  			pc2->~JustTesting();//⚠️显式的调用析构函数；倒着使用析构函数
>  			pc1->~JustTesting();//⚠️最好出栈的顺序使用析构函数，后进先出来。
>  
>        delete []buff;  // 删除定位的空间就可以了
>}
>```
>
>
>
><img src="/Users/macbookpro/Nas_Data/MD_FILE/pic/截屏2022-12-01 14.26.39.png" style="zoom:50%;" />
### 析构函数何时会被调用
>
>```c++
>
>void tempfunc(const char *nst){
>String temp(nst);
>}
>
>String s1("1.整个程序结束的时候，调用析构函数");
>    
>int main(){
>String s2("2.main函数运行完，会调用析构函数");
>tempfunc("666.函数运行完就调用析构函数");
>String *ps=new String("3.需要delete 才会调用析构函数");
>{
>       String s3("4.所在代码块 运行结束会调用析构函数");
>    }
>    delete ps;
>    
>     return 0;
>    }
>    
>```
>    
>

### 队列模拟

>**头文件**
>
>```c++
>
>//file_name:queue.h
>#ifndef FOR_CLION_QUEUE_H
>#define FOR_CLION_QUEUE_H
>
>#include <iostream>
>using namespace std;
>
>class Customer {
>private:
>    long arrive;
>    int processtime;
>public:
>    Customer() { arrive = processtime = 0; };
>    Customer(long ar, int pr) { arrive = ar, processtime = pr; };
>    void set(long when);
>    long when() const { return arrive; };  //返回
>    int ptime() const { return processtime; }; //返回操作时间
>
>};
>
>typedef Customer Item;  //以类为一个结构
>
>class Queue {
>private:
>    enum {
>        Q_SIZE = 10
>    };
>    struct Node {
>        Item item;       //结构体分号
>        struct Node *next;
>    };
>    Node *front;       //节点头
>    Node *rear;      //节点尾
>    int items;      //实际排队的数量
>    const int qsize;  //限定排队的数量 只能被初始化一次；
>
>public:
>    Queue(int qs = Q_SIZE);
>    ~Queue();
>    int max() const;
>    bool isempty() const;
>    bool isfull() const;
>    int queuecount() const;
>    bool enqueue(const Item &item);  //入队列
>    bool dequeue(Item &item);
>    void show();
>
>};
>
>#endif //FOR_CLION_QUEUE_H
>
>```
>
>**函数实现**
>
>```c++
>//
>// Created by macbookpro on 2022/12/5.
>//
>
>#include "queue.h"
>#include <cstdlib>
>#include <ctime>
>
>void Customer::set(long when) {
>    arrive=when;
>    processtime= rand()%3 +1;
>}
>
>Queue::Queue(int qs) : qsize(qs),front(nullptr),rear(nullptr),items(0) {//对象在{} 执行之前 变量会被初始化
>   //front=rear= nullptr;  //初始化，前面后面都没有人
>   //items=0;             //排队人数0
>   //qsize=qs;                //最大的排队人数
>}
>
>Queue::~Queue(){            //析构函数，释放所有内存
>    Node *temp;
>
>    while(front !=nullptr){  //当前节点不为空
>        temp=front;
>        cout << (temp->item).when() <<" be delete "<<endl;
>        front=front->next;
>        delete temp;
>    }
>
>}
>
>bool Queue::isempty() const {
>    return items==0;
>}
>
>bool Queue::isfull() const{
>    return items==qsize;
>}
>
>int Queue::queuecount() const{
>    return items;
>}
>
>bool Queue::enqueue(const Item &item) {
>    if(isfull()){
>        cout <<"Queue full"<< endl;
>        return false;
>    }
>    Node *add=new Node;     //开辟一个新的节点
>    add->item=item;         //新节点等于传递进来的节点
>    add->next=nullptr;      //下一个节点=空
>    items++;
>
>    if(front == nullptr){        //如果节点为空
>        front=add;}              //首个节点=新节点
>    else{
>        rear->next=add;         //当前的尾节点指向下一个节点
>    }
>    rear=add;                   //尾节点=下一个节点
>    cout <<"items cout:" << items << endl;
>    return true;
>}
>
>bool Queue::dequeue(Item &item) {
>    if(front== nullptr){
>        cout <<"enpty queue" << endl;
>        return false;
>    }
>    item=front->item;       //取出第一个元素
>    items--;                //元素个数减去1
>    Node *temp=front;       //新指针指向现在的头节点
>    front=front->next;       //头节点指向下一个节点
>    delete temp;            //删除之前临时指向的头节点
>    if(items==0)
>        rear= nullptr;
>    cout <<"items cout:" << items << endl; //当前节点
>    return true;
>}
>
>void Queue::show(){
>    int temp=1;
>    while(front != nullptr){
>        cout << "[ " << temp++ << "|" << (front->item).when() <<"|";
>        cout << (front->item).ptime() <<"]\n";
>        front=front->next;
>    }
>    cout << endl;
>}
>
>int Queue::max()const{
>    return qsize;
>}
>
>```
>
>main文件
>
>```c++
>
>#include <iostream>
>#include "queue.h"
>
>int main(){
>
>    int qs;
>    int i=0;
>    Item temp;
>
>    cout<<"Please enter the maximum length of the queue:";
>    cin >>qs;
>    Queue line(qs);
>
>    while(!line.isfull()){  //只要队列不为满，就一直循环
>        temp.set(++i *1000);
>        line.enqueue(temp);
>    }
>
>    Item result;
>//    while(!line.isempty()){
>//        line.dequeue(result);
>//    }
>
>   // line.show();
>
>    return 0;
>}复制构造函数
>```



### 复制构造函数和赋值运算符

>```c++
>class Cow{
>private:
>	char * name;//要分配内存
>	double weight;//
>public:
>	Cow();
>	Cow(char *nm,double d);//d可以是变量，也可以是常量;
>	Cow(const Cow &c ); //要新建新类
>	Cow &operator=(const Cow&c); //已经有类，重新赋值
>  Cow operator+(const Cow&c);//生成临时的类，当返回值，不需要在函数里面用指针
>}
>```
>
>
>

### 类定义栈和使用栈

>
>
>```c++
>#include <iostream>
>using namespace std;
>typedef unsigned long Item;  //定义元素为一种类型
>
>class Stack{
>	private:
>		Item *pitem;  //栈是一个指针,需要使用的时候进行初始化
>		int top;		//栈顶 数量
>		int size;		//栈的数量
>		static const int count=10; //默认值 也可以用enum{count=10};
>	public:
>		Stack(int n= count);  //初始化 写在函数原型里面
>		Stack(Stack& s);		//复制构造函数
>		~Stack(){delete []pitem;}	//释放开辟的内存		
>		int gettop()const {return top;}	//返回栈顶
>		int getsize()const{return size;}	//返回栈的总元素个数
>		bool isempty()const{return top==0;}	//判断栈是否为空
>		bool isfull()const{return top==size;}	//判断栈是否满了
>		bool push(Item it);		//入栈
>		bool pop(Item &it);		//出栈
>		Stack& operator=(Stack& st);  //赋值运算符
>		friend ostream& operator<<(ostream&os,Stack& st);
>											//重新载入cout
>
>};
>
>int main(){  //主函数
>	Stack s(20);
>	for(int i=0;i<4;i++){
>		s.push(i*i +1);
>	}
>	Stack s1=s;
>	cout << "size:"<<s1.getsize() <<",top:" << s1.gettop() << endl;
>	cout << s1<< endl;
>	Item temp;
>	for(int i=0;i<10;i++){
>		if (s.pop(temp))
>			cout << temp <<" be poped"<< endl;
>		else
>			s.push(20);
>	}
>	return 0;
>}
>
>
>Stack::Stack(int n){
>	size=n;
>	top=0;
>	pitem =new Item[size];  //开辟需要的内存空间
>}
>
>Stack::Stack(Stack& s){
>	size=s.size;
>	top=s.top;
>	pitem=new Item[size];
>	for(int i=0;i<top;i++){			//拷贝栈里面的数据
>		pitem[i]=s.pitem[i];
>	}
>}
>
>bool Stack::push(Item it){
>	if(isfull())		//是否栈满 
>	{
>		cout <<"Stack full"<< endl;
>		return false;
>	}
>	pitem[top++]=it;	
>	return true;
>}
>
>bool Stack::pop(Item &it){
>	if(isempty())		//是否栈空 
>	{
>		cout <<"Stack empty"<< endl;
>		return false;
>	}
>	it=pitem[--top];
>	return true;
>}
>
>Stack& Stack::operator=(Stack& st){
>	if(this ==&st){			//自己拷贝自己 不能释放内存，⚠️记住
>		return *this;
>	}
>	delete []pitem;			//删掉之前的内容
>	top=st.top;
>	size=st.size;
>	pitem=new Item[size];
>	for(int i=0;i<top;i++){
>		pitem[i]=st.pitem[i];
>	}
>	return *this;
>}
>
>ostream& operator<<(ostream&os,Stack& st){  //重载 count
>	os <<"Stack : [";
>	for(int i=0;i<st.top;i++){
>		os << st.pitem[i] <<" ,";
>	}
>	os <<"]";
>	return os;
>}
>```
>
>



## chapter13:类继承

### 派生类



>
>
>不建议修改源代码，可以使用类继承，可以扩充和修改类
>
>从一个类派生出另外一个类，原始类叫做基类，派生类;
>
>```c++
>//派生类语法
>class 派生类名称:public 基类名称{
>  ...
>    public:
>  	派生类名称(args):基类名称(args){
>      //初始化派生类，必须在初始化之前，初始化基类. 
>      //成员初始化列表，会调用基类的复制构造函数
>    }
>}
>// 派生类继承积累的方法，无法直接访问基类的私有变量（只能通过共有方法取访问）
>//派生类需要有自己的构造函数;（基类的私有变量和 新的私有数据都需要初始化）
>//派生类可以根据需要添加额外的数据成员和成员函数
>```
>
>**派生类的构造函数**
>
>```c++
>首先要创造积累的对象 
>派生类的构造函数 应该通过成员初始化列表讲积累信息传递给积累的构造函数
>派生类的构造函数，应该包含新增的数据成员
>```
>
>**派生类的析构函数**
>
>```c++
>释放对象的顺序和创建对象的顺序相反
>应该首先执行派生类的析构函数,然后自动调用基类的析构函数
>```
>
>⚠️**注意：创建派生类时，首先调用基类的构造函数，然后再调用派生类的构造函数，基类构造函数负责初始化继承的数据成员，派生类的构造函数主要负责新增的数据成员，派生类的构造函数总是会调用基类的一个构造函数，使用成员初始化列表的方式指定基类要调用的构造函数，否则则调用默认的基类构造函数**
>
>**派生类对象过期时，程序首先调用派生类的析构函数，然后再调用基类的析构函数**
>
>

### 派生类和基类的特殊关系


>
>
>派生类可以使用基类的方法，条件是方法不是私有的
>
>基类的指针可以指向派生类的对象，积累的引用也可以用在派生类的对象
>
>基类指针或者引用只可以调用基类的方法，不能调用派生类的方法（访问范围只在基类）
>
>```c++
>// TennisPlay 为基类， RatedPlayer 为派生类
>
>RatedPlayer base2(11,"min","liang",false);
>TennisPlayer &base1=base2;			//基类的引用 引用派生类
>base1.Name();
>cout << base1.getRating();
>```
>
>```c++
>void show(const TennisPlayer&s);  //参数为基类的引用,基类和派生类都可以当作参数传递
>void show(const TennisPlayer *ptr);//基类指针指向基类对象和派生类对象都可以
>int main(){
>	TennisPlayer s1("min","rui",true);  //基本类
>	RatedPlayer s2(11,"min","liang",false);  //派生类
>	show(s1);
>	show(s2);
>	return 0;
>}
>
>void show(const TennisPlayer&s){
>	s.Name();
>	if(s.HasTable()){
>		std::cout <<":has a table\n";
>	}else{
>		std::cout <<":hasn't a table\n";
>	}
>}
>
>```
>
>可以使用派生类对象初始化基类对象
>
>```c++
>//TennisPlayer 为基类，RatedPlayer为派生类
>	RatedPlayer s2(1000,"min","rui",false);
>	TennisPlayer s3(s2); //使用派生类作为参数初始化基类对象  
>												//使用了复制构造函数 TennisPlayer(const TennisPlayer &) 参数可以传递派生类
>	s3.Name(); 
>```
>
>派生类赋值给基本类对象
>
>```c++
>//TennisPlayer 为基类，RatedPlayer为派生类
>RatedPlayer s1(1840,"min","rui",false);
>TennisPlayer s2;
>s2=s1;  // 程序讲使用隐式重载运算符
>				// TennisPlay& operator=(const TennisPlay &t);  参数可以传递派生类对象
>```
>



### 多态公有继承

>派生类 拥有和基类一样的方法（函数）
>
>**有两种重要的机制可以用于实现多态共有继承**
>
>- **在派生类中重新定义基类的方法**
>
>- **使用虚方法**（虚函数）
>
>  
>
>**virtual**     关键字 虚构的
>
>- **如果在派生类中重新定义基类方法，通常把基类定义为虚的（加上关键字 virtual ）**
>- **如果同名函数 在基类有关键字 virtual 派生类会自动页生成为虚汗，但是最好也加上关键字，方便看**
>- **虚方法（虚函数 ）要和指针 或者引用配合使用**
>
>```c++
>class Brass{
>  ...
>    public:
>  		virtual void ViewAcct(); //虚函数 关键字virtual卸载函数声明里面就可以了，定义里面不用写关键字
>};
>
>
>class BrassPlus:public Brass{
>  ...
>    public:
>  		void ViewAcct();//如果同名函数 在基类有关键字 virtual 派生类会自动页生成为虚汗
>}
>
>//Brass 基类 BrassPlus 派生类
>
>Brass liang("liang");
>BrassPlus min("minliang",1222180122218,32);
>Brass &r1=liang;			//基类的引用 引用的对象为基类
>Brass &r2=min;				//基类的引用 引用的对象为派生类
>
>Brass *p1=&liang;			//基类的指针指向基类
>Brass *p2=&min;				//基类的指向指向派生类
>
>r1.ViewAcct();			//使用基类的方法 
>r2.ViewAcct();			//使用派生类的方法 如果没有关键字virtual 也会使用基类的方法
>
>p1->ViewAcct();			//使用基类的方法
>p2->ViewAcct();			//使用派生类的方法 如果没有关键字virtual 也会使用基类的方法
>
>
>```
>
>⚠️注意
>
>**如果没有定义虚方法：基类的指针和引用 都是调用基类的方法**
>
>**如果定义了虚方法:	基类的指针和引用 会调用指向或者引用的数据类型的方法**
>
>
>
>⚠️ **析构函数**
>
>```c++
>养成习惯，只要有派生类，就把基类的析构函数定义成虚方法
>virtual ~Brass(){};
>```
>
>⚠️注意
>
>在派生类 方法中使用基类的方法，如果重新定义了，在前面加一个 基类的名称::方法() 如果没被重新定义直接 用 方法() 就可以了
>
>```c++
>//file_name:brass.h
>#ifndef __BRASS_H__
>#define __BRASS_H__
>#include <string>
>#include <iostream>
>
>using namespace std;
>
>class Brass{
>private:
>	string fullName;	//名字
>	long acctNum; 		//账号
>	double balance;		//余额
>public:
>	Brass(const string&s="nobody",long an=-1,double bal=0.0);
>	void Deposit(double amt);			//存款
>	virtual void Withdraw(double amt);	//取款
>	double Balance()const;  			//显示余额
>	virtual void ViewAcct()const; 		//显示全部
>  virtual ~Brass(){};   //基类要被生成派生类 加单独的析构函数
>
>};
>
>
>class BrassPlus:public Brass{
>private:
>	double maxLoad ;	//透支上限
>	double rate_;		//透支利率
>	double owesBank;	//当前投资总额
>public:
>	BrassPlus(const string&s="nobody",long an=-1,double bal=0.0,
>		double ml=500.0,double rate=0.11125,double ow=0.0); //派生类构造函数
>
>	BrassPlus(const Brass&br,double ml=500.0,double rate=0.11125,double ow=0.0);
>	virtual void ViewAcct()const;	//方法重写;
>	virtual void Withdraw(double amt);  //取款
>	void ResetMax(double m){maxLoad=m;}
>	void ResetRate(double r){rate_=r;}
>	void ResetOwes(){owesBank=0.0;}
>};
>
>#endif 
>```
>
>```c++
>//file_name: brass.cpp
>#include "brass.h"
>
>Brass::Brass(const string &s,long an,double bal){
>	fullName=s;
>	acctNum=an;
>	balance=bal;
>}
>
>void Brass::Deposit(double amt){  //存钱
>	if (amt < 0)
>		cout <<"Nagative deposit is not allowed"<< endl;
>	else
>		balance +=amt;
>}
>
>void Brass::Withdraw(double amt){ //取钱
>	if(amt <0)
>		cout <<"Withdraw Must be positive[取款余额必须为正]"<< endl;
>	else if(amt > balance)
>		cout << fullName <<" not sufficient funds[余额不足]" << endl;
>	else
>		balance -=amt;
>}
>
>double Brass::Balance()const{
>	return balance;
>}
>
>void Brass::ViewAcct()const{
>	cout <<"fullName : "<< fullName << endl;
>	cout <<"acctNum : "<< acctNum << endl;
>	cout <<"余额 : $ " << balance <<endl;
>}
>
>BrassPlus::BrassPlus(const string&s,long an,double bal,
>		double ml,double rate,double ow):Brass(s,an,bal),	//构造派生类前 先构造基类 
>	maxLoad(ml),rate_(rate),owesBank(ow){
>}
>
>BrassPlus::BrassPlus(const Brass&br,double ml,double rate,double ow
>	):Brass(br){				//构造派生类前 先构造基类 
>	maxLoad=ml;
>	rate_=rate;
>	owesBank=ow;
>}
>
>void BrassPlus::ViewAcct()const{
>	Brass::ViewAcct();	//声明使用基类里面的函数 ⚠️
>	cout <<"透支上限 :$ " << maxLoad <<endl;
>	cout <<"利率：" << rate_ << endl;
>	cout <<"透支总额 :$ " << owesBank << endl;
>}
>
>
>void BrassPlus::Withdraw(double amt){
>	double bal=Balance(); // 直接调用基类方法  返回当前余额传递给临时变量⚠️
>	if(amt <=bal)
>			Brass::Withdraw(amt);   //已经重写方法了，指定使用基类的方法;
>	else if(amt <= bal +maxLoad -owesBank){
>		double advance=amt-bal;
>		owesBank = advance * ( 1 + rate_) ;
>		cout <<"手续费:" << advance * rate_ << endl;
>		Deposit(advance);		//使用继承的方法
>		Brass::Withdraw(amt);		//已经重写方法了，指定使用基类的方法;
>
>	}else{
>		cout <<"Credit limit exceeded![超出取款上线]" << endl;
>	}
>
>}
>
>```



### 注意：静态联编和动态联编 ⚠️ 

>
>
>如果要在派生类中重新定义基类方法，则将它设置为虚方法，否则，设置为非虚方法
>
>每个对象都隐藏了一个指针，指向函数地址数组的指针，这种数组被称为虚函数表
>
>每个类，编译器都创建一个虚函数地址表（数组）
>
>注意事项：
>
>- **在基类的方法声明中使用了关键字 virtual 可以让所有的派生类 的方法都是虚的**
>
>- **基本的指针或者引用 指向派生类,或者引用派生类，将使用派生类的方法**
>
>- **如果在基类里面定义为虚函数了，派生类都应该声明为虚的，前面加上关键字 virtual （方便理解）**
>
>- **virtual 只需要在声明中定义就可以了，在实现中不需要加关键字 virtual** 
>
>- **构造函数不能是虚函数** 
>
>- **析构函数应该是虚函数  virtual ~baseclass(){}** 
>
>- **友元函数不能是虚函数，因为他不是成员函数**
>
>- **虚函数 在基类和派生类中 参数也应该一样，要不然就不是属于一个函数**
>
>- **在派生类中重新定义一个函数(函数名和基一样)，但是和基类中的 函数特征标不一样，会隐藏基类的方法；**⚠️
>
>- **在派生类中重载的函数 参数特征标一定要和基类一样 ，但是返回值无所谓**
>
>- **在基类中所有函数有函数被重载(函数名一样，参数特征标不一样)，则应该所有重载的函数都需要在派生类中重新定义 并且加上关键字virtual**
>
>  





### 访问控制:protected

>**基类定义的 protected ，派生类可以访问**
>
>对于外部世界来说，protected 成员和 private成员一样 对于派生类来说 protected 和 public成员一样
>
>基类数据应该避免使用protected,避免派生类任意修改 数据



### 抽象基类

>
>
>纯虚函数
>
>抽象类一定会有一个纯虚函数 后面=0 代表
>
>```c++
>virtual double Area()const=0;  //最后的=0 代表该类是一样抽象类
>																//析构函数不可以 = 0; 应该是需要重写的其他方法可以;
>		
>```
>
>
>
>抽象类不能被实例话，存在的的理由就是给别的类当基类;
>
>```c++
>//下面是一个圆类 和椭圆类的抽象基类
>//可以用该类的指针或者引起用 管理派生出来的类（也就是圆类和椭圆类）
>class BaseEllipse{
>private:
>	double x;
>	double y;
>public:
>	BaseEllipse(double x0=0,double y0=0):x(x0),y(y0){}
>	virtual ~BaseEllipse(){}
>	void Move(int nx,int ny){x=nx,y=ny}
>	virtual double Area()const=0;	//最后面有个0；纯虚函数（pure virtual function）
>																	//代表函数可以实现，也可以不实现
>}
>```
>
>**两个派生类继承一个抽象基类**
>
>可以用一个抽象积累的指针指向派生出来的类,可以同时管理
>
>```c++
>#ifndef __ACCTABC_H__
>#define __ACCTABC_H__
>#include <string>
>#include <iostream>
>
>using namespace std;
>
>class Acctabc{				//抽象基类：不能被实例话，只能被继承
>private:
>	string fullName;		//三个私有变量，公共的部分抽取出来
>	long acctNum;
>	double balance;
>
>protected:				//被保护的方法,派生类可以直接使用
>	 const string& FullName()const{return fullName;}   //第一个const不写会出错 ⚠️不知道啥原因
>	 long AcctNum()const{return acctNum;}
>
>public:
>	Acctabc(const string&s="Nullbody",long an=-1,double ba=0.0):fullName(s),acctNum(an),balance(ba){};
>																//成员初始化
>	void Deposit(double amt);					//所有通用方法，直接写出来就完事了
>	virtual void Withdraw(double amt)=0;		//存虚函数 =0,可以定义也可以不定义
>	double Balance()const{return balance;}		//公共的方法，抽取出来
>	virtual void ViewAcct()const =0;			//一定会被重新写的函数,定义成虚函数 后面加0，写不可定义都ok
>	virtual ~Acctabc(){} 						//虚函数析构函数
>};
>
>
>
>class Brass:public Acctabc{					//第一个继承的类 没有私有变量，直接继承抽象基类
>public:
>	Brass(const string&s="Nullbody",long an=-1,double ba=0.0):Acctabc(s,an,ba){};
>	virtual void Withdraw(double amt);	//取款
>	virtual void ViewAcct()const; 		//显示全部
>	virtual ~Brass(){} 					//虚函数析构函数 最好也写上
>};
>
>
>class BrassPlus:public Acctabc{		//第二个派生类,继承抽象积累
>private:						//新增加的三个成员变量，也被定义成私有变量
>	double maxLoad ;			//透支上限
>	double rate_;				//透支利率
>	double owesBank;			//当前投资总额
>public:
>	BrassPlus(const string&s="nobody",long an=-1,double bal=0.0,
>		double ml=500.0,double rate=0.11125,double ow=0.0); //派生类构造函数
>
>
>	BrassPlus(const Acctabc&br,double ml=500.0,double rate=0.11125,double ow=0.0);  
>											//这个方法其实用不上，因为抽象基类不能被实例话，所有没有他的引用
>	virtual void ViewAcct()const;			//方法重写;
>	virtual void Withdraw(double amt);  	//取款
>	void ResetMax(double m){maxLoad=m;}
>	void ResetRate(double r){rate_=r;}
>	void ResetOwes(){owesBank=0.0;}
>	virtual ~BrassPlus(){} 				//最好也加一个虚析构函数，反正没什么错
>};
>
>
>#endif 
>```



### 继承和动态内存分配

>
>
>有开辟内存的，不适合用默认复制构造函数。没有开辟新内存，要自己重新写
>
>有开辟内存的，也不适合用复制运算符，也要自己重新写
>
>也就是说，有开辟新的内存，才需要重新写复制构造函数 和 复制运算符号;
>
>**如果有分配内存，需要有复制构造函数,赋值运算符，析构函数；**
>
>```c++
>//如果基类 和 派生类 都开辟内存了 赋值运算符 这样定义
>//fatherclass sonclass
>
>sonclass& sonclass::operator(const sonclass & st){
>  if(this==&st)
>    return *this;
>  fatherclass::operaotr=(st);  //使用 基类 的 赋值运算符
>  delete []son_poiter;					//删除旧开辟的内存
>  son_pointer =new char[strlen(st.sonpointer) +1];//开辟新的内存
>  strcpy(son_pointer,st.son_pointer);		//拷贝数据
>  return *this;			
>}
>
>```
>
>
>
>
>
>**派生类转换成基类**⚠️
>
>派生类转换成基类   **(const 基类&) 派生类**  可以运用基类的方法
>
>用 **( 基类) 派生类** 转换也可以的
>
>```c++
>//baseDMA 为基类,lacksDMA为派生类
>
>ostream& operator<<(ostream&os,const baseDMA&rs){
>	os << "Label :" << rs.label <<endl;
>	os << "rating :" << rs.rating << endl;
>	return os;
>}
>
>ostream& operator<<(ostream&os,const lacksDMA& rs){
>	os << (const baseDMA &) rs;						//派生类转换为基类
>	os << "color :" << rs.color <<endl;
>	return os;
>}
>
>```



### 派生类使用new分配内存

>派生类的复制构造函数，赋值运算符，析构函数，都需要用积累的方法来做
>
>```
>Baseclass a("some text",1);
>
>```
>
>```c++
>//headfile
>#ifndef __TEXT_H__
>#define __TEXT_H__
>
>
>#include <iostream>
>using namespace std;
>
>
>class BaseABC{	//基类
>private:
>	char *name_;
>	int age_;
>public:
>	BaseABC(const char *name,int age);
>	BaseABC(const BaseABC& ba);
>	virtual ~BaseABC();
>	virtual BaseABC& operator=(const BaseABC&ot);
>	friend ostream& operator<<(ostream &os,const BaseABC& ba);
>	virtual void show();
>};
>
>
>class Person:public BaseABC{
>private:
>	char * hobby_; //爱好
>	double height_;  //身高 
>	double weight_; //体重
>
>public:
>	Person(const char *name="None",int age=0, const char * hobby ="None",double height=0.0,double weight=0.0);
>	Person(const BaseABC& ba,const char * hobby ="None",double height=0.0,double weight=0.0);
>	Person(const Person &pe);
>	virtual ~Person();
>	virtual Person& operator=(const Person& pe);
>	friend ostream& operator<<(ostream &os,const Person& pe);
>	virtual void show();
>
>};
>
>
>#endif
>```
>
>```c++
>//function file
>#include "text.h"
>#include <cstring>
>
>
>
>
>BaseABC::BaseABC(const char *name,int age){
>	name_=new char[strlen(name)+1];
>	strcpy(name_,name);
>	age_=age;
>}
>
>
>BaseABC::BaseABC(const BaseABC&ba){
>	name_=new char[strlen(ba.name_)+1];
>	strcpy(name_,ba.name_);
>	age_=ba.age_;
>}
>
>BaseABC::~BaseABC(){
>	delete []name_;
>}
>
>BaseABC& BaseABC::operator=(const BaseABC& ot){
>	if(this ==&ot)
>		return *this;
>	delete []name_;
>	name_=new char[strlen(ot.name_)+1];
>	strcpy(name_,ot.name_);
>	age_=ot.age_;
>	return *this;
>}
>
>ostream& operator<<(ostream &os,const BaseABC& ba){
>	cout <<"\n";
>	os << "姓名 : "<<ba.name_ << "\n";
>	os << "年龄 : "<<ba.age_ << "\n";
>	return os;
>}
>
>
>void BaseABC::show(){					//⚠️:基类的的虚方法：调用非虚函数
>	cout << *this;
>}
>
>Person::Person(const char *name,int age, const char *hobby,
>	double height,double weight):BaseABC(name,age),
>		height_(height),weight_(weight)
>{
>
>	hobby_ = new char[strlen(hobby) +1];
>	strcpy(hobby_,hobby);
>	
>}
>
>Person::Person(const BaseABC& ba,const char * hobby,double height,
>	double weight):BaseABC(ba),					//⚠️ 重点1: 派生类构造 还是要用基类的构造方法
>	height_(height),weight_(weight)
>{
>	hobby_ = new char[strlen(hobby) +1];
>	strcpy(hobby_,hobby);
>
>}
>
>Person::Person(const Person &pe):BaseABC(pe){	//⚠️ 重点2:还是要用基类初始化 构造方法
>
>	hobby_=new char[strlen(pe.hobby_) +1];
>	strcpy(hobby_,pe.hobby_);
>	weight_=pe.weight_;
>	height_=pe.height_;
>}
>
>Person::~Person(){
>
>	delete []hobby_;	//删除
>}
>
>Person& Person::operator=(const Person& pe){
>	if(this ==&pe)
>		return *this;
>	BaseABC::operator=(pe);						//⚠️ 重点3:在派生类里面 用父类的赋值运算符 *this指针 可以省略
>												//这是赋值运算符的 函数表示方法 指明用父类的  = 赋值运算符  类似 a=2 的语法
>												//如果不用函数表示法：派生类会用自己的 = 赋值运算符，会造成无限递归
>	delete []hobby_;
>	hobby_ = new char[strlen(pe.hobby_)+1];
>	height_ = pe.height_;
>	weight_ = pe.weight_;
>	return *this;
>}
>
>ostream& operator<<(ostream&os,const Person&pe){   //⚠️ 重点4: 非成员函数，不能当作虚函数来使
>	os << (const BaseABC &) pe ;					//⚠️ 重点5:转换类型 在打印 os根据数据类型 使用哪种方法
>	os << "姓名 : "<< pe.hobby_ << "\n";
>	os << "身高 : "<< pe.height_ << "\n";
>	os << "体重 : "<< pe.weight_ << "\n";
>	return os;
>}
>
>void Person::show(){				//⚠️ 重点6:当作虚函数了,使用非成员函数来操作自己
>														//⚠️
>	cout <<*this;
>}
>
>
>```
>
>```c++
>//main file
>#include "text.h"
>
>const int SIZE=3;
>
>int main(){
>	Person minqian("minqian",30,"化妆",168.00,45.00);
>	BaseABC *arr[SIZE]={new BaseABC("minliang",32),  //指针要开辟新空间
>                      new Person("minrui",3,"奥特曼",120.00,24.00),
>                      &minqian   								 //指向已经存在的类实例
>                     };
>
>	for (int i=0;i<SIZE;i++){
>    //cout <<*arr[i];   //⚠️invalid, cout not member function 
>    										//翻译上一句注释，不允许，cout 不是成员函数
>		arr[i]->show();
>		cout <<"Addr:" << arr[i] << endl;
>	}
>
>	delete arr[0];  // new开辟出来的内存  delete 要记得删除
>	delete arr[1];
>	//delete arr[2];	//自动变量，不用删除，离开作用域就自动销毁了
>
>	return 0;
>}
>
>
>```
>
>

### 类设计回顾

>#### **默认构造函数：**
>
>派生类没有显示调用基类的构造函数,编译器会调用基类的默认构造函数
>
>```c++\
>Start rigel;	//使用默认构造函数 调基类的构造函数
>Start ple[6];
>```
>
>#### **复制构造函数**：
>
>以下情况用到复制构造函数
>
>- 用一个类对象 初始化另外一个类对象
>- 按值把对象传递给函数
>- 函数按值返回对象
>- 编译器生成临时对象
>
>#### **赋值运算符**：
>
>处理同类对象的赋值
>
>```
>classname s1;
>classname s2=s1;  //用复制构造函数
>classname s3;
>s3=s1;					//用赋值运算符
>```
>
>#### **析构函数：**
>
>在构造函数中使用new 分配内存，一定要显示写析构函数，如果要被继承，最好定义成虚析构函数 加上关键字 virtual
>
>
>
>**转换:**
>
>把类的类型转换成其他类型 或者把其他类型转换成类：
>
>
>
>explicit:禁止隐适转换，但是可以显示转换
>
>```c++
>class Myclass{
>private:
>	int age;
>public:
>	explicit Myclass(int n){age=n;}
>	void show(){cout <<"age:" << age << endl;}
>};
>
>int main(){
>	Myclass t(1); //⚠️ ok
>	t.show();
>	Myclass t2=5;  //⚠️：不允许
>	t2.show();
>	Myclass t3=Myclass(6); //⚠️ ok
>	t3.show();
>
>	return 0;
>}
>```
>
>
>
>#### **按值和按引用传递对象：**
>
>按值会生成临时拷贝，会生成副本，不是原来的类
>
>按引用传递参数，操作的还是原原来的对象，如果不希望被修改，应该加上const 引用
>
>按引用，参数为基类的对象传递给函数时候，可以使用用基类的对象和派生可以的对象 （指针也行）
>
>
>
>#### **返回对象和返回引用**
>
>返回对象会生成临时副本,
>
>返回引用会节约内存，还是原来的对象，操作的是同一个对象
>
>
>
>#### **const关键字**
>
>函数参数 带const；//函数不会修改参数
>
>```c++
>Start::Start(const char*s);  //参数不会被修改
>```
>
>函数最后带const ；//不会修改调用他的对象
>
>```c++
>void Start::Value()const{...}  //不会修改调用他的对象
>```
>
>函数的返回值是：const  //只是用来接收返回值  //函数返回值赋值给
>
>```c++
>//第一个const是接受数据的  第二个const 保证参数不被修改 第三个const 保证类的成员变量不被修改
>//接收的参数 是 参数或者类对象，他们都是const类型 所有需要返回值也加上const
>const Stock& Stock::topval(const Stack& s)const
>{
> if(s.total_val > total_val)
>   return s;
> else
>   return *this;
>}
>
>
>```
>
>
>
>#### **不能被继承的函数**
>
>**构造函数**和**析构函数**都不能被继承
>
>**赋值运算符**也不能继承，特征标不一样
>
>
>
>**私有成员和保护成员**
>
>关键字：**protected** 
>
>对于派生类来说，基类保护成员 可以当公有成员来使用
>
>数据最好都定义成私有的
>
>
>
>#### **虚方法：**
>
>关键字：virtual
>
>**如果希望派生类重新定义方法，应该在基类中定义为虚方法**
>
>```c++
>ViewAcct()为类的虚方法：
>void show1(const Brass& rba){  //当参数是基类的引用的时候，并且ViewAcct是虚方法，
> rba.ViewAcct();							 // rba 可以是基类的引用，页可以是派生类的引用，
> 															//然后根据引用的数据类型，决定使用基类的方法还是派生类的虚方法
>}	
>
>void show2(Brass rba){		 //按值传递 只使用积累的方法
> rba.ViewAcct();						//只能使用基类的方法
>}
>```
>
>
>
>#### **析构函数**
>
>如果基定义析构函数 他应该被定义成虚函数
>
>```c++
>Baseclass * pt=new derived_class; //基类指针指向派生类
>delete pt;					//他应该用基类虚构函数还是派生类的虚构函数
>										//积累定义
>```
>
>
>
>#### **友元函数**
>
>友元函数不是成员函数，所以不能继承
>
>如果派生类友元函数希望使用基类的友元函数,可以使用强制类型转换
>
>```c++
>cout << (const Base_Class &) Derived_Class;  //派生类强制类型转换基类,使用基类的友元函数 
>or
>cout << dynamic_case<const Base_class &> (Derived_Class);
>```
>
>
>
>**类函数总结**
>
>





## chapter14:c++中的代码重用



### 类中使用别的类

>```c++
>#ifndef __STUDENT_H__
>#define __STUDENT_H__
>
>#include <iostream>
>#include <valarray>
>#include <string>
>
>using namespace  std;
>
>
>
>class Student{
>
>private:
>typedef valarray<double> ArrayDb;
>string name;
>ArrayDb Scores;
>public:
>Student():name("None"),Scores(0){}
>explicit Student(const string &s):name(s),Scores(0){}
>explicit Student(int n):name("None"),Scores(n){}
>Student(const string&s,int n):name(s),Scores(n){}
>Student(const string&s,const double *pd,int n):name(s),Scores(pd,n){}
>
>double Average()const;
>~Student(){}
>const string &Name()const;
>double &operator[](int n);
>double operator[](int n)const;
>
>friend istream& operator>>(istream&is,Student &stu);
>friend istream& getline(istream&is,Student& stu);
>friend ostream& operator<<(ostream&os,const Student &stu);
>
>};
>
>#endif
>```
>
>w
>
>```c++
>#include "student.h"
>
>
>
>double Student::Average()const{
>if(Scores.size() > 0){
>return Scores.sum() /Scores.size();
>}else{
>return 0.0;
>}
>}
>
>
>const string &Student::Name()const{
>return name;
>}
>
>
>double &Student::operator[](int n) {
>return Scores[n];
>}
>
>
>double Student::operator[](int n)const{
>return Scores[n];
>}
>
>
>istream& operator>>(istream&is,Student &stu){
>is >> stu.name;
>return is;
>}
>
>istream& getline(istream&is,Student& stu){
>getline(is,stu.name);
>return is;
>
>}
>
>ostream& operator<<(ostream&os,const Student &stu){
>int i;
>int len=stu.Scores.size();
>
>os << "name: " << stu.name <<"Scores list:";
>
>if (len > 0) {
>for(i=0;i < len;i++){
>  os << stu.Scores[i] << " ";
>  if(i % 5 ==4)
>      os << endl;
>}
>}else{
>os <<"No data\n";
>}
>
>return os;
>
>}
>
>```
>
>```c++
>#include "student.h"
>
>const int SIZE = 3;
>const int MA = 5;
>
>
>void fill(Student &st, int n);
>
>int main() {
>
>Student aba[SIZE] = {Student(MA), Student(MA), Student(MA)};
>
>for (int i = 0; i < SIZE; i++) {
>   fill(aba[i], MA);
>}
>
>for (int i = 0; i < SIZE; i++) {
>   cout << aba[i] << endl;
>   cout << "Average :" << aba[i].Average() << endl;
>}
>
>return 0;
>}
>
>void fill(Student &st, int n) {
>cout << "please enter the fullname:" << endl;
>getline(cin, st);
>cout << "please enter the scores list:" << endl;
>for (int i = 0; i < n; i++) {
>   cin >> st[i];
>}
>while (cin.get() != '\n');
>}
>```

### 私有继承

>私有继承的私有基类方法 只能在私有派生类中使用，没有成员变量
>
>使用包含 用对象名字调用私有函数，**使用私有继承 使用类名加作用域运算符来调用私有函数**
>
>```c++
>class Student : private string, private valarray<double> {
>
>private:
>typedef valarray<double> ArrayDb;
>
>public:
>using valarray<double>::size;    //声明使用私有继承的方法，不需要带参数啥的
>using valarray<double>::sum;
>
>int Size() { return size(); }      //直接使用私有基类的方法
>double Sum() { return sum(); }
>}
>```
>
>
>
>```c++
>#ifndef __STUDENT_H__
>#define __STUDENT_H__
>
>#include <iostream>
>#include <valarray>
>#include <string>
>
>using namespace std;
>
>
>class Student : private string, private valarray<double> {
>
>private:
>typedef valarray<double> ArrayDb;
>
>ostream &arr_out(ostream &os) const;
>
>public:
>using valarray<double>::size;    //声明使用私有继承的方法，不需要带参数啥的
>using valarray<double>::sum;
>
>int Size() { return size(); }      //直接使用私有基类的方法
>double Sum() { return sum(); }
>
>
>Student() : string("None"), ArrayDb(0) {}
>
>explicit Student(const string &s) : string(s), ArrayDb(0) {}
>
>explicit Student(int n) : string("None"), ArrayDb(n) {}
>
>Student(const string &s, int n) : string(s), ArrayDb(n) {}
>
>Student(const string &s, const double *pd, int n) : string(s), ArrayDb(pd, n) {}
>
>double Average() const;
>
>~Student() {}
>
>const string &Name() const;
>
>double &operator[](int n);
>
>double operator[](int n) const;
>
>friend istream &operator>>(istream &is, Student &stu);
>
>friend istream &getline(istream &is, Student &stu);
>
>friend ostream &operator<<(ostream &os, const Student &stu);
>
>
>};
>
>
>#endif
>
>
>```
>
>```c++
>#include "student2.h"
>
>
>
>ostream& Student::arr_out(ostream &os) const{   //不修改类 成员记得加const
>int i;
>size_t len =ArrayDb::size();  //只能用私有基类的方法
>if (len > 0) {
>   for(i=0;i < len;i++){
>       os << ArrayDb::operator[](i) << " ";
>       if(i % 5 ==4)
>           os << endl;
>   }
>}else{
>   os <<"No data\n";
>}
>
>return os;
>
>
>}
>
>
>double Student::Average()const{
>if(size() > 0){
>   return sum() /size();   //  using 私有基类的方法 ，可以直接使用
>}else{
>   return 0.0;
>}
>}
>
>
>const string &Student::Name()const{
>return (const string&) *this;
>}
>
>
>double &Student::operator[](int n) {
>return ArrayDb::operator[](n);
>}
>
>
>double Student::operator[](int n)const{
>return ArrayDb::operator[](n);
>}
>
>
>istream& operator>>(istream&is,Student &stu){
>
>is >> (string& ) stu;
>return is;
>}
>
>istream& getline(istream&is,Student& stu){
>getline(is,(string& ) stu);
>return is;
>
>}
>
>ostream& operator<<(ostream&os,const Student &stu){
>
>
>os << "name: " << (const string &) stu <<"Scores list:";
>
>stu.arr_out(os);                //友元函数无法使用私有私有基类的数据成员，可以用派生类的方法调用私有基类，然后使用派生类的方法
>
>return os;
>
>}
>
>```
>
>

### 多重继承和虚类类



<img src="http://minliang.asuscomm.com:5543/pic/1672327320173413.png" alt="**!(http://minliang.asuscomm.com:5543/pic/1672327320173413.png)**" style="zoom:50%;" />

虚基本类 是多个对象只继承一个对象

一个基类派生两个虚基类，然后一个派生类，继承两个这两个虚基类

A 派生出 B C 并且 BC都定义成虚基类 

有D同时继承 B C的时候 此时A只有一个方法

>```c++
>class Worker{
>private:
>	string fullname;
>	long id;
>public:
>	Worker(const string &s,long d);
>}
>
>class Waiter:public virtual Worker	//继承虚基类
>{
>private:
>	int panache;
>public:
>	Waiter(): Worker(),panache(){}
>	Waiter(const string&s,long n,int p=0):Worker(s,n),panache(p){}
>}
>
>class Singer:virtural public Worker	//继承虚基类2
>{
>private:
>	int voice;
>public:
>	Singer():Worker(),voice(other){}
>	Singer(const string& s,long n,int v=other):Worker(s,n),voice(v){}
>	void Set();
>	void Show()const;
>};
>
>
>class SingingWaiter:public Watier,public singer{
>public:
>	SingingWaiter(){};
>	SingingWaiter(const string&s,long d,int p,int v):Worker(s,d),Waiter(s,d,p),Singer(s,d,v){}
>	SingingWaiter(const Worker&wk,int p,int v):Worker(wk),Waiter(wk,p),Singer(wk,v){}
>																					//虚基类都要默认构造一下
>}
>
>
>```
>
>当有多个同名方法的时候
>
>```c++
>class A{
>  public:
>  void show()const;
>}
>
>class B:virtual public A{
>  public:
>  void show()const;
>}
>
>class C:virtual public A{
>  public:
>  void show()const;
>}
>
>class D:public B,public C{
>  public:
>  D:A(args),B(args),C(args)(); //都需要构造函数，因为B C都包含A， A只会被初始化一次，BC里面的A不会被构造）
>  															//
>  void show()const ;//此时也需要定义 const
>  									//要不然D调用 show()函数不知道调用谁
>  
>}
>
>int main(){
>  D d;//
>  d.A::show();//调用A里面的show 函数
>  d.B::show();//调用B里面的show 函数
>  d.C::show();//调用C里面的show 函数
>  d.show();//调用D自己定义的show 函数
>}
>```
>
>

### 类模版

>注意事项
>
>**1.类的头部加上 template <clsss T>** 
>
>**2.函数定义每个都需要加上   template <clsss T>** 
>
>**3 作用域 不在是。类名称::  而是  类名<T>**
>
>**4.头文件和实现不能分开，需要放在头文件中   模版不是函数定义不能单独放一个文件中 要和头文件放一起**
>
>```c++
>template <clsss T>  // or template<typename T>
>class Stack{
>...
>};
>
>每个成员函数都需要加上 // template <clsss T> 
>template <clsss T>  
>Stack<T>::Stack(){   //作用域运算符改成 Stack<T>
>...
>}
>```
>
>```c++
>int main(){
>Stack<int> stack1;   //实例话
>Stack<string> stack2;  //实例话2
>}
>```

#### 类模版2

>
>
>```c++
>#ifndef __STACK__H__
>#define __STACK__H__
>#include <iostream>
>
>
>
>template<typename T>
>class Stack{
>private:
>static const int MAX=10;
>T items[MAX];
>int top;
>public:
>Stack();
>bool isfull();
>bool isempty();
>bool push(T& item);
>bool pop(T& item);
>};
>
>//
>// template<typename T>
>// int Stack<T>::MAX=10;
>
>template<typename T>
>Stack<T>::Stack(){
>top=0;
>}
>
>template<typename T>
>bool Stack<T>::isfull(){
>return top==MAX;
>}
>
>template<typename T>
>bool Stack<T>::isempty(){
>return top==0;
>}
>
>template<typename T>
>bool Stack<T>::push(T& item){
>if(!isfull()){
>   items[top++]=item;
>   return true;
>}else
>   return false;
>}
>
>
>template<typename T>
>bool Stack<T>::pop(T& item){
>if(!isempty()){
>   item=items[--top];
>   return true;
>}else
>   return false;
>}
>
>
>#endif
>
>```
>
>```c++
>#include <iostream>
>using namespace std;
>#include "stack.h"
>
>const int SIZE=4;
>int main(){
>	const char * arr[SIZE]={"1.hello,kitty","2.hello,kitty",
>							"3.hello,kitty","4.hello,kitty"};
>	Stack<const char *> s;
>	for(int i=0;i<SIZE;i++){
>		s.push(arr[i]);
>	}
>	const char *ar;
>
>	for(int i=0;i<SIZE;i++){
>		s.pop(ar);
>		cout << ar << endl;
>	}
>
>	return 0;
>}
>```
>
>

### 数组模版和非类型参数

>**template<class T,int n>**
>
>n叫做表达式参数，表达式参数可以是整形，枚举，引用，或者指针
>
>```c++
>//下面是两个类
>ArrayTp<double,12> eggweights;
>ArrayTp<double,13> donuts;
>
>//下面是一个类，两个实例，12，13是构造函数的参数
>Stack<int> eggs(12);
>Stack<int> dunkers(13);
>
>
>```
>
>**递归模版**
>
>```c++
>ArrayTp <ArrayTp <int,5>,10> twodee;
>等价于
>int twodee[10][5];  //维度的顺序相反的，注意
>
>```
>
>Code:
>
>```c++
>#ifndef __ARRAYTP_H__
>#define __ARRAYTP_H__
>
>#include <iostream>
>
>using namespace std;
>
>template<class T,int n>
>class ArrayTp{
>private:
>	T ar[n];
>public:
>	T &operator[](int i);	//可以读取并且修改
>	T operator[](int i)const; //只能读取
>};
>
>
>template<class T,int n>
>T& ArrayTp<T,n>::operator[](int i){  //加上作用域 ArrayTp<T,n>
>	return ar[i];
>}
>
>template<class T,int n>
>T ArrayTp<T,n>::operator[](int i)const{
>	return ar[i];
>}
>
>#endif
>
>
>```
>
>```c++
>#include <iostream>
>
>#include "arraytp.h"
>using namespace std;
>
>int main(){
>	ArrayTp<int,10> sums;
>	ArrayTp<double ,10> aves;
>	ArrayTp<ArrayTp<int,5>,10> twodee;
>
>	int i,j;
>
>	for(i=0;i<10;i++){
>		sums[i]=0;
>
>		for(j=0;j<5;j++){
>			twodee[i][j]=(i+1)*(j+1);
>			sums[i] +=twodee[i][j];
>		}
>		aves[i] =(double)sums[i] /10;
>
>	} 
>
>	for(i=0;i<10;i++){
>		for(j=0;j<5;j++){
>			cout.width(2);
>			cout << twodee[i][j] << " ";
>		}
>		cout << "sum:" << sums[i] << " , Average:" << aves[i] << "\n";
>	}
>
>	return 0;
>
>}
>```

### 默认模板类型参数

>
>
>```c++
>template<class T1,class T2=int>   //模版参数为默认值 ，
>class className{
>...
>};
>
>ClassName<int,double> c1;
>ClassName<int> c2; // ok
>
>```
>
>

### 多个模版类型

>
>
>```c++
>template<class T1,class T2>
>class Pair{
>private:
>T1 a;
>T2 b;
>public:
>T1& first();
>T2& second();
>}
>```
>
>

### 模版的具体化 11.4

>
>
>类的模版和函数很类似，因为可以有隐式实例化，显示实例化，和显示具体化
>
>**模版以泛型的的方式描述类，而是具体化是使用具体的类型生成类声明**
>
>1.隐式实例化
>
>```c++
>ArrayTp<int,100>stuff;// 生成了实例，
>
>ArrayTp<int,30> *pt ;//一个指针 只是去创建一个指针，不会隐式实例化
>```
>
>2.显示实例化
>
>```c++
>template class ArrayTp<string,100>;  //并没有创建对象
>																			//让编译器准备好,为了速度快
>
>```
>
>3.显示具体化
>
>```c++
>当类模版已经定义好了，为特定数据类型创建的具体化，特殊参数，特殊处理
>
>template<class T1,class T2>
>class A{
>public:
>	void show(){cout <<"func 1" << endl;}
>}
>
>
>template<> //两个都不要
>class A<int,int>{
>public:
>	void show(){cout <<"当数据类型都为int,int的时候，用这种方法"<<endl;}
>}
>
>int main(){
>A<double,double> T1;
>T1.show();//用不特殊的方法
>A<int,int> T2;
>T2.show();//参数都为int,int 用特殊方法；
>
>}
>
>```
>
>4.部分具体化
>
>```c++
>当类模版有两种数据类型，有一种类型是特定的数据类型，比如是int 要特殊处理
>template<class T1,class T2>
>class A{
>public:
>	void show(){cout <<"func 1" << endl;}
>}
>
>
>template<class T2>
>class A<int,T2>{
>public:
>	void show(){cout <<"当数据第一个为int类型的时候，用这种方法"<<endl;}
>}
>
>template<class T1>
>class A<T1,double>{
>public:
>	void show(){cout <<"当数据第2个为double类型的时候，用这种方法"<<endl;}
>}
>
>int main(){
>A<char,char> t1;
>t1.show();
>A<int,char> t2;
>t2.show();
>A<char,double>t3;
>t3.show();
>}
>
>```
>
>All code
>
>```c++
>#include <iostream>
>using namespace std;
>
>//1
>template <class T1,class T2>
>class A{
>public:
>	void show();
>};
>
>template<class T1,class T2>
>void A<T1,T2>::show(){
>	cout <<"use general definition|方法1｜我是普通方法" <<endl;
>}
>
>
>//
>//如果传递进来的是int,int 类型，要特殊处理；
>template<>
>class A<int,int>{		 //特殊处理类的声明
>public:
>	void show();
>};
>void A<int,int>::show(){ //特殊处理方法
>	cout <<"use specialized definition｜方法2｜我是显式具体化" <<endl;
>}
>
>//如果传递进来的第二个参数是int 要特殊处理
>template<class T1>
>class A<T1,int>{
>public:
>	void show();
>};
>template<class T1>
>void A<T1,int>::show(){
>	cout <<"using partcal specialized definition｜方法3｜我属于部分具体化" <<endl;
>}
>
>
>
>//如果传递进来的第1个参数是int 要特殊处理
>template<class T2>
>class A<long, T2>{
>public:
>	void show();
>};
>
>template<class T2>
>void A<long,T2>::show(){
>	cout <<"using partical specialized definition|方法4｜我属于欧部分具体化的第二个参数"<< endl;
>}
>
>//显示实例话//让编译器生成类
>template class A<double,int>;
>
>int main(){
>	A<double ,double> *temp=new A<double,double>;
>	temp->show();
>	delete temp;
>	A<int,int> t2;
>	t2.show();
>	A<double,int> t3;
>	t3.show();
>	A<long,char> t4;
>	t4.show();
>	return 0;
>}
>```
>
>

### 成员模版

>类的数据成员是一个类模版
>
>类的成员函数是一个函数模版 ｜有一些编译器不支持这样写在类模版里面套模版
>
>```c++
>#include <iostream>
>#include <string>
>
>using namespace std;
>
>//大类
>template<class T>
>class Beta{
>private:
>
>	template<class V> //私有函数里面定义一个类模版
>	class hold{					//小类
>	private:
>		V value;
>	public:
>		hold(V v=0):value(v){}
>		void show () const{cout << value<< endl;}
>		V Value()const{return value;}
>	};
>
>	hold<T> q;
>	hold<int> n;
>public:
>	Beta(T t,int i):q(t),n(i){}
>	void Show() const{q.show();n.show();}
>	void Show2()const{cout <<"T:" << q.Value() <<" , int:" << n.Value();}
>
>	template<class U>//函数模版 U没规定类型，T是类已经传递进来的类型
>	U blab(U u,T t){return (q.Value() + n.Value())*u/t;}
>};
>
>
>int main(){
>
>	Beta<double> guy(5.6,5);
>	cout <<"T set to double" << endl;
>	guy.Show();
>	//guy.Show2();
>
>	cout <<"V==T,the are all double,U set to int" << endl;
>	cout << guy.blab(4,5.6) << endl;
>
>	cout <<"V==T,the are all double,U set to double" << endl;
>	cout << guy.blab(4.0,5.6) << endl;
>
>
>
>	return 0;
>}
>```
>
>
>
>有些编译器不支持在类里面 写类模版 上面的代码 可以写成下面的
>
>```c++
>#include <iostream>
>
>using namespace std;
>
>
>template <class T1>
>class Big{
>private:
>	template <class T2> //私有模版类
>	class Small;
>
>	Small<T1> q; //数据成员1
>	Small<int> n;	//数据成员2
>public:
>	Big(T1 t,int nv):q(t),n(nv){} //构造函数
>
>	void Show()const{q.show();n.show();}
>
>	template<class U> //成员函数模版
>	U get_value(U u,T1 tt)const;
>};
>
>
>template<class T1>
>template<class T2>
>class Big<T1>::Small{ //Big<T1>类里面的类
>private:
>	T2 t;
>public:
>	Small(T2 n):t(n){}
>	void show()const{cout << t << endl;}
>	T2 Value()const{return t;}
>};
>
>
>template<class T1>
>template<class U>
>U Big<T1>::get_value(U u,T1 tt)const{ //Big<T1>类里面的成员函数
>	return (q.Value() + n.Value())* tt/u;};
>
>
>
>int main(){
>
>	Big<double> bb(6.5,5);
>	bb.Show();
>	cout << "get_value() : " <<bb.get_value(3,3.4) << endl;
>	cout << "get_value(2) : " <<bb.get_value(3.0,3.4) << endl;
>
>	return 0;
>}
>```
>
>

### 把模版用作参数

>
>
>**template<class T,int n>**
>
>**T属于类型参数，n属于非类型参数**
>
>
>
>**template<template< class T> class Thing>.** //模版类型作为一个参数
>
>**class Crab**
>
>
>
>```c++
>#include <iostream>
>#include "stack.h"
>using namespace std;
>
>						
>/*
>							
>template<template<class T,int SIZE> class T2,int nv> //有两个参数，一个是类模版，第二个是非类型参数nv
>        class Thing{
>        private:
>            T2<int,nv> t1;				//第二个非类型参数传递给 类模版
>            T2<double,nv*2> t2;
>        public:
>            Thing():t1(),t2(){}
>            bool push(int n){return t1.push(n);}		//函数重载，当参数是int类型时候，传递给t1
>            bool push(double d){return t2.push(d);}	//函数重载，当参数是double类型时候，传递给t2
>            void show();
>            bool pop(int& n){return t1.pop(n);}
>            bool pop(double& n){return t2.pop(n);}
>
>        };
>*/
>		
>template<template<class T> class Thing>  //类的模版  只有1个参数
>class Crab{
>private:
>	Thing<int> s1; //模版类
>	Thing<double> s2; //类2
>public:
>	bool push(int a,double x){return s1.push(a) && s2.push(x);}
>	bool pop(int &a,double &x){return s1.pop(a) && s2.pop(x);}
>	void show()const{
>		s1.show();
>		s2.show();
>	}
>};
>
>
>
>int main(){
>	int ni; 
>
>	double nb;
>
>	Crab<Stack> nebula;
>	cout <<"enter int & double pairs such as (5 5.6), 0,0 to end" << endl;
>
>	while((cin >> ni >> nb) && (ni>0 || nb>0) ){
>		if(!nebula.push(ni,nb))
>			break;
>		cout <<"入栈 " << "int : " << ni <<" ,double : " << nb << endl;
>	}
>
>	nebula.show();
>
>	while(nebula.pop(ni,nb))
>		cout <<"出栈 " << "int : " << ni <<" ,double : " << nb << endl;
>
>
>
>
>	return 0;
>}
>```
>
>
>
>
>
>
>
>```c++
>//file_name stack.h
>#ifndef __STACK__H__
>#define __STACK__H__
>#include <iostream>
>
>template<typename T>
>class Stack{
>private:
>	static const int MAX=10;
>	T items[MAX];
>	int top;
>public:
>	Stack();
>	bool isfull();
>	bool isempty();
>	bool push(T& item);
>	bool pop(T& item);
>};
>
>
>template<typename T>
>Stack<T>::Stack(){
>	top=0;
>}
>
>template<typename T>
>bool Stack<T>::isfull(){
>	return top==MAX;
>}
>
>template<typename T>
>bool Stack<T>::isempty(){
>	return top==0;
>}
>
>template<typename T>
>bool Stack<T>::push(T& item){
>	if(!isfull()){
>		items[top++]=item;
>		return true;
>	}else
>		return false;
>}
>
>
>template<typename T>
>bool Stack<T>::pop(T& item){
>	if(!isempty()){
>		item=items[--top];
>		return true;
>	}else
>		return false;
>}
>
>#endif
>
>```



### 类模版的静态变量-static 重要

>类模版的静态变量
>
>用一种类才共享一个类模版静态变量
>
>比如下面的
>
>**HasFriend<int> t1;** //所有的HasFriend<int> 才属于同一种类，共享一个类模版静态变量
>
>**HasFriend<double> t2** ;//这种属于另外一种了  与HasFriend<int> 不是同一种类，不共享类模版静态变量
>
>```c++
>template<class T>
>  class HasFriend{
>    private:
>    	T item;
>    	static int ct;//类模版的静态变量
>    public:
>      HasFriend(const T &i):item(i){ct++;} //同一种类共享一种ct值
>      ~HasFriend(){ct--;}
>  }
>
>template<class T>
>  int HasFriend<t>::ct=0; //类模版t的静态变量初始化，重要啊...
>                          //所有的一种类型共用一个ct值 
>                          //HasFriend<int> 共用一个ct值 该ct值+1之后，所有的 HasFriend<int> ct值+1
>                          //其他的 类型 比如HasFriend<double> 不会+1 还是模版的初始值 
>
>```
>
>





### 模版类和友元

>
>
>模版类声明也可以有友元，模版友元分为3类
>
>1. **非模版友元**
>
>   ```c++
>   template<class T>
>     class HasFriend{
>       public:
>       	friend void counts();	//所有HasFriend 的友元函数
>     }
>   ```
>
>   
>
>2. **约束模版友元，友元的类型取决于类被实例化时候的类型**
>
>   ```c++
>   //
>   // Created by macbookpro on 2023/1/6.
>   //
>   //非模版函数作为友元函数；
>   //使用函数模版，并且在类中具体化；
>   
>   #include <iostream>
>   using namespace std;
>   
>   template<class T>   //定义在外面的函数模版1，不带参数
>   void counts();
>   
>   template<class U>   //定义在外面的函数模版2，带参数
>   void Reports(U &);
>   
>   template<class V> //类
>   class HasFriend
>   {
>   private:
>       V item;
>       static int ct;
>   public:
>       HasFriend(const V &i):item(i){ct++;}
>       ~HasFriend(){ct--;}
>   
>       friend void counts<V>(); //函数模版具体化
>   
>       friend void Reports<HasFriend<V>> (HasFriend<V> &hf);  //函数模版具体化
>   };
>   
>   template<class V>
>   int HasFriend<V>::ct=0;//全局静态变量 //一种类型的类 共享一个静态变量
>                           // HasFriend<int> 共享一种
>                           // HasFriend<double> 共享另外一种
>   
>   template<class T>//函数模版的实现1
>   void counts(){
>       cout << "count:" <<HasFriend<T>::ct <<"\n";
>   }
>   
>   template<class U>   //函数模版的实现2
>   void Reports(U &tp){
>       cout <<tp.item << endl;
>   }
>   
>   int main(){
>       cout <<"No object declared:------\n";
>       counts<int>();
>       HasFriend<int> hfi1(10);
>     
>       cout << "After hfi1 declared:------\n";
>       counts<int>();
>       Reports(hfi1);
>   
>       HasFriend<int> hfi2(20);
>       cout << "After hfi2 declared:------\n";
>       counts<int>();
>       Reports(hfi2);
>   
>       HasFriend<double> hfd(5.55);
>       cout << "After hdf declared:------\n";
>       counts<double>();
>       Reports(hfd);
>   
>       return 0;
>   }
>   
>   
>   
>   ```
>
>   
>
>3. **非约束模版友元，友元的所有具体化都是每一个具体化的友元**
>
>   ```c++
>   #include <iostream>
>   
>   using namespace std;
>   
>   template<class T>
>   class ManyFriend{
>   private:
>       T item;
>   public:
>       explicit ManyFriend(const T&i):item(i){}
>   
>       template<class C,class D>
>               friend void show2(C&,D&);
>   };
>   
>   template<class C,class D>
>   void show2(C &c,D &d){
>       cout << c.item <<"  , " << d.item << endl;
>   }
>   
>   int main(){
>       ManyFriend<int> hfi1(10);
>       ManyFriend<int> hfi2(20);
>       ManyFriend<double> hfdb(10.5);
>       cout << "hfi1,hfi2 : ";
>       show2(hfi1,hfi2);
>       cout << "hfdb,hfi2:" ;
>       show2(hfi2,hfdb);
>   
>       return 0;
>   }
>   
>   ```
>
>   ### 

### 模版别名

>**using 别名=数据类型;**
>
>```c++
>typedef std::array<double,12> arrd;
>typedef std::array<int,12>arri;
>typedef std::array<std::string,12>arrst;
>
>arrd gallons;
>arri days;
>arrst months;
>```
>
>#### c++11新别名
>
>```c++
>template<typename T>
>using arrtype=std::array<T,12>; //arrype 是模板别名;
>
>using t1=arrtype<double> gallons;
>using t2=arrtype<int> days;
>using t3=arrtype<std::string> months;
>
>```
>
>```c++
>typedef const char *pc1;
>using pc2=const char *; //新的语法
>typedef const int *(*pa)[10];
>using pa2=const int *(*pa)[10];
>
>```
>
>

### 总结

>
>
>```c++
>公有继承 基类方法 派生类都可以用
>私有继承 基类方法 派生类只能用一部分
>  
>```



## chapter15:友元，异常和其他



### 友元类

>**友元类的所有方法都可以访问原始类的`私有成员，保护成员，public成员` **
>
>
>
>```c++
>class Base{
>private:
>	int a;
>protected:
>	int b;
>	void func();
>public:
>	void func2();
>	friend class Fr;
>};
>
>class Fr{
>private:
>	...
>	public:
>	void func3(Base &ba){ba.func();} //调用 友元类的私有函数
>	void show(Base &ba){cout << ba.a << " ," << ba.b;} //访问友元类的私有变量；
>}
>```
>
>**Example**
>
>```c++
>#ifndef __TV__H__ 
>#define __TV__H__ 
>
>#include <iostream>
>using namespace std;
>
>class TV{
>private:
>	enum{off,on};	//状态
>	enum{MinVal,MaxVal=20}; //音量
>	enum{MinChan=1,MaxChan=100}; //频道
>	enum{tv,DVD};	//模式
>
>
>	int state;	//状态
>	int volume;	//音量
>	int channel;	//频道
>	int input;	// tv,DVD
>public:
>	TV(int s=off):state(s),volume(5),channel(2),input(tv){}
>	void onoff(){state= (state == on) ?off:on;}
>	bool volup();
>	bool voldown(); //音量
>	void chanup(); //channel up
>	void chandown();
>	void set_input(){input = (input == tv)?DVD:tv;}
>	void show_setings()const;
>
>						//重点
>	friend class Remote;//Remote 所有方法 都可以访问TV类的 private 成员，protected 成员
>						//两个类 不存在包含 和 所属关系
>						//但是某个类 的方法，可以访问另外一个类的私有成员和保护成员和public 成员
>};
>
>
>class Remote{ //遥控器
>private:
>	int mode;
>public:
>	Remote(int m=TV::tv):mode(m){};
>
>	void onoff(TV&t){t.onoff();};//要操作哪一个电视
>								//调用 类里面的函数
>	bool volup(TV& t){return t.volup();}
>	bool voldown(TV& t){return t.voldown();}
>	void chanup(TV&t){ t.chanup();}
>	void chandown(TV &t){ t.chandown();}
>	void set_channel(TV &t,int c){t.channel=c;} //设置Tv的私有成员
>	void set_input(TV &t){t.set_input();}
>
>	void display(){
>		cout <<"Remote Mode: " << (mode==TV::tv ?"tv":"DVD") << endl;
>			}
>
>};
>
>
>#endif
>```
>
>```c++
>#include "tv.h"
>
>bool TV::volup(){
>	if(volume < MaxVal){
>		volume++;
>		return true;
>	}else 
>		return false;
>}
>
>bool TV::voldown() //音量
>{
>	if(volume>MinVal)
>	{
>		volume--;
>		return true;
>	}else
>		return false;
>}
>void TV::chanup()//channel up
>{
>
>	if(channel < MaxChan)
>		channel++;
>	else
>		channel=MinChan;
>}
>
>void TV::chandown(){
>	if(channel > MinChan)
>		channel--;
>	else
>		channel=MaxChan;
>}
>
>void TV::show_setings()const{
>	cout <<"TV is " << (state==on ? "on" : "off") << " ";
>	if(state ==on){
>		cout << ", volume:" << volume ;
>		cout <<", channel:" << channel ;
>		cout << ", Mode:" << (input == tv ?"TV":"DVD") << endl; 
>	}else
>		cout << "."<<endl;
>}
>```
>
>```c++
>#include "tv.h"
>
>int main(){
>	TV Panda;
>	cout <<"Initial setting for Panda Tv---" << endl;
>	Panda.show_setings();
>	Panda.onoff();
>	Panda.show_setings();
>
>	cout <<"----------"<< endl;
>	Panda.volup();
>	Panda.chanup();
>	Panda.show_setings();
>
>	cout <<"--Have a Remote--"<< endl;
>	Remote rt;
>	rt.set_channel(Panda,55);	
>	for(int i=0;i<97;i++)
>		rt.volup(Panda);
>	for(int i=0;i<101;i++)
>		rt.chanup(Panda);
>
>
>	Panda.show_setings();
>	rt.onoff(Panda);
>	Panda.show_setings();
>	rt.display();
>
>
>	return 0;
>}
>```
>
>

### 友元成员函数

>**只有友元类中的函数可以访问私有变量**
>
>简单描述：**设置某一个类中的某一个方法 才可以访问其的私有成员（private）和保护成员（protected）**
>
>`friend void 类::函数()`  函数得写在前面，要不然不认识
>
>```c++
>#include <iostream>
>using namespace std;
>
>class Tv; //前置声明 TV类
>
>class Remote{
>public:
>	void getvalue(Tv &t);  //在此之前不认识TV 需要前置声明 TV;
>
>	void sayhellokitty(){		//其他方法
>		cout <<"hello,kitty" << endl;
>	}
>	void show(Tv &t);
>
>	void reset(Tv&t,int n); //因为要修改Tv中的私有变量，但是前置声明之声明了有这么一个类，
>							//但是还不知道类中有哪些私有变量，所以这个函数需要写在类声明后面
>							//可以用inline 声明为内联函数，也可以不用
>};
>
>
>class Tv{
>private:
>	int channel;
>public:
>	Tv(int c=0):channel(c){}
>	int value(){return channel;}
>	void show() {cout <<"i am in class_Tv method_show()" << endl;}
>
>	friend void Remote::getvalue(Tv&t);  //声明 Remote中的getvalue为友元函数
>	friend void Remote::reset(Tv&t,int n); //修改私有变量
>};
>
>
>inline  //inline 用不用都行
>void Remote::getvalue(Tv&t){   //方法中channel为私有变量，如果定义在类中不认识
>	cout <<"value:" << t.channel << endl;
>}
>
>void Remote::show(Tv &t){
>	t.show();
>}
>
>void Remote::reset(Tv&t,int n){
>	t.channel =n;
>}
>
>
>int main(){
>	Tv tv(6);
>	Remote rem;
>	rem.getvalue(tv);
>	rem.sayhellokitty();
>	rem.show(tv);
>	rem.reset(tv,666); //tv中的私有变量
>	cout << tv.value() << endl;
>	return 0;
>}
>
>
>
>
>```
>
>
>
>设置一个类友元函数 把上面的头文件改成下面的
>
>```c++
>#ifndef __TV__H__ 
>#define __TV__H__ 
>
>#include <iostream>
>using namespace std;
>
>
>class TV; // 前置声明
>
>
>
>class Remote{ //遥控器
>private:
>	int mode;
>
>							//此类方法中用到了enum 拷贝一份enum 的变量
>	enum{off,on};	
>	enum{MinVal,MaxVal=20}; 
>	enum{MinChan=1,MaxChan=100}; 
>	enum{tv,DVD};	//模式
>public:
>	Remote(int m=tv):mode(m){};
>
>	void onoff(TV&t);
>								//调用 类里面的函数
>	bool volup(TV& t);			//方法都需要定义在最下面 前置声明之声明了类，没有声明方法
>								//方法需要放在最下面，并且 加上 inline 关键字 声明为内联函数
>	bool voldown(TV& t);
>	void chanup(TV&t);
>	void chandown(TV &t);
>	void set_channel(TV &t,int c);
>	void set_input(TV &t);
>	void display();
>
>};
>
>
>
>class TV{
>private:
>	enum{off,on};	//状态
>	enum{MinVal,MaxVal=20}; //音量
>	enum{MinChan=1,MaxChan=100}; //频道
>	enum{tv,DVD};	//模式
>
>
>	int state;	//状态
>	int volume;	//音量
>	int channel;	//频道
>	int input;	// tv,DVD
>public:
>	TV(int s=off):state(s),volume(5),channel(2),input(tv){}
>	void onoff(){state= (state == on) ?off:on;}
>	bool volup();
>	bool voldown(); //音量
>	void chanup(); //channel up
>	void chandown();
>	void set_input(){input = (input == tv)?DVD:tv;}
>	void show_setings()const;
>
>	// 定义了两个类方法为友元函数					
>	friend void Remote::set_channel(TV &t,int c);  //Remote 需要放在 前面，要不然不认识
>	friend void Remote::display();
>};
>
>inline //使之成为内联函数，和定义在类中一样
>void Remote::onoff(TV&t){t.onoff();};
>
>inline 
>bool Remote::volup(TV& t){return t.volup();}
>
>inline
>bool Remote::voldown(TV& t){return t.voldown();}
>
>inline
>void Remote::chanup(TV&t){ t.chanup();}
>
>inline
>void Remote::chandown(TV &t){ t.chandown();}
>
>inline
>void Remote::set_channel(TV &t,int c){t.channel=c;} //设置Tv的私有成员
>
>inline
>void Remote::set_input(TV &t){t.set_input();}
>
>inline
>void Remote::display(){
>	cout <<"Remote Mode: " << (mode==tv ?"tv":"DVD") << endl;
>		}
>
>#endif
>```
>
>
>
>

### 类互为友元

>**两个类 可以互相访问其私有成员 或者 保护成员**
>
>```c++
>class C2;//先声明C2 让C1类知道有这么一个C2类
>
>class C1{
>	friend class C2
>public:
>		void func1(C2 &c2);  //要访问C2类中的私有成员 由于不知道C2中有啥私有成员，需要把
>												//需要把该方法的具体实现写在C2之后
>}
>class C1{
>	friend class C2
>public:
>		void func2(C1&c1){...};
>}
>
>void C1::func1(C2 &c2){
>....//具体实现
>}
>```
>
>

### 共同的友元函数 

>
>
>**一个函数想访问两个类的私有成员**
>
>
>
>```c++
>#include <iostream>
>using namespace std;
>
>
>// int sync(T1 &t1,T2 &t2)为两个类共同的友元函数，
>//该函数可以访问 两个类中的私有变量
>//防止特征标位置不对，最好在重载一下
>
>class T2; //提前前置声明 防止T1不认识
>
>class T1{
>private:
>	int val;
>public:
>	T1(int n=0):val(n){}
>	friend int sync(T1 &t1,T2 &t2); //没见过T2 类，需要前置声明
>	friend int sync(T2& t2,T1&t1);		//需要重载 两个类 谁在前 谁在后
>};
>
>class T2{
>private:
>	int value;
>public:
>	T2(int n):value(n){}
>	friend int sync( T1 &t1,T2 &t2);
>	friend int sync(T2& t2, T1&t1);
>
>};
>
>inline int sync( T1 &t1,T2 &t2){
>	return t1.val +t2.value;
>}
>
>inline int sync(T2& t2, T1&t1){
>	return sync(t1,t2);
>}
>
>
>int main(){
>	T1 t1(20);
>	T2 t2(30);
>	int val=sync(t1,t2);
>	int val2=sync(t2,t1);//用到重载的原因，两个类的参数特征标不一样
>	cout << val << endl;
>	cout << val2 << endl;
>	return 0;
>}
>```
>
>

### 嵌套类

>**类里面定义类**
>
>
>
>```c++
>//实现队列 模版
>#include <iostream>
>#include <string>
>using namespace  std;
>
>template<class T>
>class Queue{
>private:
>   int Qmax;
>   int Qtop;
>   class Node{
>   public:
>       T value;
>       Node* next;
>       explicit Node(const T&t):value(std::move(t)),next(nullptr){};
>       //void set_next(){}
>   };
>
>   Node * prevP;
>   Node * nextP;
>public:
>   explicit Queue(const int n):Qmax(n),Qtop(0),prevP(nullptr),nextP(nullptr){}
>   ~Queue();
>   bool isfull()const;
>   bool isempty()const;
>   int curSize();
>   bool enqueue(const T&t);
>   bool dequeue(T&t);
>   void display();
>};
>
>template<class T>
>Queue<T>::~Queue(){
>Node *temp;
>while(prevP!= nullptr)
>{
>   temp=prevP;
>   prevP=prevP->next;
>   cout<< (temp->value) << " be delete" << endl;
>   delete temp;
>}
>}
>
>template<class T>
>bool Queue<T>::isfull()const{
>return Qtop==Qmax;
>}
>
>
>template<class T>
>bool Queue<T>::isempty()const{
>return Qtop==0;
>}
>
>template<class T>
>int Queue<T>::curSize() {
>return Qtop;
>}
>
>template<class T>
>bool Queue<T>::enqueue(const T &t) {
>if(!isfull()){
>   Node *Nptr=new Node(t);
>   if(curSize()==0){
>       prevP=nextP=Nptr;
>   }else{
>       nextP->next=Nptr;
>       nextP=Nptr;
>
>   }
>   Qtop++;
>   return true;
>}else{
>   cout <<"当前队伍已经满了" << endl;
>   return false;
>}
>}
>
>template<class T>
>bool Queue<T>::dequeue(T &t) {
>if(!isempty()){
>   Node* temp=prevP;
>   prevP= prevP->next;
>   t=temp->value;
>   delete temp;
>   Qtop--;
>   return true;
>}else{
>   cout <<"当前队伍为空" << endl;
>   return false;
>}
>}
>
>template<class T>
>void Queue<T>::display() {
>Node * temp=prevP;
>int t=0;
>cout <<"当前排队顺序:";
>while(temp != nullptr){
>   cout << ++t <<": "<<temp->value << " ";
>   temp=temp->next;
>}
>cout << endl;
>}
>
>int main(){
>string temp;
>string Nothing("nothing2");
>Queue<string> qs(3);
>while(!qs.isfull()){
>   cout << "please enter the client name:";
>   getline(cin,temp);
>   qs.enqueue(temp);
>   cout <<"当前 队列有 " << qs.curSize() << "个人" << endl;
>
>}
>qs.display();
>qs.enqueue(Nothing);
>
>while(!qs.isempty()){
>   qs.dequeue(temp);
>   cout << "当前轮到:" << temp << " , 队伍数量" <<qs.curSize() <<  endl;
>}
>qs.dequeue(Nothing);
>qs.enqueue(Nothing);
>cout <<"Done" <<endl;
>return 0;
>
>}
>```
>
>

### 异常

>`abort() 函数` 头文件cstdlib 中 **直接中断程序**
>
>`throw arg` 引发异常  arg 可以是字符串 数字 或者类对象
>
>`catch` 捕获异常
>
>异常的三种组成部分
>
>```c++
>·抛出异常 		throw 
>·catch 抓住异常 catch(数据类型){怎么处理}
>·使用try 
>try{ ... }
>```
>
>
>
>**异常为字符串 或者数字** 
>
>```c++
>//程序在函数里面 自定义throw 抛出异常了，
>//函数不会继续执行，会跳出函数题，并且携带
>//异常类型到主程序,主程序 catch(const char *s){自定义的函数体} 继续执行
>
>
>int hmean(int a,int b){
>if(a==b)
>throw "a等于b"; //抛出异常
>else if(a < b)
>throm "a 小于b";
>return a-b;
>}
>
>int main(){
>try{
>hmean(4,5);
>}
>catch(const char* a){   //抛出的是int。要用参数 const int a
>cout << a << endl;//打印异常
>}
>}
>```
>
>**异常为类**
>
>```c++
>#include<iostream>
>#include<cstdlib>
>#include "exe_mean.h"
>#include <cmath>
>using namespace std;
>
>
>double hmean(double t1,double t2);
>double gmean(double a,double b);
>
>int main(){
>	double x,y,z;
>
>	cout <<"Enter two number:";
>	while((cin >> x >>y)){
>
>		try{ 
>			z=hmean(x,y); 
>			cout <<  x << " and " << y << " Harmonic mean is " << z << " \n";
>			z=gmean(x,y);
>			cout <<  x << " and " << y << " g mean  result  is " << z << " \n";
>		}
>
>		//第一个异常
>		catch(Bad_heam &b){  		//类要用引用，实际上是异常的拷贝，之前的异常已经不在了（试过了不用引用也可以的）
> 											//因为基类的引用可以指向派生类的对象
>			b.msg();  					//调用类方法
>
>			cout <<"Enter two number again :";
>			continue;
>		}
>
>		//第二个异常
>		catch(Bad_gmean & g){ // g是异常的拷贝，不是异常本身,记住啦
>			cout <<g.msg() << endl;  //调用类的方法 返回字符串
>			cout <<"Enter two number again :";
>			continue;
>
>		}
>
>		cout <<"Enter two number:";
>	}
>
>	return 0;
>} 
>
>double hmean(double t1,double t2){
>	if(t1==-t2)
>		throw Bad_heam(t1,t2);  //抛出错误 错误类型是  类的对象
>
>	return (2.0*t1*t2) / (t1+t2);
>}
>
>double gmean(double a,double b){
>	if(a <0 || b< 0){
>		throw Bad_gmean(a,b);
>	}
>	return sqrt(a*b);
>}
>```
>
>
>
>```c++
>//定义的两个 定义异常的类
>
>#ifndef __EXE__MEAN_H__
>#define __EXE__MEAN_H__
>#include <iostream>
>using namespace std;
>
>
>class Bad_heam{
>private:
>	double v1;
>	double v2;
>public:
>	Bad_heam(double a=0.0,double b=0.0):v1(a),v2(b){}
>	void msg();
>	friend ostream & operator<<(ostream& os,const Bad_heam& bh);
>
>
>};
>
>inline
>void Bad_heam::msg(){
>	cout << "ERROR:: hmen( " <<v1 <<"," <<v2 <<"):invalid arguments:a = -b\n"; 
>}
>
>class Bad_gmean{
>	private:
>	double v1;
>	double v2;
>	public:
>	Bad_gmean(double a=0.0,double b=0.0):v1(a),v2(b){}
>	const char *msg();
>
>};
>
>inline
>const char *Bad_gmean::msg(){
>	return "gmean() arguments should be  >= 0";
>
>}
>
>ostream & operator<<(ostream& os,const Bad_heam& bh){
>	os <<  "ERROR:: hmen( " <<bh.v1 <<"," <<bh.v2 <<"):invalid arguments:a = -b [-> in function opetator << ostream]\n"; 
>	return os;
>}
>
>#endif
>```
>
>

### 异常规范 和c++

>			 	
>
>			 	```c++
>			 	double harm(double a) throw(Bad_thing);   //可能抛出异常类 Bad_thing
>			 	double marm(double )throw();							//不会抛出异常
>			 	double marm() noexcept; 									// marm() 不会抛出异常
>			 	```
>
>			 	

### 栈解退

>函数异常
>
>```c++
>/*
>main() 里面调用了 A函数,A函数调用了B函数，B函数里面调用了C函数
>如果C函数里面抛出异常了 throw 异常
>C函数后面的代码不会执行
>会回到B函数里面找 try catch 语句，如果B函数里面没有,会把B函数出栈 下面的代码不执行
>会继续回A函数里面找 try catch 语句，如果A函数里面没有,会把A函数出栈 下面的代码不执行
> 会回到mian 里面找 再没有的话就会终止程序了
> */
>
>int main(){
>Afunc(){
>bfunc(){
> cfunc(){
>   throw "异常"
> }
>   }
> }
>}
>```
>
>

### 异常类的顺序

>
>
>```c++
>class Base1{...}
>class Base2:public Base1{...}
>class Base3:public Base2{...}
>
>void myfunc(){
>if(...)
>throw Base1; //抛出基类
>else if(...)
>throw base2; //抛出派生类
>else if(...)
>throw base3; //抛出派生类的类
>}
>
>int main(){ 
>try{
>myfunc();
>}
>catch(base3 &b3){....} //要把派生类的派生类放最上面，因为是引用
>catch(base2 &b2){....}	//基类的引用 可以指向任何他的派生类，
>catch(base1 &b1){....}	//所有派生异常会被基类截断
>
>
>}
>```
>
>

### exception 类

>
>
>```c++
>//exception 类的定义
>class exception
>{
>public:
>exception() noexcept;
>exception(const exception&) noexcept;
>exception& operator=(const exception&) noexcept;
>virtual ~exception() noexcept;
>virtual const char* what() const noexcept;
>};
>```
>
>**继承exception 类**
>
>也可以继承logic_error类，自带 string 类的私有成员 what() 函数返回这个的成员 
>
>```c++
>#include <stdexcept>  //logic_error 所属头文件
>class Myerror:public logic_error{
>provate:
>Myerror(const string & t="默认参数"):logic_error(t){}
>//不需要重新写 what方法 基类自带
>}
>
>
>```
>
>
>
>```c++
>#include <iostream>
>#include <exception>
>#include <cstring>
>#include <stdexcept>
>using namespace std;
>
>class Myerror:public exception{  //继承基类
>private:
>char * msg;	//添加私有成员
>public:
>explicit Myerror(const char * s="None"):exception(){ //构造函数需要先构造基类
>msg=new char[strlen(s)+1];
>strcpy(msg,s);
>msg[strlen(s)]='\0';
>}
>
>~Myerror()noexcept override{
>delete []msg;
>}
>
>//类方法不用写virtual
>//出错，有时候你以重写了，却没有重新载入 用clion 看一下，左边有箭头
>const char* what() const noexcept override{
>
>return msg;
>
>}
>
>
>
>};
>
>class OtherError:public exception{
>public:
>OtherError():exception(){}
>const char* what() const noexcept override{
>
>return "出错啦｜我是第二个派生类啊";
>
>}
>
>};
>
>void func(const int& n);
>
>int main(){
>// func(1);
>
>try{
>func(10);
>
>}
>
>catch(exception &e){  //用一个基本类的引用,可以同时指向两种exception派生出来的类
>											//两种派生类的异常 都可以捕获
>
>cout << e.what() << endl;
>}
>
>try{
>func(1);
>}
>
>catch(exception &e){
>cout << e.what() << endl;
>}
>return 0;
>}
>
>
>void func(const int& n){  //一个函数抛出两种类型错误
>if(n == 1)
>throw Myerror("something wrong"); 
>if( !(n %2) )
>throw OtherError();
>cout << "n+1 value: "<< n+1 << endl;
>
>}
>
>```
>
>

### new开辟内存空间抛异常

> 
>
> ```c++
> int *p=new(std::nothrow) int;// 不抛异常，返回空指针
> int *p=new(std::nowthrow) int[300]; //抛出异常  mac 没这玩意儿
> ```
>
> 
>
> ```c++
> #include <iostream>
> #include <stdexcept>
> 
> using namespace  std;
> struct Big{
> double stuff[2000000];
> };
> int main(){
>     Big *pb;
> try{
>     cout <<"用一个指针变量，开辟1W个 Bigstr 结构体,该结构体有20W个double类型" << endl;
> 
>     pb=new Big[10000000]; //不能开辟这么多，会抛出异常
>     cout <<"开辟成功 " << endl;
> }
> 
> catch(std::bad_alloc & bb){
>     cout <<" 抓住new 分配内存的错误啦" << endl;
>     cout << bb.what() << endl;
>     exit(-1);
> }
> 
> cout << "Memory new ok" <<endl;
> pb[0].stuff[0]=3.3;
> cout << pb[0].stuff[0] << endl;
> 
> delete []pb;
> 
> return 0;
> 
> }
> 
> ```

### 关键字 noexcept TODO::

>**指定函数不抛出异常,放在函数后面,函数定义和函数体都要写**
>
>**如果定义函数模版，或者显示具体话 每个函数定义和函数声明也都要加上noexcept要不然不属于同一个函数**
>
>```c++
>```
>
>
>
>‼️ 需要用c++11 编译
>
>`g++ -std=c++11 file_name.cpp`
>
>```c++
>#include <iostream>
>
>using namespace std;
>template<class T>
>void show(const T &t)noexcept;
>void show(const char * t)noexcept;
>void display(const char *t)noexcept; //函数声明和 定义都要加上关键字 noexcept
>template<>void show<string>(const string& t)noexcept; //显示具体化也加上 
>
>
>int main(){
>	show(8); //使用模版
>	show("hello,kitty"); //使用非模版
>	display("hello,kitty");
>	return 0;
>}
>
>template<>void show<string>(const string& t)noexcept{ //每个定义都的加上关键字noexcept
>	cout <<"[ in special func of string ]" << t << endl;
>}
>
>
>void display(const char *t)noexcept{ //每个定义都的加上关键字noexcept
>	cout <<"in func display:" << t <<endl;
>}
>
>void show(const char * t)noexcept{ //每个定义都的加上关键字noexcept
>	std::cout <<"in func show:"<< t << std::endl;
>}
>
>template<class T>
>void show(const T &t)noexcept{//每个定义都的加上关键字noexcept
>	std::cout <<"in func show(template):"<< t << std::endl;
>};
>```
>
>

### 异常,类和继承

>
>
>有一些类把异常类定义在类里面
>
>然后派生出另外一个类，
>
>```c++
>class Base{
>private:
>		int a; //私有变量
>public:
>	class Error1:public exception{
> int ina;
> public:
> 	Error1(int ineer_a,const char* st="我在Base中出错了,我是默认参数"):inner_a(a),exception(st){...}{}; 
> 					//用Base变量,添加为异常类的私有变量
> 	int get_ina(){return ina;} 
> 	//也可以重新写show()函数 ,exception 构造函数 有一个const char * 字符串,show函数可以返回 它
>   const char* what()const _NOEXCEPT{ //重写基类
>         cout << "index:" << ina << "Error\n"";
>         return exception::what();
>				}
>
>}
>}
>
>class derive:public Base{		//派生类
>privare:
>	string b; //派生类的私有变量
>public:
>class Error2:public Base::Error1{ //记得加上作用域 派生类里面的 从基类的异常类中派生出另外一个异常类
> public:
> 	string inner_b;
> private:
>     Error(const string&ib,int aa,const char*st="添加默认构造参数"):inner_b(ib),Base::error1(aa,st){} 
> 		//重写基类方法
> 		const char* what()const _NOEXCEPT{ //重写基类
>         cout << "index:" << ina << "Error\n"";
>         return Base::Error1::what();
>				}
>
>}
>}
>
>```
>
>书中代码说明
>
>```c++
>#include <iostream>
>#include "sales.h"
>
>
>using namespace std;
>
>
>
>
>
>
>
>
>
>
>int main(){
>
>	double vals1[12];
>	double vals2[12];
>
>	for(int i=0;i<12;i++){
>		vals1[i]=i*10 +1 +2000;
>		vals2[i]=i*10 +1 +2320; 
>	}
>
>	Sales sale1(2013,vals1,12);
>
>	LabelSale sale2("Big watermalen ",2022,vals2,12);
>
>	try{
>
>		// show sale 1
>		cout <<"Year:" << sale1.Year() << "\n";
>		for(int i=0;i<12;i++){  // 12超出范围,会抛异常
>			cout << sale1[i] << " ";
>			if(i % 6 ==5)
>				cout << endl;
>		}
>
>		// show sale 2
>		cout <<"Year:" << sale2.Year() << " "<<sale2.Label() <<"\n";
>
>
>		for(int i=0;i<12;i++){  //15超出范围,会抛异常
>			cout << sale2[i] << " ";
>			if(i % 6 ==5)
>				cout << endl;
>		}
>
>
>
>	}
>
>										//异常类的排列 应该这样排列
>										// 派生类的派生类 ->> 派生类 ->> 基类;
>	catch(LabelSale::nBad_index & bad){	//类里面的异常,要加上作用域
>		cout << "ERROR Bad info  :"<<bad.what() << endl;
>		cout << "ERROR Bad value :"<<bad.LableValue() << endl;
>		cout << "ERROR Bad index :" <<bad.BiValue() << endl;
>	}
>
>
>	catch(Sales::Bad_index & bad){ //类里面的异常 要加上作用域
>		cout << "ERROR Bad info  :"<<bad.what() << endl;
>		cout << "ERROR Bad index :" <<bad.BiValue() << endl;
>		cout << bad.what() << endl;
>
>	}
>
>
>
>	catch(logic_error & bad){
>
>		cout <<bad.what() << endl;
>	}
>
>
>	try{
>		sale2[2]=40;
>		sale1[15]=60; //try 会让下面的 catch 捕获
>	}
>
>
>	catch(exception & bad){  //会截获所有异常,所有异常excption 派生出来的
>		cout << "in exception " << endl;
>		cout << bad.what() << endl;
>	}
>
>
>
>	catch(LabelSale::nBad_index & bad){	//类里面的异常,要加上作用域
>		cout << "ERROR Bad info  :"<<bad.what() << endl;
>		cout << "ERROR Bad value :"<<bad.LableValue() << endl;
>		cout << "ERROR Bad index :" <<bad.BiValue() << endl;
>	}
>
>	catch(Sales::Bad_index & bad){ //类里面的异常 要加上作用域
>		cout << "ERROR Bad info  :"<<bad.what() << endl;
>		cout << "ERROR Bad index :" <<bad.BiValue() << endl;
>		cout << bad.what() << endl;
>
>	}
>
>
>	cout <<"Bye" << endl;
>
>
>	return 0;
>}
>```
>
>
>
>```c++
>#ifndef __SALES_H__
>#define __SALES_H__
>
>#include <iostream>
>#include <stdexcept>
>#include <string>
>#include <cstring>
>
>using namespace std;
>
>
>class Sales{
>public:
>	enum {MONTH=12};
>	explicit Sales(int yy=0):year(yy){
>		for(int i=0;i<MONTH;i++){
>			gross[i]=0.0;
>		}
>	}
>
>	Sales(int yy,const double *gr,int n);
>
>	virtual ~Sales(){}
>	int Year(){return year;}
>	virtual double operator[](int i)const;//{return gross[i];}
>	virtual double& operator[](int i); //可以修改数组里面的值
>
>	class Bad_index:public logic_error
>	{
>	private:
>		int bi;//索引编号
>	public:
>		explicit Bad_index(int i,const string& t="Index error in Sales Error"):bi(i),logic_error(t){}
>		~Bad_index()_NOEXCEPT{}  // 或者 把_NOEXCEPT 修改成throw() 不会抛出任何异常
>									//throw(int) 代表会抛出一个int 类型的异常
>									//throw(int,char) 会抛出
>									//throw(...) 会抛出任何异常
>
>		int BiValue()const{return bi;}
>
>		const char* what()const _NOEXCEPT{ //重写基类
>			cout << Number() << " <<<<< ";
>			return logic_error::what();
>		}
>
>
>	};
>
>
>private:
>
>	double gross[MONTH];
>	int year;
>};
>
>
>
>
>class LabelSale:public Sales{
>private:
>	string label; //标签
>public:
>	explicit LabelSale(const string& lb="None",int y=0):Sales(y),label(lb){}
>	LabelSale(const string& lb,int yy,const double *gr,int n):label(lb),Sales(yy,gr,n){}
>	~LabelSale(){}
>
>	const string& Label()const{return label;}
>
>	virtual double operator[](int i)const;
>	virtual double& operator[](int i);
>	class nBad_index:public Sales::Bad_index{  //继承是Sales 里面的共有类 记得加上作用域
>	private:
>		string lbl;
>	public:
>		nBad_index(const string&lb,int ix,
>			const string &s="Index error in Labelsale object")
>			:lbl(lb),Sales::Bad_index(ix,s){} //类里面的类 也加上类的作用域
>		~nBad_index()_NOEXCEPT{}
>		const string& LableValue()const{return lbl;}
>
>
>	};
>
>
>
>
>};
>
>
>Sales::Sales(int yy,const double *gr,int n):year(yy){
>
>	int nn=n<MONTH?n:MONTH;
>
>	int i;
>
>	for(i=0;i < nn;i++)
>		gross[i]=gr[i];
>
>
>	for(;i<MONTH;i++)
>		gross[i]=0.0;
>
>
>}
>
>double Sales::operator[](int i)const{
>	if(i >= MONTH || i < 0 )
>		throw(Bad_index(i));
>	return gross[i];
>}
>
>double& Sales::operator[](int i){
>	if(i >= MONTH || i < 0 )
>		throw(Bad_index(i));
>	return gross[i];
>}
>
>
>double LabelSale::operator[](int i)const{
>	if(i >= MONTH || i < 0 )
>		throw(nBad_index(Label(),i));
>	return Sales::operator[](i);
>}
>
>
>
>double& LabelSale::operator[](int i){
>	if(i >= MONTH || i < 0 )
>		throw(nBad_index(Label(),i));
>	return Sales::operator[](i);
>}
>
>
>#endif
>
>
>```
>
>

###  RTTI

> 
>
> **运行阶段类型识别（runtime Type identification）**
>
> **派生类的指针 不可以指向基类 -》派生类里面的成员和基类的成员不一样** 反之OK
>
> **派生类指针  基类不存在的函数， 报错**
>
> 
>
> **dynamic_cast**  指针转换
>
> ```c++
> base *pt;//基类指针
> deriva *pt2=dynamic_cast<deriva *>(pt);		//基类指针转类型 转为派生类指针，并且赋值给一个派生类指针
> 																					//如果转换不成功 返回NULL 或者 0 
> //转换函数会检查 pt的数据类型 和 要转换的数据类型,如果  如果(pt)的类型 是 <deriva *> 派生出来的 就赋值给左边的变量 或者指针
> //否则就返回0 复制给左边
> 
> if(pt)
> do something;
> else
> cout << "convet failed |转换失败" << endl;
> 
> ```
>
> 
>
> typeid 
>
> ```c++
> typeid 接收两种类的参数;
> 类名;
> 结果为对象的表达式;
> typeid 的返回 一个对type_info对象的引用 ， type_info在头文件 <typeinfo> 中 以前在 <typeinfo.h>;
> 
> 
> class A_class{...};										//基类
> class B_class:public A_class{...};		//第一代派生类
> class C_class:public B_class{...};		//第二代派生类
> 
> A_class Aobj;    //实例话一个对象
> 
> A_class* PAobj;   //声明一个A_class 的指针；
> 
> typeid(Aobj) typeid(A_Class) ; // 这两个都返回一个typeinfo的对象
> 
> typeid(Aobj);
> typeid(A_class);
> typeid(*PAobj);   // 这三个表达式 都会返回一个typeinfo的应用 三个都相等
> 									// typeid(Aobj).name(); 可以看到对象所在的类名， 是个字符串 可以打印出来 不过前面前面有个随机数字
> 
> typeid(PAobj) ！= typeid(*PAobj); //注意 前面是个指针 不能返回同一个typeinfo 对象	
> 													//typeid(PAobj).name()值为 P开头+随机数字+类名称的字符串 default ="p" + typeid(*PAobg).name()
> 
> -----;
> C_class Cobj;						//实例话一个 C_class 
> A_class * pa =&Cobj;			//声明一个 基类指针 并且用它指向 C_class的 对象
> 
> if(typeid(*pa) == typeid(C_class))    //可以用typeid 判断 pa是不是指向 C_class的对象
> {
> C_class * temp=(C_class *)pa;					 //用类型转换 把基类的指针转换成 一个临时派生类的指针 并且赋值给 temp变量
> temp->func();														//temp 指针 执行 C_class定义的方法  或者函数
> }
> 
> 
> 
> 
> 
> 
> 
> ```
>
> 
>
> 
>
> Code 
>
> ```c++
> //
> // Created by macbookpro on 2023/1/17.
> //
> 
> 
> #include <iostream>
> #include <cstdlib>
> #include <ctime>
> 
> using namespace  std;
> 
> class Grad{
> private:
> int hold;
> public:
> explicit Grad(int h=0):hold(h){};
> virtual void Speak()const{cout <<"[1].I am a grand class \n";}
> int Value()const {return hold;}
> };
> 
> class SuperB:public Grad{  //第二代派生类
> public:
> explicit SuperB(int h=0):Grad(h){}
> void Speak()const {cout <<"[2].I am a SuperB class"<< endl;}
> virtual void Say()const {cout <<"in SuperB value is" << Value() << endl;}
> };
> 
> class Magnificent:public SuperB{  //第三代派生类
> private:
> char ch;
> public:
> explicit Magnificent(int h=0,char c='A'): SuperB(h),ch(c){}
> void Speak()const {cout <<"[3].I am a Magnificent class"<< endl;}
> void Say()const{cout<< "I hold a character value:" << ch << " and I hold a int value"<< Value() <<" \n"; }
> 
> };
> 
> Grad *Get_one(){ //
> 
> Grad *p= nullptr;
> 
> switch (rand() %3) {
>     case 0:{
>         p= new Grad(rand() % 100);
>         break;
>     }case 1:{
>         p=new SuperB(rand() % 100);
>         break;
>     }case 2:{
>         p=new Magnificent(rand() % 100,'B');
>         break;
>     }
> }
> return p;
> }
> 
> 
> int main(){
> srand(time(nullptr));//随机数种子放在 main 函数里面
> 
> Grad *pg= nullptr;
> SuperB *sp= nullptr;
> for(int i=0;i<5;i++){
>     cout <<"----------------" << endl;
>     pg= Get_one();
>     pg->Speak();
> 
>     if((sp =dynamic_cast<SuperB *>(pg) )&& (sp !=NULL))
>         sp->Say();
>     else
>         cout << "Error pointer[][][][][][][][]" << endl;
> 
> }
> 
> return  0;
> }
> ```
>
> 

### 类型转换运算符

>**dynamic_cast** 和 **static_cast**  区别
>
>dynamic_cast 只允许类的层次结构向上转换
>
>static_cast 允许枚举类型和整数之间 或者基本类型相互转换
>
>
>
>```c++
>dynamic_cast;
>const_cast;
>static_cast;
>reinterpret_cast;
>
>
>```
>
>
>
>**dynamic_cast**  在类的层次中向上转换 ->派生类转换成基本类
>
>```c++
>在类的层次中向上转换  -》 只能派生类转换成基类
>	deriva *pt2=new Deriva(argument);
>base *pt=dynamic_cast<base*> (pt2);
>
>
>```
>
>
>
>**const_cast** 把const类型转换成非const
>
>```c++
>//只能转换成同一种类型
>
>int a=6;
>const int *pa=&a;		//不能通过 *pa修改值
>int *pb=const_cast<int *> (pa);  //把const int* 转换成int*
>*pb=7;//now a=7					//可以通过*pb修改值了
>```
>
>
>
>**static_cast**   有继承关系的类才可以互相转换 or 基本类型互相转换
>
>```c++
>
>double x = static_cast<double> (10) / 3;  // result :3.3333
>double y= 10 / 3;                             // result :3
>//在类的层次中，static_cast 向上向下转换都可以的
>
>class  T1{};
>class T2 :public T1{};
>class T3{};
>
>T1 t1;
>T2 t2;
>T1 *pa=static_cast<T1*> (&t2);  //T1 指针指向 t2   派生类的指针 转换成 基类指针
>T2 *pb=static_cast<T2*> (&t1);  //T2 指针 指向 t1   基类的指针 转换成 派生类的指针
>
>T3 *pc=static_cast<T3*>(&t1);  //invalid 非继承关系
>```
>
>**reinterpert_cast**
>
>```c++
>//用于天生的危险类型转换，但不允许删除const
>//按照指针拷贝值
>
>struct dat{ unsigned short a; unsigned short b;};
>int value=0xffffff7f;   // ff7f 是a ,ffff是b
>dat *pd=reinterpret_cast<dat*>(&value);
>cout <<pd ->a << endl;
>cout <<pd ->b << endl;
>
>struct dat{
>   unsigned int a1:2;
>   unsigned int a2:2;
>   unsigned int a3:2;
>   unsigned int a4:2;
>   unsigned int a5:2;
>   unsigned int a6:2;
>   unsigned int a7:2;
>   unsigned int a8:2;
>   unsigned int a9:2;
>   unsigned int a10:2;
>   unsigned int a11:2;
>   unsigned int a12:2;
>   unsigned int a13:2;
>   unsigned int a14:2;
>   unsigned int a15:2;
>   unsigned int a16:2;
>};
>int value=0x7fffffff;  //第一个 二进制是 0111    a16=ob01 a15=0b11 a16=1 a15=3
>int *pt=&value;        
>dat* pdat=reinterpret_cast<dat*>(pt);
>cout << pdat->a16 << endl;
>cout << pdat->a15 << endl;
>
>```
>
>



## chapter16:string 类和标准模版库

### string 类

>String 有很多构造函数
>
>```c++
>	1) string(const char *) 使用这个构造函数
>	string one("Lottery winner");
>
>	2) string(size_t n,char n)
>	string two(20,'A');
>
>	3) string(const string& s)   拷贝构造函数
>	string three(one);
>
>	4) string()   空字符串
>	string four;
>
>
>	5) string(char *start,size_t n)  拷贝 start 前 n 个字符
>	char alls[]="!@#$%^&QWERTY";
>	string fine(alls,20); //不严谨  打印结果 i am eendC+ 
>
>
>	6) template<class Iter>  string(iter begin,iter end);  模版范围不包括 end  包括 
>	string six(alls+1,alls+6);
>
>	7 ）拷贝构造函数 string ,start_position, size  
>	//string(const string &str,string size_type   
>	//				 pos=0 , size_type n =npos);
>
>	string eight(four,3,4);
>
>
>	8) string(const && str) noexcept; //可以修改  c++ 11 
>
>
>	9) string(initializer_list<char>i);
>	string nine{'h','e','l','l','0'};  //c++11
>```
>
>查看分配的内存
>
>```c++
>
>	string st;
>	st.capacity();  //查看分配的内存 单位字节
>	st.reserve(100); // 重新分配100个字节 
>```
>
>
>
>

### 智能指针模版类

>**智能指针头文件<memory>**
>
>⚠️**只删除指针，不能删除数组，必须得有名字 智能指向new新开辟的内存区域**
>
>```c++
>template<class T>
>class auto_ptr{
>private:
>	T* _ptr;
>public:																		//throw() 不抛错
>	auto_ptr(T* arg=0)throw():_ptr(arg){}  // arg 参数默认为0 也可以 new T
>	~auto_prt(){delete _ptr;}			//自动释放内存   头文件不这样写，方便自动看
>}
>
>//怎么用？
>
>auto_prt<int> t1(new int);    //auto_prt<int> 是类名称
>
>
>```
>
>
>
>**auto-ptr ** c99 已经被弃用
>
>**unique_ptr,shared_ptr**
>
>模版类的对象 
>
>	-会有析构函数自动释放
>
>```c++
>void demo(){
>auto_ptr<double> ap(new double);
>*ap=25.5;				//运行到代码块最后  auto_ptr<double> 类 会自动调用析构函数 释放内存
>return ;
>}
>```
>
>**三种智能指针都应该避免这种情况**
>
>**智能指针一定要用new 开辟出来的空间**
>
>```c++
>string str("hello");
>unique_ptr<string> ptr(&str);  //报错  不允许释放内存空间了
>//析构函数 不允许释放str 所在的内存空间
>cout << *ptr << endl;
>
>⚠️ 也不允许 
>string *pt= nullptr;
>unique_ptr<string> ptr(pt); //初始化已经存在的指针
>```
>
>auto_ptr 为什么被弃用
>
>```c++
>auto_ptr<string> p2(string("hell"));
>auto_ptr<string> p;
>p=p2; //都指向 “hello”  试图删除 内存空间两次
>
>解决方法:
>			//应该使用深度复制 如果第一个不为NULL 再开辟一个内存空间 
>			//交出所有权
>			//share_tr 引用计数(reference counting ) 赋值的时候,计数器加1，过期的时候 计数器减1最后一个指针过去的时候，才调用delete
>			//计数器默认为0,拷贝复制的时候，计数器加1，析构函数应该这样写,
>			//if(cout !=0)
>						count--;
>				else
>delete T;
>```
>
>**三种智能指针的区别**
>
>```c++
>	//auto_prt的用法:当p2 指向p1所指向的内存空间 p1的所有全被剥夺,不能使用
>	//编译不回报错，运行的时候才报错
>	auto_ptr<string> p1(new string("hello1"));
>	autp_ptr<string> p2;
>	p2=p1;
>
>	//unique_ptr:计数器的初始值为0 每创建一个对象都会计数器+1
>	//复制运算符里面  if 计数器 >1 throw() 直接报错 
>	//编译直接报错，不会运行
>	unique_ptr<string> p1(new string("hello1"));
>	unique_ptr<string> p2;  
>	p2=p1;
>
>	//shared_ptr:计数器的初始值为0 每创建一个对象都会计数器+1
>	//析构函数里面 if 计数器==1 delete ；计数器 --
>	shared_ptr<string> p1(new string("hello1"));
>	shared_ptr<string> p2;
>	p2=p1;
>```
>
>```c++
>unique_ptr<string> demo(const char* s){
>unique_ptr<string> tmp(string(s));  //临时的右值，没有使用机会，编译器允许这样操作 离开作用域回被销毁
>return temp;			//返回的指针其实上只是一个 地址；对象已经被销毁 
>}		
>
>unique_ptr<string> p;			//编译不回报错
>p=demo("hello,kitty"); //定义的temp是个右值，并且离开函数定义的作用域已经被销毁
>
>unique_ptr<string> pu1(new string("hello"));
>unique_ptr<string> pu2;
>pu2=pu1; // ⚠️ NOT ALLOW pu1 是右值，但是不是临时的 
>
>unqie_ptr<string> pu3;
>pu3=unqie_ptr<string>(new string("hello,kitty"));//⚠️ ALLOW 调用构造函数
>													//创建临时对象 然后很快被赋值给pu3 然后临时对象回被销毁
>
>当unique_ptr 重写赋值给另外一个 unique_ptr 的时候，可以用std::move() 方法 
>
>using namespace std;
>unique_ptr<string> p1,p2;
>ps1=demo("helo,kieey");
>ps2=move(ps1);	//把ps1 给解除了 重写赋予她一个新的功能 
>ps1=demo("new argument");
>cout <<*ps1 <<*ps << endl;
>
>```
>
>

### 如何选择智能指针

>
>
>```c++
>auto_ptr; //尽量不用，编译不报错，运行才报错 离开作用域会被销毁.
>如果要用多个指针指向同一个对象 应该使用 shared_ptr;
>如果只用一个指针指向一个对象 应该用unique_ptr;
>
>```
>
>

### 标准模版库

>
>
>容器:
>
>```c++
>基本方法
>size（）
>swap（）
>begin（）容器的第一个元素的迭代器
>swap（）
>end（） 最后一个加1 
>	erase()  删除 两个参数 开始指针和最后指针
>insert() 插入数据 三个参数 容器的开始位置,插入容器的开始指针，插入容器的结束指针
>for_each(args);// container.begin() ,container.end(),function	
>random_shuffle(); random_shuffle(XX.begin(),xx.end());
>
>```
>
>迭代器：
>
>```c++ 
>广义的指针 
>可以重载operator*（） 
>递增 operator++()
>
>创建迭代器
>vector<double>::iterator pd; 
>		//or auto pd=pd.begin();
>		//迭代器只是一个指针，可以指向容器里面的第一个元素 pd.begin  
>		//也可以指向容器里面的最后一个元素
>		//
>```
>
>**For_each**函数
>
>```c++
>#include <algorithm>
>void ShowReview(const Review&r){
>	cout << r.rating <<"\t"<< r.title << endl;
>}
>
>Vector<Review> data; //
>
>for_each(data.begin(),data.end(),ShowReview);
>
>```
>
>**ramdon_shuffle**函数
>
>```c++
>#include <algorithm>
>//随机排列顺序
>
>int a[4]={1,2,3,4};
>randon_shuffle(&a[0],&a[4]); 
>
>//如果数据是容器；
>struct SS{...}
>
>vector<SS> Vs;
>
>random_shuffle(Vs.begin(),Vs.end());  //打乱容器中的顺序
>```
>
>**sort**函数
>
>```c++
>#include <algorithm>
>
>//基本数据类型
>
>int arr[]={3,4,5,6,7,4};   
>sort(&arr[0],&arr[5]);  //该数据类型已经支持 operator<(const int a1,const int a2)
>for_each(&arr[0],&arr[5],[](int a){cout << a << " ";});
>
>//如果数据类型不支持 bool operator<(const 该数据类型1，const 该数据类型2)
>//需要自定义 参数为两个数据类型，并且返回值为bool的 函数
>Struct SS{
>string name;
>int age;
>};
>
>bool MySortFunc(const SS s1,const SS s2){
>if(s1.name < s2.name)
>return true;
>else if(s1.name ==s2.name && s1.age < s2.age)
>return true;
>else
>return false;
>}
>
>vector<SS> Myss;
>...各种操作之后。
>
>//排序操作
>sort(Myss.begin(),Myss.end(),MySortFunc) //第三个参数为自定义的比较函数
>
>
>
>
>
>
>
>
>```
>

### 一元谓词二元谓词 仿函数

>接受一个参数的叫做一元谓词
>
>接受一个参数的叫做一元谓词
>
>```c++
>仿函数;
>class FackFunc{
>private:
>	int value;
>public:
>	FackFunc(int n):value(n){}
>	bool operator()(int others){
> return value > others;
>}
>}
>FackFunc My(5); 
>
>My(4) ; 			  // True;
>FackFunc(4)(5);//false;
>```
>
>
>
>
>
>

### 算法 algorithm

>
>
>```c++
>1	非修改时的  头文件 algorithm
>2	修改			头文件 algorithm
>3	排序			 头文件 algorithm
>4 通用数字运算		numeric
>```
>
>```c++
>#include <iostream>
>#include <algorithm>
>
>using namespace  std;
>
>int main(){
>string name;
>
>cout <<"Enter the letter group:quit to quit:" << endl;
>
>while(cin >> name && name !="quit"){
>   sort(name.begin(),name.end());      //先进行顺序排列
>   cout <<"Now the name:" << name << endl;
>
>   while(next_permutation(name.begin(),name.end())){ //返回只要还可以进行排序就一直返回true
>       cout <<  name  << " ";
>   }
>   cout << endl;
>   cout <<"Enter the letter group:quit to quit:" << endl;
>}
>return 0;
>}
>```
>
>### Algorithm 中的函数模板
>
>| 名称                                                         | 说明                                                         |
>| :----------------------------------------------------------- | :----------------------------------------------------------- |
>| [`adjacent_find`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#adjacent_find) | 搜索相等或满足指定条件的两个相邻元素。                       |
>| [`all_of`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#all_of) | 当给定范围中的每个元素均满足条件时返回 **`true`**。          |
>| [`any_of`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#any_of) | 当指定元素范围中至少有一个元素满足条件时返回 **`true`**。    |
>| [`binary_search`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#binary_search) | 测试已排序的范围中是否有等于指定值的元素，或在二元谓词指定的意义上与指定值等效的元素。 |
>| [`clamp`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#clamp) |                                                              |
>| [`copy`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#copy) | 将一个源范围中的元素值分配到目标范围，循环访问元素的源序列并将它们分配在一个向前方向的新位置。 |
>| [`copy_backward`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#copy_backward) | 将一个源范围中的元素值分配到目标范围，循环访问元素的源序列并将它们分配在一个向后方向的新位置。 |
>| [`copy_if`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#copy_if) | 复制给定范围中对于指定条件为 **`true`** 的所有元素。         |
>| [`copy_n`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#copy_n) | 复制指定数量的元素。                                         |
>| [`count`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#count) | 返回范围中其值与指定值匹配的元素的数量。                     |
>| [`count_if`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#count_if) | 返回范围中其值与指定条件匹配的元素的数量。                   |
>| [`equal`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#equal) | 逐个元素比较两个范围是否相等或是否在二元谓词指定的意义上等效。 |
>| [`equal_range`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#equal_range) | 在排序的范围中查找符合以下条件的位置对：第一个位置小于或等效于指定元素的位置，第二个位置大于此元素位置，等效意义或用于在序列中建立位置的排序可通过二元谓词指定。 |
>| [`fill`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#fill) | 将相同的新值分配给指定范围中的每个元素。                     |
>| [`fill_n`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#fill_n) | 将新值分配给以特定元素开始的范围中的指定数量的元素。         |
>| [`find`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#find) | 在范围中找到具有指定值的元素的第一个匹配项位置。             |
>| [`find_end`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#find_end) | 在范围中查找与指定序列相同的最后一个序列，或在二元谓词指定的意义上等效的最后一个序列。 |
>| [`find_first_of`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#find_first_of) | 在目标范围中搜索若干值中任意值的第一个匹配项，或搜索在二元谓词指定的意义上等效于指定元素集的若干元素中任意元素的第一个匹配项。 |
>| [`find_if`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#find_if) | 在范围中找到满足指定条件的元素的第一个匹配项位置。           |
>| [`find_if_not`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#find_if_not) | 返回指示的范围中不满足条件的第一个元素。                     |
>| [`for_each`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#for_each) | 将指定的函数对象按向前顺序应用于范围中的每个元素并返回此函数对象。 |
>| [`for_each_n`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#for_each_n) |                                                              |
>| [`generate`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#generate) | 将函数对象生成的值分配给范围中的每个元素。                   |
>| [`generate_n`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#generate_n) | 将函数对象生成的值分配给范围中指定数量的元素，并返回到超出最后一个分配值的下一位置。 |
>| [`includes`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#includes) | 测试一个排序的范围是否包含另一排序范围中的所有元素，其中元素之间的排序或等效条件可通过二元谓词指定。 |
>| [`inplace_merge`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#inplace_merge) | 将两个连续的排序范围中的元素合并为一个排序范围，其中排序条件可通过二元谓词指定。 |
>| [`is_heap`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#is_heap) | 如果指定范围中的元素形成堆，则返回 **`true`**。              |
>| [`is_heap_until`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#is_heap_until) | 如果指定范围形成直到最后一个元素的堆，则返回 **`true`**。    |
>| [`is_partitioned`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#is_partitioned) | 如果给定范围中对某个条件测试为 **`true`** 的所有元素在测试为 **`true`** 的所有元素之前，则返回 **`false`**。 |
>| [`is_permutation`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#is_permutation) | 确定给定范围的元素是否形成有效排列。                         |
>| [`is_sorted`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#is_sorted) | 如果指定范围中的元素按顺序排序，则返回 **`true`**。          |
>| [`is_sorted_until`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#is_sorted_until) | 如果指定范围中的元素按顺序排序，则返回 **`true`**。          |
>| [`iter_swap`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#iter_swap) | 交换由一对指定迭代器引用的两个值。                           |
>| [`lexicographical_compare`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#lexicographical_compare) | 逐个元素比较两个序列以确定其中的较小序列。                   |
>| [`lower_bound`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#lower_bound) | 在排序的范围中查找其值大于或等效于指定值的第一个元素的位置，其中排序条件可通过二元谓词指定。 |
>| [`make_heap`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#make_heap) | 将指定范围中的元素转换到第一个元素是最大元素的堆中，其中排序条件可通过二元谓词指定。 |
>| [`max`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#max) | 比较两个对象并返回较大对象，其中排序条件可通过二元谓词指定。 |
>| [`max_element`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#max_element) | 在指定范围中查找最大元素的第一个匹配项，其中排序条件可通过二元谓词指定。 |
>| [`merge`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#merge) | 将两个排序的源范围中的所有元素合并为一个排序的目标范围，其中排序条件可通过二元谓词指定。 |
>| [`min`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#min) | 比较两个对象并返回较小对象，其中排序条件可通过二元谓词指定。 |
>| [`min_element`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#min_element) | 在指定范围中查找最小元素的第一个匹配项，其中排序条件可通过二元谓词指定。 |
>| [`minmax`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#minmax) | 比较两个输入参数，并按最小到最大的顺序将它们作为参数对返回。 |
>| [`minmax_element`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#minmax_element) | 在一次调用中执行由 [`min_element`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#min_element) 和 [`max_element`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#max_element) 执行的操作。 |
>| [`mismatch`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#mismatch) | 逐个元素比较两个范围是否相等或是否在二元谓词指定的意义上等效，并找到出现不同的第一个位置。 |
>| [` move`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#alg_move) | 移动与指定范围关联的元素。                                   |
>| [`move_backward`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#move_backward) | 将一个迭代器的元素移动到另一迭代器。 移动从指定范围的最后一个元素开始，并在此范围的第一个元素结束。 |
>| [`next_permutation`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#next_permutation) | 重新排序范围中的元素，以便使用按字典顺序的下一个更大排列（如果有）替换原有排序，其中“下一个”的意义可通过二元谓词指定。 |
>| [`none_of`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#none_of) | 当给定范围中没有元素满足条件时返回 **`true`**。              |
>| [`nth_element`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#nth_element) | 对范围内的元素分区，正确找到范围中序列的第 *n* 个元素，以使序列中位于此元素之前的所有元素小于或等于此元素，位于此元素之后的所有元素大于或等于此元素。 |
>| [`partial_sort`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#partial_sort) | 将范围中指定数量的较小元素按非降序顺序排列，或根据二元谓词指定的排序条件排列。 |
>| [`partial_sort_copy`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#partial_sort_copy) | 将源范围中的元素复制到目标范围，其中源元素按降序或二元谓词指定的其他顺序排序。 |
>| [`partition`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#partition) | 将范围中的元素分为两个不相交的集，满足一元谓词的元素在不满足一元谓词的元素之前。 |
>| [`partition_copy`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#partition_copy) | 将条件为 **`true`** 的元素复制到一个目标，将条件为 **`false`** 的元素复制到另一目标。 元素必须来自于指定范围。 |
>| [`partition_point`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#partition_point) | 返回给定范围中不满足条件的第一个元素。 元素经过排序，满足条件的元素在不满足条件的元素之前。 |
>| [`pop_heap`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#pop_heap) | 移除从堆顶到范围中倒数第二个位置之间的最大元素，然后将剩余元素形成新堆。 |
>| [`prev_permutation`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#prev_permutation) | 重新排序范围中的元素，以便使用按字典顺序的下一个更大排列（如果有）替换原有排序，其中“下一个”的意义可通过二元谓词指定。 |
>| [`push_heap`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#push_heap) | 将范围末尾的元素添加到包括范围中前面元素的现有堆中。         |
>| [`random_shuffle`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#random_shuffle) | 将范围中 *N* 个元素的序列重新排序为随机 *N*! 种序列中的 可能排列之一。 |
>| [`remove`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#remove) | 从给定范围中消除指定值，而不影响剩余元素的顺序，并返回不包含指定值的新范围的末尾。 |
>| [`remove_copy`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#remove_copy) | 将源范围中的元素复制到目标范围（不复制具有指定值的元素），而不影响剩余元素的顺序，并返回新目标范围的末尾。 |
>| [`remove_copy_if`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#remove_copy_if) | 将源范围中的元素复制到目标范围（不复制满足谓词的元素），而不影响剩余元素的顺序，并返回新目标范围的末尾。 |
>| [`remove_if`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#remove_if) | 从给定范围中消除满足谓词的元素，而不影响剩余元素的顺序，并返回不包含指定值的新范围的末尾。 |
>| [`replace`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#replace) | 检查范围中的每个元素，并替换与指定值匹配的元素。             |
>| [`replace_copy`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#replace_copy) | 检查源范围中的每个元素，并替换与指定值匹配的元素，同时将结果复制到新的目标范围。 |
>| [`replace_copy_if`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#replace_copy_if) | 检查源范围中的每个元素，并替换满足指定谓词的元素，同时将结果复制到新的目标范围。 |
>| [`replace_if`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#replace_if) | 检查范围中的每个元素，并替换满足指定谓词的元素。             |
>| [`reverse`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#reverse) | 反转范围中元素的顺序。                                       |
>| [`reverse_copy`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#reverse_copy) | 反转源范围中元素的顺序，同时将这些元素复制到目标范围         |
>| [`rotate`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#rotate) | 交换两个相邻范围中的元素。                                   |
>| [`rotate_copy`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#rotate_copy) | 交换源范围中两个相邻范围内的元素，并将结果复制到目标范围。   |
>| [`sample`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#sample) |                                                              |
>| [`search`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#search) | 在目标范围中搜索其元素与给定序列中的元素相等或在二元谓词指定的意义上等效于给定序列中的元素的序列的第一个匹配项。 |
>| [`search_n`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#search_n) | 在范围中搜索具有特定值或按二元谓词的指定与此值相关的指定数量的元素。 |
>| [`set_difference`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#set_difference) | 将属于一个排序的源范围、但不属于另一排序的源范围的所有元素相并到一个排序的目标范围，其中排序条件可通过二元谓词指定。 |
>| [`set_intersection`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#set_intersection) | 将属于两个排序的源范围的所有元素相并为一个排序的目标范围，其中排序条件可通过二元谓词指定。 |
>| [`set_symmetric_difference`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#set_symmetric_difference) | 将属于一个而不是两个排序的源范围的所有元素相并为一个排序的目标范围，其中排序条件可通过二元谓词指定。 |
>| [`set_union`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#set_union) | 将至少属于两个排序的源范围之一的所有元素相并为一个排序的目标范围，其中排序条件可通过二元谓词指定。 |
>| [`sort`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#sort) | 将指定范围中的元素按非降序顺序排列，或根据二元谓词指定的排序条件排列。 |
>| [`shuffle`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#shuffle) | 使用随机数生成器重新排列给定范围中的元素。                   |
>| [`sort_heap`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#sort_heap) | 将堆转换为排序的范围。                                       |
>| [`stable_partition`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#stable_partition) | 将范围中的元素分为两个不相交的集，满足一元谓词的元素在不满足一元谓词的元素之前，并保留等效元素的相对顺序。 |
>| [`stable_sort`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#stable_sort) | 将指定范围中的元素按非降序顺序排列，或根据二元谓词指定的排序条件排列，并保留等效元素的相对顺序。 |
>| [`swap`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#swap) | 在两种类型的对象之间交换元素值，将第一个对象的内容分配给第二个对象，将第二个对象的内容分配给第一个对象。 |
>| [`swap_ranges`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#swap_ranges) | 将一个范围中的元素与另一大小相等的范围中的元素交换。         |
>| [`transform`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#transform) | 将指定的函数对象应用于源范围中的每个元素或两个源范围中的元素对，并将函数对象的返回值复制到目标范围。 |
>| [`unique`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#unique) | 移除指定范围中彼此相邻的重复元素。                           |
>| [`unique_copy`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#unique_copy) | 将源范围中的元素复制到目标范围，彼此相邻的重复元素除外。     |
>| [`upper_bound`](https://learn.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=msvc-170#upper_bound) | 在排序的范围中查找其值大于指定值的第一个元素的位置，其中排序条件可通过二元谓词指定。 |



### 	其他库

>
>
>数组模版 vector，valarray，array
>
>```
>vector：自动调整大小
>
>valarray :支持向量
>
>```
>
>slice 类
>
>```c++
>python 里面的slice ;
>
>#include <valarray>
>
>valarray<int> arr(10);
>
>arr[slice(0,3,3)]=10;
>
>arr value: [10 0 0 10 0 0 10 0 0 0]
>
>slice(开始索引,取出的值，取多少个值);
>slice 也属于一个类;
>```
>
>c++ 11 通用初始化语法:
>
>
>
>```c++
>std::vector<double>payment{45.77,34.66,34.55};
>
>vector<type> 包含一个构造函数 initializer_list<type> 
>
>{45.77,34.66,34.55} 作为 initializer_list<double> 
>
>vector(initializer_list<value_type> __il);
>
>
>
>```
>
>Initializer_list
>
>```c++
>//需要包含头文件 < initializer_list >
>#include<valarray>
>#include<initializer_list>
>#include <iostream>
>
>using namespace std;
>
>template<class T>
>T sum(initializer_list<T> li){
>	T value=0;
>	for(auto p=li.begin();p!=li.end();p++)
>		value +=*p;
>	return value;
>}
>
>template<class T>
>T average(initializer_list<T> li){
>	return sum<T>(li)/(li.end() -li.begin());
>	//显示调用 sum<T> 求和 除以 (迭代器尾减掉 迭代器头) 等于个数
>}
>
>
>int main(){
>	initializer_list<double> b{4,4,8.6,0};
>	cout << sum(b) << endl;
>	cout << average(b) << endl;
>
>	cout << average({3,4,5,6,8}) << endl;
>	//隐式转换成 initializer_list<int>
>
>	cout << average(initializer_list<double>{3.0,4,5,6,8}) << endl;
>	//不知道参数为甚么类型，需要显示  3.0 与 int 类型
>
>
>
>
>
>
>	return 0;
>}
>```
>
>



## chapter17:输入，输出和文件

### 重定向

>
>
>打印结果打印到一个文件里面
>
>```bash
>./a.out > temp.txt 
>```
>
>打印地址 可以 在变量前面加 void *
>
>其他方法
>
>```c++
>cout.put('I').put('t');//单个字符
>cout.write(str,length); //length是长度，会越界 
>```
>
>缓冲区
>
>```c++
>cout << "hello,good morning" << flush;
>//flush 清空缓冲区，发送到屏幕
>//endl 刷新缓冲区 并且换行
>flush(cout);
>
>//输入密码的时候，可以退格，是因为输入字符没有直接输入，而是留在缓冲区
>```
>
>Cout 格式化的显示
>
>```c++
>```
>
>调整字段宽度
>
>```c++
>int width();
>int width(int i);
>只影响第一个
>```
>
>cin
>
>```c++
>cin >> 
>  会忽略 空格 换行
>cin.get() 不跳过 空白字符 空格 换行 制表符;
>char ch;
>ch=cin.get()
>  
>cin.putback(ch);  ch放回缓冲区
>  
>cin.peek() 去读缓冲区的首个字符，只是读，没有取出来
>  
>  
>getline 会丢弃分割符号
>get不会
>```
>
>

<img src="/Users/macbookpro/Documents/%E6%88%AA%E5%B1%8F2023-02-02%2009.28.03.png" style="zoom:50%;" />

### 文件io

>输入输出，应该站在你自己的角度,你要输出要设备里
>
>`ofstream`  		`cout`  	 cout 到file
>
>要读取设备 
>
>`ifstream` 		`cin`			file 里面 cin 到屏幕
>
>```c++
>fstream 包含iostream
>  流状态检查
>  is_open()
>  clear(); 清空之间的缓冲 reset filestream;
>					先清空 再关闭
>  close(); 关闭文件
>
>  操作两个文件，要创建两个文件流;
>
>	ofstream fout; 		  //输出流
>	fout.open(filename);  //默认 "w"模式
>
>
>```
>
>#### 文件模式
>
>`以为默认的方式打开文件，会把文件的长度截为0`
>
>```c++
>默认的方式为 
>  ios_base::out | ios_base ::trunc ;
>
>ifstream fin;
>fin.open(filename,iso_base::in ) ;//in为默认参数
>
>
>ofstream fout;
>fout.open(filename,ios_base::out | ios_base ::trunc ; ) 
>
>
>ios ::
>		static const openmode app    = 0x01; //追加到文件尾巴   							python "a"
>    static const openmode ate    = 0x02;	//打开文件，并且移到文件尾
>    static const openmode binary = 0x04;	//二进制文件
>    static const openmode in     = 0x08;  //打开文件以便于读取
>    static const openmode out    = 0x10; //打开文件 以便写入
>    static const openmode trunc  = 0x20;	//如果文件存在，截断文件
>
>0000 0001; 	app 
>0000 0010;	ate
>0000 0100;	binary
>0000 1000;	in
>0001 0000;	out
>0010 0000;	trunc
>  
>  
>in "r"模式;
>out  "w"模式;
>out|trunc  				"w"模式;
>out|app						"a"模式;
>out |out 					"r+"模式;	//打开以读写,在文件允许的位置写入
>out |out |trunc 	"w+"模式;	//打开以读写，如果已经存在，则首先截短文件
>binary						
>
>
>;;;;
>```
>
>

### 二进制写入文件

>
>
>```c++
>int num=555;
>ofstream fout;
>fout.open("filename",ios_base::out|ios_base::app|ios_base::binary);
>//打开文件 out + 追加 + 二进制模式
>
>fout.write((char *)&num, sizeof(num));
>//从哪里开始写，写多大
>//二进制写入 不能用 <<  得用 write 函数
>
>
>struct pl{
>	char name[20];
>	int age;
>	double feet; 
>};
>
>pl min;
>strcpy(min.name,"minliang");
>min.age=23;
>min.feet=34.5;
>
>
>//文本写入
>fout.open("filename",ios_base::out|ios_base::app);
>fout << min.name << " " << min.age << " " << min.feet << " " <<'\n'; //文本形式
>
>//二进制写入
>fout.open("filename",ios_base::out|ios_base::app|ios_base::binary);
>fout.write((char *)&min,sizeof(pl));		//二进制形式
>//需要类型转换，转换成 字节形式的指针
>fout.close();
>
>//二进制读取 
>ifstream fin;
>fin.open("filename",ios_base::in|ios_base::binary);
>fin.read((char*)&struct_name,sizeof(struct));
>cout << struct_name.info1 << " " <<  struct_name.info2 << endl;
>if(fin.is_open()) //如果文件不存在 fin.is_open() 就为false；
>```

### 随机存取

>
>
>```c++
>读取文件定位 seekg
>写文件丁文 	seekp
>ifstream fin;
>fin.seekg(0)； //定位到文件头
>!fin.eof() ;; 判断是否到文件尾，文件尾会促发eofbit 导致fin 失效 需要
>fin.clear() ;;重新回复文件状态
>```
>
>```c++
>#include <iostream>
>#include <fstream>
>#include <iomanip>  //设置小数点
>
>using namespace std;
>
>struct planet{
>	char name[20];
>	double population;
>	double g;
>};
>
>
>int main(){
>	const char * filename="planet.dat";
>	planet pl;
>
>	cout <<fixed;
>
>	fstream finout; //输入流和输出流 定义成 fstream 
>
>	int ct=0;
>
>	finout.open(filename,ios_base::in|ios_base::out|ios_base::binary);
>
>	if(finout.is_open()){
>		cout << "Here is the content of file:" << filename << endl;
>		while(finout.read((char *)&pl,sizeof(pl))){
>			cout << "Ct Num : " << ct++ <<" ,Name:" <<pl.name << setprecision(0) <<",Pop:" << pl.population << ",G:"							<<setprecision(2)  <<pl.g << endl;
>		}
>		
>	}
>
>
>	if(finout.eof())
>		finout.clear(); 
>	//读到文件尾了，会促发eofbit 标志为 会禁止对文件做进一步的读写
>	//需要用clear() 重写设置文件流,清除标志位
>
>	cout <<"Enter the Number you wish to change";
>	int rec;
>	cin >> rec;
>
>	while(cin.get() !='\n'); //交替输入 干掉回车换行
>
>	if(rec < 0 | rec >=ct ){
>		cout <<"out of range!" << endl;
>		exit(0);
>	}
>
>
>	streampos place=rec*sizeof(pl);//需要跨过的字节
>
>	//seekg 输入指针 移动到指定的位置	ifstream   读取文件  fin >>到屏幕
>	
>	//seekp 输出指针 移动到指定的位置   ofstream   写文件    cout << data;
>
>	finout.seekg(place); 
>	finout.read((char*)&pl,sizeof(pl));	
>	cout <<"the change of the data" << endl;
>	cout << "rec : " << rec <<" ,Name:" <<pl.name << setprecision(0) <<",Pop:" << pl.population << ",G:"<<setprecision(2)  <<pl.g << endl;
>	if(finout.eof())
>		finout.clear();
>
>	cout << "enter Plant Name:" ;
>	cin >> pl.name;
>	while(cin.get() !='\n');
>	cout << "enter planet population:";
>	cin >> pl.population;
>	cout << "enter planet G ";
>	cin >> pl.g;
>	while(cin.get() !='\n');
>
>	finout.seekp(place);
>	finout.write((char *)&pl,sizeof(pl));
>
>	finout.seekg(0);
>	//重写读取文件
>	ct=0;
>
>	if(finout.is_open()){
>		cout << "Here is the content of file:" << filename << endl;
>		while(finout.read((char *)&pl,sizeof(pl))){
>			cout << "Ct Num : " << ct++ <<" ,Name:" <<pl.name << setprecision(0) <<",Pop:" << pl.population << ",G:"<<setprecision(2)  <<pl.g << endl;
>		}
>		
>	}
>
>
>	finout.close();
>
>
>
>	return 0;
>}
>```
>
>

### 内核格式化

>
>
>```c++
>使用内核格式化 可以轻松的把数字转换成字符串
>也可以把字符串转换成数字
>  istringstream 和 ostringstream 类可以使用istream 和 stream类的方法来管理存储在字符串中的字符数据
>  
>  把一串数字文本 注入到 stringstream 的对象中
>  再从该对象
>  while(stringstream &  >> int type){
>    cout << type;
>  }
>  
>
> 
>```
>
>```c++
>//file1 
>1 2 3 4 5 6 7 8 9
>  
>  
>#include <iostream>
>#include <sstream>
>#include <fstream>
>#include <string>
>using namespace std;
>int main(){
>
>  stringstream Mystr; //内核格式化
>  int temp;
>  char ch;
>  int sum=0; 
>
>	ifstream fin;
>	fin.open("file1"); //输入文件名字
>
>	
>	while(fin.get(ch)){
>		Mystr << ch;			 //类似cout  每个字符都注入到stringstream 对象中
>	}
>
>	while(Mystr >> temp){		//从stringstream 对象读出来  存放到 int 中
>
>		cout << temp << endl;
>		sum +=temp;
>	}
>
>	cout << "Sum:" << sum << endl;
>
>
>	fin.close();
>
>	return 0;
>
>
>}
>```
>
>```c++
>#include <iostream>
>#include <fstream>
>#include <sstream>
>#include <string>
>#include <cctype>
>
>using namespace std;
>
>bool insert(stringstream& s,string& str);
>
>int main(){
>
>	stringstream str;
>
>	string temp("1 2 &53 -4 5 6");
>	string temp2("hello kiff44,54 54");
>	
>	insert(str,temp);		//注入两个字符串
>	insert(str,temp2);		//注入两个字符串
>	int n;
>	long total=0;
>	while(str >>n ) {
>		cout << n  << endl;
>		total +=n;
>
>	}
>
>	cout <<"Total value = " << total << endl;
>
>	return 0;
>
>}
>
>
>	//通过修改注入的值
>bool insert(stringstream& s,string& str){
>	auto p=str.begin();
>
>	for(;p<str.end();p++){
>		if(isdigit(*p)  ||   *p=='-'){
>			s << *p;
>		}else{
>			s << " ";
>		}
>	}
>	return true;
>
>}
>```
>
>

## chapter18:探讨c++新标准



### 复习一下之前的

>`decltype`
>
>```c++
>int a=6;
>decltype((a)) fuck=a;// now fuck type is : int & 
>```
>
>`using`
>
>```c++
>常用的: typedef std::vector<std::string>::iterator othername;
>using othernaame=std::vector<std::string>::iterator;
>
>
>using 可以给模版起别名,typedef 不能
>template<typename T>
>using arr12=std::array<T,12>;// 模版的别名
>
>arr12<double> a1 ;// 把
>```
>
>异常规范的修改`noexpect`
>
>```c++
>void func(int) throw(bad_dog) ;//会抛错
>void func(int) throw();//不会抛错
>void func(arg) noexpect;	//不会抛错
>```
>
>作用域枚举 `class enum` or `struct enum`
>
>```c++
>enum  egg{Small,Medium,Larg,Jumbo};
>enum  T_shirt{Small,Medium,Larg,Xlarge};
>//无法通过编译，有两个 Small
>
>应该加上一下作用域:
>
>enum class egg{Small,Medium,Larg,Jumbo};
>enum  class T_shirt{Small,Medium,Larg,Xlarge};
>
>egg choice=egg::Small; //赋予值加上作用域
>T_shirt floyd=T_shirt::Small;//
>
>
>```
>
>`explicit`
>
>```c++
>禁止单参数构造函数导致的自动转换;
>
>```
>
>类的成员初始化
>
>```c++
>class Foo{
>private:
>	int a{0};
>	double b{0};
>	double* pb{nullptr};
>
>}
>```
>
>基于范围的for 循环
>
>```c++
>double arr[3]={1.3,1.5,1.66};
>for(auto p:arr){
>cout << p << endl;
>}
>```
>
>右值引用
>
>```c++
>可以取地址的 为左值
>不可以取地址的 为右值
>```
>
>

### 移动语义和右值引用

>移动语义 
>
>int a =5;
>
>Int b = a+1; //a+1 为右值 会生成临时对象 
>
>⚠️**函数的返回值也是右值**
>
>右值引用不可以指向 变量
>
>int a=6;
>
>Int &&pa=a;//no 
>
>```c++
>#include <iostream>
>#include <utility>
>
>using namespace std;
>
>class Useless{
>private:
>	int n;
>	char *pc;
>	static int ct;
>	void ShowObject()const;
>public:
>	Useless();
>	explicit Useless(int k);
>	Useless(int k,char ch);
>	Useless(const Useless& f);
>	Useless(Useless&& f);  //移动构造函数 
>											//两个对象用 右边 可以 Static_cast<Useless&&>(right)
>											//或者std::move(right)  
>											//
>	~Useless();
>	Useless operator+(const Useless&f)const;
>
>
>Useless& operator=(Useless &&f){  //移动赋值运算符  右值为两个对象的时候，在内存空间生成的临时对象直接赋值给左边
>		cout << "|||||||||Use move assgin" << endl;
>		if(this==&f)
>			return *this;
>		delete []pc;
>		n=f.n;
>		pc=f.pc;
>		f.n=0;
>		f.pc=nullptr;
>		return *this;
>
>	}
>	void ShowData()const;	
>
>};
>
>int Useless::ct=0;
>
>
>Useless::Useless(){
>	++ct;
>	n=0;
>	pc=nullptr;
>	cout << "default constructor called,member of object: " << ct << endl;
>	ShowObject();
>}
>
>Useless::Useless(int k):n(k){
>	++ct;
>	cout << "Int constructor called,number of object:" << ct << endl;
>	pc=new char[n];
>	ShowObject();
>}
>
>Useless::Useless(int k,char ch):n(k){
>	++ct;
>	cout << "Int & char constructor called,member of object:" <<ct<< endl;
>	pc=new char[n];
>	for(int i=0;i<n;i++){
>		pc[i]=ch;
>	}
>	ShowObject();
>}
>
>
>Useless::Useless(const Useless& f):n(f.n){
>	ct++;
>	cout << "copy const constructor called ,the member object: " << ct<< endl;
>
>	pc=new char[n];
>	for(int i=0;i<n;i++){
>		pc[i]=f.pc[i];
>	}
>	ShowObject();
>}
>
>//移动构造函数
>Useless::Useless(Useless&& f):n(f.n){
>	++ct;
>	pc=f.pc;   			 //指针赋予给另外一个指针,
>	f.pc=nullptr;			//清空指针 nullptr 可以再次被delete
>	f.n=0;					//清空成员
>}
>
>Useless::~Useless(){
>	cout << "destructor called,member left :" << --ct << endl;
>	cout << "delete object:" ;
>	ShowObject();
>	delete []pc;
>}
>
>Useless Useless::operator+(const Useless&f)const{
>	cout <<"Enter operator + "<< endl;
>	Useless temp(n+f.n);
>	for(int i=0;i<n;i++){
>		temp.pc[i]=pc[i];
>	}
>	for(int i=n;i<temp.n;i++){
>		temp.pc[i]=f.pc[i-n];
>	}
>	cout << "temp object:\n";
>	cout <<"Leaving operator + " << endl;
>	return temp;
>
>}
>
>void Useless::ShowObject()const{
>	cout <<"[";
>	cout << "Number of elements: " << n << endl;
>	cout << "Data addr:" << (void *) pc ;
>	cout<<"]\n";
>}
>
>void Useless::ShowData()const{
>	if(n==0){
>		cout << "(empty data)" << endl;
>	}else{
>		for(int i=0;i<n;i++){
>			cout <<pc[i];
>		}
>		cout << endl;
>	}
>}
>
>int main(){
>
>	Useless one(10,'a');
>	cout << "------------------------------"<< endl;
>	one.ShowData();
>	cout << "------------------------------"<< endl;
>
>	Useless two(static_cast<Useless&&>(one+one));  //把数据改变数据类型，变成右值
>
>	Useless two2(move(one));	//把one的数据控制权交给two2
>								//one里面的指针为nullptr 可以再次被析构
>
>
>	cout << "------------------------------"<< endl;
>	one.ShowData();
>	two.ShowData();
>	two2.ShowData();
>
>
>	// cout << "------------------------------"<< endl;
>	// Useless one(10,'x');
>	// cout << "------------------------------"<< endl;
>	// Useless two(one);
>	// cout << "------------------------------"<< endl;
>	// Useless three(20,'o');
>	// cout << "------------------------------"<< endl;
>	// Useless four(one + two);
>	// cout << "------------------------------"<< endl;
>	// cout << "-------------show one-----------------"<< endl;
>	// one.ShowData();
>	// cout << "-------------show two-----------------"<< endl;
>	// two.ShowData();
>	// cout << "-------------show three-----------------"<< endl;
>	// three.ShowData();
>	// cout << "-------------show four-----------------"<< endl;
>	// four.ShowData();
>	// cout << "-------------code done-----------------"<< endl;
>
>
>
>	return 0;
>}
>
>
>```
>
>```
>
>```

### default 和delete 关键字


>
>
>```c++
>类的六个成员函数
>	//默认构造函数
>	//拷贝构造函数
>	//移动构造函数
>	//拷贝运算符
>	//移动运算符
>	//析构函数
>
>关键字default 只能用于6个成员函数
>
>关键字delete 可以哟哦能够与任何成员函数
>	delete 还有一种用法是禁止使用该方法
>
>	class someclass{
>		...;
>	public:
>		someclass(double );
>		someclass(int)=delete; //参数为int 设置为禁用
>	}
>
>```
>
>

### 委托构造函数

>
>
>```c++
>委托构造函数
>	一个构造函数中允许调用其他构造函数
>
>	class Note{
>	private:
>		int k;
>		double x;
>		string st;
>	public:
>		Note();
>		Note(int n);
>		Note(int n,double d);
>		Note(int n,double d,string s);
>	}
>
>	Note::Note(int n,double d,string s):k(n),x(d),st(s){}
>	Note::Note():Note(0,0.01,"No"){}// 调用其他构造函数
>	Note::Note(int n):Note(n,0.01,"hello"){}// 调用其他构造函数
>	Note::Note(int n,double d):Note(n,d,"kiitty"){}; //调用其他构造函数
>
>```
>
>

### 继承构造函数 

>**需要声明使用 基类的构造函数**
>
>Using BaseName::BaseName;
>
>```c++
>#include <iostream>
>
>using namespace std;
>
>class BS{
>	int q;
>	double w;
>public:
>	BS():q(0),w(0.0){};
>	BS(int x):q(x),w(100){};
>	BS(double y):q(1),w(y){};
>	BS(int x,double y):q(x),w(y){}
>	void Show()const{cout << q << "," << w << endl;}
>};
>
>
>class DR:public BS{
>private:
>	short j;
>public:
>	using BS::BS;	//使用BS自己的构造函数  要加上c++标准11 
>	DR():j(-100){}
>	DR(double x):BS(2*x),j(int(x)){}
>	DR(int i):j(-2),BS(i,0.5*i){}
>	void Show()const{cout << "j=" << j << endl;BS::Show();}
>}; 
>
>int main(){
>	DR o1;			//Use DR()
>	DR o2(18.81);		//USe DR(double)
>	DR o3(10,1.0 );  	//USE BS(int,double) ;DR.j is random value
>						//DR 里面没有与之匹配的构造函数,会调用BS 里面的构造函数 j为随机值
>	o3.Show();
>	return 0;
>}
>```
>
>

### 管理虚方法 override 和final

>
>
>**override 覆盖**
>
>出现在派生类
>
>```c++
>	void f(char ch)const override{cout << val() << " " << ch << "!!!!"<< endl;}
>		//override 明确的表明，强制的告诉编译器，和看代码的其他用户 这是派生类的重载  需要写在const 后面
>```
>
>**final**   禁止派生类重写该方法()  特征标一样
>出现在基类
>
>```c++
>virtual void f(char ch)const final{cout << val() << " " << ch <<  endl;}
>									//final 禁止派生类 重写该函数 写在const 后面
>									//同名函数的可以写，但是不可以函数特征标一样
>									//同名函数会隐藏基类方法  可以显式的用 derivedObj.baseNAME::baseMethod();
>```
>
>```c++
>#include <iostream>
>
>using namespace std;
>
>class Action
>{	int a;
>	public:
>		Action(int i=0):a(i){}
>		int val()const {return a;}
>		virtual void f(char ch)const final{cout << val() << " " << ch <<  endl;}
>									//final 禁止派生类 重写该函数 写在const 后面
>};
>
>class Bingo:public Action{
>public:
>	Bingo(int i=0):Action(i){}
>	void f(char ch)const override{cout << val() << " " << ch << "!!!!"<< endl;}
>
>		//override 明确的表明，强制的告诉编译器，和看代码的其他用户 这是派生类的重载  需要写在const 后面
>
>};
>
>int main(){
>	Bingo b(10);
>	//b.f('@'); //基类的  可以显式的使用 b.Action::f('@');
>	b.f('a');
>
>
>	return 0;
>}
>```
>
>
>
>

### lambda函数

>
>
>lambda函数 是函数的右边值
>
>```c++
>template<class T>
>void show2(double x, T& fp){   	//T& 是函数指针的引用  不可以用lambda表达式 
>  															//参数类型应该 T&& 或者 const T& 或者 T 
>	std::cout << x << " ->" << fp(x) << '\n';
>}
>
>```
>
>
>
>
>
>
>
>```c++
>#include <iostream>
>#include <vector>
>#include <algorithm>
>#include <ctime>
>#include <cstdlib>
>
>/*
>*/
>
>using namespace std;
>
>
>int main(){
>	vector<int> numbers(SIZE1*10000);
>	srand(time(0));
>	generate(numbers.begin(),numbers.end(),rand); //rand()产生的随机数一次放在迭代器里面
>
>
>	//对于接受函数指针和函数符的函数 可以使用lambda 表达式
>	//lambda 没有声明返回值 编译器  decltype 自动推断
>	//lambda 没有函数名
>	//给lambda 表达式 加上函数名字 auto 编译器推断
>
>	int count3,count13;
>	count3=count13=0;
>
>
>	count3=count_if(numbers.begin(),numbers.end(),[](int n){return n %3 ==0;});
>	cout << "Lambda expression value = " << count3 << endl;
>	for_each(numbers.begin(),numbers.end(),[&count13](int n){count13 += (n %13 ==0);});
>	cout << "Lambda count13 value = " << count13  << endl;
>
>	//lambda 额外的功能
>	//可以访问作用域内的任何动态变量 捕获的的值放在[]内  加上& 是按照引用访问变量
>	// [&] 的功能 
>
>	count3=count13=0;
>
>	for_each(numbers.begin(),numbers.end(),[&](int a){count3 += (a %3==0);count13 +=(a %13==0);});
>											//lambda 里面的变量全都为引用
>	cout << "count3 =" << count3 << endl;
>	cout << "count13 = " << count13 << endl;
>
>	return 0;
>
>
>}
>```
>
>
>
>

### 包装器模版

>**wrapper**
>
>**需要包含头文件 #include <functional>**
>
>**function<douuble,<char,int>> MyWrapper;**
>
>**MyWrapper 可以指向 参数为 char 和int 并且返回值为double的函数，仿函数 和lambda 函数**
>
>```c++
>#include <iostream>
>using namespace std;
>
>template <typename T,typename F>
>T use_f(T v,F f){
>	static int  count =0;
>	count++;
>	cout <<  "Use_f count :" << count << " , Addr = " << &count << endl;
>	return f(v);
>}
>
>class Fp{
>private:
>	double z_;
>public:
>	Fp(double z=1.0):z_(z){}
>	double operator()(double p){
>		return z_ * p;
>	}
>};
>
>class Fq{
>	private:
>		double z_;
>	public:
>	Fq(double z=1.0):z_(z){}
>	double operator()(double q){
>		return z_ + q;
>	}
>};
>
>
>double dub(double x){return 2.0 *x;};
>double square(double x){return x*x;};
>
>//特征标 参数为 double 返回值也是double 
>//头文件 <functional>
>
>
>
>int main(){
>	double y=1.21;
>
>								//定义包装器
>	function<double(double)> fdd=dub;  //包装器指向 dub 函数  // 函数参数和返回值都是double
>	cout << use_f(y,fdd) << endl;
>
>
>	fdd=square;	//指向第二个函数
>	cout << use_f(y,fdd) << endl;
>
>	fdd=Fp(2.0); //指向第三个 第三个为仿函数
>	cout << use_f(y,fdd) << endl;
>
>	fdd=Fp(23.0); //指向第四个 第四个为仿函数
>	cout << use_f(y,Fp(3.2)) << endl;
>
>
>	fdd=[](double x){return  x+0.1;};	//指向第一个lambda 函数
>
>	cout << use_f(y,fdd) << endl;
>
>	fdd=[](double x){return  x+x/2;}; //指向第二个lambda 函数
>
>	cout << use_f(y,fdd) << endl;
>
>
>	return 0;
>}
>```
>
>
>
>
>
>
>
>

### 可变参数模版

>```c++
>//要创建可变参数模版需要理解几个要点
>模版参数包
>函数参数包
>展开参数包
>递归
>```
>
>```c++
>template <class T,class... Args>   // 模版参数包
>void show(T t,Args... args){		//函数参数包
>cout << t << endl;							//展开参数包
>show(args...);									//递归自己
>}
>```
>
>```c++
>#include <iostream>
>using namespace std;
>
>/*
> 可变参数求和，可以是任意数据类型
> */
>
>long double sum_value(){
>    return 0 ; //最后一个情况
>}
>
>template<class T,class... Args>
>long double sum_value(T value,Args... args){
>    return (long double)value + sum_value(args...);
>                        //取回第一个值，然后递归给自己,然后最后一个没有参数
>                        //需要考虑无参数的情况
>}
>
>
>int main(){
>    cout << sum_value(111,2,5.5) << endl;
>    cout << sum_value('a','b',5.3,6) << endl;
>    cout << sum_value(3.4445,'b',5.3,6) << endl;
>    cout << sum_value(1,2,3) << endl;
>    return 0;
>    
>}
>
>```
>
>
>
>模版参数包，函数参数包
>
>```c++
>#include <iostream>
>#include <string>
>using namespace std;
>
>
>void show_list(){}  //匹配最后一个空参数
>
>
>template<class T>		//匹配最后一个参数 并且增加换行
>void show_list(T t){
>	cout << t << endl;	
>}
>
>/* 
>	show_list(x*x,"!" ,7,mr);参数会变成
>	x*x , ("!" ,7,mr);		//x *x 会被打印出来，其他的呼递归给自己
>	"!" ,	(7,mr); 		//"!" 会被打印出来 (7,mr)会递归给自己
>	7 ，  (mr);				// 递归给自己
>	mr,   ();				// mr 匹配 template<class T> show 函数
>									// 空参数匹配  void show_list()
>					还剩下一个空参数  需要写一下空函数,啥都不用干
>*/
>template<typename T,typename... Args>
>void show_list(T value,Args... args){
>	cout << value << " , ";
>	show_list(args...); 
>}
>
>int main(void){
>	int n=14;
>	double x=2.71;
>	string mr="Mr rick";
>	show_list(n,x);
>	show_list(x*x,"!" ,7,mr);
>	return 0;
>}
>```
>
>

