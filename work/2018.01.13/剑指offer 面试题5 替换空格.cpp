#include<iostream>
using namespace std;
/*
	剑指offer 面试题5 替换空格 
	题目：
		请实现一个函数，把字符串中的每个空格替换成“%20”。例如，输入“we are happy.”，则输出“we%20are%20happy”.
	解析：
		首先我们最直观的做法就是从头到尾扫描字符串，遇到空格，就将后边的字符串后移两位，然后再将“%20”赋到这三个空中，
	这样的方法就太复杂了，每次遇到空格，都要将后边的全部后移一次。时间复杂度为O(n的平方)
		另外一种简单的方法：先统计这个字符串的长度以及空格的个数，再计算出改变后的字符串长度；将原字符串从尾部开始遍历，
	将字符赋到新字符串所在的位置，遇到空格就一次性赋三个位置，知道原数组遍历完。
		
*/
char s[50];
int oldlong=0;//原字符串的长度
int newlong=0;//改变后字符串的长度
int count=0;//空格数
char c;

void getlong(){//得到输入的字符串的长度以及将要得到替换后的字符串的长度
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
	if(newlong>50){
		cout<<"字符串长度超出给定长度，替环失败。"
		return;
	}
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

