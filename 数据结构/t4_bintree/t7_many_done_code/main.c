
/*

text input: 	abd##e##cf#g###

*/

#include <stdio.h>
#include <stdlib.h>

typedef char ValueType;

struct BINARY_TREE{
	ValueType item;
	int lflag;
	int rflag;
	struct BINARY_TREE *ltree;
	struct BINARY_TREE *rtree;
};

struct BINARY_TREE *pre=NULL;//全局节点
struct BINARY_TREE *create_tree();
void ShowNode(struct BINARY_TREE * treeNode);		//显示单个节点
void ShowTreePre(struct BINARY_TREE * treeStart); //先序查看
void ShowTreeMid(struct BINARY_TREE * treeStart); //中序查看
void ShowTreePost(struct BINARY_TREE * treeStart); //后序查看
void SortTree(struct BINARY_TREE *treeStart);		//递归序列化二叉树
void SortTreeAddEnd(struct BINARY_TREE *treeStart);//给序列化二叉树加个尾巴
void ShowSortTreePre(struct BINARY_TREE *treeStart);// 显示序列化后的二叉树::TODO error
void traverse_thread(struct BINARY_TREE *treeStart);// 显示序列化后的二叉树
struct BINARY_TREE *Search_inorder_Thread(struct BINARY_TREE * treeStart,ValueType ch);//二叉树中找字符 返回所在的节点
struct BINARY_TREE *Find_Pre_Node(const struct BINARY_TREE * node);// 找到node的前驱点
struct BINARY_TREE *Find_Post_Node(const struct BINARY_TREE * node);// 找到node的后驱点






int main(){
	ValueType ch;
	struct BINARY_TREE *current,*pre,*post;//要找到的节点，前驱点，后驱点
	printf("Please enter the item for pre_顺序，# for null:\n");
	struct BINARY_TREE * mytree=create_tree();
	ShowTreePre(mytree);
	printf("\n");
	ShowTreeMid(mytree);
	printf("\n");
	ShowTreePost(mytree);
	printf("\n");
	SortTreeAddEnd(mytree);
	
	printf("\n");
	printf("traverse_thread later; \n");
	traverse_thread(mytree);
	printf("\n");

	
	
	printf("please enter your want to find the element:\n");


	while(getchar()!='\n');

	while((ch=getchar()) && (ch !='#')){

		current=Search_inorder_Thread(mytree,ch); //找到的节点
		printf("current:[%c]\n",current->item);
		pre=Find_Pre_Node(current);					//当前节点的前驱点
		if(pre)
			printf("pre:[%c]\n",pre->item);
		else
			printf("pre data NONE\n");
		post=Find_Post_Node(current);				//当前节点的后驱点
		if(post)
			printf("post:[%c]\n",post->item);
		else
			printf("post data NONE\n");
		printf("please enter your want to find the element:\n");
		while(getchar()!='\n');
	}


	





	



	return 0;
}

void ShowNode(struct BINARY_TREE * treeNode){
	if(treeNode){
		printf("-----------\n");

		printf("item:%c\n",treeNode->item);
		printf("lflag:%d\n",treeNode->lflag);
		printf("rflag:%d\n",treeNode->lflag);
		if(treeNode->ltree)
			printf("ltree:%p\n",treeNode->ltree);
		else
			printf("ltree: NULL\n");

		if(treeNode->rtree)
			printf("rtree:%p\n",treeNode->rtree);
		else
			printf("ltree: NULL\n");

		printf("-----------\n");
	}else
		printf("No data\n");
}


struct BINARY_TREE *create_tree(){
	struct BINARY_TREE *ptree;
	
	ValueType ch;
	ch=getchar();
	
	if(ch =='#'){
		ptree=NULL;
	}else{
		ptree=(struct BINARY_TREE *)malloc(sizeof(struct BINARY_TREE));
		ptree->item = ch;
		ptree->ltree =ptree->rtree =0;
		ptree->ltree=create_tree();
		ptree->rtree=create_tree();
	}
	return ptree;
}

