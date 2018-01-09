package com.hellospring.demo;

public class Bean2Factory {
	//静态方法，返回bean2对象
	public static IBean getBean() {
		return new Bean2();		
	}
}
