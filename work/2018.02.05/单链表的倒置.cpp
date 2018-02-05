#include<iostream>
#include <stdlib.h>
#include<string>
using namespace std;

/*
	�����������
	������֮ǰ�ù�ջ���Ƚ�����ص����������������ã�����õݹ�����
*/


typedef struct ListNode{ //����������
	int m_nKey;
	ListNode* m_pNext;
}PNode,*PLinklist;

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

void userecursive(ListNode *pHead){//ͨ���ݹ�ʵ��
	if(pHead->m_pNext!=NULL){//����ʵ�洢���ݵĽ�㿪ʼ�ж�
		pHead=pHead->m_pNext;		
		userecursive(pHead); //�ȵݹ�������Ϳ�ʵ�ַ������
		cout<<pHead->m_nKey<<" ";
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
			cout<<pHead->m_nKey<<" ";
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
			cout<<"ʹ�õݹ鷴���ӡ"<<endl;
			userecursive(list);
		}else{
			cout<<"�������Ա�����"<<endl;
		}
	}else{
		cout<<"��ʼ������ʧ��"<<endl;
	}
	return 0;
}