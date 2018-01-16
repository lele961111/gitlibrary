#include<iostream>
#include<malloc.h>
#include<stdlib.h>
using namespace std;

/*
	剑指offer 面试题7 重建二叉树
	题目：
		输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
	例如，输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，重建二叉树，输出它的头结点。
	解析：
		刚看到这道题的时候，是没有解决思路的，因为虽然已知前序遍历和中序遍历就可以求出此二叉树，但前序遍历和中序遍历表面上关系也不大，没法入手。
	但是仔细分析前序遍历和中序遍历，你就会发现这样个规律：首先，前序遍历就是先访问根节点，再访问左右子节点；中序遍历就是先访问左子节点，再访问根节点，再访问右子节点。
	前序遍历的第一个就是根节点，而中序遍历中根节点左边都是左子树，右边都是右子树。根据中序遍历中左子树节点的个数就可以分出前序遍历中的左子树和右子数。
	这样利用递归每次都求出子树的根节点并判断左右结点进行挂链，就可以完成重建二叉树的工作。本程序 通过后序遍历来测试是否成功。
	
*/


struct BinaryTreeNode{ //定义链表结点
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

int n,*pb,*pc;
int i=0;
void init(){
	cout<<"请输入结点总数:";
	cin>>n;
	cout<<endl;
	pb=(int*)malloc(n*sizeof(int));
	pc=(int*)malloc(n*sizeof(int));
	cout<<"请输入前序遍历序列："<<endl;
	for(i=0;i<n;i++){
		cin>>pb[i];
	}
	cout<<"请输入中序遍历序列："<<endl;
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

BinaryTreeNode* findroot(int leftpb,int rightpb,int leftpc,int rightpc){//leftpb代表左子树前序遍历序列的首下标，rightpb代表左子数前序遍历序列的尾下标
																		//leftpc    右    中序                  rightpb    右    中序
	cout<<"进入递归"<<endl;
	int i=0;
	for(;pb[leftpb]!=pc[leftpc+i]&&leftpc+i<=rightpc;i++);
	if(leftpc+i>rightpc){//前序遍历序列与中序遍历序列不匹配判断
		cout<<"前序遍历序列与中序遍历序列不匹配"<<endl;
		throw std::exception("前序遍历序列与中序遍历序列不匹配"); //这里创建个异常，直接跳出深度递归
		
	}
	cout<<"左子树的个数："<<endl;
	//得到i 为左子树的个数
	BinaryTreeNode* root=new BinaryTreeNode();
	root->m_nValue=pb[leftpb];
	root->m_pLeft=root->m_pRight=NULL;
	cout<<"值为："<<root->m_nValue<<endl;
	if(i!=0){ //如果有左子树，递归
		cout<<"挂左子树"<<endl;
		root->m_pLeft=findroot(leftpb+1,leftpb+i,leftpc,leftpc+i-1);
	}
	if(leftpb+i+1<=rightpb){//如果有右子数，递归
		cout<<"挂右子数"<<endl;
		root->m_pRight=findroot(leftpb+i+1,rightpb,leftpc+i+1,rightpc);
	}
	cout<<"返回root"<<endl;
	return root;	
}

void aftertraverse(BinaryTreeNode* root){ //后续遍历测试是否成功
	if(root->m_pLeft!=NULL){
		//遍历左结点
		aftertraverse(root->m_pLeft);
	}
	if(root->m_pRight!=NULL){
		//遍历右结点
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
		cout<<"输入结点个数有误"<<endl;
	}
	return 0;
}

