#include<iostream>
#include<string>
using namespace std;
/*
	题目：
		如果一个01串任意两个相邻位置的字符都是不一样的，我们就叫这个01串为交错O1串。例如:"1","10101","0101010"都是交错01串。小易现在有一个01串s,
	小易想找出一个最长的连续子串，并且这个子串是一个交错01串。小易需要你帮帮忙求出最长的这样的子串的长度是多少。
	输入描述:
		输入包括字符串s,s 的长度length(I s length < 50),字符串中只包含'0‘和'1'
	输出描述:
		输出一个整数，表示最长的满足要求的子串长度。
	输入例子1:
		111101111
	输出例子1:
		3
*/

string s;
int i;
bool init(){ //c
	bool b=true;
	cout<<"请输入01串："<<endl;
	getline(cin,s);
	i=0;
	for(;s[i]!='\0'&&(s[i]=='0'||s[i]=='1');i++); //用来遍历判读是否为为合格的01串
	if(i!=s.length()){
		cout<<"输入格式错误"<<endl;
		b=false;
	}
	return b;
}

void findMax(){
	int count1=1,count2=1;//count1表示当前最长子串， count2表示整个字符串中最长子串
	for(int j=0;j<i-1;j++){
		if(s[j]!=s[j+1]){
			count1++;
		}else{
			count1=1;
		}
		count2=count1>count2?count1:count2;//三元表达式获取最长字符串
	}
	
	cout<<"满足要求的子串长度："<<count2;
	cout<<endl;
}

int main(void){
	if(init()){
		findMax();
	}
	
	return 0;
}