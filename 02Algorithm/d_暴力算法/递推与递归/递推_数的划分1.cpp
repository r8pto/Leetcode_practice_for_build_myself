#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int f(int n, int m){
	if(n==0 || m==0 || n<m){ // ��һ������������������ 
		return 0;
	}
	if(m==1 | n==m){  // �ڶ��������ֻ��һ�����ֻ��n����ȫ��1 
		return 1;
	}else{
		return f(n-m,m) + f(n-1,m-1); // ������������û���� 
	}
}


int main(int argc, char** argv) {
	int n, k;
	cin>>n>>k;
	cout << f(n,k) << '\n'; 
	return 0;
}
