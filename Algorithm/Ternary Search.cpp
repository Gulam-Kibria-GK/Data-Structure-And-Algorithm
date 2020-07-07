#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define error 1e-25

struct st{
    double x,y,z;
}arr[4];

double dis(st p1, st p2) {
   double temp =((p1.x-p2.x)*(p1.x-p2.x) )+ ((p1.y-p2.y)*(p1.y-p2.y))+ ((p1.z-p2.z)*(p1.z-p2.z));
   return sqrt(temp);
}

double ter_search(){
    ll i,j,k,l;
    double one3,two3;
    one3=dis(arr[0],arr[2]);
    two3=dis(arr[1],arr[2]);
    ll c = 100;
    while(c--){
        st f1,s1;
        f1.x=((2.0*arr[0].x)+arr[1].x)/3.0;
        f1.y=((2.0*arr[0].y)+arr[1].y)/3.0;
        f1.z=((2.0*arr[0].z)+arr[1].z)/3.0;

        s1.x=(arr[0].x+(2.0*arr[1].x))/3.0;
        s1.y=(arr[0].y+(2.0*arr[1].y))/3.0;
        s1.z=(arr[0].z+(2.0*arr[1].z))/3.0;

        one3=dis(f1,arr[2]);
        two3=dis(s1,arr[2]);
        if(one3>two3){
            arr[0]=f1;
        }
        else{
            arr[1]=s1;
        }
    }
    return ((abs(one3+two3))/2.0);
}

int main()
{
    ll i,j=0,k,n,m;
    cin>>k;
    while(k--){
        j++;
        for(i=0;i<3;i++){
            cin>>arr[i].x>>arr[i].y>>arr[i].z;
        }
        cout<<"Case "<<j<<": ";
        double ans=ter_search();
        printf("%.12lf\n",ans);
    }
}

//1240 - Point Segment Distance (3D)(Light OJ)
