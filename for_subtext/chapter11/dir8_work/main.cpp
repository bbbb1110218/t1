#include "vector.h"
#include <cmath>
#include <cstdlib>

int main(){
	using namespace VECTOR;
	srand(time(NULL));
	Vector result;
	cout << result <<endl;


	Vector temp;


	int count=0;

	cout << "请输入绝对距离:" << endl;
	int sum_miles;
	int step;

	double ang;

	double MAX,MIN;
	double *PMAX=&MAX;
	double *PMIN=&MIN;




	double tempabs;
	while(cin >> sum_miles){
		cout << "请输入要每步的距离:";

		if(!(cin >> step)){
			if(!cin)
				break;}



		cout <<"目标距离:" << sum_miles <<",每步距离:"<<step << endl;

		while(result.get_abs() < sum_miles){

			ang=rand() % 360;
			temp=Vector(step,ang,Vector::POL);

			tempabs =temp.get_x();

			if(count == 0){
				MAX = MIN = tempabs;
			}
			else
			{
				MAX = (tempabs >MAX) ? tempabs : MAX;
				MIN = (tempabs <MAX) ? tempabs : MIN;
			}

			result = result + temp;
			cout <<count+1<<" ,(x,y) = (" <<result.get_x() <<" , " << result.get_y() <<"  ), "<<"当前距离: "<<result.get_abs() << endl;
			count++;
		}
	
	

		cout <<"MAX STEP:"<< MAX <<",MIN STEP:" << MIN <<endl;
		cout <<"一共用了" << count << "到达目的距离" << sum_miles <<"\n";
		double per_step=result.get_abs() /count;
		cout <<"每步的距离:" <<per_step << endl;
		cout <<"当前坐标(x,y)= ("<< result.get_x() <<"," <<result.get_y() <<" )\nor\n";
		cout <<"当前坐标(m,a)= ("<< result.get_abs() <<"," <<result.get_angel() <<" )\n";
		
		result.reset(0,0);
		count=0;
		cout << "请输入绝对距离:" << endl;
	}



	return 0;
}