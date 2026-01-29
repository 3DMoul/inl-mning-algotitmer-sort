#include "queue.h"

void Queue::queue_destroy(Queue* q){
	
}
bool Queue::queue_enqueue(Queue* q, Event e){
	return false;
}
bool Queue::queue_dequeue(Queue* q, Event* out){
	return false;
}
bool Queue::queue_isFull(const Queue* q) { return (back + 1) % capacity == front; }
bool Queue::queue_isEmpty(const Queue* q) { return front == back; }
