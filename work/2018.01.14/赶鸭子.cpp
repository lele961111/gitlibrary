#include<iostream.h>
/*
	题目： 赶鸭子
		一个人赶着鸭子去每个村庄卖，每经过一个村子卖去所赶鸭子的一半又一只。
	这样他经过了七个村子后还剩两只鸭子，问他出发时共赶多少只鸭子？经过每个村子卖出多少只鸭子？
	解析：
	这个问题是一个典型的递归题，经过一个村子卖一半又一只，那么上一个村子的鸭子数=下一个村子的鸭子数*2+2。
*/
int digui(int b,int count)   // b指剩余的数量,count指经过村子的数量
{
	int a,n;   //a指卖出的数量，n指总数
	
	if(count>0)
	{
		a=b+2;	
		n=a+b;
		b=n;
		b=digui(b,count-1);
		cout<<"此人在第"<<count<<"个村子卖出"<<a<<"只鸭子"<<endl;		
	}
	
	return b;

}

int main()
{
	int B;  //a指卖出的数量，b指剩余的数量，n指总数
	int Count;  //经过村子的数量
	
	cout<<"请输入剩余鸭的数量和经过的村子数：（用空格隔开）";
	cin>>B>>Count;
	cout<<endl;
	B=digui(B,Count);   
	cout<<"此人出发时共赶"<<B<<"只鸭子"<<endl;
	return 0;
}