#include<iostream>
#include<stdio.h>
using namespace std;
#define MaxSize 50

typedef struct
{
	int data[MaxSize];
	int length;
}SqList;

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

bool listInsert(SqList &L,int i,int e){
	if(i<1 || i>L.length+1){
		return false;
	}
	if(L.length>=MaxSize){
		return false;
	}
	for(int j=L.length;j>=i;j--){
		L.data[i]=L.data[i-1];
	}
	L.data[i-1]=e;
	L.length++;
	return true;
}

void pirntList(SqList &list){
	for(int i=0;i<list.length;i++){
		if(i==list.length-1)
			cout<<list.data[i];
		else
			cout<<list.data[i]<<',';
	}
	
}

bool listDelete(SqList &L,int i,int &e){
	if(i<1||i>L.length){
		return false;
	}
	e=L.data[i-1];
	for(int j=i;i<L.length;i++){
		L.data[i-1]=L.data[i];
	}
	L.length--;
	return true;
}

void listReverse(SqList &L){
	if(L.length==0)
		return;
	for(int i=0;i<L.length/2;i++){
		int tmp=L.data[i];
		L.data[i] = L.data[L.length-1-i];
		L.data[L.length-1-i]=tmp;
	}
}

void deleteX(SqList &L,int x){
	int k=0;//k用来统计不等于x的个数
	for(int i=0;i<L.length;i++){
		if(L.data[i]!=x){
			k++;
			if(k-1!=i){
				L.data[k-1]=L.data[i];
			}
			
		}
	}
	L.length=k;
}

void deleteX2(SqList &L,int x){
	int k=0;//k用来统计等与x的个数，对于不等于x的数，前移k个位置。
	for(int i=0;i<L.length;i++){
		if(L.data[i]==x){
			k++;
		}else{
			L.data[i-k]=L.data[i];
		}
	}
	L.length=L.length-k;
}

bool delete_s_t(SqList &L,int s,int t){
	if(L.length==0 || s>=t){
		return false;
	}
	int k=0;//统计不在s与t之间的数字
	for(int i=0;i<L.length;i++){
		if(!(L.data[i]>=s && L.data[i]<=t)){
			k++;
			L.data[k-1]=L.data[i];
		}
	}
	L.length=k;
	return true;

}

bool delete_same(SqList &L){
	if(L.length==0)
		return false;
	int i,j; //i存储第一个非重复的元素，j为工作指针
	for(i=0,j=1;j<L.length;j++){
		if(L.data[i]!=L.data[j])
			L.data[++i]=L.data[j];
	}
	L.length=i+1;
	return true;
}

bool merge(SqList A,SqList B,SqList &C){
	int i=0,j=0,k=0;
	while(i<A.length&&j<B.length){
		int res=0;
		if(A.data[i]<B.data[j]){
			res=A.data[i++];
		}else{
			res=B.data[j++];
		}
		C.data[k++]=res;
	}
	while(i<A.length){
		C.data[k++]=A.data[i++];
	}
	while(j<B.length){
		C.data[k++]=B.data[j++];
	}
	C.length=A.length+B.length;
	return true;
}

typedef int DateType;

void reverse(DateType A[],int left,int right,int length){
	if(left>=right || right>=length)
		return;
	int mid = (left+right)/2;
	for(int i=0;i<=mid-left;i++){
		int tmp = A[left+i];
		A[left+i] = A[right-i];
		A[right-i]=tmp;
	}
	return;
}

//头插法简历链表

LinkList createList(LinkList &L){
	//每次都是在头节点插入元素
	LNode *s;int x;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	scanf("%d",&x);
	while(x!=9999){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next;
		L->next=s;
		scanf("%d",&x);
	}
	return L;
}


void reverseMain(DateType A[],int m,int n,int length){
	reverse(A,0,m+n-1,length);
	reverse(A,0,m-1,length);
	reverse(A,m,m+n-1,length);
}

int main(){

	LinkList list;
	createList(list);
	cout<<list->next->next->data<<endl;



	SqList listA,listB,listC;
	for(int i=0;i<11;i++){
		listInsert(listA,i+1,i);
	}
	for(int i=0;i<20;i++){
		listInsert(listB,i+1,i);
	}
	cout<<"before delete"<<endl;
	//pirntList(list);
	//listReverse(list);
	merge(listA,listB,listC);
	cout<<"after"<<endl;
	pirntList(listC);
	cout<<listC.length<<endl;

	int a[] = {1,1,1,1,1,1,2,2,2,2,2,2};
	reverseMain(a,6,6,12);
	for(int i=0;i<12;i++){
		cout<<a[i];
	}
	cout<<endl;

	return 0;
}