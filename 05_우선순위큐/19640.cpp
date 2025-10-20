#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct employee{
    int workday, urgent, idx, numinline;
    bool operator<(const employee& other) const{
        if(workday != other.workday) return workday < other.workday;
        if(urgent != other.urgent) return urgent < other.urgent;
        if(idx != other.idx) return idx > other.idx;
        return false; //빼먹지 말기,,,,
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k; // n :사원, m : 줄 수, k : 대기 인원, 나는 k+1번째
    cin >> n >> m >> k;
    
    //아이디어..
    //매번 선두에 있는 사람들만 힙에 넣고, 한 명씩 빠질 때마다 힙에 새 사람을 채워넣어서 비교하면 되겠네..
    //나머지 = 0인 사람이 선두. 결국 나머지 그 자체가 m개의 줄에서의 자신의 번호가 될듯.
    //if( 근무 일수가 높다면 if( 화장실이 급하다면 if( 번호가 낮다면 ) 화장실을 쓰고, 
    //pop되고, 해당 줄에 있던 사람이 선두로 온다. count++)) //이걸 operator에 쓰면 정상 작동.
    
    vector<vector<employee>> lines(m); // m개의 줄

    // 입력
    for (int i = 0; i < n; ++i) {
        int d, u;
        cin >> d >> u;
        lines[i % m].push_back({d, u, i, i % m});
    }
    
    vector<int> frontIdx(m, 0);

    // 각 줄의 맨 앞사람을 우선순위 큐에 넣기
    priority_queue<employee> pq;
    for (int i = 0; i < m; ++i) {
        if (!lines[i].empty()) {
            pq.push(lines[i][0]);
            frontIdx[i] = 0;
        }
    }

    int count = 0;
    while (!pq.empty()) {
        employee current = pq.top();
        pq.pop();

        // 내가 화장실을 사용하는 순간
        if (current.idx == k) {
            cout << count;
            return 0;
        }

        count++;
        
        // 줄에서 다음 사람을 큐에 추가
        int linenum = current.numinline;

        frontIdx[linenum]++;
        if (frontIdx[linenum] < (int)lines[linenum].size()) {
            pq.push(lines[linenum][ frontIdx[linenum] ]);
        }
    }
    
    return 0;
}