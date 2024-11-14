#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct Edge{
    int src,dist,weight;
};

void bellmanFord(int V,int E,int src,vector<Edge>& edges){
    vector<int>distance(V,INT_MAX);
    distance[src]=0;

    for(int i=1; i<=V-1; i++){
        for(int j=0; j<E; j++){
            int u=edges[j].src;
            int v=edges[j].dist;
            int weight=edges[j].weight;
            if(distance[u]!=INT_MAX && distance[u]+weight<distance[v]){
                distance[v]=distance[u]+weight;
            }
        }
    }

    for(int j=0; j<E; j++){
        int u=edges[j].src;
        int v=edges[j].dist;
        int weight=edges[j].weight;
        if(distance[u]!=INT_MAX && distance[u]+weight<distance[v]){
            cout<<"Graph contains a negative-weight cycle"<<endl;
            return;
        }
    }
    cout<<"Vertex\tDistance from Source\n";
    for(int i=0; i<V; i++){
        cout<<i<<"\t\t"<<(distance[i]==INT_MAX ? "Infity" : to_string(distance[i]))<<endl;
    }
}
int main(){
    int V,E,src;
    cout<<"Enter the number of vertices : ";
    cin>>V;
    cout<<"Enter the number of edges : ";
    cin>>E;
    vector<Edge>edges(E);
    for(int i=0; i<E; i++){
        cout<<"Enter source destination and weight of edge "<<i+1<<" : ";
        cin>>edges[i].src>>edges[i].dist>>edges[i].weight;
    }
    cout<<"Enter the source vertex : ";
    cin>>src;
    bellmanFord(V,E,src,edges);
}