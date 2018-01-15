package com.hellospring.demo;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.AfterReturning;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;

@Aspect
public class AdviceBook {
	@Before(value="execution(* com.hellospring.demo.Book.*(..))")
	public void before() {
		System.out.println("AviceBook before() 前置通知");
	}
	@After(value="execution(* com.hellospring.demo.*.*(..))")
	public void after1() {
		System.out.println("AviceBook after1() 后置通知");
	}
	@AfterReturning(value="execution(* com.hellospring.demo.*.*(..))")
	public void after2() {
		System.out.println("AviceBook after2() 返回通知");
	}
	@Around(value="execution(* com.hellospring.demo.*.*(..))")	
	public void around(ProceedingJoinPoint pjp) throws Throwable {
		System.out.println("around before");
		pjp.proceed();
		System.out.println("around after");
		
	}
}
