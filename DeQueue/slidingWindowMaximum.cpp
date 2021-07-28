#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> maximumInWindow(vector<int> v,int n,int k){
    vector<int> answer;
    deque<int> dq(k);
    int i;
    for(i=0;i<k;i++){
        while(!dq.empty() && v[i]>=v[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(;i<n;i++){
        answer.push_back(v[dq.front()]);
        while(!dq.empty() &&  dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && v[i]>=v[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    answer.push_back(v[dq.front()]);
    return answer;
}
int main(){
    vector<int> vi={12,1,78,90,57,89,56};
    vector<int> ans=maximumInWindow(vi,vi.size(),3);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;

}