# `之前写` 的

### 输入验证1

```c
#include <stdio.h>
#include <stdbool.h>



long get_long(void);//函数原型
long get_long(void){
    long num;
    int ch;
  
    printf("please enter an integer:");
    
    while(scanf("%ld",&num) !=1)
    {
        while((ch =getchar()) !='\n')
            putchar(ch);
        printf(" is not an integer\nPlease enter an ");
        printf("Integer,such as -44,43 and 45\n");
        printf("please enter an integer:");
    }
    
    while(getchar() !='\n')
        continue;
    
    if(num >=2022)
        return 2022;
    else if (num <= 1927)
        return 1927;

    return num;
}


int main(void)
{   long fuck;
    fuck=get_long();
    printf("get_long value is %ld\n",fuck);
    return 0; 
}

```

### 输入验证2

```c
//最小数量和最大数量之间的平方和
#include <stdio.h>
#include <stdbool.h>

long get_long(void);

bool bad_limit(long begin,long end,long low,long high);

double sum_squares(long min,long max);

//计算范围整数的平方和
double sum_squares(long min,long max)
{
  double total = 0.0;
  long i;
  for(i=min;i <= max;i++)
    total += (double)i*(double)i;
  return total;
}


long get_long(void)
{
    long input;
    char ch;
    while(scanf("%ld",&input) !=1)
    {
        while((ch=getchar()) !='\n')
            continue;
        printf("please enter an integer such as -4,-3 or 543\n");
        printf("continue to enter the integer:");
    }
    return input;
}

//判断数字的合法性
bool bad_limit(long start,long stop,long MIN,long MAX){
    bool not_good = false;
    if(stop < start )
    {   printf("1 error");
        not_good = true;}
    if(start < MIN || start > MAX)
    {   printf("2 error");
        not_good =true;}
    if(stop < MIN || start > MAX)
    {   printf("3 error");
        not_good=true;}
    return not_good;
}


int main(void){
    const long MIN = -10000000L;
    const long MAX = +10000000L;

    long start; //用户指定范围最小值；
    long stop; //用户指定范围最小值；
    long answer;

    printf("该程序会计算范围的整数的平方和\n");
    printf("请请输入最小值，最大值\n");
    printf("最小值:");
    
    start = get_long();
    
    printf("最大值:");
    
    stop = get_long();
    
    while (start !=0 || stop != 0)
    {
        if(bad_limit(start,stop,MIN,MAX))
        {
            printf("Please try again.\n");
        }
        
        else
        {
            answer = sum_squares(start,stop);
          {
            printf("the sumwer values is %ld for %ld to %ld\n",answer,start,stop);
          }
        }
        printf("继续请输入最小值，最大值\n");
        printf("最小值:");
        
        start = get_long();
        
        printf("最大值:");
        
        stop = get_long();
  }
  printf("Done.\n");
  return 0;
}


```

### 输入验证2copy

```c
#include <stdio.h>
#include <stdbool.h>
#define MIN -10000000L
#define MAX 10000000L


//判断
bool panduan(long start,long stop,long min,long max);

bool panduan(long start,long stop,long min,long max)
{   bool is_good=false;
    
    if (start > stop)
    {  printf("start can't be bigger than stop");
        is_good = true;
    }
    if (start < min || start > max)
    {
        printf("%ld must bewteen with %ld and %ld\n",start,MIN,MAX);
        is_good=true;
    }
    if (stop < min || stop > max)
    {
        printf("%ld must bewteen with %ld and %ld\n",stop,MIN,MAX);
        is_good=true;
    }
    return is_good;
}

long get_sum(long start,long stop);


long get_sum(long start,long stop){
    long f_sum = 0;
    for(long i=start;i <=stop;i++)
    {
        f_sum += i ;//* i;
    }
    return f_sum;
}

long get_long(void){
    long num;
    char ch;
    
    while(scanf("%ld",&num) !=1)
    {
        while((ch=getchar()) !='\n')
        {
            putchar(ch);
        }
        printf(" is not a number.\nPlease enter an integer such as 7,5,-4\n");
    }
    return num;
}



int main(void)
{
    long start;
    long stop;
    long sum;
    
   
    printf("this is a program to 最小值和最大值的区间的平方和.\n");
    printf("请输入最小值和最大值 输入 0  0  结束程序.\n");
    printf("最小数：");
    start=get_long();
    printf("最大数：");
    stop=get_long();
    while (start !=0 || stop !=0)
    {
        if (panduan(start, stop, MIN, MAX))
        {
            printf("请重新输入\n");
        }
        else
        {
            sum = get_sum(start,stop);
            printf("%ld 到 %ld 的平方和为 %ld",start,stop,sum);
        }
        
        printf("\n\nthis is a program to 最小值和最大值的区间的平方和.\n");
        printf("请输入最小值和最大值 输入 0  0  结束程序.\n");
        printf("最小数：");
        start=get_long();
        printf("最大数：");
        stop=get_long();
    }
    
    return 0;
}

```

