#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*
	今天算法：求一个整数序列的最长递增子序列。
	输入：第一行为序列长度，第二行给出整数序列。
	输出：第一行为最长递增子序列的长度，第二行为最长递增子序列。
	例输入：
	5
	3 1 4 2 3
	输出：	
	3
	1 2 3
	解析：利用数组k[]；来存储从1到max代表的最小的数，遍历原数组，进行比较对号入座(插入它当前对于前边所有值它应该在的序列处)，最后得到的数组就是结果
*/

int count=0; //看看能循环多少次，时间复杂度

int * a;
int * k;
int * 
void init(){
	cout<<"请输入序列长度";
	int n;
	int max=0;
	cin>>n;
	a=new int[n];
	k=new int[n];
	k[0]=-10000; //用于k[0]比较，起初想避免数值0与数组初始值冲突，用负数可解决，  -10000 就可以输入负数  也不错
	int i,j;
	cout<<"输入整数序列："<<endl;
	for(i=0;i<n;i++){ //获取序列
		cin>>a[i];
	}
	for(i=0;i<n;i++){ //遍历数组，将每个数放到响应的位置
		count++;
		if(a[i]>=max){  //当数值大于等于最大序列数时，从后遍历，节省循环
			for(j=max;j>=0&&a[i]<=k[j];j--,count++); //直到当前数值大于它相对当前应该处于最大位置处的前一位时，停止，将数值插入到它该在的地方
			k[++j]=a[i];
			cout<<"  k["<<j<<"]="<<k[j]<<endl;
			max=max>j?max:j; //max重新获取最大序列数
		}else{ //当数值小于最大序列数时，从前遍历，节省循环
			for(j=0;j<=max&&a[i]>k[j];j++,count++);//直到当前数值小于等于它相对于当前应该处于最大位置处时，插入
			k[j]=a[i];
			cout<<"k["<<j<<"]="<<k[j]<<endl;
		}	
	}
	cout<<"最长递增子序列的长度："<<max<<endl;
	cout<<"最长递增子序列:"<<endl;
	for(i=1;i<=max;i++){
		cout<<k[i]<<" ";
	}
	cout<<endl;
	cout<<"总共循环次数："<<count;
}

bool judge(){
	
}

int main(void){
	init();
	return 0;
}
