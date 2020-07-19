#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct result
{
    char name[100];
    ll id;
    double cgpa;
};

void input(struct result student[],ll n);

void sorted(struct result a[],ll n);

void output(struct result student[],ll n);

int main()
{
    ll n;
    cout<<"Enter the student number...."<<endl;
    cin>>n;
    cout<<endl;
    struct result student[n];
    input(student,n);
    sorted(student,n);
    output(student,n);
    return 0;
}

void input(struct result student[],ll n)
{
    int i;
    cout<<"Enter the input........"<<endl<<endl;
    for(i=0; i<n; i++)
    {
        cin>>student[i].id>>student[i].name>>student[i].cgpa;
    }
    cout<<endl;
}


void sorted(struct result a[],ll n)
{
    int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i].cgpa<a[j].cgpa)
            {
                struct result t;
                t.id=a[i].id;
                strcpy(t.name,a[i].name);
                t.cgpa=a[i].cgpa;

                a[i].id=a[j].id;
                strcpy(a[i].name,a[j].name);
                a[i].cgpa=a[j].cgpa;

                a[j].id=t.id;
                strcpy(a[j].name,t.name);
                a[j].cgpa=t.cgpa;
            }
            else if(a[i].cgpa==a[j].cgpa)
            {
                if(strcmp(a[i].name,a[j].name)>0)
                {
                    struct result t;
                    t.id=a[i].id;
                    strcpy(t.name,a[i].name);
                    t.cgpa=a[i].cgpa;

                    a[i].id=a[j].id;
                    strcpy(a[i].name,a[j].name);
                    a[i].cgpa=a[j].cgpa;

                    a[j].id=t.id;
                    strcpy(a[j].name,t.name);
                    a[j].cgpa=t.cgpa;

                }
                else if(strcmp(a[i].name,a[j].name)==0)
                {
                    struct result t;
                    t.id=a[i].id;
                    strcpy(t.name,a[i].name);
                    t.cgpa=a[i].cgpa;

                    a[i].id=a[j].id;
                    strcpy(a[i].name,a[j].name);
                    a[i].cgpa=a[j].cgpa;

                    a[j].id=t.id;
                    strcpy(a[j].name,t.name);
                    a[j].cgpa=t.cgpa;
                }
            }
        }
    }
}


void output(struct result student[],ll n)
{
    ll i;
    cout<<"print the output........"<<endl<<endl;
    for(i=0; i<n; i++)
    {
        printf("number %lld: CGPA :%.2lf  NAME :%s ID :%d\n",i+1,student[i].cgpa,student[i].name,student[i].id);
    }
}

