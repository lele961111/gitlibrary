package com.helloTransaction.dao;

import org.springframework.jdbc.core.JdbcTemplate;

public class TuserDao {
	private JdbcTemplate jdbcTemplate;

	public void setJdbcTemplate(JdbcTemplate jdbcTemplate) {
		this.jdbcTemplate = jdbcTemplate;
	}
	
	public void add() {
		String sql="update Tuser set userMoney=userMoney+? where userId=?";
		int count=jdbcTemplate.update(sql, "1000","1");
		System.out.println(count);
	}
	
	public void reduce() {
		String sql="update Tuser set userMoney=userMoney-? where userId=?";
		int count=jdbcTemplate.update(sql, "1000","2");
		System.out.println(count);
	}
	
}
