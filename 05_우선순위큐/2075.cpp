#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> pq; 
    
    //이미 개수가 꽉 찼으면 검사 후 넣기.
    
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){ //NxN
            
            int num;
            cin >> num;
            
            if(pq.size() < n){ //현재 개수가 n보다 작으면 바로 큐에 넣기
                pq.push(num);
            }
            else if(num > pq.top()) {//n보다 크다면 n개의 큰 수 안에 들어갈 수 있는 지 검사. 
                pq.pop();
                pq.push(num);
            }
        }
    }
    
    //top에 n번째로 큰 수가 있음. 
    cout << pq.top();

    return 0;
}