
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dll.h"
#include <stdio.h>

dll_head_t* create_dll() {
    dll_head_t* head = (dll_head_t*) malloc(sizeof(dll_head_t));
    head->first = NULL;
    return head;
}

void destroy_dll_node(dll_node_t* node) {
    printf("Destroying node with contents \"%s\"\n", node->contents);
    free(node->contents);
    free(node);
    return;
}

void destroy_dll(dll_head_t* head) {
    printf("Destroying linked list\n");
    dll_node_t* to_destroy = head->first;
    while (to_destroy != NULL) {
        dll_node_t* next = to_destroy->next;
        destroy_dll_node(to_destroy);
        to_destroy = next;
    }
    return;
}

dll_node_t* node_from_str(const char* source) {
    size_t length = strlen(source);
    char* copy = (char*) malloc(length+1);
    copy[length] = 0;
    dll_node_t* node = (dll_node_t*) malloc(sizeof(dll_node_t));
    node->prev = NULL;
    node->next = NULL;
    node->contents = strncpy(copy, source, length+1);
    return node;
}

void insert_first_dll(dll_head_t* head, const char* source) {
    dll_node_t* new = node_from_str(source);
    if (head->first == NULL) {
        head->first = new;
        return;
    }
    dll_node_t* old = head->first;
    head->first = new;
    new->next = old;
    old->prev = new;
    return;
}


void insert_last_dll(dll_head_t* head, const char* source) {
    dll_node_t* new = node_from_str(source);
    if (head->first == NULL) {
        head->first = new;
        return;
    }
    dll_node_t* last = get_last_dll(head);
    new->prev = last;
    last->next = new;
}

dll_node_t* get_last_dll(dll_head_t* head) {
    dll_node_t* node = head->first;
    if (node == NULL) {
        return NULL;
    }
    while(node != NULL){
        if (node->next == NULL) {
            return node;
        }
        node = node->next;
    }
    assert(0 && "This is unreachable, because of the dll's invariants");
}

dll_node_t* get_from_dll(dll_head_t* head, size_t index) {
    dll_node_t* node = head->first;
    for (size_t i = 0; node != NULL && i < index; i++){
        node = node->next;
    }
    return node;
}

dll_node_t* find_in_dll(dll_head_t* head, const char* target) {
    dll_node_t* node = head->first;
    while(node != NULL){
        if (strcmp(target, node->contents) != 0) {
            node = node->next;
            continue;
        }
        return node;
    }
    return NULL;
}

void pop_dll_node(dll_node_t* node) {
    if (node == NULL) {
        return;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
        if (node->next != NULL) {
            node->next->prev = node->prev;
        }
    }
}

dll_node_t* pop_from_dll(dll_head_t* head, size_t index) {
    dll_node_t* node = get_from_dll(head, index);
    if (node != NULL) {
        head->first = node->next;
    }
    node->next = NULL;
    return node;
}

dll_node_t* pop_first_from_dll(dll_head_t* head) {
    dll_node_t* node = head->first;
    if (node == NULL) {
        return NULL;
    }
    head->first = node->next;
    return node;
}

dll_node_t* pop_last_from_dll(dll_head_t* head) {
    dll_node_t* node = get_last_dll(head);
    pop_dll_node(node);
    return node;
}

size_t dll_length(dll_head_t* head) {
    dll_node_t* node = head->first;
    size_t i = 0;
    for (; node != NULL; i++ ){
        node = node->next;
    }
    return i;
}

void dll_display(dll_head_t* head) {
    printf("Linked List: head");
    dll_node_t* node = head->first;
    while (node != NULL){
        printf(" -> \"%s\"", node->contents);
        node = node->next;
    }
    printf("\n");
    return;
}