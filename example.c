/* A basic introduction into linked lists in C
yes i mostly wrote this to remind myself
Credit: https://github.com/CoffeePanda0 */



/* First we define a struct, this will be for each index of the list. Unlike a traditional array being contained
in one pointer, linked lists usually use one single struct, which points to the next in a different area of
memory and so on. The head always points to the first value of the linked list, and new indexes are added on the
left as opposed to a traditional array */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data; // Value we want to hold
    struct Node *next; // Pointer to the next object after this struct
};

struct Node *head = NULL; // Front of the list

/* Function to add a node to the front of a linked list */
void insert(int data) {
    struct Node *new_node = malloc(sizeof(struct Node)); // allocate memory
    
    new_node->data = data; // set data
    new_node->next = head; // set the next item to be the current item
    head = new_node; // Change the first item to be the ite we just added, as we added the object to the left

}

void delete() { // Deletes from the front of a linked list
    
    if (head == NULL) {
        printf("List is already empty\n");
    } else {
        struct Node *head_link = head; // Keep the memory address of the old deleted head so we can free it

        head = head->next;
        free(head_link);
    }
}

void print_list() { // Prints each item from the linked list
    struct Node *tmp = head;

    while (tmp != NULL) { // While we still have any objects left..
        printf("Current item is: %i\n", tmp->data);
        tmp = tmp->next; // Change the current item to the next one
    }

}

int main() {
    /* Create the first item, and allocate memory for it, then set its values */
    head = malloc(sizeof(struct Node)); 
    head->data = 5; // Set the data to whatever you want
    head->next = NULL; // Set next to NULL as this is currently the only object we have

    /* Now we can test. First we will add two more items, and this should print 4,3,5 as they are
    added in reverse order */

    insert(3);
    insert(4);
    print_list();

    delete();
    delete();
    print_list(); // We should now only print 5 as that was added first
 
    delete(); delete();
    print_list(); // Now we can see that the list is empty, and all elements have been removed

    return 0;
}
