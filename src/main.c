#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "linkedlist.h"

void demo_singly_linked_list(void) {
    printf("\n# Singly Linked List:\n");
    Singly_Linked_List_Node* linked_list_head = singly_linked_list_new(1);

    singly_linked_list_append(linked_list_head, 2);
    singly_linked_list_append(linked_list_head, 3);
    singly_linked_list_append(linked_list_head, 4);

    printf("After appends:");
    singly_linked_list_print(linked_list_head);
    printf(" (%llu nodes)\n", singly_linked_list_len(linked_list_head));

    singly_linked_list_insert(linked_list_head, 0, 5);
    singly_linked_list_insert(linked_list_head, 5, 6);
    singly_linked_list_insert(linked_list_head, 7, 7);

    printf("After inserts:");
    singly_linked_list_print(linked_list_head);
    printf(" (%llu nodes)\n", singly_linked_list_len(linked_list_head));

    size_t found_idx;
    bool found = singly_linked_list_lookup(linked_list_head, 4, &found_idx);
    if (found) {
        printf("Lookup value `4` found at idx: %llu\n", found_idx);

        int removed_val;
        bool removed = singly_linked_list_remove(linked_list_head, found_idx, &removed_val);
        if(removed) {
            printf("removed at %llu = %d\n", found_idx, removed_val);
        }

        removed = singly_linked_list_remove(linked_list_head, 0, &removed_val);
        if(removed) {
            printf("removed at 0 = %d\n", removed_val);
        }
        singly_linked_list_remove(linked_list_head, 7, &removed_val);

        printf("After removed:");
        singly_linked_list_print(linked_list_head);
        printf(" (%llu nodes)\n", singly_linked_list_len(linked_list_head));
    }

    printf("\n");

    singly_linked_list_free(linked_list_head);
}

void demo_doubly_linked_list(void) {
    Doubly_Linked_List_Node* doubly_linked_list = doubly_linked_list_new(1);

    printf("\n# Doubly Linked List:\n");

    printf("Head: %d", doubly_linked_list->val);

    printf("\n");

    free(doubly_linked_list);
}

int main(void) {
    demo_singly_linked_list();
    demo_doubly_linked_list();
    return 0;
}