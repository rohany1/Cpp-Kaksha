#include<iostream>
#include<string>

using namespace std;

int main(){
    string s="afafniergfnsrfneiorfnssrg";
    int arr[26];
    for(int i=0;i<26;i++){
        arr[i]=0;
    }
    for(int i=0;i<s.length();i++){
        int num=s[i]-'a';
        arr[num]++;
    }
    int largest=0;
    int index=0;
    for(int i=0;i<26;i++){
        if(arr[i]>largest){
            largest=arr[i];
            index=i;
        }
    }
    char ans=index+'a';
    cout<<largest<<" "<<ans<<endl;
    return 0;
}