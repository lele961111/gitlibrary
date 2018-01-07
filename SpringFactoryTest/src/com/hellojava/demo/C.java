package com.hellojava.demo;

public class C {
	private InterFace IF;

	public InterFace getIF() {
		return IF;
	}
	
	public C() {
		super();
		// TODO Auto-generated constructor stub
	}

	public void setIF(InterFace iF) {
		IF = iF;
	}

	public C(InterFace iF) {
		super();
		IF = iF;
	}
	public void Do() {
		IF.show();
	}
}
