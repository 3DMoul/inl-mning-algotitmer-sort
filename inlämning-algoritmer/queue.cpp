#include "queue.h"
Queue::Queue(int _capacity) {
	assert(_capacity > 0);
	this->capacity = _capacity + 1;
	this->front = 0;
	this->back = 0;
	buffer.resize(capacity);
}
void Queue::destroy(){
	// clear and delete this instance (caller should not use the pointer afterwards)
	buffer.clear();
	front = 0;
	back = 0;
	capacity = 0;
	delete this;
}

bool Queue::enqueue(Event* e){
	assert(e != nullptr);
	assert(!isFull());
	if ((int)buffer.size() < capacity) buffer.resize(capacity);
	buffer[back] = e;
	back = (back + 1) % capacity;
	return true;
}

Event* Queue::dequeue(){
	assert(!isEmpty());
	Event* out = buffer[front];
	front = (front + 1) % capacity;
	return out;
}

bool Queue::isFull() const { return (back + 1) % capacity == front; }
bool Queue::isEmpty() const { return front == back; }
