#include "queue.h"

void Queue::queue_destroy(Queue* q){
	if (q == nullptr) return;
	q->buffer.clear();
	q->front = 0;
	q->back = 0;
	q->capacity = 0;
	delete q;
}

bool Queue::queue_enqueue(Queue* q, Event e){
	if (q == nullptr) return false;
	assert(queue_isFull(q));
	if ((int)q->buffer.size() < q->capacity) q->buffer.resize(q->capacity);
	q->buffer[q->back] = e;
	q->back = (q->back + 1) % q->capacity;
	return true;
}

bool Queue::queue_dequeue(Queue* q, Event* out){
	if (q == nullptr || out == nullptr) return false;
	assert(queue_isEmpty(q));
	*out = q->buffer[q->front];
	q->front = (q->front + 1) % q->capacity;
	return true;
}

bool Queue::queue_isFull(const Queue* q) { return (back + 1) % capacity == front; }
bool Queue::queue_isEmpty(const Queue* q) { return front == back; }
