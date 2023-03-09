#include <stdio.h>
#include <stdlib.h>



int binary_search(int *p,int n,int find);

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

		result=binary_search(p,n,find);

		if(result == -1)
			printf("Cant't find the element\n");
		else
			printf("find element in index #%d \n",result);
			

	
		printf("please enter the element you want to search:\n");

	}





	free(p);

	return 0;
}





int binary_search(int *p,int n,int find){

	int start =0;
	int end=n-1; //end为最后的索引，应该是元素个数减去1
	int middle;  //中间的数 
	int count=0;


	while(start <= end){

		middle =(start+end)/2;
		printf("第[%d]次 开始[%d] end[%d] 中间[%d]\n",count,start,end,middle);
		count++;
		

		if(p[middle] ==find){
			printf("查找次:[%d]",count);
			return middle;
		}else if(p[middle] >find){
			end  =  middle-1;
		}else
			start = middle +1;
			
		



	}
	printf("查找次:[%d]\n",count);
	return -1;

}