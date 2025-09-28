#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int substringSet(string s){
    int len = s.size();
    set<string> str;
    
    for(int i=0;i<len;i++){
        for(int j = i+1; j<=len; j++){
            string sub = s.substr(i, j-i);
            str.insert(sub);
        }
    }
    
    return str.size();
}

int main(){
    string s;
    cin >> s;
    
    cout << substringSet(s); //set은 중복 값을 넣어도 한 번만 저장함.
    
    return 0;
}