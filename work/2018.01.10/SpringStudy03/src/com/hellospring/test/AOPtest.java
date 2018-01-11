package com.hellospring.test;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.hellospring.demo.Book;

public class AOPtest {
	@org.junit.Test
	public void test() {
		ApplicationContext context=new ClassPathXmlApplicationContext("AOPspring.xml");
		Book book=(Book) context.getBean("book");
		book.read();
	}
	
}
