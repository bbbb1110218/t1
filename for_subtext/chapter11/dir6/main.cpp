#include "vector.h"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <ctime>

void sleep(double n){
	static int sleep =1;
	time_t start=clock();
	cout <<"Count["<< sleep++ <<"],"<<"I will sleep " << n << "second" <<endl;
	while(((clock() - start) < (n*CLOCKS_PER_SEC)));
}

int main(){
	using namespace VECTOR;
	srand(time(NULL));

	Vector result;
	Vector temp;


	int count=0;
	sleep(1);
	sleep(1);

	ofstream fout;
	fout.open("temp.log");




	cout << "请输入绝对距离:" << endl;
	int sum_miles;
	int step;


	double ang;
	while(cin >> sum_miles){
		cout << "请输入要每步的距离:";

		if(!(cin >> step)){
			if(!cin)
				break;


		}
		cout <<"目标距离:" << sum_miles <<",每步距离:"<<step << endl;

		while(result.get_abs() < sum_miles){

			ang=rand() % 360;
			sleep(0.5);
			temp=Vector(step,ang,Vector::POL);
			result = result +temp;
			fout <<count+1<<" ,(x,y) = (" <<result.get_x() <<" , " << result.get_y() <<"  ), "<<"当前距离: "<<result.get_abs() << endl;
			//cout <<count+1<<" ,(x,y) = (" <<result.get_x() <<" , " << result.get_y() <<"  ), "<<"当前距离: "<<result.get_abs() << endl;
			count++;
		}

		
		cout <<"一共用了" << count << "到达目的距离" << sum_miles <<"\n";
		double per_step=result.get_abs() /count;
		cout <<"每步的距离:" <<per_step << endl;
		cout <<"当前坐标(x,y)= ("<< result.get_x() <<"," <<result.get_y() <<" )\nor\n";
		cout <<"当前坐标(m,a)= ("<< result.get_abs() <<"," <<result.get_angel() <<" )\n";
		
		result.reset(0,0);
		count=0;
		cout << "请输入绝对距离:" << endl;
		fout.close();


	}



	






	return 0;
}