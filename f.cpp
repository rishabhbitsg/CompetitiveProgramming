#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

int main()
{
    int n;
    // number of teams
    scanf("%d",&n);
    // teams
    char teams[n][30];

    int pts[n] = {0};
    int gf[n] = {0};
    int ga[n] = {0};
    int gd[n] = {0};

    for(int i = 0; i < n; i++)
    cin>>teams[i];
    
    // number of matches
    int k;
    scanf("%d",&k);

    // first team
    char t1[k][30];

    // second team
    char t2[k][30];

    // first team goals
    int g1[k];

    // second team goals
    int g2[k];


    for(int j = 1; j <= k; j++)
    {
        cin>>t1[j]>>t2[j]>>g1[j]>>g2[j];
        
        if(g1[j] == g2[j])
        {
            for(int l = 0; l < n; l++)
            {
                if(strcmp(t1[j],teams[l]) == 0)
                {
                    pts[l] += 1;
                    gf[l] += g1[j];
                    ga[l] += g2[j];
                }
                if(strcmp(t2[j],teams[l]) == 0)
                {
                    pts[l] += 1;
                    gf[l] += g2[j];
                    ga[l] += g1[j];
                }
                
            }
        }
        else if(g1[j] > g2[j])
        {
            for(int l = 0; l < n; l++)
            {
                if(strcmp(t1[j],teams[l]) == 0)
                {
                    pts[l] += 3;
                    gf[l] += g1[j];
                    ga[l] += g2[j];
                }
            }
            for(int l = 0; l < n; l++)
            {
                if(strcmp(t2[j],teams[l]) == 0)
                {
                    pts[l] += 0;
                    gf[l] += g2[j];
                    ga[l] += g1[j];
                }
            }
        }
        else if(g2[j] > g1[j])
        {
            for(int l = 0; l < n; l++)
            {
                if(strcmp(t1[j],teams[l]) == 0)
                {
                    pts[l] += 0;
                    gf[l] += g1[j];
                    ga[l] += g2[j];
                }
            }
            for(int l = 0; l < n; l++)
            {
                if(strcmp(t2[j],teams[l]) == 0)
                {
                    pts[l] += 3;
                    gf[l] += g2[j];
                    ga[l] += g1[j];
                }
            }
        }
    }
    for(int i = 0; i <n; i++)
    {
        gd[i] = gf[i] - ga[i];
    }


}