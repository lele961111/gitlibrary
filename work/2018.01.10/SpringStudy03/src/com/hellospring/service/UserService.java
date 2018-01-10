package com.hellospring.service;

import javax.annotation.Resource;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.hellospring.dao.UserDao;

@Component(value="userService")
public class UserService {
	
	//注解 不需要用set方法
	//自动注入属性
//	@Autowired
//	UserDao userdao;
	
	//Rescoure  name属性值写注解创建对象的value值
	@Resource(name="userDao")
	UserDao userdao;
	
	public void add() {
		userdao.add();
		System.out.println("UserService add()");
	}
}
