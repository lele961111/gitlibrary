#include<iostream>
#include<stack>
#include<malloc.h>
#include<stdlib.h>
using namespace std;
/*
	剑指offer 面试题6 从尾到头打印链表
	题目：
		输入一个链表的头节点，从尾到头反过来打印出每个节点的值。链表定义如下： sturct ListNode{int m_nKey; ListNode* m_pNext;};
	解析：
		通过栈来实现这个问题，因为栈是“先进先出”，遍历链表，存入栈中，再输出栈就能完成反向输出链表。
		这道题也可以用递归来实现，递归本质上就是一个栈结构，只需先递归再输出即可实现反向输出。
		使用递归会出现的问题：当链表非常长的时候，就会导致函数调用的层级很深，有可能导致函数调用栈溢出。
*/

typedef struct ListNode{ //定义链表结点
	int m_nKey;
	ListNode* m_pNext;
}PNode,*PLinklist;

int initlist(PLinklist *head){	//初始化线性表，让链表的表头指针为空
	*head=(PLinklist)malloc(sizeof(PNode));
	if(*head){
		(*head)->m_pNext=NULL;
		return 1;
	}
	else{
		return 0;
	}	
}

int createlist(PLinklist *head){ //创建线性表，挂链
	PNode *pTemp,*pHead;
	pHead=*head;
	for(int i=0;i<10;i++){
		pTemp=(PLinklist)malloc(sizeof(PNode));
		if(pTemp){
			pTemp->m_nKey=i;
			pTemp->m_pNext=NULL;
			pHead->m_pNext=pTemp;
			pHead=pTemp;
		}else{
			return 0;
		}
	}
	return 1;
}

void usestack(ListNode *pHead){//通过使用栈完成先进后出
	std::stack<ListNode*> nodes; //创建栈
	ListNode* pNode=pHead->m_pNext;//由于线性表头指针指向的是表头结点，数据在表头结点后边，所以让指针指向头结点的下一个结点
	while(pNode!=NULL){ //入栈
		nodes.push(pNode);
		pNode=pNode->m_pNext;
	}
	while(!nodes.empty()){//出栈
		pNode=nodes.top();
		cout<<pNode->m_nKey<<" ";
		nodes.pop();
	}
	cout<<endl;
}

void userecursive(ListNode *pHead){//通过递归实现
	if(pHead->m_pNext!=NULL){//从真实存储数据的结点开始判断
		pHead=pHead->m_pNext;		
		userecursive(pHead); //先递归在输出就可实现反向输出
		cout<<pHead->m_nKey<<" ";
	}
}

//打印链表，链表的遍历
void printlist(ListNode *pHead){
	if(NULL==pHead) //链表为空
	{
		cout<<"链表为空"<<endl;
	}else{
		while(NULL!=pHead->m_pNext){
			pHead=pHead->m_pNext;
			cout<<pHead->m_nKey<<" ";
		}
		cout<<endl;
	}
}

int main(void){
	PLinklist list;
	if(initlist(&list)==1){
		if(createlist(&list)==1){
			cout<<"原链表输出："<<endl;
			printlist(list);
			cout<<"使用栈反向打印"<<endl;
			usestack(list);
			cout<<"使用递归反向打印"<<endl;
			userecursive(list);
		}else{
			cout<<"创建线性表有误"<<endl;
		}
	}else{
		cout<<"初始化链表失败"<<endl;
	}
	return 0;
}
