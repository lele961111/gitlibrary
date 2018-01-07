package com.hellojava.test;

/*
 * 实现截取字符串功能
 */
public class StringTest {
	static String id="";
	static String cla="";
	static String[][] ss= {{""},{""}};
	static int i=0;
	static int j=0;
	static boolean b=true;
	public static void main(String[] args) {
		String s="	<bean id=\"a\" class=\"com.hellojava.demo.A\"></bean>";
		
		for (String string : s.split(" id=\"")) {
			id=string;
		}
		
		for (String string : id.split("\"",2)) {
			if(b) {				
				ss[0][i]=string;
				i++;
				b=false;
			}
			else {
				s=string;
				b=true;
			}			
		}
	
		
		for (String string : s.split(" class=\"")) {
			cla=string;
		}
		for (String string : cla.split("\"",2)) {
			if(b) {	
				ss[1][j]=string;
				j++;
				b=false;
			}
			else {
				s=string;				
				b=true;
			}			
		}
		System.out.println(ss[0][0]);
		System.out.println(ss[1][0]);
	}
}
