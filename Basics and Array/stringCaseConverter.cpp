#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){

    string s="avfhjerjnsi";
    //convert string to uppercase

    for(int i=0;i<s.length();i++){
        //a is 97 and A is 65
        s[i]=s[i]-32;
    }
    cout<<s<<endl;
    //sort it
    sort(s.begin(),s.end());
    cout<<s<<endl;

    string s1="JDFNERFOMASDKF";
    //convert to lower case
    for(int i=0;i<s1.length();i++){
        //a is 97 and A is 65
        s1[i]=s1[i]+32;
    }
    cout<<s1<<endl;
    //sort it
    sort(s1.begin(),s1.end());
    cout<<s1<<endl;

    //inbuilt function
    string s2="anfjgtrigioz";
    //transform(string start from,end at,from where,to what)
    transform(s2.begin(),s2.end(),s2.begin(),::toupper);
    cout<<s2<<endl;
    transform(s2.begin(),s2.end(),s2.begin(),::tolower);
    cout<<s2<<endl;
    return 0;
}