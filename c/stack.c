#include<iostream>
#include<stdio.h>
using namespace std;

/**
	验证括号的合法性
	本程序是利用栈来匹配括号。括号包括三种类型()，[],{}
*/
#define MaxSize 50

typedef struct 
{
	char data[MaxSize];
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

bool push(sqStack &stack,int x){
	if(stackOverFlow(stack)){
		return false;
	}
	stack.data[++stack.top]=x;
	return true;
}

bool pop(sqStack &stack,char &x){
	if(isEmpty(stack)){
		return false;
	}	
	x=stack.data[stack.top--];
	return true;
}


bool checkBracket(char * str){
	sqStack stack;
	initStack(stack);
	int i=0;
	char e;
	int len = strlen(str);
	for(i=0;i<len;i++){
		if(str[i]=='['){
			push(stack,str[i]);
			continue;
		}
		if(str[i]=='{'){
			push(stack,str[i]);
			continue;
		}
		if(str[i]=='('){
			push(stack,str[i]);
			continue;
		}
		if(str[i]==')'){
			pop(stack,e);
			if(e!='('){
				return false;
			}else{
				continue;
			}
		}
		if(str[i]=='}'){
			pop(stack,e);
			if(e!='{'){
				return false;
			}else{
				continue;
			}
		}
		if(str[i]==']'){
			pop(stack,e);
			if(e!='['){
				return false;
			}else{
				continue;
			}
		}
	}

	if(!isEmpty(stack)){
		printf("%s\n","括号不符合");
		return false;
	}else{
		printf("%s\n","括号匹配正确" );
		return true;
	}

}

int main()
{
	char str[]="[][]A+B[{[]]";
	bool flag = checkBracket(str);
	printf("%d\n", flag);
	return 0;
}