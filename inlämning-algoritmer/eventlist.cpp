#include "eventlist.h"

event_List* list_Functions::createEventList(Event*& E){
    event_List* newEvent = (event_List*)std::malloc(sizeof(event_List));
    if (!newEvent)
        return nullptr;
    newEvent->currentEvent = E;
    newEvent->next = nullptr;
    return newEvent;
}
int list_Functions::listSize(event_List* head) {
    int count = 0;
    event_List* current = head;
    while (current->currentEvent != nullptr) {
        count++;
        current = current->next;

    }
    return count;
}
event_List* list_Functions::insertAtFront(event_List*& head, Event*& new_Event){
    // Create a new node with the given data
    event_List* new_node = new event_List(new_Event);

    // Make the next of the new node point to the current
    // head
    new_node->next = head;

    // Return the new node as the new head of the list
    return new_node;
}