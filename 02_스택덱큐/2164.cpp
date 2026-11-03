#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    queue<int> q;
        
    cin >> n;
    
    //숫자 쌓기, 1이 front 위치
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    
    while(q.size() > 1){
        q.pop(); // 제일 위에 있는 거 버리기
       // q.push(q.pop()); //위에 있는 걸 아래로 다시 넣기 //이거 안 됨..
        int tmp = q.front();
        q.push(tmp);
        q.pop();
    }
    
    cout << q.front();
    
    return 0;
}