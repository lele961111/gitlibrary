#include<iostream>
#include<malloc.h>
#include<stdlib.h>
using namespace std;

/*
	��ָoffer ������8 ����������һ���ڵ�
	��Ŀ��
		����һ�ö����������е�һ���ڵ㣬����ҳ�����������е���һ���ڵ㣿���ֵĽڵ�����������ֱ�ָ�������ӽڵ��ָ�룬����һ��ָ�򸸽ڵ��ָ�롣
	������
		����Ҫ֪������������ȷ������ӽڵ㣬�ٷ��ʸ��ڵ㣬���������ӽڵ㣬����һ���ڵ����һ���ڵ������ֿ��ܣ��ٵ�����ڵ������ӽڵ�ʱ�������������������ӽڵ������һ���ڵ㣻
		�ڵ�����ڵ�û�����ӽڵ㲢���Ǹ��ڵ�����ӽڵ�ʱ�����ڵ���������ӽڵ㣻�۵�����ڵ�û�����ӽڵ㲢���Ǹ��ڵ�����ӽڵ�ʱ���򸸽ڵ�����ҵ����ڵ���Ϊ�丸�ڵ�����ӽڵ�ʱ���ø��ڵ������һ���ڵ㡣
		�ڶ��ֺ͵�������ʵ�����Թ�Ϊһ�ࣺ���ýڵ�û�����ӽڵ�ʱ����ֻ��Ҫ�жϵ�ǰ�ڵ��Ƿ��Ǹ��ڵ�����ӽڵ㼴�ɣ����򸸽ڵ������һ���ڵ㣬���������ϱ�����

*/

struct BinaryTreeNode{ //����������
	char m_nValue;
	BinaryTreeNode* m_pParents;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
}*Thead;


char pb[9]={'a','b','d','e','h','i','c','f','g'};
char pc[9]={'d','b','h','e','i','a','f','c','g'};

//����������7��������
BinaryTreeNode* findroot(int leftpb,int rightpb,int leftpc,int rightpc,BinaryTreeNode* head){//leftpb����������ǰ��������е����±꣬rightpb����������ǰ��������е�β�±�
																		//leftpc    ��    ����                  rightpb    ��    ����
	int i=0;
	for(;pb[leftpb]!=pc[leftpc+i]&&leftpc+i<=rightpc;i++);
	if(leftpc+i>rightpc){//ǰ���������������������в�ƥ���ж�
		cout<<"ǰ���������������������в�ƥ��"<<endl;
		throw std::exception("ǰ���������������������в�ƥ��"); //���ﴴ�����쳣��ֱ��������ȵݹ�
		
	}
	//�õ�i Ϊ�������ĸ���
	BinaryTreeNode* root=new BinaryTreeNode();
	root->m_nValue=pb[leftpb];
	root->m_pParents=head;
	root->m_pLeft=root->m_pRight=NULL;
//	cout<<"ֵΪ��"<<root->m_nValue<<endl;
	if(i!=0){ //��������������ݹ�
		root->m_pLeft=findroot(leftpb+1,leftpb+i,leftpc,leftpc+i-1,root);
	}
	if(leftpb+i+1<=rightpb){//��������������ݹ�
		
		root->m_pRight=findroot(leftpb+i+1,rightpb,leftpc+i+1,rightpc,root);
	}
	return root;	
}



//������������������Ƿ񽨳ɹ�
void PreOrderTraverse(BinaryTreeNode *T){
    if(T){
       printf("%c",T->m_nValue);
       PreOrderTraverse(T->m_pLeft);
       PreOrderTraverse(T->m_pRight);
    }
}


BinaryTreeNode *t=NULL;
void getpNode(BinaryTreeNode *T,char ch){ //��ȡ�ڵ�ָ��
	if(T){
		if(T->m_nValue==ch){
			t=T;
		}
       getpNode(T->m_pLeft,ch);
       getpNode(T->m_pRight,ch);
    }
}

void getNext(BinaryTreeNode *T){//�õ���һ���ڵ��ֵ
	if(T){
		if(T->m_pRight){
			T=T->m_pRight;
			while(T->m_pLeft){
				T=T->m_pLeft;
			}
			cout<<"��һ���ڵ�Ϊ��"<<T->m_nValue<<endl;
		}else{
			while(T->m_pParents->m_pLeft!=T){
				T=T->m_pParents;
			}
			cout<<"��һ���ڵ�Ϊ��"<<T->m_pParents->m_nValue<<endl;
		}
	}else{
		cout<<"��֪�ڵ��쳣"<<endl;
	}

}

int main(void){
	BinaryTreeNode* root=NULL;
	root=findroot(0,8,0,8,root);
	cout<<"������ڵ�valueֵ��a,b,c,d,e,f,g,h,i���е�һ����"<<endl;
	char ch;
	cin>>ch;
	getpNode(root,ch);
	cout<<"t��value="<<t->m_nValue<<endl;
	getNext(t);
	cout<<endl;
	PreOrderTraverse(root);
	return 0;
}








