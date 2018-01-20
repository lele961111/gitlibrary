#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<stack>
using namespace std;

/*
	��ָoffer������9��������ջʵ�ֶ���
	��Ŀ��
		������ջʵ��һ�����С����е��������£���ʵ��������������appendTail��deleteHead���ֱ�����ڶ���β������ڵ���ڶ���ͷ��ɾ���ڵ�Ĺ��ܡ�
	������
			ջ�ǡ��Ƚ�������������ǡ��Ƚ��ȳ���  ������ջʵ�ֶ��о��ǡ��Ƚ����������ȳ��������ʵ�ֵĽ�����ǡ��Ƚ��ȳ�����
		��ô�Ϳ��Խ���һ��ջ�����ݴ浽��һ��ջ��ٽ��г�ջ����ʵ�ֶ��еĲ���ɾ�������־�ֻ��ʵ�ֶԿն��еĲ���ɾ��������
		Ҫ��ʵ�ֶԷǿն��еĲ���ɾ��������Ҫ���ǵ����������⣬ջ1�ǿգ�ջ2�ǿ�����²����µĽڵ�ʱ��������Ҫ��ջ2�����ݴ浽ջ1�У�����ջ1�в��뼴�ɡ�
*/


template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    
    // �ڶ���ĩβ���һ�����
    void appendTail(const T& node);

    // ɾ�����е�ͷ���
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
			cout<<"ɾ���ڵ�ֵ��"<<data<<endl;
            stack1.pop();
            stack2.push(data);
			
        }
    }

    if(stack2.size() == 0)
	{
		cout<<"����Ϊ��"<<endl;
		return NULL;
	}else{		
		stack2.pop();
		return NULL;
	}
    
    
}


//�������յĶ�������ӡ�ɾ��Ԫ��
void test1(){
	CQueue<char> queue;
	queue.appendTail('a');
	queue.deleteHead();
	
}

//�������ǿյĶ�������ӡ�ɾ��Ԫ��
void test2(){
	CQueue<char> queue;
	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');
	queue.deleteHead();
	queue.deleteHead();

}

//��������ɾ��Ԫ��ֱ������Ϊ��
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




