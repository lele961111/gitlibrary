package com.hellospring.dao;

import org.springframework.stereotype.Component;

@Component(value="userDao")
public class UserDao {
	public void add() {
		System.out.println("UserDao add()");
	}
}
