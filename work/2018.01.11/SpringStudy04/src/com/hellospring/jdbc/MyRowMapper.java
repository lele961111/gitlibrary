package com.hellospring.jdbc;

import java.sql.ResultSet;
import java.sql.SQLException;

import org.springframework.jdbc.core.RowMapper;

import com.hellospring.entity.User;

public class MyRowMapper implements RowMapper<User> {

	@Override
	public User mapRow(ResultSet rs, int num) throws SQLException {
		
		//从结果集中取出数据
		int id=rs.getInt("userId");
		String username=rs.getString("userName");
		String userpwd=rs.getString("userPwd");
		//把数据封装到对象里边
		User user=new User();
		user.setId(id);
		user.setUsername(username);
		user.setUserPwd(userpwd);
		return user;
	}

}
