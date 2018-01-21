#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;

/*
	��Ŀ������������ʵ��һ��ջ
	������
		�����ǡ��Ƚ��ȳ���  ջ�ǡ��Ƚ������ ջ����ջ��������ʵ�֣������ҳ���ֵ�Ķ��У�Ȼ��ֱ�Ӳ����ȥ�ͺã����鷳�ó�ջ�������Ϊ�����������ĸ����С�
	��ջ��ʱ���ҳ���ֵ�Ķ��У������е�ֵ��������һ�����У��������һ��ֵ���Ǹ�ֵ���ǳ�ջ��ֵ������ֱ��������ֵ���ǳ�ջ�ˡ�  
*/

template <typename T> class Cstack{
public:
	Cstack(void);
	~Cstack(void);
	void appendTail(const T& node);
	void deleteHead();
private:
	queue<T> q1;
	queue<T> q2;
};

template <typename T> Cstack<T>::Cstack(void)
{
}

template <typename T> Cstack<T>::~Cstack(void)
{
}

template <typename T> void Cstack<T>::appendTail(const T& element){
	if(q1.size()==0){
		if(q2.size()==0){//�����Ϊ�գ��Ͳ������1��
			q1.push(element);
			cout<<"��ջ��"<<element<<endl;
		}
		else{//����2����ֵ  �������2
			q2.push(element);
			cout<<"��ջ��"<<element<<endl;
		}
	}else{//����2����ֵ  �������2
		q1.push(element);
		cout<<"��ջ��"<<element<<endl;
	}
}

template <typename T> void Cstack<T>::deleteHead(){
	if(q1.size()==0){
		if(q2.size()==0){//�����Ϊ�գ����ܳ�ջ
			cout<<"��ջ����"<<endl;
		}else if(q2.size()==1){//����2����һ��ֵ  ֱ�ӳ�ջ  
			cout<<"��ջ��"<<q2.front()<<endl;
			q2.pop();
		}else{//����1����ֵ������תֵ����
			while(q2.size()>1){//�������һ��ֵ
				q1.push(q2.front());
				q2.pop();
			}
			cout<<"��ջ��"<<q2.front()<<endl;
		}
	}
	else if(q1.size()==1){//����1����һ��ֵ  ֱ�ӳ�ջ
		cout<<"��ջ��"<<q1.front()<<endl;
		q1.pop();
	}else{//����2����ֵ������תֵ����
			while(q1.size()>1){//�������һ��ֵ
			q2.push(q1.front());
			q1.pop();
		}
		cout<<"��ջ��"<<q1.front()<<endl;
		q1.pop();
	}
}

//����ջ�����ɾ��Ԫ��
void test1(){
	Cstack<char> stack;
	stack.deleteHead();
	stack.appendTail('a');
}

//���ǿ�ջ�����ɾ��Ԫ��
void test2(){
	Cstack<char> stack;
	stack.appendTail('a');
	stack.appendTail('b');
	stack.deleteHead();
	stack.appendTail('c');

}

//����ɾ��Ԫ��ֱ��ջΪ��
void test3(){
	Cstack<char> stack;
	stack.appendTail('a');
	stack.appendTail('b');
	stack.appendTail('c');
	stack.deleteHead();
	stack.deleteHead();
	stack.deleteHead();
}

int main(void){
	//test1();
	//test2();
	test3();
	return 0;
}




