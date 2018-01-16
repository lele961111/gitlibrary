package com.helloTransaction.test;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import com.helloTransaction.service.TuserService;
import com.helloTransaction.service.TuserService1;


public class TuserTest {
	@Test
	public void xmltest(){
		ApplicationContext context=new ClassPathXmlApplicationContext("spring.xml");
		TuserService tuserService=(TuserService) context.getBean("tuserService");
		tuserService.trading();
	}
	
	@Test
	public void annotationtest() {
		ApplicationContext context=new ClassPathXmlApplicationContext("annotationspring.xml");
		TuserService1 tuserService1=(TuserService1) context.getBean("tuserService1");
		tuserService1.trading();
	}
}
