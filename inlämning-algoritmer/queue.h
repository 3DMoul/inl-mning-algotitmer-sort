#pragma once
#include <iostream>
#include <vector>
#include "eventmanager.h"
#include <stdio.h>
#include <assert.h>
class Queue {
public:
	void queue_destroy(Queue* q);
	bool queue_enqueue(Queue*& q, Event* e);
	Event* queue_dequeue(Queue*& q);
	bool queue_isEmpty(const Queue* q);
	bool queue_isFull(const Queue* q);
	Queue(int _capacity){
		assert(_capacity > 0);
		this->capacity = _capacity + 1;
		this->front = 0;
		this->back = 0;
		buffer.resize(capacity);
	}
private:

	std::vector<Event*> buffer;
	int front;
	int back;
	int capacity;
};