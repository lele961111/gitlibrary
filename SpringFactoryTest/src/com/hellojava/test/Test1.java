package com.hellojava.test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import com.hellojava.demo.A;

/*
 * 读取文件信息测试
 */
public class Test1 {
	public static void main(String[] args) {
		File f=new File("E:\\javaspace-sts\\SpringFactoryTest\\src/Spring.xml");
		FileReader fr=null;
		BufferedReader br=null;
		try {
			fr=new FileReader(f);
			br=new BufferedReader(fr);
			String i=br.readLine();
			while(i!=null) {
				System.out.println(i);
				i=br.readLine();
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		if(fr!=null) {
			try {
				fr.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}		
	}
}
