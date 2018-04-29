#include <iostream>
#include <stack>

using namespace std;


struct MyQueue {
    //stack s1 stores newest on top while stack s2 stores oldest on top
    //therefore for dequeue pop s2 and for enqueue push into s1    
    //s1 is transferred (pushed one at a time) into s2 if s2 is empty
    //the amoritzed cost of all three operations is O(1)
    stack<int> s1, s2;
    void enqueue(int x) {
        s1.push(x);
        }    
        
    void dequeue() {
        if(s2.empty())
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
                }
        s2.pop();
        }
        
    int& front(){
        if(s2.empty())
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
                }
        return s2.top();           
        }
    };


int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    for (int i = 0; i < q; ++i){
        cin >> type;
        if (type == 1) {
            cin >> x;
            q1.enqueue(x);
            }
        else if (type == 2)
            q1.dequeue();
        else
            cout << q1.front() << endl;        
        }        
    
    return 0;
    }
