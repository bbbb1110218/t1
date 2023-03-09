#include <stdio.h>
#include <limits.h>

#define MAXINT INT_MAX
#define SIZE 5

int result[SIZE][SIZE];
int dis[SIZE];
int p[SIZE];

void showMatrix(int(*matrix)[SIZE],int x){
    for(int i=0;i<x;i++){
        for(int y=0;y<SIZE;y++){
            printf("%10d\t",matrix[i][y]);
        }
        printf("\n");
    }
    printf("\n");
}

void reset_disp(int *pdis,int count){
    for(int i=0;i<count;i++){
        pdis[i]=0;
    }
}

void Show_disp(int *p,int count){
    for(int i=0;i<count;i++){
       printf("%10d\t",p[i]);
    }
    printf("\n");
}






int main(){
    int MyMatrix[SIZE][SIZE]={{0,10,MAXINT,MAXINT,5},
                          {MAXINT,0,1,MAXINT,2},
                          {MAXINT,MAXINT,0,4,MAXINT},
                          {7,MAXINT,6,0,MAXINT},
                          {MAXINT,3,9,2,0}};


    return 0;
}