#include "Graph.h"
#include "MinHeap.h"
#include "HeapVector.h"

// default constructor
// creates an empty graph
Graph::Graph(){
}

// overloaded constructor:
// Loads a graph from a text file
// - filename: the path to the file as a null-terminated string (Coursera defined format)
Graph::Graph(const char *filename){

	ifstream file(filename);
	
	// skip if file cannot be opened
	if (!file.good()) return;
	
	// load each line of the file to a string in a vector
	vector<string> lines;
	string line;
	while (getline(file, line, '\n'))
		lines.push_back(line);
	
	// The file format is an initial integer that is the node size of the graph 
	// and the further values will be integer triples: (i, j, cost). 
	// we will skip 1st line as the graph is dynamically allocated
	
	// 1st pass: create all nodes 
	int last = -1;
	for(auto it= ++lines.begin(); it!=lines.end(); it++){
		int read;
		stringstream ss(*it);
		ss >> read;
		if (read != last){ // add if node does not exist
			this->addNode(to_string(read));
			last=read;
		}
	}
	
	// 2nd pass: connect the nodes
	for(auto it= ++lines.begin(); it!=lines.end(); it++){
		int i, j, cost;
		stringstream ss(*it);
		ss >> skipws >> i >> j >> cost;
		this->link(i, j, cost);
	}
	
}

