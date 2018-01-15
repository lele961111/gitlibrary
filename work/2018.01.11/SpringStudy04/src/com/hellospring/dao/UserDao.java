package com.hellospring.dao;

import org.springframework.jdbc.core.JdbcTemplate;

public class UserDao {
	private JdbcTemplate jdbcTemplate;

	public void setJdbcTemplate(JdbcTemplate jdbcTemplate) {
		this.jdbcTemplate = jdbcTemplate;
	}

	public void add() {
		String sql="insert into users values(default,?,?)";
		int count=jdbcTemplate.update(sql,"1222","1222");
		System.out.println(count);
	}
	
	public void delete() {
		String sql="delete form users where userId=?";
		int count=jdbcTemplate.update(sql, "4");
		System.out.println(count);
	}
}
