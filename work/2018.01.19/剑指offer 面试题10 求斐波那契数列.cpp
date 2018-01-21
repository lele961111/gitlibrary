#include<iostream>
using namespace std;

/*
	剑指offer 面试题10 求斐波那契数列
	题目：求斐波那契数的第n项
		写一个函数，输入你，求斐波那契数列的第n项，斐波那契的定义如下：n=0时，f(n)=0,n=1时，f(n)=1,n>1时，f(n)=f(n-1)+f(n-2)；当前项是前一项和前二项的和
	解析：
		解决这个问题是很简单的，用递归方法就可以实现，但是这种通用的方法效率很低，它会计算很多已经计算过的数列，如果用循环将
	之前算过的数列存起来就可以避免重复计算了。实现复杂度是O（n）
		
*/

void Fibonacci(int n){
	int ints[2]={0,1};//先把前两个值存起来
	if(n<2){
		cout<<"第"<<n<<"项="<<n<<endl;
	}else{//
		int i=2;
		int num1=ints[1];//前1项的值
		int num2=ints[0]+ints[1];//当前项的值
		int temp;
		while(i!=n){//开始往后计算
			temp=num2;
			num2=num1+num2;
			num1=temp;
			i++;
		}
		cout<<"第"<<n<<"项="<<num2<<endl;
	}
}

int main(void){
	cout<<"请输入n:"<<endl;
	int n;
	cin>>n;
	Fibonacci(n);
	return 0;
}




