#include<iostream>
using namespace std;

/*
	面试题13：机器人的运动范围
	题目：
		地上有一个m行n列的方格，一个机器人从坐标（0,0）的格子开始移动，他每次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和大于k的格子。
		例如:当k为18时，机器人能够进入方格（35,37），因为3+5+2+7=18，但它不能进入方格（35,38），因为3+5+3+8=19.
		请问该机器人能够到达多少个格子？
	解析：
		这个题也是可以用回溯来解决相对矩阵的路径和经典的走迷宫相比，这个处理起来还是较容易些，首先它不需要清理走过的痕迹，只需记录能走的个数即可。
		在以建立一个数组来做标识的前提下，让做过的每个点都向其四个方向进行试探，能走就走，不能就停止向下次试探。最后只需统计能走的个数就可以完成任务。
		在方法设计上：计算位数之和，初始化数组和得到需要的参数，判断当前点能不能走，向四个方向试探方法。
		(x,y)的四个方向：(x,y+1),(x,y-1),(x+1,y),(x-1,y)

	本案例可计算范围为三位数，扩展请改num方法，扩展：可从任意位置开始走

*/

int num(int x,int y){
	int n=x/100+x/10%10+x%10+y/100+y/10%10+y%10;
	return n;
}

int *arr;
int k;
int m,n;

//初始化
void init(){
	cout<<"请输入方格的行和列："<<endl;	
	cin>>m>>n;
	cout<<"请输入k值："<<endl;
	cin>>k;
	arr=new int[m*n];
	for(int i=0;i<m*n;i++){
		arr[i]=0;
	}

}

//判断当前位置是否能走
bool check(int x,int y){
	if(x>=0&&x<m&&y>=0&&y<n&&num(x,y)<=k&&arr[x*n+y]!=1){   //判断要充分， 判断是否越界，是否走过，是否能走
		cout<<"("<<x<<","<<y<<")"<<endl;
		return true;
	}
	return false;
}

//判断下个位置是否能走 回溯法
int checknext(int x,int y){
	int count=0; //记录能走个数
	if(check(x,y)){
		arr[x*n+y]=1;
		count=1+checknext(x-1,y)+checknext(x+1,y)+checknext(x,y+1)+checknext(x,y-1);
	}
	return count;
}

int main(void){
	init();
	cout<<"请输入开始走的位置："<<endl;
	int X,Y;
	cin>>X>>Y;
	cout<<endl;
	cout<<"机器人能走的格子数为："<<endl;
	int count=checknext(X,Y);
	cout<<count<<endl;
	return 0;
}