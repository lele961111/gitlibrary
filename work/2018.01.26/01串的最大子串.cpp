#include<iostream>
#include<string>
using namespace std;
/*
	��Ŀ��
		���һ��01��������������λ�õ��ַ����ǲ�һ���ģ����Ǿͽ����01��Ϊ����O1��������:"1","10101","0101010"���ǽ���01����С��������һ��01��s,
	С�����ҳ�һ����������Ӵ�����������Ӵ���һ������01����С����Ҫ����æ�������������Ӵ��ĳ����Ƕ��١�
	��������:
		��������ַ���s,s �ĳ���length(I s length < 50),�ַ�����ֻ����'0����'1'
	�������:
		���һ����������ʾ�������Ҫ����Ӵ����ȡ�
	��������1:
		111101111
	�������1:
		3
*/

string s;
int i;
bool init(){ //c
	bool b=true;
	cout<<"������01����"<<endl;
	getline(cin,s);
	i=0;
	for(;s[i]!='\0'&&(s[i]=='0'||s[i]=='1');i++); //���������ж��Ƿ�ΪΪ�ϸ��01��
	if(i!=s.length()){
		cout<<"�����ʽ����"<<endl;
		b=false;
	}
	return b;
}

void findMax(){
	int count1=1,count2=1;//count1��ʾ��ǰ��Ӵ��� count2��ʾ�����ַ�������Ӵ�
	for(int j=0;j<i-1;j++){
		if(s[j]!=s[j+1]){
			count1++;
		}else{
			count1=1;
		}
		count2=count1>count2?count1:count2;//��Ԫ���ʽ��ȡ��ַ���
	}
	
	cout<<"����Ҫ����Ӵ����ȣ�"<<count2;
	cout<<endl;
}

int main(void){
	if(init()){
		findMax();
	}
	
	return 0;
}