### 四选项

```c
# include<stdio.h>

char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);

//count函数
//便利数字，从1开始
void count(void){
    int n,i;
    printf("count how far,Enter an integer:\n");
    n=get_int();
    for(i=1;i<=n;i++)
        printf("%d\n",i);
    while (getchar() !='\n')
        continue;
}

//get_choice
//展示首页菜单
char get_choice(void){
    int ch;
    printf("Enter the letter of your choice:\n");
    printf("a.advice                 b.bell.\n");
    printf("c.count                  q.quit\n");
    ch=get_first();
    while((ch < 'a' || ch >'c') && ch !='q')
    {
        printf("Please respond with a,b,c,or q.\n");
        ch=get_first();
    }
    return ch;
}

//获得首个首字母 过滤其他字母
char get_first(void)
{
    int ch;
    ch =getchar();
    while(getchar() !='\n')
        continue;
    return ch;
}

//得到数字 过滤其他
int get_int(void)
{
    int input;
    char ch;
    
    while(scanf("%d",&input) !=1)
    {
        while ((ch=getchar()) !='\n')
            putchar(ch);
        printf(" is not an integer please enter some numbe ");
        printf("such as 15,45,66\n");
    }
    return input;
}

//主函数
int main(void){
    char choice;
   // void count(void);
    
    while((choice = get_choice()) !='q')
    {
        switch(choice)
        {
            case 'a':
                printf("Buy low,sell high.\n");
                break;
            case 'b':
                putchar('\a');
                printf("B program over\n");
                break;
            case 'c':
                count();
                break;
            default:
                printf("Program error.\n");
                break;
                
        }
        
    }
    printf("Bye.\n");
    return 0;
}

```

### 四选项2

```c


/*
printf("Enter the letter of your choice:\n");
printf("a.advice                 b.bell.\n");
printf("c.count                  q.quit\n");
*/

#include <stdio.h>
#include <stdbool.h>

int get_int(void);
char get_first(void);
char get_choice(void);
void count(void);
bool hello_kitty(char choice);

bool hello_kitty(char choice)
{
    bool result =true;
    if (choice == 'a') result = false;
    if (choice == 'b') result = false;
    if (choice == 'c') result = false;
    if (choice == 'q') result = false;
    return result;
}

int main(void){
    char choice;
    while((choice =get_choice()) !='q'){
        switch(choice)
        {   case 'a':
                printf("buy the low and sell the high\n");
                break;
            case 'b':
                putchar('\a');
                printf("i am ringing.\n");
                break;
            case 'c':
                count();
                break;
            default:
                printf("Program error.\n");
                break;
            
        }
    }
    printf("Bye-Bye.\n");
    return 0;
}

int get_int(void){
    int num;
    char ch;
    
    while(scanf("%d",&num) !=1)
    {
        while((ch=getchar()) !='\n')
        {
            putchar(ch);
        
        }
        printf(" is not an number ");
        printf(" Please enter an number such as 9 or 4444:");
        
    }
    
    while(getchar() != '\n')
        continue;
    
    return num;
}

char get_first(void)
{
    char ch;
    
    ch=getchar();
    
    while(getchar() !='\n')
        continue;
    return ch;
}

char get_choice(void){
    char big_choice;
    
    printf("Enter the letter of your choice:\n");
    printf("a.advice                 b.bell.\n");
    printf("c.count                  q.quit\n");
    printf("\nYour choice:");
    
    big_choice=get_first();
    
    //while(big_choice != 'a' && big_choice != 'b' && big_choice != 'c' && big_choice != 'q')
    while(hello_kitty(big_choice))
    {
        printf("输入非法，请输入a b c or q\n");
        printf("Your number is:\n");
        big_choice =get_first();
    }
    
    return big_choice;
}

void count(void){
    int i;
    int end;
    
    printf("please enter an number,i can 从1 数到你输入的数字\n");
    end=get_int();

    for(i=1;i<=end;i++){
        printf("%d\n",i);
    }    
}
```

