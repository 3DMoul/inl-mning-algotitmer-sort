#include "eventlist.h"

int list_Functions::listSize(event_List* head) {
    int count = 0;
    event_List* current = head;
    while (current->currentEvent != nullptr) {
        count++;
        std::cout << count << std::endl;
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

void list_Functions::List_destroy(event_List* List)
{
}

void list_Functions::List_append(event_List* List, Event e)
{
}

Event* list_Functions::List_get(const event_List* List, int id)
{
    Event* current = List->currentEvent;
    
    if (List->currentEvent == nullptr)
        return nullptr;
    else if (!(current->get_EventId_() == id))
        current = List->next->currentEvent;
    else
    return current;
}

void list_Functions::List_set(event_List* List, int index, Event e)
{
}
