#include<iostream>
using namespace std;

/*
	��ָoffer ������16 ��ֵ�������η�
		��Ŀ��ʵ�ֺ���double Power(double base,int exponent)����base��exponent�η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣
		������
			�������ʵ�ܼ򵥣�һ��ѭ���˾Ϳ��Խ�������������Ľⷨ������ʱ�䣬���о����ԡ������exponent�η�Ϊ����ʱ�Ͳ����ˡ�
			�����ڳ˻����棬ԭ��Ҫ��exponent-1�Σ�����n�η�=n/2�η�*2�η��� ���¾��ܽ�ʡ�ܶ�γ˲�������Ҫע���������η���Ϊ����ʱ�����Ҫ�ٳ�һ��base��
			�����exponentΪ�������棬ֻ���ڵ���Power����ʱ������ֵ����������㣬������ʱ����1���� �õ����ս����
*/

double base=0;//��ʾ��ֵ
int exponent=0;//��ʾ�����η�
void init(){
	cout<<"��������ֵ��"<<endl;
	cin>>base;
	cout<<"�����������η�"<<endl;
	cin>>exponent;
}

double Power(double base,int exponent){
	if(exponent==0){
		return 1;
	}
	if(exponent==1){
		return base;
	}
	double num=Power(base,exponent>>1); //exponent����2������n�η�=n/2�η���2�η� �򻯼�����
	num*=num; 
	if(exponent%2==1){ //�������η�Ϊ����ʱ���ٳ���һ��
		num*=base;
	}
	return num;
}

int main(void){
	init();
	if(exponent<0){
		double d=Power(base,-exponent);
		cout<<"���Ϊ"<<1.0/d<<endl;
	}else{
		double d=Power(base,exponent);
		cout<<"���Ϊ"<<d<<endl;
	}
	
	return 0;
}