# 函数

### 第一个函数

```c
#include  <stdio.h>
#include <string.h>
#define NAME "minlang"
#define  ADDRESS "wandaxingcheng"
#define PLACE  "jiangxi,nanchang"
#define WIDTH 60


//函数原型 也可以放放main 函数里面，但是不建议这么做
void n_space(char ch,int num);

void n_space(char ch,int num)
{
    int count; //局部变量，用完 之后会释放内存，其他函数可以同名
    for(count=1;count<=num;count++)
        putchar(ch);
    //putchar('\n');
}

int main(void){
    n_space('#',WIDTH);
    putchar('\n');
    n_space(' ',(WIDTH-strlen(NAME))/2);
    printf("%s\n",NAME);
    n_space(' ',(WIDTH-strlen(ADDRESS))/2);
    printf("%s\n",ADDRESS);
    n_space(' ',(WIDTH-strlen(PLACE))/2);
    printf("%s\n",PLACE);
    n_space('#',WIDTH);
    putchar('\n');
    putchar('\n');
    return WIDTH;
}

```

# 递归

### 函数中间递归

```c
#include <stdio.h>

void up_and_down(int);
void circle(int);

int main(void){
    up_and_down(1);
    return 0;
}

void up_and_down(int n){  //n=1
    
    printf("i am level 上半部分 %d,我的地址:%p\n",n,&n);
    if(n <4)
        up_and_down(n+1);
    printf("i am level 下半部分 %d,我的地址:%p\n",n,&n);
    return;

}
```

```c
i am level 上半部分 1,我的地址:0x7ff7bfeff26c
i am level 上半部分 2,我的地址:0x7ff7bfeff24c
i am level 上半部分 3,我的地址:0x7ff7bfeff22c
i am level 上半部分 4,我的地址:0x7ff7bfeff20c
i am level 下半部分 4,我的地址:0x7ff7bfeff20c
i am level 下半部分 3,我的地址:0x7ff7bfeff22c
i am level 下半部分 2,我的地址:0x7ff7bfeff24c
i am level 下半部分 1,我的地址:0x7ff7bfeff26c
Program ended with exit code: 0
```

### 尾递归

```
#include <stdio.h>

double fact(int n);  //使用循环求一个正整数 的阶乘
double rfact(int n); //使用递归求一个正整数 的阶乘

int main(void){
    int num;
    printf("please enter the number(q to quiet):");
    while( (scanf("%d",&num)) ==1 )
    {
        if (num <0)
            printf("please enter an number bigger than 0\n");
        else if (num >  100)
            printf("please enter an number less than 12\n");
        else
            {
                printf("%d循环阶乘的结果是 %.0lf\n",num,fact(num));
                printf("%d循环递归的结果是 %.0lf\n",num,rfact(num));    
            }
        printf("Enter the number(q to quiet):");
    }
    printf("Bye-bey.\n");
    return 0;
}

double fact(int n)  //使用循环求一个正整数 的阶乘
{   double num=1;
    int i;
    for (i=1;i<=n;i++)
        num *=i;
    return num;
}

double rfact(int n) //使用递归求一个正整数 的阶乘
{   if (n==1)
        return 1;
    else
        return n*rfact(n-1); //每次调用都会占一个内存，放在站中
}


```

### 数字变成二进制使用了递归

