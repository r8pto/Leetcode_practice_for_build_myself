#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int calculateDayOfYear(string day, const vector<int> &prefixSum){
	int month = stoi(day.substr(0, 2));  // ��n�����ַ���ת��Ϊʮ���ƣ�ʹ��ʱ����ͷ�ļ�string 
	int date = stoi(day.substr(3));
	return prefixSum[month - 1] + date;  // ����ǰ׺�͵�˼�룬��ÿ���µ���һ�����飬������Щ�ͣ�����ܹ������� 
}

int main(int argc, char** argv) {
	// 1. �����������ڲ��� 
	string arriveAlice, leaveAlice, arriveBob, leaveBob;
	 
	cin>>arriveAlice>>leaveAlice>>arriveBob>>leaveBob;
	vector<int> datesOfMonths = {31, 28, 31, 30, 31, 30, 31, 31,
								30, 31, 30, 31};  // ����һ���������·ݵ����� 
								
	vector<int> prefixSum(1, 0);  // ǰ׺�ͼ��� 
	    for (int date : datesOfMonths) {
            prefixSum.emplace_back(prefixSum.back() + date);   
        }

        int arriveAliceDay = calculateDayOfYear(arriveAlice, prefixSum);  // �����ʱһ���еĶ����� 
        int leaveAliceDay = calculateDayOfYear(leaveAlice, prefixSum);
        int arriveBobDay = calculateDayOfYear(arriveBob, prefixSum);
        int leaveBobDay = calculateDayOfYear(leaveBob, prefixSum);
        cout<<max(0, min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay) + 1) <<endl;


}


