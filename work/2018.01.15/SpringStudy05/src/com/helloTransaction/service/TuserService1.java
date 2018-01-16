package com.helloTransaction.service;

import org.springframework.transaction.annotation.Transactional;

import com.helloTransaction.dao.TuserDao;

@Transactional
public class TuserService1 {
	private TuserDao tuserDao;

	public void setTuserDao(TuserDao tuserDao) {
		this.tuserDao = tuserDao;
	}


	public void trading() {
		tuserDao.add();
		int i=10/0;
		tuserDao.reduce();
	}
}
