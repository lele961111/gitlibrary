#include<iostream>
using namespace std;

/*
	��ָoffer ������11 ��ת�������С����
	��Ŀ��
		��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת������һ����������������һ����ת�������ת�������С��Ԫ�ء�
	������
		��򵥵ķ�������һ�α����ҳ���Сֵ��ʱ�临�Ӷ�ΪO(n);��ϸ�������������������������������ϣ����Һ�ߵ����ֵ��ҪС�ڵ�����ߵ���Сֵ��
	�������ǿ���ͨ�����ֲ��ҷ� �Ƚ����һ��ֵ���м�ֵ�Ĵ�С��������Сֵ���Ǹ����������У�Ȼ��һֱ����ֱ��ʣ��һ��������������ʱֱ�ӱȽϵó���Сֵ��
	�����������һ��������֣��������飺1 1 1 0 1��1 0 1 1 1   ���ǲ�֪������һ��ֵ���м�ֵ�����ֵ������ǣ���Сֵ������߻����ұߣ�������ʱֻ�ܽ���ѭ��������
	��Ȼ���з������鷳����Ч�����еģ������ݶ��ʱ�򣬾������ֳ����ֵ����á�
*/
//��ʼ������  ���ֲ���  ����һ��ѭ������  �ҵ���Сֵ

int *ints;
int begin=0,end;

void init(){ //��ʼ������
	cout<<"���������鳤��"<<endl;
	int n;
	cin>>n;
	end=n-1;
	ints=(int*)malloc(n*sizeof(int));
	cout<<"����������ֵ��"<<endl;
	for(int i=0;i<n;i++){
		cin>>ints[i];
	}
}

void bianli(){ //ѭ������Ѱ����Сֵ
	int num;
	if(ints[begin]==ints[end]&&ints[begin]==ints[(begin+end)/2]){
		num=ints[begin];
		for(int i=begin+1;i<=end;i++){
			num=num<ints[i]?num:ints[i];
		}
		cout<<"��Сֵ��"<<num<<endl;
		throw new std::exception("����");
	}	
}

void find(int b,int e){	
	int c;
	while(e-b!=1&&e!=b){ 
		bianli();
		c=(b+e)/2;
		cout<<"��ʼλ�ã� "<<b<<" �м�λ�ã�"<<c<<"  ����λ�ã� "<<e<<endl;
		if(ints[c]<=ints[e]){//�м�ֵС�����ֵ
			e=c;		
		}else{
			b=c;
		}
	}	
	if(ints[b]<=ints[e]){//��ֻ������ֵ����һ��ֵʱֱ���ж����
		cout<<"��Сֵ��"<<ints[b]<<endl;
	}else{
		cout<<"��Сֵ��"<<ints[e]<<endl;
	}	
}



int main(void){
	init();
	find(begin,end);
	return 0;
}




