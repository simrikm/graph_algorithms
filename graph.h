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

#ifndef GRAPH_H
#define GRAPH_H

using namespace std;

class Graph: public AbstractGraph
{

	public:
	int num_nodes;
	list<int>* adjlist;
	set<pair<int,int>> edges;
	vector<Node> nodes;
	map<int,Node> id_node;
	virtual int get_num_nodes()override;
	virtual int get_num_edges()override;
	 virtual bool is_neighbor(Node u, Node v)override;
	 virtual vector<Node> get_neighbors(Node u)override;
	virtual map<int,Node> get_id_to_node_map()override;
	
	Graph(){}
};

Graph make_graph(int num_nodes,vector<int> u, vector<int> v);

#endif
