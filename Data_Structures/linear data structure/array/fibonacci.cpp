#include<bits/stdc++.h>
using namespace std;
long long int fib(long long int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    else
        return fib(n-1)+fib(n-2);
}
int main()
{
    long long int n;
    cin>>n;
    long long int result=fib(n);
    cout<<result<<endl;
}
