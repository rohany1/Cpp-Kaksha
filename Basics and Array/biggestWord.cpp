#include<iostream>
using namespace std;

int main(){
    char arr[100]="apple";
    int n;
    cin>>n;

    cin.ignore();
    cin.getline(arr,n);
    cin.ignore();

    int maxLength =0;
    int currLength =0;
    int start=0;
    int maxStart=0;
    int i=0;
    while(i<n){
        if(arr[i]==' '|| arr[i]=='\0'){
            if(currLength>maxLength){
                maxLength = currLength;
                maxStart =start;
            }
            currLength=0;
            start=i+1;
        }else{
            currLength++;
        }
        
        if(arr[i]=='\0'){
            break;
        }
        i++;
    }
    cout<<arr<<endl;
    cout<<maxLength<<endl;
    for(int i=0;i<maxLength;i++){
        cout<<arr[i+maxStart];
    }cout<<endl;

}