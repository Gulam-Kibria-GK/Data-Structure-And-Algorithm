#include<bits/stdc++.h>
using namespace std;
void tower(int n,char a,char b,char c)
{
    if(n==1)
    {
        printf("%c->%c\n",a,c);
        return;
    }
    tower(n-1,a,c,b);
    printf("%c->%c\n",a,c);
    tower(n-1,b,a,c);
    //printf("%c->%c\n",a,c);
}
int main()
{
    int n;
    cin>>n;
    tower(n,'A','B','C');
}
