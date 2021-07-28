#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    string s="465192360";

    sort(s.begin(),s.end(),greater<int>());

    cout<<s<<endl;
}