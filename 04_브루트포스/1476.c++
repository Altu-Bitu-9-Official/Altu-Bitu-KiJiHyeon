#include <iostream>
using namespace std;

int calculateYear(int E, int S, int M){
    for(int i=1;i<7980;i++){ //어차피 최대 가능 year는 7980년
        if((i - E + 15) % 15 == 0)
            if((i - S + 28) % 28 ==0)
                if((i - M + 19) % 19 ==0)
                    return i;
    }
}

int main(){
    
    int E, S, M;
    cin >> E >> S >> M;
    
    cout << calculateYear(E, S, M);
    return 0;
}

