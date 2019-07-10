#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "project3.h"
#include <bits/stdc++.h>
#include <random>
#include "node.h"
#include "graph.h"
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;


void add_data_to_files(int n,double data ,string filename,int opt, map<int,int> d){
	ofstream f;
	f.open(filename,ios::app);
	if(opt==0)
		f<<" "<<n<<","<<data<<"\n";
	if(opt==1)
		for(auto elem : d){
   		f<<" "<<elem.first <<","<<elem.second<<"\n";
	}
	f.close();
}

void create_files(string filename,int opt){
	ofstream f;
	f.open(filename,ios::trunc);
	if(opt==1)
		f<<"n,diameter\n";
	if(opt==2)
		f<<"n,c.coeff\n";
	if(opt==3)
		f<<"degree,nodes\n";
	f.close();


}


void creating_files(){
	create_files("diameter.csv",1);
	create_files("clustering_coefficient.csv",2);
	create_files("1000_degree.csv",3);
	create_files("10000_degree.csv",3);
	create_files("100000_degree.csv",3);

}

int main(){

	Graph g;
		
	creating_files();

	map<int,int> a;
	map<int,int> b;
	map<int,int> c;

	
	for (int n=1000; n <=100000; n*=10){
		g=create_barabasi_albert_graph(n,5);
		add_data_to_files(n,get_diameter(g),"diameter.csv",0,a);
		add_data_to_files(n,(double)get_clustering_coefficient(g),"clustering_coefficient.csv",0,a);
		if(n==1000)
			a=get_degree_distribution(g);
		if(n==10000)
			b=get_degree_distribution(g);
		if(n==10000)
			c=get_degree_distribution(g);
	}

	add_data_to_files(0,0,"1000_degree.csv",1,a);
	add_data_to_files(0,0,"10000_degree.csv",1,b);
	add_data_to_files(0,0,"100000_degree.csv",1,c);

	return 0;
}
