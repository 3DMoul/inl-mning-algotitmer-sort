#include "eventlist.h"
// goes throu the whole list until nullptr and counts how big the list is
int list_Functions::listSize(event_List* head) {
    int count = 0;
    event_List* current = head;
    if (current == nullptr)
        return 0;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
// insert at the front of the list
event_List* list_Functions::insertAtFront(event_List*& head, Event*& new_Event) {
    assert(new_Event != nullptr && "insertAtFront received null Event*");

    event_List* new_node = new event_List(new_Event);
    new_node->next = head;
    return new_node;
}

void list_Functions::listDestroy(event_List*& List)
{
    event_List* current = List;
    while (current != nullptr) {
        event_List* next = current->next;
        if (current->currentEvent != nullptr) {
            delete current->currentEvent;
            current->currentEvent = nullptr;
        }
        delete current;
        current = next;
    }
    List = nullptr;
}
Event* list_Functions::listGet(const event_List* List, int id)
{
    if (List == nullptr) return nullptr;
    const event_List* cur = List;
    while (cur) {
        if (cur->currentEvent && cur->currentEvent->get_EventId_() == id)
            return cur->currentEvent;
        cur = cur->next;
    }
    return nullptr;
}