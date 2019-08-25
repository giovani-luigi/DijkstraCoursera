#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Path;

class Node{
	
	private:
		
		string alias;
	
		vector<Path> neighbors;
	
	public:
		
		// constructor
		Node(const string alias);
				
		// get the alias assigned to this node
		string getAlias() const;
		
		// add the node n from the grap as a neighbor of this node
		// - n: the index (in the graph) of the neighbor to add
		// - cost: [default=1] the cost/weight of the connection
		void addNeighbor(int n, int cost = 1);
		
		// get all adjacent nodes
		inline const vector<Path>& getNeighbors() const { 
			return neighbors; 
		}
		
};

struct Path{
	
	int index;
	int cost;
	
	// default initializer
	Path(){ index=0; cost=0; }
	
	Path(int index, int cost){
		this->index = index;
		this->cost = cost;
	}	
};

struct Edge{
	
	int from;
	int to;
	int cost;
	
	Edge(int from, int to, int cost){
		this->from = from;
		this->to = to;
		this->cost = cost;
	}	
};

ostream& operator<< (ostream& out, const Node& right);

#endif

