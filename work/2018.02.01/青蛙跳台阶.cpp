#include<iostream>
#include<stack>
#include<string>
using namespace std;

int find(int n)  
{  
	
	if(n<=0){
		cout<<"̨�ײ��ܵ���1��";
		return 0;
	}else{
		return n==1?1:n==2?2:find(n-1)+find(n-2);
	}
} 

int main(void){
	cout<<"������̨������"<<endl;
	int n;
	cin>>n;
	cout<<"������̨�״�����"<<find(n)<<endl;
	return 0;
}