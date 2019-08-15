#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Link;

class Node{
	
	private:
		
		string alias;
	
		vector<Link> links;
	
	public:
		
		// constructor
		Node(const string& alias);
				
		// get the alias assigned to this node
		string getAlias() const;
		
		// add a node into the adjancency list
		void addNeighbor(Node* n, int cost = 1);
		
		// get all adjacent nodes
		inline const vector<Link>& getLinks() const { 
			return links; 
		}
		
};

struct Link{
	Node* target;
	int cost;
};

ostream& operator<< (ostream& out, const Node& right);

#endif

