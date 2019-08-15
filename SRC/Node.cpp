#include "Node.h"

Node::Node(const string& alias){
	this->alias = alias;
}

string Node::getAlias() const{
	return alias;
}

void Node::addNeighbor(Node* n, int cost){
	Link link = { n, cost };
	links.push_back(link);
}

ostream& operator<< (ostream& out, const Node& right){
	return out << right.getAlias();
}
