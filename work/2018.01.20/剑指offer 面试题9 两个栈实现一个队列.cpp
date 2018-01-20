#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<stack>
using namespace std;

/*
	剑指offer面试题9：用两个栈实现队列
	题目：
		用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail和deleteHead，分别完成在队列尾部插入节点和在队列头部删除节点的功能。
	解析：
			栈是“先进后出”，队列是“先进先出”  用两个栈实现队列就是“先进后出，后进先出”，最后实现的结果就是“先进先出”。
		那么就可以将第一个栈的内容存到另一个栈里，再进行出栈即可实现队列的插入删除，这种就只能实现对空队列的插入删除操作。
		要想实现对非空对列的插入删除，就需要考虑到这样的问题，栈1非空，栈2非空情况下插入新的节点时，我们需要将栈2的内容存到栈1中，再在栈1中插入即可。
*/


template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    
    // 在队列末尾添加一个结点
    void appendTail(const T& node);

    // 删除队列的头结点
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}

template<typename T> void CQueue<T>::appendTail(const T& element)
{
    if(stack2.size()==0){
		stack1.push(element);
	}else{
		while(stack2.size()>0)
        {
            T& data = stack2.top();
            stack2.pop();
            stack1.push(data);
        }
		stack1.push(element);
	}

} 

template<typename T> T CQueue<T>::deleteHead()
{
    if(stack2.size()==0)
    {
        while(stack1.size()>0)
        {
            T& data = stack1.top();
			cout<<"删除节点值："<<data<<endl;
            stack1.pop();
            stack2.push(data);
			
        }
    }

    if(stack2.size() == 0)
	{
		cout<<"队列为空"<<endl;
		return NULL;
	}else{		
		stack2.pop();
		return NULL;
	}
    
    
}


//测试往空的队列里添加、删除元素
void test1(){
	CQueue<char> queue;
	queue.appendTail('a');
	queue.deleteHead();
	
}

//测试往非空的队列里添加、删除元素
void test2(){
	CQueue<char> queue;
	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');
	queue.deleteHead();
	queue.deleteHead();

}

//测试连续删除元素直至队列为空
void test3(){
	CQueue<char> queue;
	queue.appendTail('d');
	queue.appendTail('b');
	queue.appendTail('c');
	queue.deleteHead();
	queue.deleteHead();
	queue.deleteHead();
}

int main(void)
{
    //test1();
	test2();
	//test3();
	return 0;
}




