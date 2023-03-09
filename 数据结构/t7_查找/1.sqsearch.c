#include <stdio.h>
#include <stdlib.h>



int sqsearch(int *p,int n,int find);


int main(){
	int n,i;
	int *p;
	int find;
	int result;
	printf("please enter the number of your data\n");
	scanf("%d",&n);
	p=(int *)malloc(sizeof(int) * (n+1));

	printf("Please enter element of your data\n");

	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}


	printf("please enter the element you want to search:\n");

	while(scanf("%d",&find) && find !=-1){	

		result=sqsearch(p,n,find);

		if(result == n)
			printf("Cant't find the element\n");
		else
			printf("find element in index #%d\n",result);
			

	
		printf("please enter the element you want to search:\n");

	}





	free(p);

	return 0;
}


int sqsearch(int *p,int n,int find){
	p[n]=find;
	int i=0;
	while(p[i] !=find) i++;
	return i;
}