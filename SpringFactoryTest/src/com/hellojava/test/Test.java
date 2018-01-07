package com.hellojava.test;

import javax.annotation.Resource;

import org.springframework.beans.factory.support.DefaultListableBeanFactory;
import org.springframework.beans.factory.xml.XmlBeanDefinitionReader;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.core.io.ClassPathResource;
import com.hellojava.demo.BFdemo;
import com.hellojava.demo.C;

public class Test {
	public static void main(String[] args) {
		//定义,载入,解析
//		DefaultListableBeanFactory factory = new DefaultListableBeanFactory();
//		XmlBeanDefinitionReader reader=new XmlBeanDefinitionReader(factory);
//		org.springframework.core.io.Resource resource = new ClassPathResource("Spring.xml");
//		reader.loadBeanDefinitions(resource);
//		C c=factory.getBean(C.class);	
//		c.Do();
		
		//封装
//		ApplicationContext context=new ClassPathXmlApplicationContext("spring.xml");
//		C c=(C)context.getBean(C.class);
//		c.Do();
		
		//只是简单的将文件中的需要的信息存放在Map集合中
		BFdemo bf=new BFdemo("spring.xml");
		bf.Do();
		
	}
}
