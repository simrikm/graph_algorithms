#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <map>
#include "project3.h"
#include <set>
#include <algorithm>
#include <iostream>
#include <list>
#include <climits>

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node{
	int a;
protected:
	static int nextID;
	public:
		int id;
		vector<int> edges;
		vector<int> neighbours;
		Node(){};
		Node(int pa):a(pa){id=++nextID;}
		bool operator==(const Node& other) const
		{ return id == other.id;}
friend ostream& operator <<  (ostream& os, const Node& m)
{
	os<<m.a<<endl;
	return os;
}	
};


//int Node::nextID=0;
#endif
//int Node::nextID=0;
