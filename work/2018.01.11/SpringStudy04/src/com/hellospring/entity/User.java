package com.hellospring.entity;

public class User {
	private int id;
	private String username;
	private String userPwd;
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public String getUserPwd() {
		return userPwd;
	}
	public void setUserPwd(String userPwd) {
		this.userPwd = userPwd;
	}
	@Override
	public String toString() {
		return "User [id=" + id + ", username=" + username + ", userPwd=" + userPwd + "]";
	}
	
}
