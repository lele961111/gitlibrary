#include<iostream>
#include<string>
#include<stack>
using namespace std;

/*
	1.������������ת��Ϊ�������֣���λ�������ڣ�
	123 -> һ�ٶ�ʮ��
	100001 ->ʮ����һ
	������ ��������ǲ�����ջ�ķ�ʽ�����еģ���Ҫ���������ж������������ջ������������ȱʧ������ԣ�ֻ��Ӳ�������ж������еĿ�����
		�жϣ���ĩβ����0ʱ��������ջ����s1Ϊ"��"����ջΪ��ʱ���������������λ������λʱ���⴦����s1Ϊ"��"ʱ����s2+s1�����ﻹҪ�ж������Ƿ�����Ĳ��룬�еĻ���s2��,�������s1+s2;
			  ����������0ʱ���ж�ջ���Ƿ�Ϊ���㡱���ǾͲ���ջ�ˣ����Ǿ���һ������s1Ϊ����ʱֱ�Ӳ���s1+s2��������ڵ��ϱ��Ǹ�ֵΪ��ʱҲҪ��ջ��������Ҫ������ֵ��ĵ�һ����
*/

bool b=true;
stack<string> sta;

string findnum(int x){
	switch(x){
	case 0 : return "��"; break;
	case 1 : return "һ"; break;
	case 2 : return "��"; break;
	case 3 : return "��"; break;
	case 4 : return "��"; break;
	case 5 : return "��"; break;
	case 6 : return "��"; break;
	case 7 : return "��"; break;
	case 8 : return "��"; break;
	case 9 : return "��"; break;
	default: return "";
	}
}

string finddigit(int i){
	switch(i){
	case 1:return "ʮ";break;
	case 2:return "��";break;
	case 3:return "ǧ";break;
	case 4:return "��";break;
	case 8:return "��";break;
	case 5:return "ʮ";break;
	case 6:return "��";break;
	case 7:return "ǧ";break;
	default: return "";
	}
	
}

void doit(int n,int i){
	string s1,s2;
	if(n>0){
		s1=findnum(n%10);
		s2=finddigit(i);
		//cout<<"s1="<<s1<<"    s2="<<s2<<endl;
		/*if(!sta.empty()){
			cout<<"sta.top()="<<sta.top()<<endl;
		}*/
		if((s1=="��"&&sta.empty())){//����ĩβ��0
			doit(n/10,i+1);			
		}else if(s2=="��"||s2=="��"){//������λ����λ��ֵ
			if(s1=="��"){
				if(sta.top()=="��"){
					sta.push(s2);
				//	cout<<" 1��ջ��"<<s2<<endl;
					doit(n/10,i+1);
					cout<<s2;
				}else{
					sta.push(s2+s1);
				//	cout<<" 2��ջ��"<<s2+s1<<endl;
					doit(n/10,i+1);
					cout<<s2+s1;
				}				
			}else{
				sta.push(s1+s2);
			//	cout<<" 3��ջ��"<<s1+s2<<endl;
				doit(n/10,i+1);
				cout<<s1+s2;
			}						
		}else if(s1=="��"&&sta.top()=="��"){//����������������ֻ����һ����
			doit(n/10,i+1);		
		}else if(s1!="��"){//Ϊֵ�Ļ�ֱ�Ӳ���
			sta.push(s1+s2);
		//	cout<<"4��ջ��"<<s1+s2<<endl;
			doit(n/10,i+1);
			cout<<s1+s2;
		}
		else if(s1=="��"&&(sta.top()=="��"||sta.top()=="��"||sta.top()=="����"||sta.top()=="����")){//�����������ϱߵ���			
			doit(n/10,i+1);
		}
		else{//�����һ����
			sta.push(s1);
		//	cout<<"5��ջ��"<<s1<<endl;
			doit(n/10,i+1);
			cout<<s1;
		}
	}
}




int main(void){
	int n;
	cout<<"���������֣�"<<endl;
	cin>>n;
	doit(n,0);
	cout<<endl;
	return 0;
}
