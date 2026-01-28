#include "eventlist.h"

event_List* list_Functions::createEventList(Event* E)
{
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
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}