#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <algorithm> 	// std::reverse()
#include <ctime>
#include <string> 
#include <climits>  	// INT_MAX
#include <fstream> 		// std::ifstream()
#include <sstream>		// std::stringstream()

#include "Node.h"
#include "HeapVector.h"

using namespace std;

const int INFINITE_COST = INT_MAX;
const bool VERBOSE = false;

class Graph{
	
	private:
		
		vector<Node> nodes;
		
	public:
		
		// default constructor
		Graph();
		
		// overloaded constructor:
		// Loads a graph from a text file
		// - filename: [optional] the path to the file as a null-terminated string
		Graph(const char *filename);
		
		// overloaded constructor:
		// Builds a new graph, generating a number of nodes with an edge density
		// - count: the amount of nodes that the graph should have
		// - range: the range from where to pick the cost of each generated edge, starting from Zero
		// - density: the density, i.e. if density=0.1, 10% of possible edges will exist
		Graph(int nodes, int range, float density = 0.2);

		// add a new node to the graph and returns it's index
		int addNode(const string alias);

		// add an undirected edge between two nodes n1 and n2, with the specified cost
		void link(int n1, int n2, int cost = 1);
		
		// overloaded method:
		// gets the cost of the edge between two nodes. 
		// - Returns -1 when no edge between the nodes are found
		int getCost(int n1, int n2);			
		
		// test if two nodes are adjacent
		bool areAdjacent(int n1, int n2);

		// returns the shortest path between a source and a target node using Dijkstra algorithm
		vector<Node> getShortestPath(int sourceIndex, int targetIndex);
		
		// returns the min. spanning tree starting at a given node
		// - sourceIndex: the index of the source node in the graph
		// - min_cos: [output] the min. cost
		Graph getMinimumSpanningTree(int sourceIndex, int& min_cost);
		
		// gets the number of nodes (vertices) in the graph
		inline int size(){ return nodes.size();	}
		
		// print the nodes of the graph and it's edges
		friend ostream& operator<< (ostream& out, const Graph& g);
	
};

ostream& operator<< (ostream& out, const Graph& g);

#endif
