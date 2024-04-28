#include <stdint.h>
#include <stddef.h>

typedef struct __dll_node {
    struct __dll_node* next;
    struct __dll_node* prev;
    char * contents;
} dll_node_t;

dll_node_t* create_dll();
void destroy_dll(dll_node_t* head);


size_t dll_length(dll_node_t* head);
void insert_first_dll(dll_node_t* head, const char* source);
void insert_last_dll(dll_node_t* head, const char* source);
dll_node_t* get_last_dll(dll_node_t* head);
dll_node_t* get_from_dll(dll_node_t* head, size_t index);
dll_node_t* find_in_dll(dll_node_t* head, const char* target);

dll_node_t* pop_last_from_dll(dll_node_t* head);
dll_node_t* pop_first_from_dll(dll_node_t* head);
dll_node_t* pop_from_dll(dll_node_t* head, size_t index);
void pop_dll_node(dll_node_t* node);

void destroy_dll_node(dll_node_t* node);
dll_node_t* node_from_str(const char* source);
void dll_display(dll_node_t* head);