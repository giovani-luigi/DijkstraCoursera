#include <iostream>
#include "Graph.h"
#include "MinHeap.h"


//void testDijkstra1(){
//	
//	// create a new Graph object
//	Graph *g = new Graph();
//	
//	cout << "Building nodes..." << endl;
//
//	int c1 = g->addNode(string("City 1")); // 0
//	int c2 = g->addNode(string("City 2")); // 1
//	int c3 = g->addNode(string("City 3")); // 2
//	int c4 = g->addNode(string("City 4")); // 3
//	int c5 = g->addNode(string("City 5")); // 4
//	
//	cout << "Linking nodes..." << endl;
//	
//	g->link(c1, c2, 1); // c1 <=> c2 = $1
//	g->link(c1, c3, 3); // c1 <=> c3 = $3
//	g->link(c2, c4, 2); // c2 <=> c4 = $2
//	g->link(c2, c5, 5); // c2 <=> c5 = $5
//	g->link(c3, c4, 2); // c3 <=> c4 = $2
//	g->link(c4, c5, 1); // c4 <=> c5 = $1
//
//	// best path = n[0](City 1) -> n[1](City 2) -> n[3](City 4) -> n[4](City 5)
//
//	vector<Node> bestPath = g->getShortestPath(c1, c5);
//
//	cout << "Printing best path: " << endl;
//	for ( int i=0; i<bestPath.size(); i++){
//		cout << "Next vertex: " << bestPath[i] << endl;
//	}
//
//	cout << "Done." << endl;
//	
//	cout << *g << endl;	
//}

//void testDijkstra2(){
//	
//	// create a new Graph object
//	Graph *g = new Graph();
//	
//	cout << "Building nodes..." << endl;
//
//	int c0 = g->addNode(string("City 0")); // start
//	int c1 = g->addNode(string("City 1"));
//	int c2 = g->addNode(string("City 2"));
//	int c3 = g->addNode(string("City 3"));
//	int c4 = g->addNode(string("City 4"));
//	int c5 = g->addNode(string("City 5"));
//	int c6 = g->addNode(string("City 6"));
//	int c7 = g->addNode(string("City 7")); // end
//	
//	cout << "Linking nodes..." << endl;
//	
//	g->link(c0, c1, 2);
//	g->link(c0, c2, 3);
//	g->link(c0, c3, 4);
//	g->link(c1, c2, 1);
//	g->link(c1, c3, 5);
//	g->link(c1, c6, 6);
//	g->link(c2, c4, 3);
//	g->link(c3, c5, 3);	
//	g->link(c3, c7, 4);	
//	g->link(c4, c6, 2);	
//	g->link(c6, c7, 5);
//	
//	// best path = n[0](City 0) -> n[3](City 3) -> n[7](City 7)
//
//	vector<Node> bestPath = g->getShortestPath(c0, c7);
//
//	cout << "Printing best path: " << endl;
//	for ( int i=0; i<bestPath.size(); i++){
//		cout << "Next vertex: " << bestPath[i] << endl;
//	}
//
//	cout << "Done." << endl << endl;
//	
//	cout << *g << endl;	
//}

//void testDijkstraRandomGraph(){
//	
//	// create a new Graph object
//	Graph *g = new Graph(20, 10, 0.1);
//	
//	cout << "Building nodes..." << endl;
//	
//	// find the best path between first and last node
//	vector<Node> bestPath = g->getShortestPath(0, g->size()-1);
//
//	cout << "Printing best path: " << endl;
//	for ( int i=0; i<bestPath.size(); i++){
//		cout << "Next vertex: " << bestPath[i] << endl;
//	}
//
//	cout << "Done." << endl << endl;
//	
//	cout << *g << endl;	
//}

void testMinSpanTree(){
	
	Graph g("graph.txt");
	
	cout << g << endl;
	
}

int main(int argc, char** argv) {
	
	testMinSpanTree();
	
	return 0;
}
