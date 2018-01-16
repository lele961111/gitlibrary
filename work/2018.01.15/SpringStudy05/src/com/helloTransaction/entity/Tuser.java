package com.helloTransaction.entity;

import java.io.Serializable;

public class Tuser implements Serializable {
	private int userId;
	private String userName;
	private int userMoney;
	public Tuser() {
		super();
		// TODO Auto-generated constructor stub
	}
	public Tuser(int userId, String userName, int userMoney) {
		super();
		this.userId = userId;
		this.userName = userName;
		this.userMoney = userMoney;
	}
	public int getUserId() {
		return userId;
	}
	public void setUserId(int userId) {
		this.userId = userId;
	}
	public String getUserName() {
		return userName;
	}
	public void setUserName(String userName) {
		this.userName = userName;
	}
	public int getUserMoney() {
		return userMoney;
	}
	public void setUserMoney(int userMoney) {
		this.userMoney = userMoney;
	}
}
