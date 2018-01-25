#include<iostream>
#include<math.h>
using namespace std;

/*
	剑指offer面试题14 剪绳子
	题目：
		给你一根长度为n的绳子，请把绳子剪成m段（m,n都是整数，n>1并且m>1）,每段绳子的长度记为k[0],k[1],...,k[m].请问k[0]*k[1]*...*k[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2，3,3的三段，此时得到的最大乘积是18.
	解析：本题用了两种方法解决分别是动态规划和贪婪算法。
		动态规划：四个特点，①整体问题的解为最优解，②整体问题的最优解依赖于子问题的最优解，③子问题之间还有相互重叠的更小的问题，④从上往下分析问题，从下往上求解问题
		贪婪算法：只保证每一步得出的结果为最优解
*/


//动态规划
int maxdp(int length){
	if(length<2){  //直接列出长度3以内的最大乘积
		return 0;
	}
	if(length==2){
		return 1;
	}
	if(length==3){
		return 2;
	}
	int* n=new int[length+1]; //用来存储子问题的最优解
	n[0]=0;
	n[1]=1;
	n[2]=2;
	n[3]=3;
	int max=0;
	for(int i=4;i<=length;i++){ 
		max=0;
		for(int j=1;j<=i/2;++j){ //遍历所有解，寻找最优解
			int count=n[j]*n[i-j];
			if(max<count){
				max=count;
			}
			n[i]=max; //存储最优解
		}
	}
	max=n[length];
	delete[] n;
	
	return max;
}


//贪婪算法
int maxtl(int length){
	if(length<2){
		return 0;
	}
	if(length==2){
		return 1;
	}
	if(length==3){
		return 2;
	}
	int count1=length/3; //存3的倍数
	if(length-count1*3==1){ //当剩余的值为1时 说明含有3,1 最大为2 2 所以count1--
		count1-=1;
	}
	int count2=(length-count1*3)/2; //存剩余数除以2的个数
	return (int)(pow(3,count1))*(int)(pow(2,count2));//pow(a,b)  a的b次方
}

int main(void){
	cout<<"请输入绳子的长度："<<endl;
	int length;
	cin>>length;
	cout<<length<<"长的绳子能剪成乘积最大为："<<maxdp(length)<<endl;
	cout<<length<<"长的绳子能剪成乘积最大为："<<maxtl(length)<<endl;
	return 0;
}