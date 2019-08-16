#include "Graph.h"

// default constructor
// creates an empty graph
Graph::Graph(){
}

// overloaded constructor
// Builds a new graph, generating a number of nodes with an edge density
Graph::Graph(int count, int range, float density){
	
	// create all vertices/nodes
	for (int i = 0; i<count ; i++ )
		addNode(string("N") + to_string(i) );
	
	// seed the random generator
	srand(clock());
	
	// iterate through all possible edges, creating an edge 
	// using density as a probability of its existence
	for (int i=0; i<count; i++)
		for (int j=0; j<count; j++)
			if ( (rand() % 100) < (density * 100) )
				if ( !areAdjacent(i, j) ) // check if an edge already exists
					link(i, j, 1 + (rand() % range) );  // create an edge between i and j, with a random cost within a range				
}

// add a new node to the graph and returns a reference to it
Node* Graph::addNode(const string& alias){
	Node* n = new Node(alias);
	nodes.push_back(n);
	return n;
}

// overloaded method:
// add an edge between two nodes n1 and n2, with the specified cost
void Graph::link(Node* n1, Node* n2, int cost){
	n1->addNeighbor(n2, cost);
	n2->addNeighbor(n1, cost);
}

// overloaded method:
// add an edge between two nodes n1 and n2, with the specified cost
void Graph::link(int n1, int n2, int cost){
	link(getNode(n1), getNode(n2), cost);
}

// overloaded method:
// gets the cost of the edge between two nodes. 
// - Returns -1 when no edge between the nodes are found
int Graph::getCost(Node* n1, Node* n2){
	if (n1 == n2) return 0; // optimization
	vector<Edge> edges = n1->getEdges();
	for (int i=0; i<edges.size(); i++){
		if ( edges[i].target == n2 ) // if the node n1 has path to n2
			return edges[i].cost;
	}
	return -1; // no edges between n1 and n2 found
}

// overloaded method:
// gets the cost of the edge between two nodes. 
// - Returns -1 when no edge between the nodes are found
int Graph::getCost(int n1, int n2){
	return getCost(getNode(n1), getNode(n2));
}

// overloaded method:
// test if two nodes are adjacent
bool Graph::areAdjacent(Node* n1, Node* n2){
	return (getCost(n1, n2) > -1);
}

// overloaded method:
// test if two nodes are adjacent
bool Graph::areAdjacent(int n1, int n2){
	return areAdjacent(getNode(n1), getNode(n2));
}

// output operator override
ostream& operator<< (ostream& out, const Graph& g){
	for (int i = 0; i<g.nodes.size(); i++){
		
		// print the current node we are iterating
		out << "Node[" << i << "]: '" << g.nodes[i]->getAlias() << "' => ";
		
		// print all connections from current node
		vector<Edge> edges = g.nodes[i]->getEdges();
		for (int j = 0; j<edges.size(); j++)
			out << "($" << edges[j].cost << ", '" << edges[j].target->getAlias() << "')";
		
		out<< endl;
	}	
	return out;
}


