#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*
	验证括号是否能正常闭合。包含 () [] {}。
	例如： {[()]}{}()[] 这个是能正常闭合的。(})]{ 这个是不能正常闭合的。
	输入：字符串s。
	输出：YES或者NO
	解析：很显然可以用栈来实现这个题   先检索当前字符是否符合入栈出栈要求，再通过置换后和栈顶比较，不一样就将原字符入栈，一样就出栈，最后栈空为Yes，否则为No
	置换方法  用三元表达式来实现，操作简单，但要仔细，容易写错
*/

stack<char> sc;//定义栈来存储 () {} []


bool judge(char c){ //检测字符是否符合进行入栈出栈操作
	if(c=='('||c==')'||c=='['||c==']'||c=='{'||c=='}'){
		return true;
	}else{
		return false;
	}
}

//找到指定字符后置换
char replace(char c){ //三元表达式解决掉
//	cout<<"换之前c="<<c<<endl;
	c= c=='(' ? ')' : c==')' ? '(': c=='{' ? '}' : c=='}' ? '{' : c=='[' ? ']' : '[';
//	cout<<"换之后c="<<c<<endl;
	return c; 
}

void judgeall(){
	string s;
	cin>>s;
	int i=0;
	while(i<s.length()){
	//	cout<<"进入while i="<<i<<endl;
		for(;i<s.length()&&!judge(s[i]);i++); //找到字符或到‘\0’  到'\0'对程序要求没有影响，无需担心
	//	cout<<"找到字符  i="<<i<<"s[i]="<<s[i]<<endl;
		char temp=s[i];   //临时变量拥有放置换后的值
	//	cout<<sc.size()<<endl;
		if(sc.size()==0){   //如果栈为空是自动入栈  因为栈为空是好像不能用top（）把， 会出错
			sc.push(s[i]);
		}else{
			if(sc.top()==replace(temp)){
				sc.pop();
				cout<<"出栈"<<endl;
			}else{
				sc.push(s[i]);
				cout<<"入栈"<<endl;
			}
		}
		i++;
	}
}

int main(void){
	judgeall();
	if(sc.size()!=0){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
	}
	return 0;
}