package com.hellojava.demo;
/*
 * 本类原意是为了实现编程式BeanFactory的三个步骤:定位,载入,解析
 * ①定位: Resource(位置)
 * ②载入: BeanFactory beanFactory =new DefaultBeanFactory();
 * 		 Reader r=new (指定BeanFactory)
 * ③解析: r.readResource()
 * 
 * ApplicotionContext 是对上面三个步骤的封装
 * 具体实现 见 test文件
 * 
 * 实际上由于自己对这个编程式BeanFactory还没有领悟, 只通过文件流,集合,截取字符串做到定位,载入吧.
 */
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class BFdemo {
	
	static String id;//存放含有id内容的子字符串
	static String cla;//存放含有class内容的子字符串
	static String s1;
	static String s2;
	static int i=0;
	static int j=0;
	static boolean b=true; //控制字符串拆分赋值条件
	Map<String,String> map=new HashMap<String,String>(); //创建Map集合存放id和class
	
	private String Fname;//文件名

	public BFdemo(String fname) {
		super();
		Fname = fname;
	}
	public void Do() {
		if(Fname.endsWith(".xml")) {//判断是否为xml文件
			//此处文件位置获取不够灵活,xml只能存放在src文件夹下,但也不会直接写死,导致项目转移出现错误
			//File f=new File("E:\\javaspace-sts\\SpringFactoryTest\\src\\Spring.xml");
			File f=new File(this.getClass().getResource("/").getPath()+"\\"+Fname);
			//利用字符流来读取文件
			FileReader fr=null;
			BufferedReader br=null;
			try {
				fr=new FileReader(f);
				br=new BufferedReader(fr);
				String s=br.readLine();
				//对每一行进行操作
				while(s!=null) {
					if(s.indexOf(" id=\"")>0||s.indexOf(" class=\"")>0) {
						find(s);
					}
					
					s=br.readLine();
				}
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			if(fr!=null) {//关闭文件操作
				try {
					fr.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}			
		}
		//输出截取字符串得到的id和class内容
		print();
		
	}
	
	//find方法不够灵活,它只能对一行只要一个id和class 的字符串操作,所有xml文件必须中规中矩
	public void find(String s) {
		for (String string : s.split(" id=\"")) {//得到两个字符串,第一个是" id="",第二个开始一部分就是需要的内容
			id=string;
		}
		for (String string : id.split("\"",2)) {//将含有id信息的字符串再次分割
			if(b) {	//将分割后的第一个字符串付给s1 即得到需要的id内容
				
				s1=string;
				i++;
				b=false;
			}
			else {
				s=string;
				b=true;
			}			
		}
	
		//与去id内容类似
		for (String string : s.split(" class=\"")) {
			cla=string;
		}
		for (String string : cla.split("\"",2)) {
			if(b) {	
				s2=string;
				j++;
				b=false;
			}
			else {
				s=string;				
				b=true;
			}			
		}
		map.put(s1, s2);
	}
	
	public void print() {
		//遍历hashmap   迭代器遍历    entrySet()方法返回一个存储Entry<k,v>类型对象的Set集合
		Set<Entry<String,String>> entrySet=map.entrySet();
		Iterator<Entry<String,String>> it=entrySet.iterator();
		while(it.hasNext()) {
			Entry<String,String> e=it.next();
			System.out.println("id="+e.getKey()+"  class="+e.getValue());
		}
	}
	
}
