#include<iostream>
using namespace std;
/*
	剑指offer 面试题4 二维数组中的查找
		题目：
			在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
		请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
		
		解析：
			二维数组a[rows][cols]     整数num
			最简单也最复杂（指是在时间或空间复杂度上）的方法就不具体介绍了，直接遍历找出 这样做的话，没有价值，我们就要探讨一个问题是否还会有更简单的解决方法
			题目的第一句就能得到这样的结论，a[i][j]>num时，以a[i][j]为开始到a[rows][cols]的数组都大于num；
											a[i][j]<num时，以a[0][0]为开始到a[i][j]的数组都小于num；
			首先我想到的方法局限性很大，主要针对n*n数组：利用上述结论通过a[0][0]~a[rows][cols]对角线找到a[i][j]<num<a[i+1][j+1],删除掉部分不满足条件的两个小数组，
		最后剩下的是另外两个小数组，再对这两个小数组进行这种方法，直到找到，或者直到这两个小数组为2*2数组，然后再遍历这两个数组寻找满足要求的数。 
			这个方法也是比较麻烦的，只节省了一点遍历的次数。
			后来我又想到如果从数组的右上角开始遍历，又得到了一个结论：a[i][j]>num时,那么i行的值都不满足了；a[i][j]<num时,那么j列的值都不满足了
		所以可以这样遍历：if a[i][j]>num i++;  if a[i][j]<num j--; else 找到   这样只需判断i和j是否超出数组范围来控制循环遍历

		找到所有解：其方法和找到一个解是一样的，这是当找到时不停止循环,而是让遍历位置向左下移一位。
*/

int rows=0,cols=0; //rows代表数组的行 cols代表数组的列 
int **a;//指针指向数组
int num=0;//寻找数
int i,j; //表示正在遍历数组的位置
void getdata(){ //获取数据
	cout<<"请输入二维数组的行和列（空格分开）"<<endl;
	cin>>rows>>cols;
	i=0;
	j=cols-1;
	int i=0;
	//申请空间
	int **arr=new int* [rows];
	a=arr;
	for(; i<rows;i++){
		a[i]=new int[cols];
	}

	//为数组复制
	cout<<"请输入二维数组的值(空格分开)"<<endl;
	for(i=0;i<rows;i++){
		int j=0;
		for(;j<cols;j++){
			cin>>arr[i][j];
		}
		cout<<endl;
	}

	//输入要找的数
	cout<<"请输入要找的数："<<endl;
	cin>>num;
	cout<<endl;
}


bool judge(){//判断当前数组中的数是否等于寻找数
	cout<<i<<"  "<<j<<endl;
	
	if(a[i][j]>num){ //大于的话前进一列
		j--;
	}
	else if(a[i][j]<num){//小于的话下一行
		i++;
	}
	else{//找到后输出并结束while循环
		cout<<"已找到:("<<i<<","<<j<<")"<<endl;
		return false;
	}
	return true;
}

void judgeall(){//所有解
	
	if(a[i][j]>num){ //大于的话前进一列
		j--;
	}
	else if(a[i][j]<num){//小于的话下一行
		i++;
	}
	else{//找到后输出并结束while循环
		cout<<"找到:("<<i<<","<<j<<")"<<endl;
		i++;
		j--;
	}
	if(i>rows&&j<0){
		cout<<"没有找到"<<endl;
	}
}

void deletea(){ //释放空间
	for(int i=0;i<rows;i++){
		delete[] a[i];
	}
	**a=NULL;
}

void outa(){//输出数组
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	getdata();
	int b=true;
	while(i<rows&&j>=0&&b){
		b=judge();
		
	}
	if(b){
		cout<<"没有匹配到相同的值"<<endl;
	}

	//所有解
/*	while(i<rows&&j>=0){
		judgeall();		
	}
*/
	deletea();
	return 0;
}
