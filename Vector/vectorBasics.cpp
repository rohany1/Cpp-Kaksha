#include<iostream>
#include<vector>
#include<algorithm> //Sort file
using namespace std;

int main(){
    vector<int> v;
    //push back function
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    //Three ways to iterate over vector
    
    //First one // Basic for loop
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;

    //Second one // Using iterator //Iterator is a pointer to vector
    vector<int>:: iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }cout<<endl;

    //Third one // Using auto function
    for(auto element:v){
        cout<<element<<" ";
    }cout<<endl;

    //Pop back function
    v.pop_back(); // 1 2

    vector<int> v2(3,50);
    //50 50 50

    //Swap
    swap(v,v2);
    for(auto element:v){
        cout<<element<<" ";
    }cout<<endl;
    for(auto element:v2){
        cout<<element<<" ";
    }cout<<endl;

    //Sort
    sort(v.begin(),v.end());
    return 0;

}
