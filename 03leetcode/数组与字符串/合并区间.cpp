#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// �Լ����庯��ʱ��Ҫ���β�������������
void output(vector<vector <int>> intervals) {
	// �������
	for (auto i : intervals) {
		for (auto j : i) {
			cout << j<<" ";
		}
		cout << endl;
	}
}

int main(){
	// ���Ե�һ��Ҳ���������������������
	// 1. ����Ҫ����һ�����Ҫ�����������
	vector<vector <int>> intervals;
	int n;   // ��Ҫ�ϲ�������ĸ���
	cin >> n;
	for (int i = 0; i < n; ++i) {
		vector<int> interval;
		for (int j = 0; j < 2; ++j) {
			int k;
			cin >> k;
			interval.push_back(k);
		}
		intervals.push_back(interval);
	}
	// ���жϵ�intervals��ֻ��һ��Ԫ��ʱ��ֱ�ӷ���
	if (n == 1) {
		output(intervals);
	}

	// 2. ��intervals�����������������Ҫ�ҵ��������
	sort(intervals.begin(), intervals.end());    // ��ԭ����������н�������

	vector<vector<int>> vec;
	vec.push_back(intervals[0]);  // �������һ������
	int j = 0;
	for (int i = j + 1; i < n; i++) {
		// �����Ǻ��Ѿ�ѡȡ�˵ļ��Ͻ��бȽϣ�����ܽ�����Ч�ĸ���
		if (intervals[i][0] <= vec[j][1]) {  // i��j��1���������˼����һ�����ϵ���������һ�����ϵ��յ�
			vec[j][1] = max(vec[j][1], intervals[i][1]);   // ����ϴ���Ǹ���Χ
		}
		else {
			vec.push_back(intervals[i]);  // û���ص�����ֱ�����һ������
			j++;
		}
	}

	output(vec);


	system("pause");
	return 0;
}