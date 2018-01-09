package com.hellospring.demo;

public class Person {
	private String pname;
	
	public Person(String pname) {
		this.pname=pname;
	}
	
	public void print() {
		System.out.println("pname="+pname);
	}
}
