#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	// 1. ������������� 
	int n;
	cin>>n;
	int num[n];
	for(int i=0; i<n; i++){
		cin>>num[i];
	}
	
	// 2. ��������������±�
	// (1) �ȼ����ܺ� 
	int size = sizeof(num)/sizeof(num[0]);
	int sum = 0;
	for (int i=0;i<size;i++){
		sum +=num[i];
	}
	
	// (2) ����߿�ʼ���㣬���left*2 + num[i] == all �����i
	int left = 0;
	for (int i=-1;i<size; i++){
		if(i==-1){
			left=0;
		}else{
			left += num[i-1];
		}

		if(left*2 + num[i]==sum){
			cout<<i;
			break;
		}else{
			if(i==size-1){
				cout<<-1;
			}
		}
	}

}


