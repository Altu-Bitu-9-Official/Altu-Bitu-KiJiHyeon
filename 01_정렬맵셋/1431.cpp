#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//자릿수 더하는 함수
int sumDigit(string serialNum){
    int sum = 0;
    for(int i=0;i<serialNum.size();i++){
        if(isdigit(serialNum[i]))
            sum += serialNum[i] - '0'; //문자라서 숫자로 만들어줘야 함
    }
    return sum;
}

//sort함수에 쓸 cmp 부분
bool cmp(const string& s1, const string& s2){
//    if(s1.size > s2.size)
//        return true; 이렇게 쓰면 안 됨.
    if(s1.size() != s2.size()){
        return s1.size() < s2.size(); //길이 짧은 게 먼저
    }
    if(sumDigit(s1) != sumDigit(s2)){
        return sumDigit(s1) < sumDigit(s2);
    }
    return s1 < s2;
}

int main(){
    int n; //개수 입력받기
    cin >> n;
    
    vector<string> serialNum(n);
    for(int i=0; i<n; i++){
        cin >> serialNum[i]; //실제 시리얼번호 입력받기
    }
    
    sort(serialNum.begin(), serialNum.end(), cmp);
    
    // 출력
	for (int i = 0; i < n; i++) {
		cout << serialNum[i] << '\n';
	}
	return 0;
}