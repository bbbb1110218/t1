#include <iostream>
#include <vector>
#include <valarray>
#include <algorithm>
using namespace std;


void Show(double x)
{cout << x << " ";
}




int main(){
	double temp;
	vector<double> data;
	cout << "Enter numbers(must bigger than 0)" << endl;
	while(cin >> temp && temp > 0)
		data.push_back(temp);

	sort(data.begin(),data.end());
	int size=data.size();

	int i;


	valarray<double> numbers(size);
	
	for(int i=0;i<size;i++){
		numbers[i]=data[i];
	}

	valarray<double> result(size);
	result =numbers + 2.0;

	for(i=0;i<size;i++){
		Show(result[i]);
	}

	valarray<double> arr= result >9;






	return 0;
}