package com.hellospring.demo;

import org.aspectj.lang.ProceedingJoinPoint;

public class AdviceBook {
	public void before() {
		System.out.println("AviceBook before() 前置通知");
	}
	
	public void after1() {
		System.out.println("AviceBook after1() 后置通知");
	}
	
	public void after2() {
		System.out.println("AviceBook after2() 返回通知");
	}
		
	public void around(ProceedingJoinPoint pjp) throws Throwable {
		System.out.println("around before");
		pjp.proceed();
		System.out.println("around after");
		
	}
}
