#include <iostream>
#include "Graph.h"
#include "MinHeap.h"

/*

Basic problem: 
Write a set of constructors for declaring and initializing a graph.
An edge will have a positive cost that is its distance. 

Have a procedure that produces a randomly generated set of edges 
with positive distances. Assume the graphs are undirected. 

The random graph procedure should have edge density as a parameter 
and distance range as a parameter. So a graph whose density is 0.1 
would have 10% of its edges picked at random and its edge distance 
would be selected at random from the distance range. The procedure 
should run through all possible undirected edges, say (i,j) and place 
the edge in the graph if a random probability calculation is less 
than the density.

Compute for a set of randomly generated graphs 
an average shortest path.

*/
 
void test1(){

	// create a new Graph object
	Graph *g = new Graph();
	
	cout << "Building nodes..." << endl;

	int c1 = g->addNode(string("City 1")); // 0
	int c2 = g->addNode(string("City 2")); // 1
	int c3 = g->addNode(string("City 3")); // 2
	int c4 = g->addNode(string("City 4")); // 3
	int c5 = g->addNode(string("City 5")); // 4
	int c6 = g->addNode(string("City 6")); // 5
	
	cout << "Linking nodes..." << endl;
	
	g->link(c1, c2); // c1 <=> c2
	g->link(c2, c3); // c2 <=> c3
	g->link(c2, c4); // c2 <=> c4
	g->link(c2, c5); // c2 <=> c5
	g->link(c3, c6); // c3 <=> c6
	g->link(c4, c6); // c4 <=> c6	

	cout << "Done." << endl;
	
	cout << *g << endl;
}

void test2(){

	cout << "Building graph..." << endl;

	// create a new Graph object with random 
	Graph *g = new Graph(10, 2, 0.2);
	
	cout << "Result:" << endl;
	
	cout << *g << endl;
}
 
void test3(){
	
	MinHeap heap;
	
	heap.add(new HeapNode(20, 1));
	heap.printArray();
	heap.add(new HeapNode(30, 2));
	heap.printArray();
	heap.add(new HeapNode(10, 3));
	heap.printArray();
	heap.add(new HeapNode(70, 4));
	heap.printArray();
	heap.add(new HeapNode(40, 5));
	heap.printArray();
	heap.add(new HeapNode(90, 6));
	heap.printArray();
	
	cout << endl << endl;
	
	cout << "Updating: existing node" << endl;
	system("pause"); 
	
	heap.update(6, 100);
	
	cout << "Pulling... " << endl;
	system("pause"); 
	
	for (int i=0; i<6; i++){
		HeapNode* node = heap.pull();
		cout << "Next: " << node->key << endl;
		delete node;
		heap.printArray();
		system("pause");
	}
	
}

void testDijkstra1(){
	
	// create a new Graph object
	Graph *g = new Graph();
	
	cout << "Building nodes..." << endl;

	int c1 = g->addNode(string("City 1")); // 0
	int c2 = g->addNode(string("City 2")); // 1
	int c3 = g->addNode(string("City 3")); // 2
	int c4 = g->addNode(string("City 4")); // 3
	int c5 = g->addNode(string("City 5")); // 4
	
	cout << "Linking nodes..." << endl;
	
	g->link(c1, c2, 1); // c1 <=> c2 = $1
	g->link(c1, c3, 3); // c1 <=> c3 = $3
	g->link(c2, c4, 2); // c2 <=> c4 = $2
	g->link(c2, c5, 5); // c2 <=> c5 = $5
	g->link(c3, c4, 2); // c3 <=> c4 = $2
	g->link(c4, c5, 1); // c4 <=> c5 = $1

	// best path = n[0](City 1) -> n[1](City 2) -> n[3](City 4) -> n[4](City 5)

	vector<Node> bestPath = g->getShortestPath(c1, c5);

	cout << "Printing best path: " << endl;
	for ( int i=0; i<bestPath.size(); i++){
		cout << "Next vertex: " << bestPath[i] << endl;
	}

	cout << "Done." << endl;
	
	cout << *g << endl;	
}


void testDijkstra2(){
	
	// create a new Graph object
	Graph *g = new Graph();
	
	cout << "Building nodes..." << endl;

	int c0 = g->addNode(string("City 0")); // start
	int c1 = g->addNode(string("City 1"));
	int c2 = g->addNode(string("City 2"));
	int c3 = g->addNode(string("City 3"));
	int c4 = g->addNode(string("City 4"));
	int c5 = g->addNode(string("City 5"));
	int c6 = g->addNode(string("City 6"));
	int c7 = g->addNode(string("City 7")); // end
	
	cout << "Linking nodes..." << endl;
	
	g->link(c0, c1, 2);
	g->link(c0, c2, 3);
	g->link(c0, c3, 4);
	g->link(c1, c2, 1);
	g->link(c1, c3, 5);
	g->link(c1, c6, 6);
	g->link(c2, c4, 3);
	g->link(c3, c5, 3);	
	g->link(c3, c7, 4);	
	g->link(c4, c6, 2);	
	g->link(c6, c7, 5);
	
	// best path = n[0](City 0) -> n[3](City 3) -> n[7](City 7)

	vector<Node> bestPath = g->getShortestPath(c0, c7);

	cout << "Printing best path: " << endl;
	for ( int i=0; i<bestPath.size(); i++){
		cout << "Next vertex: " << bestPath[i] << endl;
	}

	cout << "Done." << endl << endl;
	
	cout << *g << endl;	
}


int main(int argc, char** argv) {
	
	testDijkstra2();
	
	return 0;
}
