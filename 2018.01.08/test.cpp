#include<iostream>
/* ��ָoffer ������20:��ʾ��ֵ���ַ���
	��Ŀ:��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ(����������С��).����,�ַ���"+100"��"5e2"��"-123"��"3.1416"��"-1E-16"����ʾ��ֵ��
		��"12e"��"1a3.14"��"1.2.3"��"+-5"��"12e+5.4"�����ǡ�


  ����: �����������������Ĺ淶��дΪ[+/-]A[.]B[e/E][+/-]C �� [.]B[e/E][+/-]C
		�ڲ����Ƿ�������£���ȷ��ֵ�Ĺ淶��Ϊ�������֣���A  ��A.B  ��A[e/E]C  ��A.B[e/E]C  ��.B  ��.B[e/E]C
		��������ֵҲ�Ǻ������Ե��ص㣺���ַ�ֻ���ǣ�+/-/0~9/.��  A,B,C��������  
		�����Լ�������֯������ǿ����ֱ�ӿ������
*/
#include<string>
using namespace std;
char n1[10]={'0','1','2','3','4','5','6','7','8','9'}; //�����ж��ַ��Ƿ�Ϊ��ֵ
char n2[12]={'-','+','0','1','2','3','4','5','6','7','8','9'};//�����ж��ַ��Ƿ�Ϊ��ֵ����������
char n3[2]={'e','E'};//�����ж��ַ��Ƿ�Ϊe����E

bool isN(char c){
	int i=0;
	for(;i<10&&c!=n1[i];i++);
	if(i==10){
		return false;
	}
	else{
		return true;
	}
}

bool isNZF(char c){
	int i=0;
	for(;i<12&&c!=n2[i];i++);
	if(i==12){
		return false;
	}
	else{
		return true;
	}
}

bool isE(char c){
	int i=0;
	for(;i<2&&c!=n3[i];i++);
	if(i==2){
		return false;
	}else{
		return true;
	}
}

int main(void){
	int i=0,j=0; //i��ʾ
	string s=".3e-1";
	for(;s[j]!='\0';j++); //�����ַ���s  �õ��ַ�������j
	if(isNZF(s[i])){
		//A����		
		for(i+=1;i<j&&isN(s[i]);i++);
		if(s[i]=='.'){
			//B����
			for(i+=1;i<j&&isN(s[i]);i++);
			if(isE(s[i])){
				//C����
				i++;
				if(isNZF(s[i])){//�ж����ַ��Ƿ���Ϲ淶
					for(i+=1;i<j&&isN(s[i]);i++);
					if(i==j){cout<<"����"<<endl;}
					else{cout<<"������"<<endl;}
				}
				else{printf("������");}
			}
			else if(i==j){printf("����");}
			else{printf("������");}
		}
		else if(i==j){printf("����");}
		else{printf("������");}
	}
	else if(s[i]=='.'){
		//B����
		for(i+=1;i<j&&isN(s[i]);i++);
		if(isE(s[i])){
			//C����
			i++;
			if(isNZF(s[i])){//�ж����ַ��Ƿ���Ϲ淶
				for(i+=1;i<j&&isN(s[i]);i++);
				if(i==j){printf("����");}
				else{printf("������");}
			}
			else{printf("������");}
		}
		else if(i==j){printf("����");}
		else{printf("������");}
	}
	return 0;
}