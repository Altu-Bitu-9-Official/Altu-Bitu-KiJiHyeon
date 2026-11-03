#include stack
#include iostream
#include string getline 함수를 위해서.

using namespace std;

push, pop
bool checkParen(const string &str){
    stackchar st;
    
    for (char c  str){
        if(c == '('  c == '['){
                st.push(c); 여는 괄호는 스택에 넣음.
            }
        else if(c == ')'){
            if(st.empty()  st.top() != '(') return false;
            st.pop();
        }
        else if(c == ']'){
            if(st.empty()  st.top() != '[') return false;
            st.pop();
        }
       
        }
    return true; 이거 안 됨. 최종적으로도 비어있어야 함.
    return st.empty();
}


int main(){
    iossync_with_stdio(false); 효율을 위한 부분
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    cin  s; 필요없음.
    
    입력받음.
    while(getline(cin, s)){ 공백 포함 받아옴.
        if(s == .){ 온점은 종료조건
            break;
        }
        
        if(checkParen(s)){
            cout  yesn;
        }
        else{
            cout  non;
        }
        
    }
    
    
    return 0;
}