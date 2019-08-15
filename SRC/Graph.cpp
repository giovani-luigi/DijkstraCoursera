#include "Graph.h"

// default constructor
Graph::Graph(){
}

// add a new node to the graph and returns a reference to it
Node* Graph::addNode(const string& alias){
	Node* n = new Node(alias);
	nodes.push_back(n);
	return n;
}

// add an edge between two nodes n1 and n2, with the specified cost
void Graph::addEdge(Node* n1, Node* n2, int cost){
	n1->addNeighbor(n2, cost);
	n2->addNeighbor(n1, cost);
}

// output operator override
ostream& operator<< (ostream& out, const Graph& g){
	for (int i = 0; i<g.nodes.size(); i++){
		
		// print the current node we are iterating
		out << "Node[" << i << "]: '" << g.nodes[i]->getAlias() << "' => ";
		
		// print all connections from this node
		vector<Link> links = g.nodes[i]->getLinks();
		for (int j = 0; j<links.size(); j++)
			out << "($" << links[j].cost << ", '" << links[j].target->getAlias() << "')";
		
		out<< endl;
	}	
	return out;
}


