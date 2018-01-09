package com.hellospring.demo;


public class Bean1 implements IBean{
	
	static {
		System.out.println("静态块，只执行一次");
	}
	
	@Override
	public void add() {
		System.out.println("bean1 使用类的无参构造创建");
	}
	public void init() {
		System.out.println("bean实例化的三种方式");
	}
}
