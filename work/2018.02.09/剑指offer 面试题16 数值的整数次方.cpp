#include<iostream>
using namespace std;

/*
	剑指offer 面试题16 数值的整数次方
		题目：实现函数double Power(double base,int exponent)，求base的exponent次方，不得使用库函数，同时不需要考虑大数问题。
		解析：
			这道题其实很简单，一个循环乘就可以解决。但是这样的解法即花费时间，又有局限性。输入的exponent次方为负数时就不行了。
			首先在乘积方面，原先要乘exponent-1次，但是n次方=n/2次方*2次方， 这下就能节省很多次乘操作。需要注意的是如果次方数为奇数时，最后还要再乘一次base；
			其次在exponent为负数方面，只需在调用Power方法时将其正值放入参数计算，结果输出时再用1除以 得到最终结果。
*/

double base=0;//表示数值
int exponent=0;//表示整数次方
void init(){
	cout<<"请输入数值："<<endl;
	cin>>base;
	cout<<"请输入整数次方"<<endl;
	cin>>exponent;
}

double Power(double base,int exponent){
	if(exponent==0){
		return 1;
	}
	if(exponent==1){
		return base;
	}
	double num=Power(base,exponent>>1); //exponent除以2，代表n次方=n/2次方的2次方 简化计算量
	num*=num; 
	if(exponent%2==1){ //当整数次方为奇数时，再乘上一个
		num*=base;
	}
	return num;
}

int main(void){
	init();
	if(exponent<0){
		double d=Power(base,-exponent);
		cout<<"结果为"<<1.0/d<<endl;
	}else{
		double d=Power(base,exponent);
		cout<<"结果为"<<d<<endl;
	}
	
	return 0;
}



