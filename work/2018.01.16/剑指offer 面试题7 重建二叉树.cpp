#include<iostream>
#include<malloc.h>
#include<stdlib.h>
using namespace std;

/*
	��ָoffer ������7 �ؽ�������
	��Ŀ��
		����ĳ��������ǰ���������������Ľ�������ؽ��ö����������������ǰ���������������Ľ���ж������ظ������֡�
	���磬����ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}���ؽ����������������ͷ��㡣
	������
		�տ���������ʱ����û�н��˼·�ģ���Ϊ��Ȼ��֪ǰ���������������Ϳ�������˶���������ǰ�������������������Ϲ�ϵҲ����û�����֡�
	������ϸ����ǰ������������������ͻᷢ�����������ɣ����ȣ�ǰ����������ȷ��ʸ��ڵ㣬�ٷ��������ӽڵ㣻������������ȷ������ӽڵ㣬�ٷ��ʸ��ڵ㣬�ٷ������ӽڵ㡣
	ǰ������ĵ�һ�����Ǹ��ڵ㣬����������и��ڵ���߶������������ұ߶�������������������������������ڵ�ĸ����Ϳ��Էֳ�ǰ������е�����������������
	�������õݹ�ÿ�ζ���������ĸ��ڵ㲢�ж����ҽ����й������Ϳ�������ؽ��������Ĺ����������� ͨ����������������Ƿ�ɹ���
	
*/


struct BinaryTreeNode{ //����������
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

int n,*pb,*pc;
int i=0;
void init(){
	cout<<"������������:";
	cin>>n;
	cout<<endl;
	pb=(int*)malloc(n*sizeof(int));
	pc=(int*)malloc(n*sizeof(int));
	cout<<"������ǰ��������У�"<<endl;
	for(i=0;i<n;i++){
		cin>>pb[i];
	}
	cout<<"����������������У�"<<endl;
	for(i=0;i<n;i++){
		cin>>pc[i];
	}
}

void print(){
	for(i=0;i<n;i++){
		cout<<pb[i];
	}
	cout<<endl;
	for(i=0;i<n;i++){
		cout<<pc[i];
	}
	cout<<endl;
}

BinaryTreeNode* findroot(int leftpb,int rightpb,int leftpc,int rightpc){//leftpb����������ǰ��������е����±꣬rightpb����������ǰ��������е�β�±�
																		//leftpc    ��    ����                  rightpb    ��    ����
	cout<<"����ݹ�"<<endl;
	int i=0;
	for(;pb[leftpb]!=pc[leftpc+i]&&leftpc+i<=rightpc;i++);
	if(leftpc+i>rightpc){//ǰ���������������������в�ƥ���ж�
		cout<<"ǰ���������������������в�ƥ��"<<endl;
		throw std::exception("ǰ���������������������в�ƥ��"); //���ﴴ�����쳣��ֱ��������ȵݹ�
		
	}
	cout<<"�������ĸ�����"<<endl;
	//�õ�i Ϊ�������ĸ���
	BinaryTreeNode* root=new BinaryTreeNode();
	root->m_nValue=pb[leftpb];
	root->m_pLeft=root->m_pRight=NULL;
	cout<<"ֵΪ��"<<root->m_nValue<<endl;
	if(i!=0){ //��������������ݹ�
		cout<<"��������"<<endl;
		root->m_pLeft=findroot(leftpb+1,leftpb+i,leftpc,leftpc+i-1);
	}
	if(leftpb+i+1<=rightpb){//��������������ݹ�
		cout<<"��������"<<endl;
		root->m_pRight=findroot(leftpb+i+1,rightpb,leftpc+i+1,rightpc);
	}
	cout<<"����root"<<endl;
	return root;	
}

void aftertraverse(BinaryTreeNode* root){ //�������������Ƿ�ɹ�
	if(root->m_pLeft!=NULL){
		//��������
		aftertraverse(root->m_pLeft);
	}
	if(root->m_pRight!=NULL){
		//�����ҽ��
		aftertraverse(root->m_pRight);
	}	
	cout<<root->m_nValue;
	
}

int main(void){
	init();
	if(n>0){
		print();
		BinaryTreeNode* root=findroot(0,n-1,0,n-1);
		aftertraverse(root);
		cout<<endl;
	}
	else{
		cout<<"�������������"<<endl;
	}
	return 0;
}

