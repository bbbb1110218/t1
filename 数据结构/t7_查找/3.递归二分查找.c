#include <stdio.h>
#include <stdlib.h>


//递归查找
int binary_search(int *p,int first,int last,int find);

int main(){
	int n,i;
	int *p;
	int find;
	int result;
	printf("请输入数组元素个数:\n");
	scanf("%d",&n);
	p=(int *)malloc(sizeof(int) * n);

	printf("请按照由小到大的顺序输入元素:\n");

	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}


	printf("请输入要查找的元素:\n");

	while(scanf("%d",&find) && find !=-1){	

		result=binary_search(p,0,n-1,find);

		if(result == -1)
			printf("Cant't find the element\n");
		else
			printf("find element in index #%d \n",result);
			

	
		printf("please enter the element you want to search:\n");

	}





	free(p);

	return 0;
}




//递归二分查找算法 应该提前设置好终止循环的条件
int binary_search(int *p,int first,int last,int find){

	if(first > last)
		return -1;
	int middle= (first+last)/2;

	if(p[middle] == find)
			return middle;
	else if(p[middle] > find)
			return binary_search(p,middle+1,last,find);
	else
			return binary_search(p,first,middle-1,find);


}