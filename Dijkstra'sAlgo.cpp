#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int findminvertex(bool *visited , int *distance , int n){
    int minvertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minvertex==-1 || distance[i]<distance[minvertex])){
            minvertex=i;
        }
    }
    return minvertex;
}

void dijkstra(int **edges , int n){
    bool *visited = new bool[n];
    int *distance = new int[n];
    for(int i=0;i<n;i++){
        visited[i]= false;
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    
    for(int i=0;i<n-1;i++){
        int minvertex = findminvertex(visited, distance, n);
        visited[minvertex] = true;
        for(int j=0;j<n;j++){
            if(edges[minvertex][j]!=0 && !visited[j]){
                int dist = distance[minvertex] + edges[minvertex][j];
                if(dist < distance[j]){
                    distance[j]=dist;
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<i<<" "<<distance[i]<<endl;
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
    dijkstra(edges,n);
}