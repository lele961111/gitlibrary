package com.hellospring.test;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.hellospring.service.UserService;

public class Servicetest {
	static UserService userService;
	static {
		ApplicationContext context=new ClassPathXmlApplicationContext("spring.xml");
		userService=(UserService) context.getBean("userService");
	}
	@Test
	public void addtest() {		
		userService.add();
	}
	
	@Test
	public void deletetest() {
		userService.delete();
	}
}
