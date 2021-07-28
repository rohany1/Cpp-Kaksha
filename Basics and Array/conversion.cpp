#include <bits/stdc++.h>
using namespace std;

int decimalToOctal(int n)
{
    int x = 1;
    while (x <= n)
    {
        x *= 8;
    }
    x /= 8;
    int ans = 0;
    while (x > 0)
    {
        int quotient = n / x;
        ans = ans * 10 + quotient;
        n = n % x;
        x /= 8;
    }
    return ans;
}
string decimalToHexa(int n)
{
    int x = 1;
    string ans="";
    while (x <= n)
    {
        x *= 16;
    }
    x /= 16;
    while(x>0){
        int quotient =n/x;
        n=n%x;
        x=x/16;
        if(quotient<=9){
            ans=ans+to_string(quotient);
        }else{
            char c='A'+quotient-10;
            ans.push_back(c);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << decimalToHexa(n) << endl;
}