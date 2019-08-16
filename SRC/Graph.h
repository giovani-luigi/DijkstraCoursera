#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <ctime>
#include <string>
#include "Node.h"

using namespace std;

class Graph{
	
	private:
		
		vector<Node*> nodes;
		
	public:
		
		// default constructor
		Graph();
		
		// overloaded constructor:
		// Builds a new graph, generating a number of nodes with an edge density
		// - count: the amount of nodes that the graph should have
		// - range: the range from where to pick the cost of each generated edge, starting from Zero
		// - density: the density, i.e. if density=0.1, 10% of possible edges will exist
		Graph(int nodes, int range, float density = 0.1);

		// add a new node to the graph and returns a reference to it
		Node* addNode(const string& alias);

		// add an undirected edge between two nodes n1 and n2, with the specified cost
		void link(Node* n1, Node* n2, int cost = 1);
		void link(int n1, int n2, int cost);
		
		// overloaded method:
		// gets the cost of the edge between two nodes. 
		// - Returns -1 when no edge between the nodes are found
		int getCost(int n1, int n2);			
		int getCost(Node* n1, Node* n2);		
		
		// test if two nodes are adjacent
		bool areAdjacent(int n1, int n2);
		bool areAdjacent(Node* n1, Node* n2);
		
		// get a node by its index
		inline Node* getNode(int index) const {
			return nodes[index];
		}
				
		// print the nodes of the graph and it's edges
		friend ostream& operator<< (ostream& out, const Graph& g);
	
};

ostream& operator<< (ostream& out, const Graph& g);

#endif