// overloaded constructor
// Builds a new graph, generating a number of nodes with an edge density
Graph::Graph(int count, int range, float density){
	
	// create all vertices/nodes
	for (int i = 0; i<count ; i++ )
		addNode(string("N") + to_string(i));
	
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
int Graph::addNode(const string alias){
	Node n(alias);
	nodes.push_back(n);
	return nodes.size()-1;
}

// add an edge between two nodes n1 and n2, with the specified cost
void Graph::link(int n1, int n2, int cost){
	nodes[n1].addNeighbor(n2, cost);
	nodes[n2].addNeighbor(n1, cost);
}

// overloaded method:
// gets the cost of the edge between two nodes. 
// - Returns -1 when no edge between the nodes are found
int Graph::getCost(int n1, int n2){
	if (n1 == n2) return 0; // optimization
	vector<Path> edges = nodes[n1].getNeighbors();
	for (int i=0; i<edges.size(); i++)
		if ( edges[i].index == n2 ) // if the node n1 has path to n2
			return edges[i].cost;
	return -1; // no edges between n1 and n2 found
}

// test if two nodes are adjacent
bool Graph::areAdjacent(int n1, int n2){
	return (getCost(n1, n2) > -1);
}

// returns the shortest path between a source and a target node using Dijkstra algorithm
vector<Node> Graph::getShortestPath(int sourceIndex, int targetIndex){
	
	// in order to calculate the sequence of nodes we need to follow
	// to get the shortest path, we need 3 structures:
	bool visited[nodes.size()] {}; // stores a visited true/false flag (all initialize to default: 'false')
	MinHeap heap; // the min heap used to store and retrieve the nodes with smallest cost
	Path routes[nodes.size()] {};  // holds the data (min.cost + prev.node) to build resulting path
	
	// fill the min. heap and routes[] table with all nodes with INFINITE cost
	// except the cost of the source, which is Zero.
	for (int i=0; i<nodes.size(); i++){
		int cost = (i==sourceIndex ? 0 : INFINITE_COST);
		heap.add( new HeapNode(cost, i));
		routes[i].index = i;
		routes[i].cost = cost;
	}		
	
	// now while the heap is not empty, we will visit every node
	while(heap.size()>0){
		
		// get the node to visit
		HeapNode* n = heap.pull();
		
		// mark as visited
		visited[n->value] = true;
	
		// current's node cost to source
		int currentNodeCost = n->key;
		
		// obtain all neighbors of current node
		vector<Path> neighbors = nodes[n->value].getNeighbors();
		
		// for every neighbor of current node being visited we check:
		for (vector<Path>::iterator it=neighbors.begin(); it!=neighbors.end(); it++){
			
			// if node has been visited already (pulled out of heap), skip
			if (visited[it->index]) continue;
			
			// cost of node to source
			int nodeCostToSource = currentNodeCost + it->cost; 
			
			// if the new value is less than the known one (the one in the routes[] table)
			if (nodeCostToSource < routes[it->index].cost ){
				// we found a better route, so update heap and routes[] table
				routes[it->index].index = n->value; // store the "PREV. NODE" so we know the path to arrive to this node
				routes[it->index].cost = nodeCostToSource;  // store the new/better cost 
				// also, update the heap, IF its in the heap
				heap.update( it->index , nodeCostToSource);
			}
		}
		
		// destroy created objects
		delete n;
	}
	
	// Dijkstra's algorithm is done, now use generated
	// data to build the best path from source to end.
	
	if (VERBOSE){
		cout << "Result: " << endl;
		for ( int i=0; i<nodes.size(); i++){
			cout << "Routes from Vertex(" << i << ") to Vertex (" << routes[i].index << ") cost is = " << routes[i].cost << endl;
		}
	}
	
	// the shortest cost from source to target is stored
	// at the index n of routes[] where n is the index of
	// the target. 
	
	// the index of routes[] is equivalent to nodes[]Route
	
	// to build the path:
	// starting from target node, we will navigate,
	// backwards using the routes[] table
	// after gathering all nodes, we will reverse
	// the collection and return it
	vector<Node> bestPath; 
	
	int nextIndex = targetIndex;	
	while (nextIndex != sourceIndex){          // stop when we reach to source
		bestPath.push_back(nodes[nextIndex]);
		nextIndex = routes[nextIndex].index;
	}
	bestPath.push_back(nodes[sourceIndex]);	   // add the source
	reverse(bestPath.begin(), bestPath.end()); // reverse collection so we get order from start
				
	return bestPath; // return by copy
}

// returns the min. spanning tree starting at a given node
Graph Graph::getMinimumSpanningTree(int sourceIndex, int& min_cost){
	
	// initialize output cost
	min_cost = 0;
	
	// create a graph to generate as output
	Graph result;
	for (int i=0; i<nodes.size(); i++)
		result.addNode(to_string(i));
	
	// create a min heap to sort the edges
	HeapVector<Edge> edges;
	bool visited[this->size()]; // creates an array of flags
	
	// initialize array of visited nodes
	for (bool n : visited) 
		n = false;
	
	// we start at source
	edges.add(0, Edge(sourceIndex, sourceIndex, 0));
	
	do{
		
		// pull next edge from heap
		Edge edge = edges.pull();
		
		if (VERBOSE)
			cout << "Pulling edge with cost $" << edge.cost << " from node[" << edge.from << "] to node[" << edge.to << "]" << endl;

		if (!visited[edge.to]){
			
			// add the next selected node to the visited set
			visited[edge.to] = true;
			
			// add the cost of this edge
			min_cost += edge.cost;
			
			// skip starting loop edge
			if (edge.to != edge.from)
				result.link(edge.from, edge.to, edge.cost); // use this edge in the resulting graph	
			
			if (VERBOSE)
				cout << "Using edge with cost $" << edge.cost << " from node[" << edge.from << "] to node[" << edge.to << "]" << endl;
		
			// put all edges of selected node into the heap
			auto neighbors = nodes[edge.to].getNeighbors();
			for ( auto it = neighbors.begin(); it!=neighbors.end() ; it++){
				if (!visited[it->index]){
					edges.add(it->cost, Edge(edge.to, it->index, it->cost));
				}
			}
		}
	
	} while (edges.size()>0); // loop until heap is empty		
	
	return result;
}

// output operator override
ostream& operator<< (ostream& out, const Graph& g){
	for (int i = 0; i<g.nodes.size(); i++){
		
		// print the current node we are iterating
		out << "Node[" << i << "]: '" << g.nodes[i].getAlias() << "' => ";
		
		// print all connections from current node
		vector<Path> paths = g.nodes[i].getNeighbors();
		for (int j = 0; j<paths.size(); j++)
			out << "('" << g.nodes[paths[j].index].getAlias() << "'; $" << paths[j].cost << ")";
		
		out<< endl;
	}	
	return out;
}


