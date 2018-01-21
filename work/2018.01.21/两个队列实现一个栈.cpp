#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;

/*
	题目：用两个队列实现一个栈
	解析：
		队列是“先进先出”  栈是“先进后出” 栈的入栈可以这样实现：首先找出有值的队列，然后直接插入进去就好，将麻烦让出栈解决；都为空是随便插入哪个队列。
	出栈的时候找出有值的队列，将队列的值都传到另一个队列，留下最后一个值，那个值就是出栈的值，所以直接输出这个值就是出栈了。  
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
		if(q2.size()==0){//如果都为空，就插入队列1中
			q1.push(element);
			cout<<"入栈："<<element<<endl;
		}
		else{//队列2中有值  插入队列2
			q2.push(element);
			cout<<"入栈："<<element<<endl;
		}
	}else{//队列2中有值  插入队列2
		q1.push(element);
		cout<<"入栈："<<element<<endl;
	}
}

template <typename T> void Cstack<T>::deleteHead(){
	if(q1.size()==0){
		if(q2.size()==0){//如果都为空，不能出栈
			cout<<"空栈操作"<<endl;
		}else if(q2.size()==1){//队列2中有一个值  直接出栈  
			cout<<"出栈："<<q2.front()<<endl;
			q2.pop();
		}else{//队列1中有值，进行转值操作
			while(q2.size()>1){//留下最后一个值
				q1.push(q2.front());
				q2.pop();
			}
			cout<<"出栈："<<q2.front()<<endl;
		}
	}
	else if(q1.size()==1){//队列1中有一个值  直接出栈
		cout<<"出栈："<<q1.front()<<endl;
		q1.pop();
	}else{//队列2中有值，进行转值操作
			while(q1.size()>1){//留下最后一个值
			q2.push(q1.front());
			q1.pop();
		}
		cout<<"出栈："<<q1.front()<<endl;
		q1.pop();
	}
}

//往空栈里添加删除元素
void test1(){
	Cstack<char> stack;
	stack.deleteHead();
	stack.appendTail('a');
}

//往非空栈里添加删除元素
void test2(){
	Cstack<char> stack;
	stack.appendTail('a');
	stack.appendTail('b');
	stack.deleteHead();
	stack.appendTail('c');

}

//连续删除元素直至栈为空
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




