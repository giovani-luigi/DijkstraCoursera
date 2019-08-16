#include <iostream>
#include "Graph.h"

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

	Node* c1 = g->addNode(string("City 1"));
	Node* c2 = g->addNode(string("City 2"));
	Node* c3 = g->addNode(string("City 3"));
	Node* c4 = g->addNode(string("City 4"));
	Node* c5 = g->addNode(string("City 5"));
	Node* c6 = g->addNode(string("City 6"));
	
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
 
 

int main(int argc, char** argv) {
	
	//test1();
	
	test2();
	
	return 0;
}
