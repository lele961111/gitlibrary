package com.hellospring.test;



import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.hellospring.demo.Complex;
import com.hellospring.demo.Person;
import com.hellospring.demo.Ptest;
import com.hellospring.demo.User;
import com.hellospring.service.UserService;

public class Test {

	public static void setTest(ApplicationContext context) {
		//② 得到配置文件创建的对象
		User u=(User)context.getBean("user");
		u.print();
	}
	
	public static void structureTest(ApplicationContext context) {
		
		//② 得到配置文件创建的对象
		Person p=(Person)context.getBean("person");
		p.print();
	}
	
	public static void DaoTest(ApplicationContext context) {
		//② 得到配置文件创建的对象
		UserService us=(UserService)context.getBean("userService");
		us.print();
	}
	public static void PTest(ApplicationContext context) {
		Ptest pt=(Ptest)context.getBean("ptest");
		pt.print();
	}
	public static void ComplexTest(ApplicationContext context) {
		Complex ct=(Complex)context.getBean("complex");
		ct.print();
	}
	public static void main(String[] args) {
		//① 加载配置文件
		ApplicationContext context=new ClassPathXmlApplicationContext("Spring.xml");
		//字符串属性注入 set方式实例
//		setTest(context);
		//字符串属性注入 有参构造方式实例 
//		structureTest(context);
		//对象注入  set方式实例
//		DaoTest(context);
		
		//P名称空间注入
//		PTest(context);
		
		//复杂类型注入
		ComplexTest(context);
	}
}
