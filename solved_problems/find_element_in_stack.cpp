#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool found(stack<int> &S, int target){
    bool found = false;
    queue<int> Q;
    while(!S.empty()){
        if(S.top() == target){
            found = true;
        }
        Q.push(S.top());
        S.pop();
    }
    while(!Q.empty()){
        S.push(Q.front());
        Q.pop();
    }
    while(!S.empty()){
        Q.push(S.top());
        S.pop();
    }
    while(!Q.empty()){
        S.push(Q.front());
        Q.pop();
    }
    return found;
}

int main(){
    stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);

    if(found(S,3)){
        cout << "Value Exist\n";
    }
    else{
        cout << "Value not found\n";
    }
    
    cout << "Stack values order After Checking:";
    while(!S.empty()){
        cout << S.top() << " ";
        S.pop();
    }

}