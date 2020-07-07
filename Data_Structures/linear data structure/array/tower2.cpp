 #include<bits/stdc++.h>
using namespace std;

int j=0;
void tower(int n,char a,char b,char c)
{
    int i,x;
    j++;
    if(n==0)
    {
        //cout<<j<<a<<"->"<<c<<endl;
        return;
    }
    tower(n-1,a,c,b);
    cout<<a<<"->"<<c<<endl;
    tower(n-1,b,a,c);
}
int main()
{
    int n;
    cin>>n;
    tower(n,'a','b','c');
}
