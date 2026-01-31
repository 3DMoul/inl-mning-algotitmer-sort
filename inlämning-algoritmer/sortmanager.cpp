#include "sortmanager.h"


void sort_Manager::selectionSort(event_List*& List) {
    for (event_List* start = List; start != nullptr; start = start->next) {
        event_List* min_node = start;
        for (event_List* curr = start->next; curr != nullptr; curr = curr->next) {
            if (curr->currentEvent && min_node->currentEvent &&
                curr->currentEvent->get_EventId_() < min_node->currentEvent->get_EventId_()) {
                min_node = curr;
            }
        }
        if (min_node != start) std::swap(start->currentEvent, min_node->currentEvent);
    }
}
event_List* sort_Manager::getTail(event_List* head) {
    while (head && head->next)
        head = head->next;
    return head;
}

event_List* sort_Manager::partition(event_List* head, event_List* tail) {

    // Pivot is the first node
    event_List* pivot = head;

    event_List* pre = head;
    event_List* curr = head;

    while (curr != tail->next) {

        if (curr->currentEvent->get_EventId_() <
            pivot->currentEvent->get_EventId_()) {

            // swap Event pointers (NOT nodes)
            std::swap(curr->currentEvent, pre->next->currentEvent);

            pre = pre->next;
        }

        curr = curr->next;
    }

    std::swap(pivot->currentEvent, pre->currentEvent);

    return pre; // new pivot position
}

void sort_Manager::quickSortHelper(event_List* head, event_List* tail) {

    if (!head || head == tail)
        return;

    event_List* pivot = partition(head, tail);

    // Left side
    quickSortHelper(head, pivot);

    // Right side
    quickSortHelper(pivot->next, tail);
}

event_List* sort_Manager::quickSort(event_List* head) {

    event_List* tail = getTail(head);
    quickSortHelper(head, tail);
    return head;
}