```c
#include <stdio.h>


void get_bin(int);



int main(void){
    int num;
    //char ch[30];
    printf("please enter the number(q to quiet):");
    while((scanf("%d",&num))  ==1){
        printf("数字:%5d 二进制是:",num);
        get_bin(num);
        printf("\nplease enter the number(q to quiet):");
    }
    return 0;
}


void get_bin(int num)
{
    if(num / 2 !=0)
        get_bin(num/2);
    printf("%d",num % 2); //打印的值放在递归函数的后面，
  // putchar(num % 2 ? '1':'0'); //三元表达式更简洁一点
}

```

# 文件合并

### 说明

```c
//用gcc 命令
// gcc usehotel.c hotel.c -o 生成的程序名称
// 同时编译两个文件（头文件不需要加入编译）
// 确保代码没有错误，有错误也不提示。然后出现一些莫名其妙的错误
```



### 主程序 use hotel.c

```
#include <stdio.h>
#include "hotel.h"

int main(void){
	int nights;
	double hotel_rate;
	int code;
	
	while ((code=menu())  !=QUIT)
	{	
		switch(code)
        {
			
			case 1:hotel_rate=HOTEL1;
					break;
			case 2:hotel_rate=HOTEL2;
					break;
			case 3:hotel_rate=HOTEL3;
					break;
			case 4:hotel_rate=HOTEL4;
					break;
			default:hotel_rate=0;
					printf("Oop!\n");
					break;
		}
		nights=getnights();
		showprice(hotel_rate,nights);
	}
	printf("Thank you and goodbye.\n");
	return 0;

} 
```

### 头文件 hotel.h

```c
 #define QUIT 5
#define HOTEL1 180.00
#define HOTEL2 225.00
#define HOTEL3 255.00
#define HOTEL4 355.00
#define DISCOUNT 0.95 
#define START "*************************"

int menu(void);

int getnights(void);

void showprice(double rate,int nights);
```

### 函数文件 hotel.c

```c
#include <stdio.h>
#include "hotel.h"

//菜单 
int menu(void)
{	
	int code,status;
	printf("\n%s%s\n",START,START);
	printf("Enter the number of the sedired hotel:\n");
	printf("1) Fairfield ARMS            2) Hotel Olympic\n");
	printf("3) Chertworthy plaza         4) The STockton\n");
	printf("Q) quit\n");
	printf("\n%s%s\n",START,START);
	while((status = scanf("%d",&code)) !=1 || (code <1 || code >5))
	{
		if (status !=1)
			scanf("%*s");
		printf("Enter an integer from 1 to 5,Please.\n");
	}
	return code;		
}

int getnights(void)
{
	int nights;
	printf("How many nithts are needed?");
	while(scanf("%d",&nights) !=1)
	{
		scanf("%*s");
		printf("Please Enter an interger such as 2.\n");
		
	} 
	return nights;
}
void showprice(double rate,int nights)
{
	int n;
	double total=0.0;
	double factor  =1.0;
	for(n =1; n<=nights;n++,factor *=DISCOUNT){
		
		total +=rate * factor;
	}
	printf("The total cost will be $%.2f.\n",total);
}
```





# 指针

### 指针代码演示

```c
#include <stdio.h>
/*
int num=10；
int* P =&num;
int *指针名称=&变量，指针用%p取地址
作用：
1:取得变量在内存中的地址
2:保存变量在内存中的地址 使用 一个变量P来保存
3:保存地址的变量类型，我们称为指针变量类型
4: int* 是一种新的变量类型

*p; *是一个指针运算符，*p在代码里和num是一样的; *p=10 直接赋值;
*/

int main(void){
    int num=10;
    int num2=12;
    int* p=&num;   //int* 是新的变量类型，指针类型
    printf("*p=%d\n",*p); //10
    p=&num2;
    printf("*p=%d\n",*p); //12
    return 0;
}

```



### 说明

```c
#include  <stdio.h>
  
void makado(int);

int main(void){
   // int hello=3;
    int pooh=2;
    int bah=5;
    printf("In main(),pooh =%d and &pooh =%p\n",pooh,&pooh);
    printf("In main(),bah =%d and &bah =%p\n",bah,&bah);
    makado(pooh);
    return 0;
 
}

//参数传递的只是传递值
void makado(int bah)
{   int pooh=10;
    printf("In makdo(),pooh =%d and &pooh =%p\n",pooh,&pooh);
    printf("In makdo(),num =%d and &num =%p\n",bah,&bah);
    return;
}


```

