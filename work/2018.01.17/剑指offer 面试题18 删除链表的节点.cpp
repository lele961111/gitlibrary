#include<iostream>
#include<malloc.h>
#include<stdlib.h>
using namespace std;

/*
	��ָoffer ������18 ɾ������Ľڵ�
	��Ŀ����O(1)ʱ����ɾ������ڵ�
		�������������ͷָ���һ���ڵ�ָ�룬����һ��������O(1)ʱ����ɾ���ýڵ㡣
	������
		���ݽڵ��ҵ�ǰһ���ڵ�����Ҫ�����õ��ģ����ҵ���һ���ڵ�ֻ��Ҫ �ڵ�ָ���next��ͨ������һ�ڵ��ֵ������ǰ�ڵ㣬ɾ����һ�ڵ�Ϳ����Ҫ��
		
	
*/


typedef struct ListNode{ //����������
	int m_nValue;
	ListNode* m_pNext;
}PNode,*PLinklist;
PNode *pdelete;

int initlist(PLinklist *head){	//��ʼ�����Ա�������ı�ͷָ��Ϊ��
	*head=(PLinklist)malloc(sizeof(PNode));
	if(*head){
		(*head)->m_pNext=NULL;
		return 1;
	}
	else{
		return 0;
	}	
}

int createlist(PLinklist *head){ //�������Ա�����
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
				cout<<"��Ҫɾ���Ľڵ㣺"<<pdelete->m_nValue<<endl;
			}
		}else{
			return 0;
		}
	}
	return 1;
}

//ɾ���ڵ�
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
	//����ֻҪһ���ڵ㣬ɾ��ͷ�ڵ㣨Ҳ��β�ڵ㣩
	else if(*pListHead==pToBeDeleted){
		delete pToBeDeleted;
		pToBeDeleted=NULL;
		*pListHead=NULL;
	}
	//�������ж���ڵ㣬ɾ��β�ڵ�
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


//��ӡ��������ı���
void printlist(ListNode *pHead){
	if(NULL==pHead) //����Ϊ��
	{
		cout<<"����Ϊ��"<<endl;
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
			cout<<"ԭ���������"<<endl;
			printlist(list);
			DeleteNode(&list,pdelete);
			cout<<"�����������"<<endl;
			printlist(list);
		}else{
			cout<<"�������Ա�����"<<endl;
		}
	}else{
		cout<<"��ʼ������ʧ��"<<endl;
	}
	return 0;
}







