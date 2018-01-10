package com.hellospring.test;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.hellospring.demo.User;
import com.hellospring.service.UserService;

public class Test {
	
	public static void main(String[] args) {
		ApplicationContext context=new ClassPathXmlApplicationContext("Spring.xml");
//		User u=(User) context.getBean("user");
//		u.add();
		UserService userService=(UserService) context.getBean("userService");
		userService.add();
	}
}
