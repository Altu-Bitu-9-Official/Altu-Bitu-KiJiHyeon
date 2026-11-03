#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getGcd(int a, int b){//최대공약수 구하는 함수
    int tmp;
    while(b!=0){
        tmp = a%b;
        a = b;
        b = tmp; //a가 더 크게.
    }
    return a; //b가 0이 되면 a return
}

int main(){
    int N, S;
    cin >> N >> S;
    
    vector<int> pos(N);
    for(int i=0;i<N;i++){
        cin >> pos[i]; //동생들의 위치 입력
    }
    
    vector<int>gcd(N); //받아온 위치를 최대공약수 구하기 용으로 전환(실제로는 윗 for문에 한 번에 쓸듯.)
    for(int i=0;i<N;i++){
        if(pos[i] >= S)
            gcd[i] = pos[i] - S;
        else
            gcd[i] = S-pos[i];
    }
  
    int ans = gcd[0]; //N=1일 상황 대비
    for(int i=0; i<N-1 ;i++){
        ans = getGcd(gcd[i], gcd[i+1]);
        gcd[i+1] = ans;
    }
    
    cout << ans;
    
    return 0;
}