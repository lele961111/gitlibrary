#include<iostream>
#include<string>
using namespace std;

char s[50];
int oldlong=0;
int newlong=0;
int count=0;
char c;

void getlong(){
	cout<<"请输入字符串"<<endl;
	gets(s);
	for(;(c=s[oldlong])!='\0';oldlong++){
		if(c==' '){
			count++;
		}
	}
	newlong=oldlong+count*2;
}

void print(){//进行遍历赋值
	int i=oldlong;
	int j=newlong;
	while(i>=0){
		if(s[i]==' '){//进行更换
			s[j--]='0';
			s[j--]='2';
			s[j--]='%';
		}
		else{
			s[j--]=s[i];//进行下一个字符
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

