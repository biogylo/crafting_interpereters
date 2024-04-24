#include <stdint.h>
#include <stddef.h>

typedef struct __dll_node {
    struct __dll_node* next;
    struct __dll_node* prev;
    char * contents;
} dll_node_t;

typedef struct _dll_head{
    dll_node_t* first;
} dll_head_t;


dll_head_t* create_dll();
void destroy_dll(dll_head_t* head);


size_t dll_length(dll_head_t* head);
void insert_first_dll(dll_head_t* head, const char* source);
void insert_last_dll(dll_head_t* head, const char* source);
dll_node_t* get_last_dll(dll_head_t* head);
dll_node_t* get_from_dll(dll_head_t* head, size_t index);
dll_node_t* find_in_dll(dll_head_t* head, const char* target);



void destroy_dll_node(dll_node_t* node);
dll_node_t* node_from_str(const char* source);