#include<iostream>
using namespace std;

/*
	��ָoffer ������10 ��쳲���������
	��Ŀ����쳲��������ĵ�n��
		дһ�������������㣬��쳲��������еĵ�n�쳲������Ķ������£�n=0ʱ��f(n)=0,n=1ʱ��f(n)=1,n>1ʱ��f(n)=f(n-1)+f(n-2)����ǰ����ǰһ���ǰ����ĺ�
	������
		�����������Ǻܼ򵥵ģ��õݹ鷽���Ϳ���ʵ�֣���������ͨ�õķ���Ч�ʺܵͣ��������ܶ��Ѿ�����������У������ѭ����
	֮ǰ��������д������Ϳ��Ա����ظ������ˡ�ʵ�ָ��Ӷ���O��n��
		
*/

void Fibonacci(int n){
	int ints[2]={0,1};//�Ȱ�ǰ����ֵ������
	if(n<2){
		cout<<"��"<<n<<"��="<<n<<endl;
	}else{//
		int i=2;
		int num1=ints[1];//ǰ1���ֵ
		int num2=ints[0]+ints[1];//��ǰ���ֵ
		int temp;
		while(i!=n){//��ʼ�������
			temp=num2;
			num2=num1+num2;
			num1=temp;
			i++;
		}
		cout<<"��"<<n<<"��="<<num2<<endl;
	}
}

int main(void){
	cout<<"������n:"<<endl;
	int n;
	cin>>n;
	Fibonacci(n);
	return 0;
}




