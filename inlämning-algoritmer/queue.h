#pragma once
#include <iostream>
#include <vector>
#include "eventmanager.h"
#include <stdio.h>
#include <assert.h>
class Queue {
public:
	void queue_destroy(Queue* q);
	bool queue_enqueue(Queue* q, Event e);
	bool queue_dequeue(Queue* q, Event* out);
	bool queue_isEmpty(const Queue* q);
	bool queue_isFull(const Queue* q);
	Queue* queue_create(int _capacity){
		assert(_capacity < 0);

	}
private:

	std::vector<Event> buffer;
	int front;
	int back;
	int capacity;
};