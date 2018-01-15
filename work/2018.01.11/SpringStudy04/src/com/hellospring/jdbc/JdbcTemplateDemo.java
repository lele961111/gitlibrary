package com.hellospring.jdbc;

import java.util.List;

import javax.sql.DataSource;

import org.junit.Test;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.datasource.DriverManagerDataSource;

import com.hellospring.entity.User;
import com.mchange.v2.c3p0.ComboPooledDataSource;

public class JdbcTemplateDemo {
	static JdbcTemplate jdbcTemplate;
	static {		
			//设置数据库信息
			DriverManagerDataSource dataSource=new DriverManagerDataSource();
			dataSource.setDriverClassName("com.mysql.jdbc.Driver");
			dataSource.setUrl("jdbc:mysql://localhost:3306/user?useSSL=true");
			dataSource.setUsername("root");
			dataSource.setPassword("a12345");
				
			//创建jdbcTemplate对象，设置数据库
			jdbcTemplate=new JdbcTemplate(dataSource);
	}
	
	//添加
	@Test
	public void add() {	
		//调用jdbcTemplate对象里面的方法实现操作
		//创建sql语句
		
		String sql="insert into users values(default,?,?)";
		int count=jdbcTemplate.update(sql,"111","111");
		System.out.println(count);
	}
	
	//删除
	@Test
	public void delete() {	
		//调用jdbcTemplate对象里面的方法实现操作
		//创建sql语句
		String sql="delete from users where userId=?";
		int count=jdbcTemplate.update(sql,2);
		System.out.println(count);
	}
	
	//修改
	@Test
	public void update() {	
		//调用jdbcTemplate对象里面的方法实现操作
		//创建sql语句
		String sql="update users set userPwd=?  where userName=?";
		int count=jdbcTemplate.update(sql,"123","111");
		System.out.println(count);
	}
	
	//查询返回一个值
	@Test
	public void savevalue() {
		String sql="select count(*) from users";
		int count=jdbcTemplate.queryForObject(sql, Integer.class);
		System.out.println(count);
	}
	
	//查询返回一个对象
	@Test
	public void saveobject() {
		String sql="select * from users where userid=?";
		User user=jdbcTemplate.queryForObject(sql,new MyRowMapper(), 1);
		System.out.println(user);
	}
	
	//查询返回一个list集合
	@Test
	public void savelist() {
		String sql="select * from users";
		List<User> list=jdbcTemplate.query(sql,new MyRowMapper());
		System.out.println(list);
	}
	
	
}
