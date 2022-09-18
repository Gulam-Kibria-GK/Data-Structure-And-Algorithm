#include<stdio.h>
#include<stdlib.h>

struct asia_cup
{
    char team_name[20];
    int match;
    int win;
    int loss;
    float nrr; //net run rate
    int point;
};

void read_structure(struct asia_cup team[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("\nEnter information of Team number %d :\n\n",i+1);
        printf("Enter Team name : ");
        scanf("%s",&team[i].team_name);
        printf("Enter played Match number : ");
        scanf("%d",&team[i].match);
        printf("Enter match win number : ");
        scanf("%d",&team[i].win);
        printf("Enter match loss number : ");
        scanf("%d",&team[i].loss);
        printf("Enter match net run rate(nrr) number : ");
        scanf("%f",&team[i].nrr);
        team[i].point=team[i].win*2;
    }
}

void sort_Standings(struct asia_cup team[],int n)
{
    int i,j;
    for(i=0; i< n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(team[i].point<team[j].point)
            {
                struct asia_cup temp;
                temp=team[i];
                team[i] = team[j];
                team[j] = temp;
            }
            else if(team[i].point==team[j].point)
            {
                if(team[i].nrr<team[j].nrr)
                {
                    struct asia_cup temp;

                    temp = team[i];
                    team[i] = team[j];
                    team[j] = temp;
                }
            }
        }
    }
}

void print_Standings(struct asia_cup team[],int n)
{
    int i;
    for (i = 0; i <n; ++i)
    {
        printf("Team : %s\t", team[i].team_name);
        printf("M : %d\t", team[i].match);
        printf("W : %d\t", team[i].win);
        printf("L: %d\t", team[i].loss);
        printf("NRR : %0.2f\t", team[i].nrr);
        printf("pts : %d\n\n", team[i].point);
    }
}

int main()
{
    struct asia_cup team[4];

    read_structure(team,4);

    printf("\nDisplaying Standings before Sort\n\n");
    print_Standings(team,4);

    sort_Standings(team,4);

    printf("\nDisplaying Standings After Sort\n\n");
    print_Standings(team,4);
    return 0;

}

/*********
input

ind 3 1 2 +1.60
pak 3 2 1 -0.27
afg 3 0 3 -2.00
sl  3 3 0 +0.70
********/
