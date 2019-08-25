#ifndef HEAP_VECTOR_H
#define HEAP_VECTOR_H

#include <vector>
#include "MinHeap.h"

template <class T>
class HeapVector{
			
	private:
	
		// the index to provide quick sorting
		MinHeap index;
		
		// the underlying unsorted collection of items
		vector<T> items;
	
	public:
		
		// default ctor
		HeapVector(){
		}
		
		// add a new item with the given unique key
		void add(int key, T data){
			index.add(new HeapNode(key, items.size()));
			items.push_back(data);			
		}
		
		// retrieve next item
		T pull(){
			HeapNode *n = index.pull();
			int i = n->value;
			delete n;
			return items[i];
		}
		
		// returns the amount of items in the container
		int size(){ return index.size(); }
		
		// destructor
		~HeapVector(){
		}
		
};

#endif
