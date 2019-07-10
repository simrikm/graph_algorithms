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

//impelmenatation of all the members declared in graph.h
using namespace std;

int Node::nextID=0;

int Graph:: get_num_nodes(){
	return num_nodes;
}

int Graph::get_num_edges(){
	return edges.size()/2;

}

bool Graph::is_neighbor(Node u, Node v)
{
	
	if(find(nodes[u.id-1].edges.begin(),nodes[u.id-1].edges.end(),v.id)!=nodes[u.id-1].edges.end())
		return true;
	return false;

}

vector<Node> Graph::get_neighbors(Node u)
{
	cout<<"node"<<u.id;
	vector<Node> n;
	if(!nodes[u.id-1].edges.empty()){
		cout<<"the id is:"<<u.id<<endl;
	for(int i=0; i< nodes[u.id-1].edges.size();i++){
		n.push_back(id_node[nodes[u.id-1].edges[i]]);
		}
	}
	return n;
}

map<int,Node> Graph::get_id_to_node_map()
{
	return id_node;
}


Graph make_graph(int num_nodes, vector<int> u, vector<int> v){

//	int Node::nextID=0;
	Graph graph;
	
	graph.adjlist=new list<int>[num_nodes+1];

	graph.num_nodes=num_nodes;

	for (int i=1; i<=num_nodes;++i){
		Node n(i);
		graph.nodes.push_back(n); 
		graph.id_node.insert(make_pair(i,n));;
	}


	if(!u.empty()){
	for (int i=0; i< u.size();++i){
		if(u[i]>num_nodes||v[i]>num_nodes){
			cout<<"Not a valid node "<<endl;
			exit(1);

		}	
		if(u[i]!=v[i]){
				graph.nodes[u[i]-1].edges.push_back(v[i]);
				graph.nodes[v[i]-1].edges.push_back(u[i]);
				graph.edges.insert(make_pair(v[i],u[i]));
				graph.edges.insert(make_pair(u[i],v[i]));

				graph.adjlist[v[i]].push_back(u[i]);
				graph.adjlist[u[i]].push_back(v[i]);
	
		}

	}
		for (int i=0; i<graph.num_nodes;++i){
			if(!graph.nodes[i].edges.empty()){
				sort( graph.nodes[i].edges.begin(), graph.nodes[i].edges.end() );
				graph.nodes[i].edges.erase(unique( graph.nodes[i].edges.begin(), graph.nodes[i].edges.end() ),graph.nodes[i].edges.end());

			}
		}	
	}
	return graph;
}


