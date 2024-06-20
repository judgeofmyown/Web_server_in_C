#include "Queue.h"
#include "LinkedList.h"

void push(struct Queue *queue, void *data, int data_type, int size){
    queue->list.insert( &queue->list, queue->list.length, data, data_type, size);
}

void* peek(struct Queue *queue){
    
    // Check if the queue is empty
    if (queue->list.head == NULL) {
        return NULL;  // or handle the error appropriately
    }
    // Return the data at the head of the list (front of the queue)
    return queue->list.head->data;

    // struct Node *cursor = queue->list.head;
    // while (cursor->next != NULL){
    //     cursor = cursor->next;
    // }
    // return cursor->data;
}

void* pop(struct Queue* queue){
    void* data = queue->list.retrieve(&queue->list, 0);
    queue->list.remove(&queue->list, 0);
    return data; 
}

struct Queue queue_constructor(){
    struct Queue queue;
    queue.list = linked_list_int_constructor();

    queue.push = push;
    queue.peek = peek;
    queue.pop = pop;

    return queue;
};

void queue_destructor(struct Queue *queue){
    linked_list_destructor(&queue->list);
    // free(queue);
}