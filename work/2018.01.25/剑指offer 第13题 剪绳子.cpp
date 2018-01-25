#include<iostream>
#include<math.h>
using namespace std;

/*
	��ָoffer������14 ������
	��Ŀ��
		����һ������Ϊn�����ӣ�������Ӽ���m�Σ�m,n����������n>1����m>1��,ÿ�����ӵĳ��ȼ�Ϊk[0],k[1],...,k[m].����k[0]*k[1]*...*k[m]���ܵ����˻��Ƕ��٣����磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3,3�����Σ���ʱ�õ������˻���18.
	�����������������ַ�������ֱ��Ƕ�̬�滮��̰���㷨��
		��̬�滮���ĸ��ص㣬����������Ľ�Ϊ���Ž⣬��������������Ž�����������������Ž⣬��������֮�仹���໥�ص��ĸ�С�����⣬�ܴ������·������⣬���������������
		̰���㷨��ֻ��֤ÿһ���ó��Ľ��Ϊ���Ž�
*/


//��̬�滮
int maxdp(int length){
	if(length<2){  //ֱ���г�����3���ڵ����˻�
		return 0;
	}
	if(length==2){
		return 1;
	}
	if(length==3){
		return 2;
	}
	int* n=new int[length+1]; //�����洢����������Ž�
	n[0]=0;
	n[1]=1;
	n[2]=2;
	n[3]=3;
	int max=0;
	for(int i=4;i<=length;i++){ 
		max=0;
		for(int j=1;j<=i/2;++j){ //�������н⣬Ѱ�����Ž�
			int count=n[j]*n[i-j];
			if(max<count){
				max=count;
			}
			n[i]=max; //�洢���Ž�
		}
	}
	max=n[length];
	delete[] n;
	
	return max;
}


//̰���㷨
int maxtl(int length){
	if(length<2){
		return 0;
	}
	if(length==2){
		return 1;
	}
	if(length==3){
		return 2;
	}
	int count1=length/3; //��3�ı���
	if(length-count1*3==1){ //��ʣ���ֵΪ1ʱ ˵������3,1 ���Ϊ2 2 ����count1--
		count1-=1;
	}
	int count2=(length-count1*3)/2; //��ʣ��������2�ĸ���
	return (int)(pow(3,count1))*(int)(pow(2,count2));//pow(a,b)  a��b�η�
}

int main(void){
	cout<<"���������ӵĳ��ȣ�"<<endl;
	int length;
	cin>>length;
	cout<<length<<"���������ܼ��ɳ˻����Ϊ��"<<maxdp(length)<<endl;
	cout<<length<<"���������ܼ��ɳ˻����Ϊ��"<<maxtl(length)<<endl;
	return 0;
}