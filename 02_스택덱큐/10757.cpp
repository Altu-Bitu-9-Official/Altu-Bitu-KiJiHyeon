//각 자릿수의 합을 stack에 넣어서 하나하나 빼자 가 아이디어.

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    //int가 아닌 string으로 받아오기
    string num1, num2;
    cin >> num1 >> num2;
    
    if (num1.length() < num2.length()){
        swap(num1, num2);
    }
    
    stack<int> ans;
    
    int i = num1.length() - 1;
    int j = num2.length() -1;
    int carry = 0;
    
    // 두 숫자의 자릿수를 끝에서부터 더하기
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';

        ans.push(sum % 10);
        carry = sum / 10;
    }

    // 결과 출력
    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
    cout << '\n';
    
    return 0;
}