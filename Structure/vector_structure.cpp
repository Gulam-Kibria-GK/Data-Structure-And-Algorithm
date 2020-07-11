#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct data{
    ll n,c;
    data(){
    }

    data(ll n1,ll c1){
        n=n1;
        c=c1;
    }
};
vector<data>v[1000000];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll i,j,k,l,n,m,a,b,c,e;
    cin>>n>>e;
    for(i=0;i<e;i++){
        cin>>a>>b>>c;
        v[a].push_back(data(b,c));
        v[b].push_back(data(a,c));
    }
    for(i=1;i<=n;i++){
            cout<<"for node"<<i<<" :";
        for(j=0;j<v[i].size();j++){
            cout<<v[i][j].n<<" {"<<v[i][j].c<<"} ";
        }
        cout<<endl<<endl;
    }
}
//input:-
/************************
5 8
1 2 10
1 3 6
1 4 21
2 3 20
2 4 7
2 5 11
3 4 5
4 5 12
**************************/

//output:
/*************************
for node1 :2 {10} 3 {6} 4 {21}

for node2 :1 {10} 3 {20} 4 {7} 5 {11}

for node3 :1 {6} 2 {20} 4 {5}

for node4 :1 {21} 2 {7} 3 {5} 5 {12}

for node5 :2 {11} 4 {12}

*************************/
