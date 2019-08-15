#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include "Node.h"

using namespace std;

class Graph{
	
	private:
		
		vector<Node*> nodes;
		
	public:
		
		// default constructor
		Graph();
		
		// generates a given number of nodes with the edge density 
		// - count: the amount of nodes that the graph should have
		// - density: the density, i.e. if density=0.1, 10% of possible edges will exist
		// remark: to each edge will be given a random cost
		void generate(int count, float density = 0.1);

		// add a new node to the graph and returns a reference to it
		Node* addNode(const string& alias);
		
		// get a reference to the node with the given alias
		Node* getNode(string alias);
		
		// remove a node from the graph
		void delNode(string alias);
		
		// add an edge between two nodes n1 and n2, with the specified cost
		void addEdge(Node* n1, Node* n2, int cost = 1);
		
		// delete the edge between two nodes n1 and n2
		void delEdge(Node* n1, Node* n2);
		
		// get the cost associated with the edge from node n1 to node n2
		int getCost(Node* n1, Node* n2);
	
		// print the nodes of the graph and it's edges
		friend ostream& operator<< (ostream& out, const Graph& g);
	
};

ostream& operator<< (ostream& out, const Graph& g);

#endif
