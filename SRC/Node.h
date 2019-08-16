#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Edge;

class Node{
	
	private:
		
		string alias;
	
		vector<Edge> edges;
	
	public:
		
		// constructor
		Node(const string& alias);
				
		// get the alias assigned to this node
		string getAlias() const;
		
		// add a node into the adjancency list
		void addNeighbor(Node* n, int cost = 1);
		
		// get all adjacent nodes
		inline const vector<Edge>& getEdges() const { 
			return edges; 
		}
		
};

struct Edge{
	Node* target;
	int cost;
};

ostream& operator<< (ostream& out, const Node& right);

#endif

