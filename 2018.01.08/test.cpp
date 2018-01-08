#include<iostream>
/* 剑指offer 面试题20:表示数值的字符串
	题目:请实现一个函数用来判断字符串是否表示数值(包括整数和小数).例如,字符串"+100"、"5e2"、"-123"、"3.1416"及"-1E-16"都表示数值，
		但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。


  解析: 首先这道题给出的数的规范可写为[+/-]A[.]B[e/E][+/-]C 或 [.]B[e/E][+/-]C
		在不考虑符合情况下，正确数值的规范可为以下六种：①A  ②A.B  ③A[e/E]C  ④A.B[e/E]C  ⑤.B  ⑥.B[e/E]C
		这六种数值也是含有明显的特点：首字符只能是（+/-/0~9/.）  A,B,C都是整数  
		由于自己语言组织能力不强，就直接看代码吧
*/
#include<string>
using namespace std;
char n1[10]={'0','1','2','3','4','5','6','7','8','9'}; //用于判断字符是否为数值
char n2[12]={'-','+','0','1','2','3','4','5','6','7','8','9'};//用于判断字符是否为数值或者正负号
char n3[2]={'e','E'};//用于判断字符是否为e或者E

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
	int i=0,j=0; //i表示
	string s=".3e-1";
	for(;s[j]!='\0';j++); //遍历字符串s  得到字符串长度j
	if(isNZF(s[i])){
		//A操作		
		for(i+=1;i<j&&isN(s[i]);i++);
		if(s[i]=='.'){
			//B操作
			for(i+=1;i<j&&isN(s[i]);i++);
			if(isE(s[i])){
				//C操作
				i++;
				if(isNZF(s[i])){//判断首字符是否符合规范
					for(i+=1;i<j&&isN(s[i]);i++);
					if(i==j){cout<<"是数"<<endl;}
					else{cout<<"不是数"<<endl;}
				}
				else{printf("不是数");}
			}
			else if(i==j){printf("是数");}
			else{printf("不是数");}
		}
		else if(i==j){printf("是数");}
		else{printf("不是数");}
	}
	else if(s[i]=='.'){
		//B操作
		for(i+=1;i<j&&isN(s[i]);i++);
		if(isE(s[i])){
			//C操作
			i++;
			if(isNZF(s[i])){//判断首字符是否符合规范
				for(i+=1;i<j&&isN(s[i]);i++);
				if(i==j){printf("是数");}
				else{printf("不是数");}
			}
			else{printf("不是数");}
		}
		else if(i==j){printf("是数");}
		else{printf("不是数");}
	}
	return 0;
}