#include<iostream>
#include <cctype>
#include<string>
using namespace std;
/*
	�����㷨�⣺�ڸ���n�������ҳ��������ĺ�Ϊ�̶�ֵk��
	����n��������n�������������k
	�����룺
	9
	2 3 5 4 6 12 15 13 4 
	16
	�����3 13
	
	������
		���������ȸ�����������Ȼ���ͷ��β��ʼ�жϣ�
			��.��ͷ��β��Ӵ���kֵʱ��˵��β���Ѿ����ٿ��Ƿ�Χ�ˣ���Ϊ������С������֮�Ͷ���k�󣬺��������Ӷ�������β��--;
			��.��ͷ��β���С��kֵʱ��˵��ͷ���Ѿ�û���ˣ�����͢�һ����
			��.��ͷ��β��ӵ���kֵ���Ǿ�ֱ������ˣ�Ȼ��ͷ++��β--��
			��.ֱ��ͷ��β����������
		�����㷨�����������ÿ�������
		��������������ж����������
			get�������������ж��ַ��Ƿ�Ϊ��ֵisdigit(�ַ�)�� ���ַ�תΪint�� int��=(int)(�ַ�-'0')
		    �����������ַ��������������˵������̫�󣬱��뱣֤����Ķ������� �Ҷ���<10���������Ծ�ѡ����string
			�����ж��ַ�����ÿ���ַ����ж��Ƿ�����ֵ  ��string.c_str() ����stringת��Ϊchar *��  ��ͨ��atoi()תΪint   string->int: atoi(s.c_str())
			�������ж������ʽ����ͽ���ˡ�
		
*/


int size; //��ʾ����ĳ���
int k; //��ʾ�̶�ֵ
int * n; //ָ�������ָ��
//char c;
string s;

bool isNum(string s){ //�ж��Ƿ�Ϊ��ȷ����ֵ
	int i=0;
	if(s[i]=='-'||(s[i]>='0'&&s[i]<='9'||s[i]=='+')){
		for(++i;i<s.length()&&s[i]<='9'&&s[i]>='0';i++);	
	}
	if(i!=s.length()){
		return false;
	}
	return true;
}	

//��ȡ����
bool init(){
	cout<<"������n��";
	cin>>s;
	if(!isNum(s)){
		cout<<"����nֵ��ʽ����"<<endl;
		return false;
	}else{
		size=atoi(s.c_str());
	}
	n=new int[size];
	cout<<"������n������"<<endl;
	for(int i=0;i<size;i++){
		 cin>>s;
		 if(!isNum(s)){
			cout<<"���������ʽ����"<<endl;
			return false;
		 }else{
			n[i]=atoi(s.c_str());
		 }
	}
	cout<<endl;
	cout<<"������k��";
	cin>>s;
	if(!isNum(s)){
		cout<<"����kֵ��ʽ����"<<endl;
		return false;
	}else{
		k=atoi(s.c_str());
	}
	cout<<endl;
	return true;
	
}


void print(){ //������飬���ڹ۲�����
	cout<<endl;
	for(int i=0;i<size;i++){
		cout<<n[i]<<" ";
	}
	cout<<endl;
}

//����������   ���ÿ������򣨵ݹ飩 
void Quicksort(int begin,int end){
	int b=begin;
	int e=end;
	int temp=n[begin]; //ȥ��ǰ�����һ��ֵ��Ϊ��׼
	int i=0;
	while(b<=e){
		cout<<"��������ѭ��"<<endl;
		for(;temp<n[e]&&b<e;e--); //�ȴ�β��������С������Ȼ���û�
		if(b==e){
			break;
		}
		n[b++]=n[e];
		print();
		for(;temp>n[b]&&b<e;b++); //�ٴ�ͷ�������Ҵ������Ȼ���û�
		if(b==e){
		break;
		}
		n[e--]=n[b];
		print();
		cout<<endl;
	}
	n[b]=temp;  //����׼�����������пյĵط�
		if(b!=begin){
			Quicksort(begin,b-1);
		}
		if(b!=end){
			Quicksort(b+1,end);
		}
		
}

void find(){//Ѱ��ƥ��ֵ
	int j=size-1;
	for(int i=0;i<j&&n[i]/1==n[i]&&n[j]/1==n[j];){ 
		if(n[i]+n[j]>k){ //����ʱβ--
			j--; 
		}else if(n[i]+n[j]<k){ //С��ʱͷ++
			i++;
		}
		else{
			cout<<"һ��⣺"<<n[i]<<","<<n[j]<<endl;
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