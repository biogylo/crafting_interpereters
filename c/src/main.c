
#include "dll.h"
#include <stdio.h>
#include <string.h>


#define ASSERT_M(boolexpr, message) ({\
    if (!(boolexpr)) {\
        printf("FAILED - The assertion (" #boolexpr ") doesn't hold! %s\n", message); \
        return -1; \
    } \
    printf("PASSED - The assertion (" #boolexpr ") does hold!\n");})

#define ASSERT(boolexpr) ASSERT_M(boolexpr, "")

#define ASSERT_STREQ(string1, string2) ASSERT(strcmp(string1, string2) == 0);
#define ASSERT_STREQ_M(string1, string2, message) ASSERT_M(strcmp(string1, string2) == 0, message);

size_t test_dll(){

    const static char* a = "first";
    const static char* b = "second";
    const static char* c = "third";
    const static char* d = "fourth";

    dll_node_t* head = create_dll();
    ASSERT(dll_length(head) == 0);
    dll_display(head);

    insert_first_dll(head, a);
    ASSERT(dll_length(head) == 1);
    dll_display(head);

    insert_first_dll(head, b);
    ASSERT(dll_length(head) == 2);
    dll_display(head);

    dll_node_t* found = find_in_dll(head, b);
    ASSERT_STREQ(found->contents, b);


    
    insert_last_dll(head, c);

    ASSERT_STREQ(get_from_dll(head, 0)->contents, b);
    ASSERT_STREQ(get_from_dll(head, 1)->contents, a);
    ASSERT_STREQ(get_from_dll(head, 2)->contents, c);
    ASSERT(dll_length(head) == 3);
    dll_display(head);


    insert_first_dll(head, d);


    ASSERT_STREQ(get_from_dll(head, 0)->contents, d);
    ASSERT_STREQ(get_from_dll(head, 1)->contents, b);
    ASSERT_STREQ(get_from_dll(head, 2)->contents, a);
    ASSERT_STREQ(get_from_dll(head, 3)->contents, c);
    ASSERT(dll_length(head) == 4);
    dll_display(head);
    printf("Popping first!\n");

    dll_node_t* first = pop_first_from_dll(head);
    dll_display(head);
    ASSERT_STREQ(first->contents, d);
    destroy_dll_node(first);
    destroy_dll(head);
    
    return 0;
}
int main() {
    return test_dll();
}