void ShowTreePre(struct BINARY_TREE * treeStart){
	if(treeStart){
		printf("%c -> ",treeStart->item);
		ShowTreePre(treeStart->ltree);
		ShowTreePre(treeStart->rtree);
	}

}

void ShowTreeMid(struct BINARY_TREE * treeStart){
	if(treeStart){
		ShowTreeMid(treeStart->ltree);
		printf("%c -> ",treeStart->item);
		ShowTreeMid(treeStart->rtree);
	}

}

void ShowTreePost(struct BINARY_TREE * treeStart){
	if(treeStart){
		ShowTreePost(treeStart->ltree);	
		ShowTreePost(treeStart->rtree);
		printf("%c -> ",treeStart->item);
	}
}

void SortTree(struct BINARY_TREE *treeStart){
	if(treeStart){
		SortTree(treeStart->ltree);


		if(treeStart->ltree ==NULL){ //判断是不是叶子节点 叶子节点 为NULL 
			treeStart->lflag=1;		
			treeStart->ltree=pre;
		}else
			treeStart->lflag=0;	


		if(pre){		//操作上一个节点
			if(pre->rtree ==NULL){
				pre->rflag=1;			
				pre->rtree=treeStart;
			}else
				pre->rflag=0;

		}
		pre=treeStart; //更新上一个节点

		SortTree(treeStart->rtree);
	}

}
void SortTreeAddEnd(struct BINARY_TREE *treeStart){
	if(treeStart){
		SortTree(treeStart);
		pre->rflag=1;
		pre->rtree=NULL;

	}
}

void ShowSortTreePre(struct BINARY_TREE *treeStart){ //ERROR

	if(treeStart){
		if(treeStart->lflag ==0)
			printf("%c -> ",treeStart->item);
		ShowTreePre(treeStart->ltree);
		if(treeStart->rflag ==0)
			ShowTreePre(treeStart->rtree);
	}
}

void traverse_thread(struct BINARY_TREE *treeStart){
	while(treeStart){
		while(treeStart->lflag ==0){
			treeStart =treeStart->ltree;
		}
		printf("[%c]->",treeStart->item);

		while((treeStart->rflag ==1) && treeStart->rtree){
			treeStart =treeStart->rtree;
			printf("[%c]->",treeStart->item);

		}
		treeStart =treeStart->rtree;
	}

}

struct BINARY_TREE *Search_inorder_Thread(struct BINARY_TREE * treeStart,ValueType ch){
	while(treeStart){
		while(treeStart->lflag ==0){
			treeStart =treeStart->ltree;
		}
		//printf("[%c]->",treeStart->item);
		if(treeStart->item == ch)
			return treeStart;

		while((treeStart->rflag ==1) && treeStart->rtree){
			treeStart =treeStart->rtree;
			if(treeStart->item == ch)
				return treeStart;

		}
		treeStart =treeStart->rtree;
	}
	return NULL; //没找到返回的结果

}

struct BINARY_TREE *Find_Pre_Node(const struct BINARY_TREE * node)// 找到node的前驱点
{	
	struct BINARY_TREE *result;	//接收返回值 不能改变要查找的值

	if(node->lflag ==1)		//之前的叶子节点
		return node->ltree; 
	else					//找左子树的最右下节点
	{	

		result=node->ltree;			//先等于左节点
		while(result->rflag==0)		//普通节点 rflag=0
			result=result->rtree;		
									//跳出rflag=0，此时flag=1;为查找的节点的最右边节点
		return result;
	}
}



struct BINARY_TREE *Find_Post_Node(const struct BINARY_TREE * node){// 找到node的后驱点
	struct BINARY_TREE *result;
	if(node->rflag)					//如果node->rflag==1 ,说明右边是叶子节点
		return node->rtree;
	else{							//就是正常节点,后驱点是右子树的最左边节点
		result=node->rtree;
		while(result->lflag==0)			
			result=result->ltree;
		return result;				//此时的lfag=1

	}

}



