#include<iostream>
#include<malloc.h>
#include<stdlib.h>
using namespace std;

/*
	剑指offer 面试题18 删除链表的节点
	题目：在O(1)时间内删除链表节点
		给定单向链表的头指针和一个节点指针，定义一个函数在O(1)时间内删除该节点。
	解析：
		根据节点找到前一个节点是需要遍历得到的，而找到后一个节点只需要 节点指针的next，通过将后一节点的值付给当前节点，删掉后一节点就可完成要求。
		
	
*/


typedef struct ListNode{ //定义链表结点
	int m_nValue;
	ListNode* m_pNext;
}PNode,*PLinklist;
PNode *pdelete;

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
			pTemp->m_nValue=i;
			pTemp->m_pNext=NULL;
			pHead->m_pNext=pTemp;
			pHead=pTemp;
			if(i==5){
				pdelete=pHead;
				cout<<"需要删除的节点："<<pdelete->m_nValue<<endl;
			}
		}else{
			return 0;
		}
	}
	return 1;
}

//删除节点
void DeleteNode(ListNode** pListHead,ListNode* pToBeDeleted){
	if(!pListHead||!pToBeDeleted){
		return ;
	}
	if(pToBeDeleted->m_pNext!=NULL){
		ListNode* pNext=pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue=pNext->m_nValue;
		pToBeDeleted->m_pNext=pNext->m_pNext;

		delete pNext;
		pNext=NULL;
	}
	//链表只要一个节点，删除头节点（也是尾节点）
	else if(*pListHead==pToBeDeleted){
		delete pToBeDeleted;
		pToBeDeleted=NULL;
		*pListHead=NULL;
	}
	//链表中有多个节点，删除尾节点
	else{
		ListNode *pNode=*pListHead;
		while(pNode->m_pNext!=pToBeDeleted){
			pNode=pNode->m_pNext;
		}
		pNode->m_pNext=NULL;
		delete pToBeDeleted;
		pToBeDeleted=NULL;
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
			cout<<pHead->m_nValue<<" ";
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
			DeleteNode(&list,pdelete);
			cout<<"新链表输出："<<endl;
			printlist(list);
		}else{
			cout<<"创建线性表有误"<<endl;
		}
	}else{
		cout<<"初始化链表失败"<<endl;
	}
	return 0;
}







