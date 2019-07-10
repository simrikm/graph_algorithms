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

void print_the_nums( vector<int>& nums)
{
		for ( vector<int>::const_iterator i = nums.begin(); i !=nums.end(); ++i){
   			  cout << *i << ' ' << '\n';
	}
	
	cout<<endl<<endl;

}



Graph create_barabasi_albert_graph( int n, int d){
	// here d should be qual to 5
	Graph graph;
	vector<int> u;
	vector<int> v;
	
//	fill(u.begin(),u.end(),1);
//	fill(v.begin(),v.end(),1);
	
	//Create an array called M whose length is 2nd
	int M[2*n*d];

	
	for(int i=0; i<2*n*d;++i)
		M[i]=n;
	
		
	for (int j=1;j<n;j++){
		for (int i=0; i<d;i++){
			int indx=2*(j*d+i);
			M[indx]=j;
			//draw r uniformly random 
			random_device rd;
			mt19937 generator(rd());
			uniform_int_distribution<int> distr(0,indx);
			int r=distr(generator);
			M[indx+1]=M[r]; //wont give seg fault id trying to access that does not exists;
			}
	}
	

	for (int k=0; k<n*d;k++){
		u.push_back(M[2*k]);
		v.push_back(M[2*k+1]);
	}

//	cout<<u.size();	
//	cout<<"the size"<<u.size()<<endl;

//	print_the_nums(u);
//	print_the_nums(v);
		
	graph=make_graph(n,u,v);

	return graph;


}
