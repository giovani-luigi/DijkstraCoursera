#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>

using namespace std;

// This structure represents a node of a heap
struct HeapNode {
	
	int key;   // used for sorting
	int value; // (UNIQUE) any data
	
	HeapNode(int key, int value){
		this->key=key;
		this->value = value;
	}
};

// This class represents a Min Heap implementation, where:
// -> every node of the heap is sorted by its 'key' field.
// -> 'value' field must be UNIQUE for proper indexing
// -> insert/update/delete are available
// -> peek (look only) / poll (extract) are available to
//    retrieve the member with the MINIMUM KEY of all.
class MinHeap{
	
	private:
		
		// underlying structure used to store the nodes of the heap
		vector<HeapNode*> nodes;
		
		// index of values: used to find the array index of a node with a given value.
		// first: the unique value of a heap node
		// second: the index of the node in the heap array 'nodes[]'
		map<int, int> heapIndex;

		// apply heapify starting at a given index
		// REMARK: non-recursive implementations
		void heapifyUp(int index);
		void heapifyDown(int index);
		
		// methods to calculate the child of a node at a given index
		inline int getRChildIndex(int index){ return 2*index+2; }
		inline int getLChildIndex(int index){ return 2*index+1; }
		inline int getParentIndex(int index){ return ((index==0) ? 0 : (index-1)/2); }
		
		// swap the content of two nodes with the given indexes
		inline void swapNodes(int n1, int n2){
			// swap indexes
			heapIndex[nodes[n1]->value] = n2;
			heapIndex[nodes[n2]->value] = n1;
			// swap values
			HeapNode* tmp = nodes[n1];
			nodes[n1] = nodes[n2];
			nodes[n2] = tmp;
		}
		
	public:
		
		// default constructor
		MinHeap();
		
		~MinHeap();
		
		// add a new node in the heap
		void add(HeapNode *n);
		
		// change the key (sorted member) of a node where 
		// its 'value' field matches a specified value.
		void update(int valueOfNode, int newKey);
		
		void printArray();
		
		// returns the node with min. key, without removing it
		HeapNode* peek();
		
		// removes the node with smallest key from the heap
		// - [Return] the removed key
		HeapNode* pull();
		
		// returns the number of nodes in the heap
		inline int size() { nodes.size(); }
		
};

#endif
