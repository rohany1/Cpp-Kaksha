//Given a “2 x n” board and tiles of size “2 x 1”,
// count the number of ways to tile the given board using the 2 x 1 tiles.
// A tile can either be placed horizontally 
//i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile. 

#include<iostream>
using namespace std;
int tilingWays(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return tilingWays(n-1)+tilingWays(n-2);
}
int main(){
    return 0;
}