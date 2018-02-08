#include<iostream>
#include<string>
using namespace std;

/*
	题目见图片
	解析：
		合法的括号序列，一个'('所对应的')'之间存在0到多个“()”，在这范围内')'的数量和它本身就是当前括号移除的情况数，
		根据这个思路每次只需统计‘(’对应的‘)’之间的')'的数量。但是要注意的是，每次找出一种可能，都要将找到的"()"去掉，避免对后边计算的影响，
		采用递归或者回溯，利用辅助空间string ss 来接受每次改变的字符串，进行深度遍历。
		  本程序没有考虑到不去掉“（）”对后边计算的影响，只能适用于与简单的（（（））） 或（）（）的计算，但是本质思想上是正确的，修改的方法就是改为回溯法先深度遍历再广度遍历。
*/

string s;

int find(){
	int length=s.length();
	int num=1;//记录总方案数
	int i=0;
	int next=0;
	while(i<length){
		cout<<"进入while "<<endl;
		int k=0; //用于判断找到当前左括号'('对应的右括号')'
		int end=0;
		int z=0; //用来记录每一次'('的可能性
		int x=0; //遍历将改后的s传给新的ss
		for(int j=i;j<length;j++){ //找到当前'('对应的')'
			end=j;
			cout<<"进入for循环 j="<<j<<endl;
			if(s[j]=='('){
				k++;
				z++;
			}else if(s[j]==')'){
				k--;
			}
			if(k==0){
				break;
			}
		}
		for(;i<length&&s[++i]!='(';); //找到下一个'('的位置
		if(k==0){
			num*=z;
		}
	}
	return num;
}

int main(void){
	cout<<"请输入合法的括号序号(请输入英文括号)"<<endl;
	cin>>s;
	int n=find();
	cout<<"方案数="<<n<<endl;
	return 0;
}



