#include<iostream>
using namespace std;
/*	剑指offer 面试题3：数组中重复的数字
	题目一：找出数组中重复的值
		在一个长度为N的数组里的所有数字都在0~N-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了多少次。
		请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2,3,1,0,2,5,3},那么对应的输出是重复的数字2或者3

    解析：解决这个问题，大概有几个方法：
		①先将数组排序，然后遍历相邻数是否相同  排序一个长为N的数组需要O（nlogn）的时间
		②遍历数组，定义新数组用来存储没有重复的数值，新数值存入新数组，每次判断新数组是否已有该数值  时间复杂度O（n）但又加了个数组空间
		③根据题意可知 数组存入的数值一定小于N,如果数组中没有重复值的话，那么通过排序后数组的下标一定等于该下标对应的值；如果数组中有重复值的话，就会存在数组下标！=下标对应的值。
		本程序就是采用第三种方式解决。
*/

int a[]={2,3,1,0,2,5,3,4,2,1,0};
int N=sizeof(a)/4;
int temp;
int i=0,j;

void findOne(){ //寻找一个重复值
	for(;i<N;){
		cout<<"进入循环"<<i<<endl;
		cout<<"改变前："<<endl;
		for(j=0;j<N;j++){
			cout<<a[j]<<" ";
		}
		cout<<endl;
		if(a[i]!=i&&a[a[i]]!=a[i]){	
			temp=a[a[i]];  //这里的置换顺序必须先将a[a[i]]->temp,a[i]->a[a[i]],temp->a[i]
			a[a[i]]=a[i];  //因为a[a[i]]需要用到a[i]的值，如果先换a[i]的话，会出现置换错误
			a[i]=temp;
		}else if(a[i]!=i&&a[a[i]]==a[i]){
			break;
		}else{			
			i++;
		}
		cout<<"改变后："<<endl;
		for(j=0;j<N;j++){
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}
	if(i!=N){
		cout<<"重复数："<<a[i]<<endl;;
	}else{
		cout<<"没有重复数"<<endl;
	}
	i=0;
}

void findAll(){ //寻找所有重复数以及出现的次数   此方法中存储重复数采用二维数组，通过类似于（并不是）上面的第二种方法来实现
	int num[2][7]={{-1,-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1,1}}; //用来存储重复数属性
	int count=0;
	for(;i<N;){
		cout<<"进入循环"<<i<<endl;
		cout<<"改变前："<<endl;
		for(j=0;j<N;j++){
			cout<<a[j]<<" ";
		}
		cout<<endl;
		if(a[i]!=i&&a[a[i]]!=a[i]&&a[a[i]]>=i){ //这里比查找一个重复数方法多了一个判断条件a[a[i]]>=i 这个是为了考虑 一个重复值与另一个已标记的重复值互换后产生的重复记录问题	
			temp=a[a[i]];  //这里的置换顺序必须先将a[a[i]]->temp,a[i]->a[a[i]],temp->a[i]
			a[a[i]]=a[i];  //因为a[a[i]]需要用到a[i]的值，如果先换a[i]的话，会出现置换错误
			a[i]=temp;
		}else if(a[i]!=i&&a[a[i]]==a[i]){
			if(i!=N){  //；两种方法主要区别就在这里 前者是遇到重复数就结束，而后者是遇到后存储，然后再往后继续遍历
				for(j=0;num[0][j]!=-1&&num[0][j]!=a[i];j++);
				if(num[0][j]==a[i]){
					num[1][j]++;
				}else{
					num[0][j]=a[i];
					num[1][j]++;					
				}
				i++;
			}
			else{
				break;
			}
		}else{			
			i++;
		}
		cout<<"改变后："<<endl;
		for(j=0;j<N;j++){
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}
	if(num[0][1]!=-1){
		cout<<"重复数	次数"<<endl;
		for(j=0;num[0][j]!=-1;j++){
			cout<<" "<<num[0][j]<<"\t"<<num[1][j]<<endl;
		}
	}else{
		cout<<"没有重复数"<<endl;
	}
	i=0;
}

int main(void){
	//
	findAll();
	//findOne();
	return 0;
}