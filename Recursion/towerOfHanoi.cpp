#include<iostream>
using namespace std;

void towerHanoi(int n,char source,char helper,char dest){
    if(n==0){
        return;
    }

    towerHanoi(n-1,source,dest,helper);
    cout<<"Move "<<source<<" to "<<dest<<endl;
    towerHanoi(n-1,helper,source,dest);
}
int main(){
    towerHanoi(3,'A','B','C');
    return 0;
}