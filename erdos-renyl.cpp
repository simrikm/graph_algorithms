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
#include <random>
#include <cmath>
#include <iomanip>
#include <cmath>

Graph create_erdos_renyi_graph(int n, float p){

	Graph graph;
	vector<int> a;
	vector<int> b;
	
	int v=1;
	int w=-1;
	
	while(v<n){
			//draw r uniformly random 
		random_device rd;
		mt19937 generator(rd());
		uniform_real_distribution<float> distr(0,1);
		int r=distr(generator);
		w=w+1+floor(log(1-r)/log(1-p));
		while(w>=v  && v < n){
			w=w-v;
			v=v+1;
		}
		if(v<n){
		a.push_back(v);
		b.push_back(w);
		}
	}
		
	graph=make_graph(n,a,b);

	return graph;

}

