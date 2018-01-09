package com.hellospring.demo;

public class User {
	private String name;
	
	//用set方法注入属性
	public void setName(String name) {
		this.name = name;
	}
	
	public void print() {
		System.out.println("name="+name);
	}
	
}
