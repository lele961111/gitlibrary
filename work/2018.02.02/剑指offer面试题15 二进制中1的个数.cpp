#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*
	剑指offer面试题15 二进制中1的个数
	题目：
		请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如，把9表示成二进制是1001，有2为是1.因此，如果输入9，则该函数输出2.
	解析：
		这道题主要考的是位运算的知识，该案例是将一个整数减去1，再和原来的整数做与运算，就会把该整数的最右边的1变成0，那么一个整数的二进制表示中多少个1，
	就可以进行多少此这样的操作。
		这道算法虽然代码量很少，但其中的想法思路却是不好想到的，位运算的计算关系也是要有一定了解才可以。

*/
int find(int n){
	int count =0;
	while(n){
		++count;
		n=(n-1)&n;
	}
	return count;
}	

int main(void){
	int a;
	cout<<"请输入一个整数："<<endl;
	cin>>a;
	int num=find(a);
	cout<<a<<"的1的个数："<<num<<endl;
	return 0;
}