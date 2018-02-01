#include<iostream>
#include<stack>
#include<string>
using namespace std;

int find(int n)  
{  
	
	if(n<=0){
		cout<<"台阶不能低于1阶";
		return 0;
	}else{
		return n==1?1:n==2?2:find(n-1)+find(n-2);
	}
} 

int main(void){
	cout<<"请输入台阶数："<<endl;
	int n;
	cin>>n;
	cout<<"青蛙上台阶次数："<<find(n)<<endl;
	return 0;
}