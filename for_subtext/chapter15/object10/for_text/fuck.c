#include <stdio.h>
// #include <malloc>

typedef struct stru{
    char name[200];
    int age;
    struct SS* next;
} spt;

struct stru *news=;

int con=0;

void set(spt* n){

    n=(void* )malloc(sizeof(spt));
    printf("enter your name:");
    puts(n->name);
    printf("Enter your age:");
    scanf("%d",&n->age);
    printf("conntinue to enter:");
    scanf("%d",&con);
    if(con)
        set(SS->next);
}

void clear(){
    spt* move;
    while(news !=NULL){
        move=news;
        news=news->next;
      

    }


}

int main(){
    set(news);
    clear();
    return 0;
}
