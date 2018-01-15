#include<iostream>
#include<stack>
#include<malloc.h>
#include<stdlib.h>
using namespace std;
/*
	��ָoffer ������6 ��β��ͷ��ӡ����
	��Ŀ��
		����һ�������ͷ�ڵ㣬��β��ͷ��������ӡ��ÿ���ڵ��ֵ�����������£� sturct ListNode{int m_nKey; ListNode* m_pNext;};
	������
		ͨ��ջ��ʵ��������⣬��Ϊջ�ǡ��Ƚ��ȳ�����������������ջ�У������ջ������ɷ����������
		�����Ҳ�����õݹ���ʵ�֣��ݹ鱾���Ͼ���һ��ջ�ṹ��ֻ���ȵݹ����������ʵ�ַ��������
		ʹ�õݹ����ֵ����⣺������ǳ�����ʱ�򣬾ͻᵼ�º������õĲ㼶����п��ܵ��º�������ջ�����
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

void usestack(ListNode *pHead){//ͨ��ʹ��ջ����Ƚ����
	std::stack<ListNode*> nodes; //����ջ
	ListNode* pNode=pHead->m_pNext;//�������Ա�ͷָ��ָ����Ǳ�ͷ��㣬�����ڱ�ͷ����ߣ�������ָ��ָ��ͷ������һ�����
	while(pNode!=NULL){ //��ջ
		nodes.push(pNode);
		pNode=pNode->m_pNext;
	}
	while(!nodes.empty()){//��ջ
		pNode=nodes.top();
		cout<<pNode->m_nKey<<" ";
		nodes.pop();
	}
	cout<<endl;
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
			cout<<"ʹ��ջ�����ӡ"<<endl;
			usestack(list);
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
