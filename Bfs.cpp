#include <iostream>
using namespace std;
#include <queue>
void print(int ** edges,int n,int sv,bool *visited){
    cout<<sv<<endl;
    visited[sv]=true;

    for(int i=0;i<n;i++){
        if(sv==i){
            continue;
        }

        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            print(edges,n,i,visited);
        }
    }
}

void printbfs(int **edges,int n,int sv,bool *visited){
    queue<int> pending;

    pending.push(sv);
    visited[sv]=true;
    while(!pending.empty()){
        int curr=pending.front();
        pending.pop();
        cout<<curr<<endl;
        for(int i=0;i<n;i++){
            if(curr==i){
                continue;
            }

            if(!visited[i] && edges[curr][i]==1){
                pending.push(i);
                visited[i]=true;
            }
        }
    }
}

void BFS(int **edges,int n){
    bool *visited=new bool [n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            printbfs(edges,n,i,visited);
        }
    }
}

int main(){
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
        int f,s;
        cin>>f>>s;

        edges[f][s]=1;
        edges[s][f]=1;
    }

    BFS(edges,n);
}