### a,b 互换位置 

```c
#include <stdio.h>


void interchange(int a,int b);
void interchange(int a,int b)
{
    int temp;
    printf("func first a=%d,%p b=%d %p\n",a,&a,b,&b);
    temp=a;
    a=b;
    b=temp;
    printf("func later a=%d,%p b=%d %p\n",a,&a,b,&b);
}

int main (void)
{
    int a,b;
    
    a=3,b=4;
    
    printf("first a=%d,%p b=%d %p\n",a,&a,b,&b);
    
    interchange(a, b); //只传递值,
    
    printf("later a=%d,%p b=%d %p\n",a,&a,b,&b);
    
    return 0;
}

```

### 指针在函数之间的通信

```c
#include <stdio.h>

void interchange(int* a,int* b);

int main(void){
    int x=5;
    int y=10;
    printf("first x=%d and y=%d\n",x,y);
    interchange(&x,&y); //传递x 和y 的内存地址给函数
    printf("now x=%d and y=%d\n",x,y);
}



void interchange(int* a,int* b)//形参数是两个指针类型的变量
{
    int c;
    c = *a;  //内存地址a 的值 赋值给 变量c
    *a = *b;  // a内存地址的值 现在等于 内存地址b的值
    *b = c;  //把c的值 赋值 给 内存地址b里面
}
 
 

```



# 数组和指针

### 打印每个月有多少天

```c
#include <stdio.h>
#define MONTHS 12

int main(void)
{
    int days[MONTHS]={31,28,31,30,31,30,31,30,31,30,31,30};
    int index;
    for(index=0;index <MONTHS;index++){
        printf("%2d have %d days\n",index+1,days[index]);
    }
    return 0;
}

```

### 数组越界改变其他变量的值，要小心

```c
#include<stdio.h>
#define SIZE 4

int main(void){
    int value1=44; //在两个int 变量中定义一个int 数组
    int arr[SIZE];	//两个int变量和数组的内存地址都是相邻的
    int value2=88;
    printf("1 &value1 :%p\n",&value1);
    printf("2 &arr[s] :%p\n",&arr);
    printf("3 &value2 :%p\n",&value2);
    
    int i;
    printf("value1=%d, value2=%d\n",value1,value2);
     
    for (i=-3;i<=SIZE;i++) //从数组的-3个索引给数组 遍历赋值
    {
        arr[i]= 0; // -1,1,3,5,7;
        printf("I am I,i =%d\n",i);
        printf("%d ,%d \n",i,arr[i]);
    }
    
    //超出数组范围赋值，在内存中改变了其他变量的值，要小心
    printf("value1 = %d,value2 = %d\n",value1,value2);
    printf("addressof arr[-1]:%p\n",&arr[-1]);
    printf("address of arr[0]:%p\n",&arr[0]);
    printf("address of arr[1]:%p\n",&arr[1]);
    printf("address of arr[2]:%p\n",&arr[2]);
    printf("address of arr[3]:%p\n",&arr[3]);
    printf("address of arr[4]:%p\n",&arr[4]);
    printf("address of value1:%p\n",&value1);
    printf("address of value2:%p\n",&value2);
    
    return 0;
    
}

```

### 看二维数组代码

```c

#include <stdio.h>
#define INDEX 5
#define COLUMN 13

int main(void){
    int arr[INDEX][COLUMN]={{[2]=1,3,4}}; //赋值看不懂
//    arr[1][0] =1;
    //arr[1][2] =12;
    for(int x=0;x<INDEX;x++){
        for(int y=0;y<COLUMN;y++){
//            if (!(x%2==0) || !(y%2==0))
//                arr[x][y]=12;
//            else
//                arr[x][y] =0;
//            printf("%2d addr %p\n",arr[x][y],&arr[x][y]);
            printf("%2d ",arr[x][y]);
        }
        putchar(10);
        
    }
    
    return 0;
    
    
}

```

### 计算每年降雨量 平均降雨量

