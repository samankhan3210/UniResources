#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

//Depth first search(DFS)

vector <int> graph[5];  // Each element of this graph represents a node
bool visited[5]={false,false,false,false,false}; //Used to check visited status

void Add_Edge(int u,int v)
{
    graph[u].push_back(v); //vertix U is connected with vertix V (1st Neighbor of U)
}

void DFS(int s) // s= source vertix
{
    stack<int>st;
    
    st.push(s); // puching source vertix
    visited[s]=true; 

    while(!st.empty())
    {
        int u =st.top();  
        cout<< u<<" ";
        st.pop();         //pop once printed

        for(int i=0;i<graph[u].size();i++) //one by one puch all neighbor of (POPED ELEMENT) in stack
        {
            if( ! visited[ graph[u][i] ]) //only visit neighor that are not visited previously.
            {
                st.push(graph[u][i]);    // pushing a single neighor
                visited[graph[u][i]]=true; // making that neighor as visited
            }
        }
    }
}
void BFS(int s) // s= source vertix
{
    queue<int>st;
    
    st.push(s); // puching source vertix
    visited[s]=true; 

    while(!st.empty())
    {
        int u =st.front();  
        cout<< u<<" ";
        st.pop();         //pop once printed

        for(int i=0;i<graph[u].size();i++) //one by one puch all neighbor of (POPED ELEMENT) in stack
        {
            if( ! visited[ graph[u][i] ]) //only visit neighor that are not visited previously.
            {
                st.push(graph[u][i]);    // pushing a single neighor
                visited[graph[u][i]]=true; // making that neighor as visited
            }
        }
    }
}

int main()
{
    Add_Edge(0,1);
    Add_Edge(0,2);
    Add_Edge(0,3);
    Add_Edge(1,4);
    Add_Edge(2,4);
    Add_Edge(3,4);

    cout<<"DFS : ";
    DFS(0);

    for(int i=0;i<5;i++)
    visited[i]=false;

    cout<<"\nBFS : ";
    BFS(0);
    return 0;
}