#include<iostream>
#include <stdlib.h>
#include<string>
using namespace std;

/*
	单链表的逆置
	解析：之前用过栈的先进后出特点来解决单链表的逆置，这次用递归解决。
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