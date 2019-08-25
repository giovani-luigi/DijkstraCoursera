#include "MinHeap.h"

// default constructor
MinHeap::MinHeap(){
}

// starting from the node at the index, start 
// reorganizing the heap towards the root (top)
// REMARK: non-recursive implementation
void MinHeap::heapifyUp(int index){
	while (nodes[index]->key < nodes[getParentIndex(index)]->key ){
		int parent = getParentIndex(index);
		swapNodes(index, parent);
		index = parent;
	}
}

// starting from the node at the index, start 
// reorganizing the heap towards the leaves (bottom)
// REMARK: non-recursive implementation
void MinHeap::heapifyDown(int index){

	// reorder nodes starting at the index towards the leaves
	for(; index<nodes.size();){

		// find the smallest of the keys between current node and its both childs
		int leftIndex = getLChildIndex(index);
		int rightIndex = getRChildIndex(index);
		
		int smallest = index;
		if (leftIndex < nodes.size()) // make sure child exists
			if (nodes[leftIndex]->key < nodes[smallest]->key)
				smallest = leftIndex;
		if (rightIndex < nodes.size()) // make sure child exists
			if (nodes[rightIndex]->key < nodes[smallest]->key)
				smallest = rightIndex;
		
		// if the smallest is not the current node, swap with it
		if (index!=smallest){
			swapNodes(index, smallest);
			index = smallest; // move down the tree
		} else {
			break; // heap is ordered
		}
	}
}

// add a new key in the heap
void MinHeap::add(HeapNode *n){
	
	// update index
	heapIndex.insert(make_pair(n->value, nodes.size()));
	
	// add new key to the end of the underlying vector
	nodes.push_back(n);
	
	// bubble up in the heap, while the new key is smaller than its current parent
	heapifyUp(nodes.size()-1);
}

// returns the min. key, without removing it.
// if heap is empty, throws an exception.
HeapNode* MinHeap::peek(){
	
	// evaluate heap state
	if (nodes.size()==0) 
		throw runtime_error("Heap is empty");
		
	return nodes[0];
}

void MinHeap::printArray(){
	
	cout << "Array=[ ";
	
	for(int i=0; i<nodes.size();i++)
		cout << "(Key= " << nodes[i]->key << ", Val=" << nodes[i]->value << ")" ;
		
	cout << "] " << endl << " Heap Index: " << endl;
	
	for (map<int, int>::iterator it=heapIndex.begin(); it!=heapIndex.end(); it++){
		int value = it->first;
		int index = it->second;
		cout << "The node with value " << value << " is at node[" << heapIndex[value] << "] and has Key=" << nodes[heapIndex[value]]->key << endl;
	}
	
	cout << endl;
}

// removes the smallest key from the heap
// - [Return] the removed key
HeapNode* MinHeap::pull(){
	
	// evaluate heap state
	if (nodes.size()==0) 
		throw runtime_error("Heap is empty");
	
	// locate the root of the heap, and save into a temp variable
	HeapNode* pulled = new HeapNode(*nodes[0]);
		
	// move the last element to the root
	nodes[0] = nodes.back();
	nodes.pop_back();  // remove 1 element from the end
	
	// update index
	heapIndex.erase(pulled->value); // remove index to root that has been pulled out
		
	// if the heap has any element remaining
	if (nodes.size()>0){
		heapIndex[nodes[0]->value] = 0; // update index of the new root
		heapifyDown(0); // re-order the heap
	}
		
	return pulled;
}

void MinHeap::update(int valueOfNode, int newKey){
	
	// make sure node with the value exists, and retrieve it
	map<int, int>::iterator it;
	it = heapIndex.find(valueOfNode);
	
	// if nothing found, return
	if (it == heapIndex.end())
		return;
	
	// locate the node in the array by its value
	int nodeIndex = it->second;
	HeapNode *node = nodes[nodeIndex];
	
	node->key = newKey;
	
	// if node has a parent, i.e. is not root
	if (nodeIndex > 0){
		int parentIndex = getParentIndex(nodeIndex);
		HeapNode *parent = nodes[parentIndex];

		// if parent is bigger: we have to swap and heapify up
		if (parent->key > node->key){
			swapNodes(nodeIndex, parentIndex);
			heapifyUp(parentIndex); // heapify up from point of change
			return;
		}
	}
	
	// if parent is smaller, no change upper from node is required
	// then check towards leaves:
	heapifyDown(nodeIndex);
}

MinHeap::~MinHeap(){
	for (auto it=nodes.begin(); it!=nodes.end(); it++ )
		delete *it;
}
