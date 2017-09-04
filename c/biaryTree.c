#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct biTNode
{
	char data;
	struct biTNode *lchild,*rchild;
}biTNode,*biTree;


/**
		在建立二叉树的时候，
			a
			/\
		   /  \
		  b    c
  		   \    \
			\	 \ 
			 d    e

因为程序中要知道叶子结点（终点），所以要将上面的二叉树变成扩展二叉树 (把叶子结点的孩子补成#, 用作标记),  扩展后就变成了：         

			a
			/\
		   /  \
		  b    c
  		 # \  # \
			\	 \ 
			 d    e
			# #  #  #

需要输入: ab#d##c#e##      (注意，输入后，按enter键即可)

*/			



void createBiTree(biTree &T)  
{  
    char c;  
    cin >> c;  
    if('#' == c)  
        T = NULL;  
    else  
    {  
        T= new biTNode;
        T->data = c;  
        createBiTree(T->lchild);  
        createBiTree(T->rchild);  
    }  
}  


void preOrder(biTree T){
	if(T!=NULL){
		printf("%c ", T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void inOrder(biTree T){
	if(T!=NULL){
		inOrder(T->lchild);
		printf("%c ", T->data);
		inOrder(T->rchild);
	}
}

void postOrder(biTree T){
	if(T!=NULL){
		postOrder(T->lchild);
		postOrder(T->rchild);
		printf("%c ", T->data);
	}
}


//中序遍历的非递归算法实现
//先扫描（并非访问）根节点的所有左节点并将她们一一进栈。然后出栈-个节点*p（显然*p没有左孩子节点或者左孩子节点已经被访问过了）
//则访问他。然后扫描该节点的右孩子节点，将其进栈，再扫描右孩子节点的所有左节点并一一进栈，如此继续，直到栈空为止。

#define MaxSize 50
#define ElemType biTree

typedef struct 
{
	ElemType data[MaxSize];
	int top;
}sqStack;

bool isEmpty(sqStack &stack){
	return stack.top==-1?true:false;
}

bool stackOverFlow(sqStack &stack){
	return stack.top+1==MaxSize?true:false;
}

void initStack(sqStack &stack){
	stack.top=-1;
}

bool push(sqStack &stack,ElemType x){
	if(stackOverFlow(stack)){
		return false;
	}
	stack.data[++stack.top]=x;
	return true;
}

bool pop(sqStack &stack,ElemType &x){
	if(isEmpty(stack)){
		return false;
	}	
	x=stack.data[stack.top--];
	return true;
}

bool getTop(sqStack &stack,ElemType &x){
	if(isEmpty(stack))
		return false;
	x=stack.data[stack.top];
	return true;

}

void _preOrder(biTree T){
	sqStack stack;
	initStack(stack);
	biTree p = T;
	push(stack,p);
	while(!isEmpty(stack)){
		pop(stack,p);
		printf("%c ",p->data);
		if(p->rchild)
			push(stack,p->rchild);
		if(p->lchild)
			push(stack,p->lchild);
	}
}


void _inOrder(biTree T){
	sqStack stack;
	initStack(stack);
	biTree p=T;
	while(p || !isEmpty(stack)){
		if(p){
			push(stack,p);
			p=p->lchild;
		}else{
			pop(stack,p);
			printf("%c ",p->data);
			p=p->rchild;
		}
	}
}

//先左，后右，再根。所以需要有一个辅助指针r，其指向最近访问过的节点。
void _postOrder(biTree T){
	sqStack stack;
	initStack(stack);
	biTree r=NULL;
	biTree p=T;
	while(p||!isEmpty(stack)){
		if(p){ //向左走到底。
			push(stack,p);
			p=p->lchild;
		}else{
			getTop(stack,p);
			if(p->rchild && r!=p->rchild ){//如果右孩子存在且未被访问。
				p=p->rchild;
				push(stack,p);
				p=p->lchild;//继续从这个节点从左走到底
			}else{
				pop(stack,p);
				printf("%c ",p->data);
				r=p;
				p=NULL;
			}
		}
	}
}





int main(int argc, char const *argv[])
{
	biTree tree;
	createBiTree(tree);
	printf("\n递归preorder:");
	preOrder(tree);
	printf("\n非递归preorder:");
	_preOrder(tree);
	printf("\n递归inOrder:");
	inOrder(tree);
	printf("\n非递归inOrder:");
	_inOrder(tree);
	printf("\n递归postOrder:");
	postOrder(tree);
	printf("\n非递归postOrder:");
	_postOrder(tree);
	printf("\n");

	return 0;
}