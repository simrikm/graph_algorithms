
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <map>
#include "project3.h"
#include "node.h"
#include <set>
#include <algorithm>
#include <iostream>
#include <list>
#include <climits>
#include "graph.h"

using namespace std;

void dfs(int node_id,int count,bool visited[],int& max,list<int>* adj,int& x)
{
	visited[node_id]=true;
	count++;
	
	for (auto i = adj[node_id].begin(); i != adj[node_id].end(); ++i) { 
        if (!visited[*i]) { 
            if (count >= max) { 
                max = count; 
                x= *i; 
            } 
            dfs(*i, count, visited, max, adj,x); 
        } 
    } 



}


int get_diameter(Graph graph){
	int x;
	int max=0;	
	int n=graph.num_nodes;
	bool visited[n+1];
	int count=0;

	fill_n(visited,n+1,false);
	
	dfs(1,count+1,visited,max,graph.adjlist,x);
	dfs(x,count+1,visited,max,graph.adjlist,x);

	return max;
}

float num_of_twoedge(Graph graph){
	int degree_sum=0;
	for (int i=1; i<=graph.num_nodes; i++){
		int d=graph.nodes[i].edges.size();
		degree_sum=degree_sum+((d*(d-1))/2);	

	}
	return (float)degree_sum;
};

float get_clustering_coefficient(Graph graph){

	float two_edge=num_of_twoedge(graph);
	set<int> l;
	int min_index=INT_MAX;
	int triangle_count=0;
	vector<int> d [graph.num_nodes+1];
	int index=0;

	for (int i=0; i<graph.num_nodes;i++){
		if(!graph.nodes[i].edges.empty()){
			 index=graph.nodes[i].edges.size();
			for(int j=0;j<index;j++){
				d[index].push_back(graph.nodes[i].edges[j]);
			}
			if(index < min_index)
				min_index=index;
		}
	}

	

	for(int i=1;i<graph.num_nodes;i++){
		for(int k=0; k<d[min_index].size();++k){
		int v=d[min_index][k];
		d[min_index][k]=-1;
	
		l.insert(v);
		
		int dw=graph.nodes[v-1].edges.size();
		for(int j=0;j<dw;j++){
			int w=graph.nodes[v-1].edges[j];
			if(!l.count(w)){
				int degree=graph.nodes[w].edges.size();
				--degree;
				graph.nodes[v-1].neighbours.push_back(graph.nodes[v-1].edges[j]);
			}

		}
		
		}
		
	}

	for(int i=0; i<graph.num_nodes; i++){
		for(int j=0; j<graph.nodes[i].neighbours.size(); j++){
			if(graph.edges.count(make_pair(i,graph.nodes[i].neighbours[j]))){
					triangle_count++;
			}
		}
	}
	return (float)triangle_count/two_edge;
}

map<int,int> get_degree_distribution(Graph graph){
		
	int max=0;
	map<int,int> degree;
	//checking for max degree
	
	for(int i=0; i<graph.num_nodes; i++){
		if(graph.nodes[i].edges.size() > max)
			max=graph.nodes[i].edges.size();
	}


	for(int i=0; i<=max; ++i){
		int count=0;
		for(int j=0;j<graph.num_nodes;j++){
			if(graph.nodes[j].edges.size()==i)
				count++;
		}
		degree[i]=count;

	}
	
	return degree;

}


