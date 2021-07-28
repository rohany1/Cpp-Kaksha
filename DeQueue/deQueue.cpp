#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);

    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<" ";
    }cout<<endl;

    dq.pop_front();
    dq.pop_back();

    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<" ";
    }cout<<endl;
}