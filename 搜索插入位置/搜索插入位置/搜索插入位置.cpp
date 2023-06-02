#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, target;
	vector<int> nums;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int j;
		cin >> j;
		nums.push_back(j);
	}
	cin >> target;
	// ��������Ҳ���ʱ�ᱨ��
	//auto index = find(nums.begin(), nums.end(), target);  // �������һ��Ҫ��auto--->�õ�����һ��ָ��
    // cout << *index;
	// 1. �ȱ�дһ�����Ӷ�ΪO(n2)���㷨
	//int count = 0;
	//for (int i = 0; i < n; ++i) {
	//	if (nums[i] == target) {
	//		cout << i;
	//		break;
	//	}
	//	count++;
	//	if (count == n) {
	//		for (int j = 0; j < n; j++) {
	//			if (target < nums[0]) {
	//				cout << 0;
	//				break;
	//			}

	//			if (j == n-1) {
	//				cout << nums.size();
	//				break;
	//			}
	//			if (nums[j] < target && nums[j+ 1]> target) {
	//				cout << j+1;
	//			}
	//		}
	//	}

	//}
	// 2. ���Ӷ�Ϊlog2n���㷨
	int left, right;

	if (target < nums[0]) {   // ���������target < nums[0]��
		cout << 0;
	}
	left = 0;
	right = nums.size() - 1;
	int i;
	while (left <=  right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			cout <<mid;
		}
		else if (nums[mid] < target) {
			// ��С��
			left = mid + 1;
		}
		else {
			// �´���
			right = mid - 1;
		}
	}
	// return left;  


	return 0;
}