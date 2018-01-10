package com.hellospring.test;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.hellospring.service.BookService;


public class HybridTest {
	public static void main(String[] args) {
		ApplicationContext context=new ClassPathXmlApplicationContext("hybridspring.xml");
		BookService bs=(BookService) context.getBean("bookService");
		bs.Add();
	}
}