```c
#include <stdio.h>

#define YEAR 5
#define MONTHS 12

int main (void){
    const float rain[YEAR][MONTHS]=
    {
        {1.2,1.3,1.3,0.5,0.2,1.2,1.3,1.3,0.5,0.2,0.5,0.2},
        {1.2,1.3,1.3,0.5,0.2,1.2,1.3,1.3,0.5,0.2,0.5,0.2},
        {1.3,0.5,0.2,0.5,0.2,0.5,0.2,1.2,1.3,1.3,0.5,0.2},
        {0.5,0.2,1.2,1.3,1.3,0.5,0.2,1.2,1.3,1.3,0.5,0.2},
        {0.2,1.2,1.3,1.3,0.5,0.2,1.2,1.3,1.3,0.5,0.2,1.2}
    };
    int year;
    int month;
    
    float subtot;
    float total;
    float every_month=0;
    
    printf("YEAR      RAINFALL          (inches)\n");
    for(year =0,total=0;year<YEAR; year++)
    {
        for(month =0,subtot=0;month <MONTHS;month++)
        {
            subtot +=rain[year][month];
        }
        printf("%4d %15.2f\n",2020+year,subtot);
        total +=subtot;
        
    }
    printf("总降水量为                      %.2f\n", total);
    printf("每年的平均降水量为                 %.2f\n\n", total/YEAR);
    
    
    printf("每月平均降水量\n");
    printf("一月  二月  三月  四月  五月 六月  七月  八月  九月 十月  十一 十二\n");
    //从月份开始循环
    for(month=0;month<MONTHS;month++)
    {
        for(year=0,every_month=0;year<YEAR;year++)
        {
            every_month +=rain[year][month];
        }
        printf("%.2f ",every_month/YEAR);
    }

    
    putchar(10);
    putchar(10);
    return 0 ;
}

```

### 看多维度的数组的内存空间

```c
#include <stdio.h>
#define WEI 4
#define INDEX 4
#define COLUMN 4
int main (void){
    double fuck[WEI][INDEX][COLUMN]={};  //看多维度的数组的内存空间 头文件可以定义维度
    
    for(int x=0;x<WEI;x++)
    {
        printf("\n第%d维数组\n",x+1);
        
        for(int xx=0;xx<INDEX;xx++)
        {
            for(int xxx=0;xxx<COLUMN;xxx++)
            {
                printf("%p ",&fuck[x][xx][xxx]);
                
            }
            putchar(10);
        }
      
    }

    return 0;
}


```

###  三维数组 ok 的

```c
#include <stdio.h>
#define WEI 20
#define INDEX 6
#define COLUMN 6
#define XING "**********************\n\n"



int main (void){
    int i1,i2,i3;
    int fuck[WEI][INDEX][COLUMN]={};
    //{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,27};
    //printf("%d\n",fuck[0][1][0]);
    fuck[0][1][1]=2;
    fuck[0][0][1]=2;
    
    for(i1=0;i1<WEI;i1++){
        for(i2=0;i2<INDEX;i2++){
            for(i3=0;i3<COLUMN;i3++){
                printf("%2d ",fuck[i1][i2][i3]);
                
            }
            putchar(10);
        }

        printf("以上是第%d维数组\n",i1+1);
        printf("%s",XING);

    }
    return 0;
}

```

### 用函数(指针传参数,计算数组之和)

```c
#include <stdio.h>
#define MONTH 12

//计算数组 SUM 函数原型
//两个参数 数组名称 实际上是 该数组第0个元素的内存地址
//第二个int 是数组的大小
int sum(int arr[],int);
//在函数原型和头文件中可以用 int arr[] 代表 int* arr


int main(void){
    int fuck[MONTH]={23,45,55,44,33,1};
    int result;
    result=sum(fuck,MONTH);
    printf("sizeof fuck %zd\n",sizeof fuck/sizeof fuck[0] );
    printf("the result is %4d",result);

    return 0;
}


int sum(int *arr,int len){
    //别忘记初始化呀
    int sum_=0;
    //下面这行代码错误,看不出来数组的大小
    printf("i am in func_sum,the size of arr is %zd\n",sizeof arr);     
    for(int i=0;i<len;i++){
        printf("the index:%d value %d\n",i,*(arr+i));
        sum_ += *(arr +i);
    }
    return sum_;
}
```

