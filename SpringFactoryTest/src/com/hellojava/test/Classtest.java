package com.hellojava.test;

import java.io.File;

//测试获取类地址
public class Classtest {
	public static void main(String[] args) {
		Classtest c=new Classtest();
		c.getaddress();
		
	}
	public void getaddress() {
		File f = new File(this.getClass().getResource("/").getPath());
		System.out.println(f);
	}
}
