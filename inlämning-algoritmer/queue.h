#pragma once
#include <iostream>
#include <vector>
#include "eventmanager.h"
#include <stdio.h>
#include <assert.h>
class Queue {
public:
	void destroy();
	bool enqueue(Event* e);
	Event* dequeue();
	bool isEmpty() const;
	bool isFull() const;
	Queue(int _capacity);
private:

	std::vector<Event*> buffer;
	int front;
	int back;
	int capacity;
};