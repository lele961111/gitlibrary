#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*
	��֤�����Ƿ��������պϡ����� () [] {}��
	���磺 {[()]}{}()[] ������������պϵġ�(})]{ ����ǲ��������պϵġ�
	���룺�ַ���s��
	�����YES����NO
	����������Ȼ������ջ��ʵ�������   �ȼ�����ǰ�ַ��Ƿ������ջ��ջҪ����ͨ���û����ջ���Ƚϣ���һ���ͽ�ԭ�ַ���ջ��һ���ͳ�ջ�����ջ��ΪYes������ΪNo
	�û�����  ����Ԫ���ʽ��ʵ�֣������򵥣���Ҫ��ϸ������д��
*/

stack<char> sc;//����ջ���洢 () {} []


bool judge(char c){ //����ַ��Ƿ���Ͻ�����ջ��ջ����
	if(c=='('||c==')'||c=='['||c==']'||c=='{'||c=='}'){
		return true;
	}else{
		return false;
	}
}

//�ҵ�ָ���ַ����û�
char replace(char c){ //��Ԫ���ʽ�����
//	cout<<"��֮ǰc="<<c<<endl;
	c= c=='(' ? ')' : c==')' ? '(': c=='{' ? '}' : c=='}' ? '{' : c=='[' ? ']' : '[';
//	cout<<"��֮��c="<<c<<endl;
	return c; 
}

void judgeall(){
	string s;
	cin>>s;
	int i=0;
	while(i<s.length()){
	//	cout<<"����while i="<<i<<endl;
		for(;i<s.length()&&!judge(s[i]);i++); //�ҵ��ַ��򵽡�\0��  ��'\0'�Գ���Ҫ��û��Ӱ�죬���赣��
	//	cout<<"�ҵ��ַ�  i="<<i<<"s[i]="<<s[i]<<endl;
		char temp=s[i];   //��ʱ����ӵ�з��û����ֵ
	//	cout<<sc.size()<<endl;
		if(sc.size()==0){   //���ջΪ�����Զ���ջ  ��ΪջΪ���Ǻ�������top�����ѣ� �����
			sc.push(s[i]);
		}else{
			if(sc.top()==replace(temp)){
				sc.pop();
				cout<<"��ջ"<<endl;
			}else{
				sc.push(s[i]);
				cout<<"��ջ"<<endl;
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