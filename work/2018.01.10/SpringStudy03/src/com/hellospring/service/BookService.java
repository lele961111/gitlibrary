package com.hellospring.service;

import javax.annotation.Resource;

import com.hellospring.dao.BookDao;

public class BookService {
	
	@Resource(name="bookDao")//value值必须为id
	BookDao bookDao;
	public void Add() {
		System.out.println(bookDao);
		bookDao.buy();
		System.out.println("BookService add()"); 
	}
}
