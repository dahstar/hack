/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   union.h
 * Author: davood
 *
 * Created on January 18, 2017, 5:37 PM
 */
#include<vector>
#ifndef UNION_H
#define UNION_H
using namespace std;
int size[1000];
bool isconnected[1000];
 void initialize( int Arr[ ], int N)
    {
        for(int i = 0;i<N;i++)
        {
            size[i]=0;
            isconnected[i]=false;
            Arr[ i ] = i ;
        }
    }
    //returns true if A and B are connected, else returns false 
     bool find( int Arr[ ], int A, int B)                           
    {
    if(Arr[ A ] == Arr[ B ])
    return true;
    else
    return false;   
    }
    //change all entries from arr[ A ] to arr[ B ].
    void unions(int Arr[ ], int N, int A, int B)
    {
        int TEMP = Arr[ A ];
        size[A]++;
        isconnected[A]=false;
    for(int i = 0; i < N;i++)
        {
        if(Arr[ i ] == TEMP)
        Arr[ i ] = Arr[ B ]; 
        }
    }
    void print(int Arr[],int n,int j)
    {
        int c;
        for(int i=0;i<n;i++)
            if(find(Arr,i,j)==true)
                c++;
        printf("%d",j);
        
       
    }
#endif /* UNION_H */

