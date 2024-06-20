
#include "LinkedList.h"
#include "Node.h"

struct Node* create_node(void* data, int data_type, int size);
void destroy_node(struct Node* node_to_destroy);

struct Node* iterate(struct LinkedList* linked_list, int index);
void insert_node(struct LinkedList *linked_list, int index, void *data, int data_type, int size);
void remove_node(struct LinkedList *linked_list, int index);
void* retrieve_data(struct LinkedList *linked_list, int index);

struct LinkedList linked_list_int_constructor(){
    struct LinkedList new_list;
    new_list.head = NULL;
    new_list.length = 0;

    new_list.insert = insert_node;
    new_list.remove = remove_node;
    new_list.retrieve = retrieve_data;
    // new_list.constructor = linked_list_int_constructor;

    return new_list;     
}

struct Node* create_node(void* data, int data_type, int size){
    struct Node* new_node_address = (struct Node*)malloc(sizeof(struct Node));
    if(new_node_address == NULL){
        printf("Memory allocation failed\n");
    }
    // struct Node new_node_instance;
    // new_node_instance.data = data;
    // new_node_instance.next = NULL;
    // *new_node_address = new_node_instance;

    new_node_address->data = data;
    new_node_address->next = NULL;
    return new_node_address;
}

void destroy_node(struct Node* node_to_destroy){
    
    node_destructor(node_to_destroy);

    // free(node_to_destroy->data);
    // free(node_to_destroy);
}

struct Node* iterate(struct LinkedList* linked_list, int index){
    if(index < 0 || index >= linked_list->length){
        printf("Index out of bound..");
        exit(-9);
    }
    struct Node* cursor = linked_list->head;
    for(int i=0; i<index; i++){
        cursor = cursor->next;
    }
    return cursor;
}

void insert_node(struct LinkedList *linked_list, int index, void *data, int data_type, int size){
    
    struct Node* node_to_insert = create_node(data, data_type, size);
    if(index == 0){
        // node_to_insert->data = data;
        node_to_insert->next = linked_list->head;
        linked_list->head = node_to_insert;
    }
    else{
        struct Node* cursor = iterate( linked_list, index-1);
        node_to_insert->next = cursor->next;
        cursor->next = node_to_insert;
    }
    linked_list->length += 1;
}

void remove_node(struct LinkedList *linked_list, int index){
    
    if(index == 0){
        struct Node* node_to_remove = linked_list->head;
        linked_list->head = node_to_remove->next;
        destroy_node(node_to_remove);
    }
    else{
        struct Node* cursor = iterate(linked_list, index-1);
        struct Node* node_to_remove = cursor->next;
        cursor->next = node_to_remove->next;
        destroy_node(node_to_remove);
    }
    linked_list->length -= 1;
}

void* retrieve_data(struct LinkedList *linked_list, int index){
    struct Node* cursor = iterate(linked_list, index);
    return cursor->data;
}

void linked_list_destructor(struct LinkedList *linked_list){
    free(linked_list);
}







