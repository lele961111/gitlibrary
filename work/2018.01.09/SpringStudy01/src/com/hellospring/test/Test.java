package com.hellospring.test;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.hellospring.demo.IBean;

public class Test {
	public static void main(String[] args) {
		//测试第一种方式
		//加载配置文件
		ApplicationContext context=new ClassPathXmlApplicationContext("Spring.xml");
		//得到配置文件创建的对象
//		IBean bean1=(IBean)context.getBean("bean1");
//		bean1.add();
		
		//测试第二种方式
//		IBean bean2=(IBean)context.getBean("bean2");
//		bean2.add();
		
		//测试第三种方式
//		IBean bean3=(IBean)context.getBean("bean3");
//		bean3.add();
		
		
		//测试 bean标签 scope属性
		IBean bean1=(IBean)context.getBean("beanscope2");
		IBean bean2=(IBean)context.getBean("beanscope2");
		//通过对象地址观察区别
		System.out.println(bean1);
		System.out.println(bean2);
	
		
	}
}
