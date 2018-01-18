#include<iostream>
#include<malloc.h>
#include<stdlib.h>
using namespace std;

/*
	剑指offer 面试题8 二叉树的下一个节点
	题目：
		给定一棵二叉树和其中的一个节点，如何找出中序遍历序列的下一个节点？树种的节点除了有两个分别指向左、右子节点的指针，还有一个指向父节点的指针。
	解析：
		首先要知道中序遍历是先访问左子节点，再访问根节点，最后访问右子节点，所有一个节点的下一个节点有三种可能：①当这个节点有右子节点时，遍历右子树的最左子节点就是下一个节点；
		②当这个节点没有右子节点并且是父节点的左子节点时，父节点就是最左子节点；③当这个节点没有右子节点并且是父节点的右子节点时，向父节点遍历找到父节点作为其父节点的左子节点时，该父节点就是下一个节点。
		第二种和第三种其实还可以归为一类：当该节点没有右子节点时，我只需要判断当前节点是否是父节点的左子节点即可，是则父节点就是下一个节点，不是在向上遍历。

*/

struct BinaryTreeNode{ //定义链表结点
	char m_nValue;
	BinaryTreeNode* m_pParents;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
}*Thead;


char pb[9]={'a','b','d','e','h','i','c','f','g'};
char pc[9]={'d','b','h','e','i','a','f','c','g'};

//利用面试题7建二叉树
BinaryTreeNode* findroot(int leftpb,int rightpb,int leftpc,int rightpc,BinaryTreeNode* head){//leftpb代表左子树前序遍历序列的首下标，rightpb代表左子数前序遍历序列的尾下标
																		//leftpc    右    中序                  rightpb    右    中序
	int i=0;
	for(;pb[leftpb]!=pc[leftpc+i]&&leftpc+i<=rightpc;i++);
	if(leftpc+i>rightpc){//前序遍历序列与中序遍历序列不匹配判断
		cout<<"前序遍历序列与中序遍历序列不匹配"<<endl;
		throw std::exception("前序遍历序列与中序遍历序列不匹配"); //这里创建个异常，直接跳出深度递归
		
	}
	//得到i 为左子树的个数
	BinaryTreeNode* root=new BinaryTreeNode();
	root->m_nValue=pb[leftpb];
	root->m_pParents=head;
	root->m_pLeft=root->m_pRight=NULL;
//	cout<<"值为："<<root->m_nValue<<endl;
	if(i!=0){ //如果有左子树，递归
		root->m_pLeft=findroot(leftpb+1,leftpb+i,leftpc,leftpc+i-1,root);
	}
	if(leftpb+i+1<=rightpb){//如果有右子数，递归
		
		root->m_pRight=findroot(leftpb+i+1,rightpb,leftpc+i+1,rightpc,root);
	}
	return root;	
}



//先序遍历二叉树测试是否建成功
void PreOrderTraverse(BinaryTreeNode *T){
    if(T){
       printf("%c",T->m_nValue);
       PreOrderTraverse(T->m_pLeft);
       PreOrderTraverse(T->m_pRight);
    }
}


BinaryTreeNode *t=NULL;
void getpNode(BinaryTreeNode *T,char ch){ //获取节点指针
	if(T){
		if(T->m_nValue==ch){
			t=T;
		}
       getpNode(T->m_pLeft,ch);
       getpNode(T->m_pRight,ch);
    }
}

void getNext(BinaryTreeNode *T){//得到下一个节点的值
	if(T){
		if(T->m_pRight){
			T=T->m_pRight;
			while(T->m_pLeft){
				T=T->m_pLeft;
			}
			cout<<"下一个节点为："<<T->m_nValue<<endl;
		}else{
			while(T->m_pParents->m_pLeft!=T){
				T=T->m_pParents;
			}
			cout<<"下一个节点为："<<T->m_pParents->m_nValue<<endl;
		}
	}else{
		cout<<"已知节点异常"<<endl;
	}

}

int main(void){
	BinaryTreeNode* root=NULL;
	root=findroot(0,8,0,8,root);
	cout<<"请输入节点value值（a,b,c,d,e,f,g,h,i）中的一个："<<endl;
	char ch;
	cin>>ch;
	getpNode(root,ch);
	cout<<"t的value="<<t->m_nValue<<endl;
	getNext(t);
	cout<<endl;
	PreOrderTraverse(root);
	return 0;
}








