package com.hellospring.demo;

public class Bean3 implements IBean {

	@Override
	public void add() {
		System.out.println("bean3 使用非静态工厂创建");
	}

}
