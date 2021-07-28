#include<iostream>
#include<string>

using namespace std;

int main(){
    // string str;
    // cin>>str;
    // cout<<str<<endl;

    string str1(5,'a');
    cout<<str1<<endl;

    string str2="ApniKaksha";
    cout<<str2<<endl;

    string str3;
    getline(cin,str3);
    cout<<str3<<endl;

    string s1="fam";
    string s2="ily";

    // s1.append(s2);
    // s1=s1+s2;
    // cout<<s1+s2<<endl;
    s1=s1+s2;
    cout<<s1<<endl;

    //Read all the function that string perform from geeks FOR geeks.


    return 0;
}