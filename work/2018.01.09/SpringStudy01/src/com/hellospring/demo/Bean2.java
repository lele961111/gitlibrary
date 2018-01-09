package com.hellospring.demo;

public class Bean2 implements IBean {

	@Override
	public void add() {
		System.out.println("bean2 静态工厂创建");
	}
	
}
