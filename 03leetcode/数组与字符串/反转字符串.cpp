#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    vector<char> s;
    char c;
    while(cin>>c){   // unix系统ctrl + D 
        s.push_back(c);
    }

    auto p1 = s.begin();  
    auto p2 = s.end()-1;  // 尾后迭代器需要-1才指向最后一个元素
    // int n = s.size();
    // char* p1 = &s[0];
    // char* p2 = &s[n-1];

    while(p1 <= p2){
        swap(*p1, *p2);
        ++p1;  // 用前置自加自减运算符可以提高运行效率
        --p2;
    }

    for(auto c:s){
        cout<<c;
    }

}