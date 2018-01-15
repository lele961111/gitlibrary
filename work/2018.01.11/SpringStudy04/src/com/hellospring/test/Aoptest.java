package com.hellospring.test;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.hellospring.demo.Book;

public class Aoptest {
	
	@Test
	public void beforetest() {
		ApplicationContext context=new ClassPathXmlApplicationContext("spring.xml");
		Book book=(Book) context.getBean("book");
		book.add();
	}
}
