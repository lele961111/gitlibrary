package com.hellospring.service;

import com.hellospring.dao.UserDao;

public class UserService {
	private UserDao userDao;
	
	public void setUserDao(UserDao userDao) {
		this.userDao = userDao;
	}

	public void print() {
		System.out.println("UserService print()");
		userDao.print();
	}
}
