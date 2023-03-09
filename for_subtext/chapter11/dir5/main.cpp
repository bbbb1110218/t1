#include "vector.h"
#include <cstdlib>
#include <ctime>


int main(){
	using namespace VECTOR;
	srand(time(NULL));



	double target;
	double dstep;
	double direction;

	int StepCount=0;

	Vector result(0.0,0.0,VECTOR::Vector::RECT);
	Vector temp;

	cout <<"Enter target diistance(q to quit):";


	while(cin >> target){
		cout <<"Enter the step length:";

		if(cin >> dstep)
			break;

		while(result.absval() < target){
			direction=rand() % 360;
			temp.resett(dstep,direction,VECTOR::Vector::POL);
			target += temp;
			StepCount++;
		}

		cout <<"一共走了" << dstep << "到达目标 " << target << "距离\n";

		target.resett(0.0,0.0,VECTOR::Vector::RECT);



		cout <<"Enter target diistance(q to quit):";

	}

	return 0;
} 