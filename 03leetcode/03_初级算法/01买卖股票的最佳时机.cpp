#include<iostream>
#include<vector>
using namespace std;
/*
 * 给你一个整数数组prices, 其中prices[i]表示某支股第i天的价格。
 * 在每一天，你可以决定是否购买和/或出售股票。你在任何时候最多只能持有一股股票。
 * 你可以先购买，然后在同一天出售
 * 返回：你能获得的最大利润。
 */

int maxProfit(vector<int>& prices){
    decltype(prices.size()) n = prices.size();
    int profit=0;
    for(int i=0; i<n-1;i++){
        if(prices[i+1]>prices[i]){
            int diff = prices[i+1] - prices[i];
            profit+=diff;
        }
    }
    return profit;
}


int main(){
    // 1. 输入
    int n;
    cin>>n;
    vector<int> prices;
    for(int i=0;i<n;++i){
        int j;
        cin>>j;
        prices.push_back(j);
    }
    // 2. 执行函数体
    int ans = maxProfit(prices);

    // 3. 输出
    cout<<ans<<endl;

    return 0;
}