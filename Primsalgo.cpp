#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int min(int *weight , int * parent , int n , bool *visited){
    int minvertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minvertex == -1 || weight[i] < weight[minvertex])){
            minvertex = i;
        }
    }
    return minvertex;
}


void prims(int **edges , int n){
    int *weight = new int[n];
    int *parent = new int[n];
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
        weight[i] = INT_MAX;
    }
    parent[0]=-1;
    weight[0] = 0;
    
    for(int i=0;i<n-1;i++){
        int minvertex = min(weight,parent,n , visited);
        visited[minvertex] = true;
        
    	for(int j=0;j<n;j++){
            if(edges[minvertex][j] !=0 && !visited[j]){
                if(edges[minvertex][j]<weight[j]){
                    parent[j] = minvertex;
                    weight[j] = edges[minvertex][j];
                }
            }
        }
        
        
        
    }
    
    for(int i=1;i<n;i++){
        if(i< parent[i]){
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
        else{
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
            
        }
        
    }
    
}



int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;

    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];

        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;

        edges[f][s]=w;
        edges[s][f]=w;
    }
    
    prims(edges,n);
}