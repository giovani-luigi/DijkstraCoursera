#include "Node.h"

Node::Node(const string alias){
	this->alias = alias;
}

string Node::getAlias() const{
	return alias;
}

void Node::addNeighbor(int n, int cost){
	Path p(n, cost);
	neighbors.push_back(p);
}

ostream& operator<< (ostream& out, const Node& right){
	return out << right.getAlias();
}
