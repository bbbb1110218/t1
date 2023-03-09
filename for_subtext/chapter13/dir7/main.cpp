#include "dma.h"


int main(){
	hasDMA map("keys",5,"mercator");
	hasDMA map2(map,"NEW");
	cout << map2;


	return 0;
}