#include<iostream>
#include<string>
using namespace std;

char s[50];
int oldlong=0;
int newlong=0;
int count=0;
char c;

void getlong(){
	cout<<"�������ַ���"<<endl;
	gets(s);
	for(;(c=s[oldlong])!='\0';oldlong++){
		if(c==' '){
			count++;
		}
	}
	newlong=oldlong+count*2;
}

void print(){//���б�����ֵ
	int i=oldlong;
	int j=newlong;
	while(i>=0){
		if(s[i]==' '){//���и���
			s[j--]='0';
			s[j--]='2';
			s[j--]='%';
		}
		else{
			s[j--]=s[i];//������һ���ַ�
		}
		i--;
	}
	for(i=0;i<newlong;i++){
		cout<<s[i];
	}
	cout<<endl;
}

int main(void){
	getlong();
	print();
	return 0;
}

