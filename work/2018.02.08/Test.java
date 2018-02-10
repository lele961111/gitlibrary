import java.util.Scanner;

public class Test {
	
	public static void suan(Scanner scan){
		System.out.println("请输入方阵的边：");
		int n=scan.nextInt();
		int[][] fangzhen=new int[n][n]; //创建二维数组代表旋转方阵
		int angin=0,end=n-2;//angin表示开始跑的下标值，end表示结束的下标值
		int count=0;//计数,用于考虑n为奇数是，最后一个数fangzhen[n/2][n/2]的赋值问题
		int x=0,y=0;//x表示行的下标，y表示列的下标
		for(int k=0;k<(n+1)/2;k++){
			System.out.println("for循环次数："+(k+1));//查看循环次数
			for(x=angin,y=angin;x<=end;x++){//第一个循环遍历1,2,3,4,5,   21,22,23    33     
				count++;
				fangzhen[x][y]=count;
				System.out.println(fangzhen[x][y]+"   x="+x+" y="+y);//测试是否填空正确
			}
			System.out.println("d第一个for循环结束");
			for(y=angin;y<=end;y++){
				count++;
				fangzhen[x][y]=count;
				System.out.println(fangzhen[x][y]+"   x="+x+" y="+y);
			}
			System.out.println("d第二个for循环结束");
			for(x=end+1;x>angin;x--){
				count++;
				fangzhen[x][y]=count;
				System.out.println(fangzhen[x][y]+"   x="+x+" y="+y);
			}
			System.out.println("d第三个for循环结束");
			for(y=end+1;y>angin;y--){
				count++;
				fangzhen[x][y]=count;
				System.out.println(fangzhen[x][y]+"   x="+x+" y="+y);
			}
			System.out.println("d第四个for循环结束");
			angin++;
			end--;
			System.out.println("angin="+angin+"end="+end);
		}	
		if(count!=n+n){
			fangzhen[n/2][n/2]=n*n;
		}
		for(int i=0;i<n;i++){//遍历方针
			for(int j=0;j<n;j++){
				System.out.print(fangzhen[i][j]+" ");
			}
			System.out.println("");
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		suan(scan);
	}

}