#include "Node.h"

Node::Node(const string& alias){
	this->alias = alias;
}

string Node::getAlias() const{
	return alias;
}

void Node::addNeighbor(Node* n, int cost){
	Edge e = { n, cost };
	edges.push_back(e);
}

ostream& operator<< (ostream& out, const Node& right){
	return out << right.getAlias();
}
