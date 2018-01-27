#include<iostream>
#include <cctype>
#include<string>
using namespace std;
/*
	今天算法题：在给定n个数中找出两个数的和为固定值k。
	输入n，再输入n个数，最后输入k
	例输入：
	9
	2 3 5 4 6 12 15 13 4 
	16
	输出：3 13
	
	解析：
		这道题可以先给他升序排序，然后从头和尾开始判断：
			①.当头和尾相加大于k值时，说明尾数已经不再考虑范围了，因为它和最小的数组之和都比k大，和其他数加都打，所有尾数--;
			②.当头和尾相加小于k值时，说明头数已经没用了，道理和①一样；
			③.当头和尾相加等于k值，那就直接输出了，然后头++，尾--；
			④.直到头和尾相遇结束。
		排序算法，本案例采用快速排序。
		本案例还想加了判断输入错误处理：
			get到两个方法：判断字符是否为数值isdigit(字符)， 将字符转为int型 int型=(int)(字符-'0')
		    不过这两个字符方法对这个题来说局限性太大，必须保证输入的都是整数 且都是<10的数，所以就选择用string
			根据判断字符串的每个字符来判定是否是数值  用string.c_str() 来讲string转换为char *型  再通过atoi()转为int   string->int: atoi(s.c_str())
			就这样判断输入格式错误就解决了。
		
*/


int size; //表示数组的长度
int k; //表示固定值
int * n; //指向数组的指针
//char c;
string s;

bool isNum(string s){ //判断是否为正确的数值
	int i=0;
	if(s[i]=='-'||(s[i]>='0'&&s[i]<='9'||s[i]=='+')){
		for(++i;i<s.length()&&s[i]<='9'&&s[i]>='0';i++);	
	}
	if(i!=s.length()){
		return false;
	}
	return true;
}	

//获取数据
bool init(){
	cout<<"请输入n：";
	cin>>s;
	if(!isNum(s)){
		cout<<"输入n值格式错误"<<endl;
		return false;
	}else{
		size=atoi(s.c_str());
	}
	n=new int[size];
	cout<<"请输入n个整数"<<endl;
	for(int i=0;i<size;i++){
		 cin>>s;
		 if(!isNum(s)){
			cout<<"输入数组格式错误。"<<endl;
			return false;
		 }else{
			n[i]=atoi(s.c_str());
		 }
	}
	cout<<endl;
	cout<<"请输入k：";
	cin>>s;
	if(!isNum(s)){
		cout<<"输入k值格式错误。"<<endl;
		return false;
	}else{
		k=atoi(s.c_str());
	}
	cout<<endl;
	return true;
	
}


void print(){ //输出数组，便于观察排序
	cout<<endl;
	for(int i=0;i<size;i++){
		cout<<n[i]<<" ";
	}
	cout<<endl;
}

//对数组排序   采用快速排序（递归） 
void Quicksort(int begin,int end){
	int b=begin;
	int e=end;
	int temp=n[begin]; //去当前数组第一个值作为基准
	int i=0;
	while(b<=e){
		cout<<"进入排序循环"<<endl;
		for(;temp<n[e]&&b<e;e--); //先从尾部遍历找小的数，然后置换
		if(b==e){
			break;
		}
		n[b++]=n[e];
		print();
		for(;temp>n[b]&&b<e;b++); //再从头部遍历找大的数，然后置换
		if(b==e){
		break;
		}
		n[e--]=n[b];
		print();
		cout<<endl;
	}
	n[b]=temp;  //将基准数放入数组中空的地方
		if(b!=begin){
			Quicksort(begin,b-1);
		}
		if(b!=end){
			Quicksort(b+1,end);
		}
		
}

void find(){//寻找匹配值
	int j=size-1;
	for(int i=0;i<j&&n[i]/1==n[i]&&n[j]/1==n[j];){ 
		if(n[i]+n[j]>k){ //大于时尾--
			j--; 
		}else if(n[i]+n[j]<k){ //小于时头++
			i++;
		}
		else{
			cout<<"一组解："<<n[i]<<","<<n[j]<<endl;
			i++;
			j--;
		}
	}
}

int main(void){
	if(init()){
		Quicksort(0,size-1);
		find();
	}
	return 0;
}