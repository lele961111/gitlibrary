#include<iostream>
#include<string>
#include<stack>
using namespace std;

/*
	1.将阿拉伯数字转换为中文数字（九位数字以内）
	123 -> 一百二十三
	100001 ->十万零一
	解析： 这道题我是采用入栈的方式来进行的，主要还是利用判断语句来控制入栈操作，这样就缺失了灵活性，只是硬生生的判断了所有的可能性
		判断：当末尾都是0时，都不入栈即当s1为"零"并且栈为空时；当处理的数在万位或者亿位时特殊处理：当s1为"零"时插入s2+s1（这里还要判断万后边是否有零的插入，有的话插s2）,否则插入s1+s2;
			  当连续出现0时，判断栈顶是否为“零”，是就不入栈了，不是就入一个；当s1为非零时直接插入s1+s2；当万或亿的上边那个值为零时也要入栈；最后就是要插入有值后的第一个零
*/

bool b=true;
stack<string> sta;

string findnum(int x){
	switch(x){
	case 0 : return "零"; break;
	case 1 : return "一"; break;
	case 2 : return "二"; break;
	case 3 : return "三"; break;
	case 4 : return "四"; break;
	case 5 : return "五"; break;
	case 6 : return "六"; break;
	case 7 : return "七"; break;
	case 8 : return "八"; break;
	case 9 : return "九"; break;
	default: return "";
	}
}

string finddigit(int i){
	switch(i){
	case 1:return "十";break;
	case 2:return "百";break;
	case 3:return "千";break;
	case 4:return "万";break;
	case 8:return "亿";break;
	case 5:return "十";break;
	case 6:return "百";break;
	case 7:return "千";break;
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
		if((s1=="零"&&sta.empty())){//处理末尾是0
			doit(n/10,i+1);			
		}else if(s2=="万"||s2=="亿"){//处理万位和亿位的值
			if(s1=="零"){
				if(sta.top()=="零"){
					sta.push(s2);
				//	cout<<" 1入栈："<<s2<<endl;
					doit(n/10,i+1);
					cout<<s2;
				}else{
					sta.push(s2+s1);
				//	cout<<" 2入栈："<<s2+s1<<endl;
					doit(n/10,i+1);
					cout<<s2+s1;
				}				
			}else{
				sta.push(s1+s2);
			//	cout<<" 3入栈："<<s1+s2<<endl;
				doit(n/10,i+1);
				cout<<s1+s2;
			}						
		}else if(s1=="零"&&sta.top()=="零"){//处理连续零的情况，只插入一次零
			doit(n/10,i+1);		
		}else if(s1!="零"){//为值的话直接插入
			sta.push(s1+s2);
		//	cout<<"4入栈："<<s1+s2<<endl;
			doit(n/10,i+1);
			cout<<s1+s2;
		}
		else if(s1=="零"&&(sta.top()=="万"||sta.top()=="亿"||sta.top()=="万零"||sta.top()=="亿零")){//处理连着万上边的零			
			doit(n/10,i+1);
		}
		else{//插入第一个零
			sta.push(s1);
		//	cout<<"5入栈："<<s1<<endl;
			doit(n/10,i+1);
			cout<<s1;
		}
	}
}




int main(void){
	int n;
	cout<<"请输入数字："<<endl;
	cin>>n;
	doit(n,0);
	cout<<endl;
	return 0;
}
