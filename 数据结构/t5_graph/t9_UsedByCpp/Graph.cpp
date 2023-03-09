#include <iostream>
#include <string>

const std::string info=" ----------------------------------\n1) Show all info\n2) add Edge\n3) Get Index By value\n4) Get Value by index\n5) Loop Simple the Node\n6) Deep LoopAll Node\n0)Exit the programe\n----------------------------------\n";


template<class T>
class Graph{

private:
	struct Edge {
		int dest;           // 目标节点的编号
    	struct Edge *next;  // 指向下一个边的指针
	};

	
	struct Node {
		T id;             // 节点
		struct Edge *edge;  // 指向第一条边的指针
	};

private:
	int num_nodes;			//元素个数量
	Node *nodes;			//节点表？
	int *flag;			//遍历的标志位
public:
	Graph(int num);
	~Graph();
	void ShowBase()const;
	void AddEdge(int FromIndex,int Toindex);
	void ShowAllByIndex()const;
private:
	void FillGraph(int n,T fvalue);
	Edge *CreateEdge(int index){
		Edge *edge=new Edge;
		edge->dest=index;
		edge->next=NULL;
		return edge;
	}
	void ResetFlag(){
		for(int i=0;i<num_nodes;i++)flag[i]=0;
	}
public:
	T GetValueByindex(int n){
		assert(n <num_nodes);
		return nodes[n].id;
	}

	int GetIndexByValue(T value){
		int i;
		for(i=0;i<num_nodes;i++){
			if(nodes[i].id ==value)
				return i;
		}
		return -1;
	}
	void ClearFlagLoopNode(int index);
	void LoopNode(int index);
	void DeepTraverseAll();

};


template<class T>
void
Graph<T>::FillGraph(int n,T fvalue){
	nodes[n].id=fvalue;
};


template<class T>
Graph<T>::Graph(int num):num_nodes(num){
	if(num==0){
		nodes=nullptr;
		flag=nullptr;
	}
	else{
		nodes=new Node[num];
		flag=new int[num];

		T temp;
		for(int i=0;i<num;i++){
			std::cout <<"Please Number #" << i<<" enter the value\n";
			std::cin >> temp;
			while(std::cin.get() !='\n');
			FillGraph(i,temp);

		}
		ResetFlag();//标志位清0
	}

};

template<class T>
Graph<T>::~Graph(){
	for(int i=0;i<num_nodes;i++){
		Edge* Tedge=nodes[i].edge;
		while(Tedge !=nullptr){
			Edge *t=Tedge;
			std::cout <<"To delete "<< t->dest << std::endl;
			Tedge=Tedge->next;
			delete t;
		}

	}
	std::cout <<"To delete self"<<std::endl;
	delete []nodes;


};

template<class T>
void
Graph<T>::ShowBase()const{
	std::cout <<"Graph Count:" << num_nodes << std::endl;
	for(int i=0;i<num_nodes;i++){
		std::cout << "index [" << i << "] :" << nodes[i].id << std::endl; 
	}

}

template<class T>
void
Graph<T>::AddEdge(int FromIndex,int Toindex){
	if(FromIndex <num_nodes && Toindex < num_nodes && FromIndex != Toindex){ //检查边界
		Edge *Tedge=CreateEdge(Toindex);
		Tedge->next=nodes[FromIndex].edge;
		nodes[FromIndex].edge=Tedge;
	}else{
		std::cout <<"Out of range Or Two index can't be the same\n";
	} 

}


template<class T>
void 
Graph<T>::ShowAllByIndex()const{
	for(int i=0;i<num_nodes;i++){
		std::cout << "index [" << i << "] :" << nodes[i].id << " "; 
		Edge * Tedge=nodes[i].edge;
		while(Tedge != NULL){
			std::cout << Tedge->dest << " ";
			Tedge=Tedge->next;
		}
		std::cout << std::endl;

	}

}

template<class T>
void 
Graph<T>::DeepTraverseAll(){
	ResetFlag();
	for(int i=0;i<num_nodes;i++){
		LoopNode(i);
	}
}


template<class T>
void 
Graph<T>::ClearFlagLoopNode(int index){
	ResetFlag();
	LoopNode(index);
}


template<class T>
void 
Graph<T>::LoopNode(int index){
	if(flag[index]==0){
		flag[index]=1;
		std::cout << " ["<<nodes[index].id << "] "; //有可能是错的，打印两边自己
		Edge *current=nodes[index].edge;
		while(current !=nullptr){
			Edge *temp=current;
			LoopNode(temp->dest);
			current=current->next;
		}


	}

}

int Text_For_String(){

	Graph<std::string> gph(6);
	int choice;
	std::string tstr;
	int CheckInt;
	int result;
	
	std::cout <<info ;
	while(std::cin >> choice && choice !=0){
		switch(choice){
		case 1:
			gph.ShowAllByIndex();
			break;
		case 2:
			int fromindex,toindex;
			std::cout << "please enter the fromindex and toindex:\n";
			std::cin >> fromindex >> toindex;
			gph.AddEdge(fromindex,toindex);
			break;
		case 3:
			std::cout << "please enter the value:\n";
			std::cin >> tstr;
			while(std::cin.get() !='\n');
			result=gph.GetIndexByValue(tstr);
			if(result !=-1)
				std::cout << "Index :" << result << std::endl;
			else
				std::cout << "Input error,Cant't find any info\n";
			break;
		case 4:
			
			std::cout << "please enter the Index To get value:\n";
			std::cin >> CheckInt;
			while(std::cin.get() !='\n');
			std::cout << gph.GetValueByindex(CheckInt) << std::endl;
			break;


		case 5:
			std::cout << "Please enter the loop node\n";
			std::cin >> CheckInt;

			while(std::cin.get() !='\n');
			gph.ClearFlagLoopNode(CheckInt);
			break;
		case 6:
			gph.DeepTraverseAll();
			break;

		default:
			break;
		}
		std::cout <<info ;
	}

	return 0;
}



int main(){
	// Text_For_String();
	
	return Text_For_String(); 
}



