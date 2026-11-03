#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string origin; //첫 글자까지는 입력을 받기
    cin >> n >> origin;
    
    //A = 0, B = 1 .. 이런 식으로 넣어놓기
    vector<int> originalpha(26, 0);
    for(char c : origin) originalpha[c - 'A']++;
    
    int ans = 0; //추가해나가기.
    
    for(int i=0;i<n-1;i++){
        string s;
        cin >> s;
        
        //길이차 2이상은 안 됨.
        if(abs((int)origin.size() - (int)s.size()) > 1) continue;
        
        vector<int> alpha(26, 0);
        for(char c : s) alpha[c-'A']++;
        
        int diff = 0;
        for (int i = 0; i < 26; ++i)
        diff += abs(originalpha[i] - alpha[i]);
        
        //같거나
        if(diff == 0){
            ans++;
        }
        //배열에서 하나의 숫자만 다름 > DOG, GOOD 같은 느낌
        if(diff == 1){
            ans++;
        }
        //a=1,b=0 / a=0, b=1의 느낌
        if(diff == 2){
            ans++;
        }
    }
    
    cout << ans;
    
    return 0;
}