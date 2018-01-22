#include<iostream>
using namespace std;

/*
	剑指offer 面试题11 旋转数组的最小数字
	题目：
		把一个数字最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小的元素。
	解析：
		最简单的方法就是一次遍历找出最小值，时间复杂度为O(n);仔细想想这个数组就是两个递增的数组的组合，而且后边的最大值是要小于等于左边的最小值，
	所以我们可以通过二分查找法 比较最后一个值和中间值的大小来划分最小值在那个二分数组中，然后一直二分直到剩下一个数或者两个数时直接比较得出最小值。
	但是这里会有一个问题出现，比如数组：1 1 1 0 1或1 0 1 1 1   我们不知道当第一个值，中间值，最后值都相等是，最小值是在左边还是右边；所以这时只能进行循环遍历。
	虽然这中饭方法麻烦但是效率是有的，当数据多的时候，就能体现出二分的作用。
*/
//初始化数组  二分查找  三点一样循环遍历  找到最小值

int *ints;
int begin=0,end;

void init(){ //初始化数组
	cout<<"请输入数组长度"<<endl;
	int n;
	cin>>n;
	end=n-1;
	ints=(int*)malloc(n*sizeof(int));
	cout<<"请输入数组值："<<endl;
	for(int i=0;i<n;i++){
		cin>>ints[i];
	}
}

void bianli(){ //循环遍历寻找最小值
	int num;
	if(ints[begin]==ints[end]&&ints[begin]==ints[(begin+end)/2]){
		num=ints[begin];
		for(int i=begin+1;i<=end;i++){
			num=num<ints[i]?num:ints[i];
		}
		cout<<"最小值："<<num<<endl;
		throw new std::exception("结束");
	}	
}

void find(int b,int e){	
	int c;
	while(e-b!=1&&e!=b){ 
		bianli();
		c=(b+e)/2;
		cout<<"开始位置： "<<b<<" 中间位置："<<c<<"  结束位置： "<<e<<endl;
		if(ints[c]<=ints[e]){//中间值小于最后值
			e=c;		
		}else{
			b=c;
		}
	}	
	if(ints[b]<=ints[e]){//当只有两个值或者一个值时直接判断输出
		cout<<"最小值："<<ints[b]<<endl;
	}else{
		cout<<"最小值："<<ints[e]<<endl;
	}	
}



int main(void){
	init();
	find(begin,end);
	return 0;
}