### 指针的运算

```c
//
//  main.c
//  hello_kitty
//
//  Created by macbookpro on 2022/8/8.
//

#include <stdio.h>

int main(void)
{
    int urn[5]={100,200,300,400,500};
    int *ptr1;
    int *ptr2;
    int *ptr3;
    ptr1=urn;
    ptr2=&urn[2];
    printf("pointer value,dereferenced pointer,pointer address:\n");
    //指针,取指针的值，取指针的指针
    printf("ptr1=%p   *ptr1=%d  &ptr1=%p \n",
           ptr1, *ptr1,&ptr1);
    
    //ptr3 指针加4 相当加了4个（sizeof(int)）  其实就是ptr1[4]
    ptr3=ptr1+4;
    printf("ptr1 +4= %p,  *(ptr1 +4)= %d\n",ptr3,*(ptr1+4));
    
    
    ptr1++;
    printf("\nvalues after ptr++\n");
    printf("ptr1=%p,*ptr1=%d\n",ptr1,*ptr1);
    
    ptr2--;
    printf("\nvalues after ptr++\n");
    printf("ptr2=%p,*ptr2=%d\n",ptr2,*ptr2);
    
    --ptr1;
    ++ptr2;
    
    printf("\nPointers reset to original values:\n");
    printf("ptr1=%p,ptr2=%p\n",ptr1,ptr2);
    printf("*ptr1=%d,*ptr2=%d\n",*ptr1,*ptr2);
    
    printf("\nsubtracting one pointer from anoter:\n");
    printf("ptr2=%p,ptr1=%p,ptr2-ptr1=%td\n\n\n",ptr2,ptr1,ptr2-ptr1);
    
    
    for(int i=0;i<4;i++)
        putchar(10);
    
    
    
    
    
    
    return 0;
    
}

```

### 使用const 显示数组被改动

```c
#include <stdio.h>
#define SIZE 5


//一般使用const ，表示数组中的元素不被修改
void show_array(const double ar[],int n);
void mult_array(double ar[],int n,double mult);


void show_array(const double ar[],int n)
{
    int i;
    for(i=0;i<n;i++){
        printf("%8.3f ",ar[i]);
    }
    putchar('\n');
}


void mult_array(double ar[],int n,double mult)
{
    int i;
    for(i=0;i<n;i++)
        ar[i] *=mult;
}


int main(void){
    double dip[SIZE]={20.0,17.66,8.2,15.3,22.22};
    show_array(dip,SIZE);
    mult_array(dip,SIZE,2.5);
    
    for(int i=0;i<SIZE;i++)
        printf("%8.3f ",dip[i]);
    putchar('\n');

    return 0;

}
```

### 利用指针计算二维数组

```c
#include <stdio.h>
#define ROWS 3
#define COLS 5

void sum_rows(int (*p)[COLS],int rows);
void sum_cols(int (*p)[COLS],int rows);
int sum2int(int (*p)[COLS],int rows);

int main(void){

    int fuck[ROWS][COLS]={{1,2,3,4,5},{5,5,6,7,8},{5,9,10,111,12}};
    sum_rows(fuck,ROWS);
    sum_cols(fuck,ROWS);
    printf("array sum is %d",sum2int(fuck,ROWS));
    

}

void sum_rows(int (*p)[COLS],int rows){
    int r,c;
    int total;
    for(r=0;r<rows;r++)
    {   total=0;
        for(c=0;c<COLS;c++)
        {
            total +=p[r][c];
        } 
        printf("row %d sum =%3d\n",r+1,total);
    }
}

void sum_cols(int (*p)[COLS],int rows){
    int r,c;
    int total;
    for(c=0;c<COLS;c++)
    {   total=0;
        for(r=0;r<rows;r++)
        {
            total +=p[r][c];
        } 
        printf("col %d sum =%3d\n",c+1,total);
    }
}

int sum2int(int (*p)[COLS],int rows){

    int r,c,total;

    for(c=0;c<COLS;c++)
    {   
        for(r=0;r<rows;r++)
        {
            total +=p[r][c];
        } 
        
    }
    return total;
}

```















