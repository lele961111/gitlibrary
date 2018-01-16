package com.helloTransaction.service;

import com.helloTransaction.dao.TuserDao;

public class TuserService {
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
