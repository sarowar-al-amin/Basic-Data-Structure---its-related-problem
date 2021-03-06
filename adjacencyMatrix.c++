// DFS algorithm implementation using adjacency matrix
#include<bits/stdc++.h>
#define white 1
#define grey 2
#define black 3

using namespace std;
// Global variable
int node, edge;
int Time = 1; // 'time' is a default keyword.

// Global array
int startTime[80];
int stopTime[80]; 
int color[80];
int adj[80][80];

// Declaring and Defining functions
void dfsVisited(int x){
    color[x] = grey;
    startTime[x] = Time;
    Time++;
    for(int i = 0; i < node; i++){
        if(adj[x][i] == 1){
            if(color[i] == white){
                dfsVisited(i);
            }
        }
    }

    color[x] = black;
    stopTime[x] = Time;
    Time++;
}

void dfs(){
    for(int i = 0; i < node; i++){
        color[i] = white;
    }
    for(int i = 0; i < node; i++){
        if(color[i] == white){
            dfsVisited(i);
        }
    }
}

int main(){

    freopen("inputForAdjacency.txt", "r", stdin);
    // cout<<"Enter the number of node: "<<endl;
    cin >> node;
    // cout<<"\nEnter the number of edge: "<<endl;
    cin >> edge;
    // cout<<endl;

    int n1, n2;

    // cout <<"Enter the edges :"<< endl;
    for(int i = 0; i < edge; i++){
        cin >> n1 >> n2;
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }

    // cout<<"Printing the adjacency matrix: "<<endl;
    // for(int  i = 0; i < node; i++){
    //     for(int j = 0; j < node; j++){
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    dfs();
    
    // int count = 0;
    // for(int i = 0; i < node; i++){
    //     if(color[i] == black){
    //         count++;
    //     }
    // }
    // if(count == node){
    //     cout <<"Traverse all nodes."<<endl;
    // }else{
    //     cout<<"Some node remain untraverse."<< endl;
    // }

    cout <<"Time of starting and finishing of all the node: "<<endl;
    for(int i = 0; i < node; i++){
        cout <<char('A'+i)<<" : " <<startTime[i] <<"  "<<stopTime[i]<<endl;
    }
    cout << endl;

    return 0;
}