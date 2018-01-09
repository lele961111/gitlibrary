package com.hellospring.demo;

import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.Properties;

public class Complex {
	private String[] str;
	private List<String> list;
	private Map<String, String> map;
	private Properties properties; //继承hashtable
	public void setStr(String[] str) {
		this.str = str;
	}
	public void setList(List<String> list) {
		this.list = list;
	}
	public void setMap(Map<String, String> map) {
		this.map = map;
	}
	public void setProperties(Properties properties) {
		this.properties = properties;
	}
	public void print() {
		System.out.println(str);
		System.out.println(list);
		System.out.println(map);
		System.out.println(properties);
	}
	
}
