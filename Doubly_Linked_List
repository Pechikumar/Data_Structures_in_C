#include <stdio.h>     // For printf, scanf
#include <stdlib.h>    // For malloc, free

// Define the structure for a doubly linked list node
struct Node {
    int data;                // To store integer data
    struct Node* prev;       // Pointer to the previous node
    struct Node* next;       // Pointer to the next node
};

// Function to create and append a new node at the end of the list
void addNode(struct Node** headRef, int value) {
    // Dynamically allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation failed
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Assign data and initialize pointers
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    // If the list is empty, new node becomes the head
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        // Otherwise, traverse to the last node
        struct Node* temp = *headRef;
        while (temp->next != NULL) {    // Move till last node
            temp = temp->next;
        }
        temp->next = newNode;           // Link new node after last node
        newNode->prev = temp;           // Link back to previous node
    }
}

// Function to print the list in forward direction
void printForward(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print the list in reverse direction
void printBackward(struct Node* head) {
    if (head == NULL) return;

    // Move to the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Print backwards
    printf("Doubly Linked List (backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;           // Initially empty list
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Loop to add n nodes
    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        addNode(&head, value);
    }

    // Print the list in forward and backward directions
    printForward(head);
    printBackward(head);

    return 0;
}



// Function to insert a node at the beginning
void insertAtBeginning(struct Node** headRef, int value) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Initialize new node
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = *headRef;

    // If list is not empty, update old head's prev
    if (*headRef != NULL) {
        (*headRef)->prev = newNode;
    }

    // Update head
    *headRef = newNode;
}



// Function to insert a node at the end
void insertAtEnd(struct Node** headRef, int value) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Initialize new node
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If the list is empty, new node becomes head
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    // Traverse to the last node
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the new node
    temp->next = newNode;
    newNode->prev = temp;
}



// Function to insert at any position (1-based index)
// If position > size+1 -> say "Invalid position" and do nothing
void insertAtPosition(struct Node** headRef, int value, int pos) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    // Case 1: Insert at beginning
    if (pos == 1) {
        newNode->next = *headRef;
        if (*headRef != NULL) {
            (*headRef)->prev = newNode;
        }
        *headRef = newNode;
        return;
    }

    // Traverse to position - 1 using for loop
    struct Node* temp = *headRef;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    // If temp is NULL -> position is invalid
    if (temp == NULL) {
        printf("Invalid position: %d (list too short)\n", pos);
        free(newNode); // Avoid memory leak
        return;
    }

    // If temp->next is NULL and pos is exactly after last node -> valid end insertion //insertion at the end
    if (temp->next == NULL && pos > 1) {
        temp->next = newNode;
        newNode->prev = temp;
        return;
    }

    // Insert in middle
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Function to delete node at the beginning
void deleteAtBeginning(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = *headRef;   // Store current head
    *headRef = (*headRef)->next;    // Move head to the next node

    if (*headRef != NULL) {
        (*headRef)->prev = NULL;    // Update new head's prev pointer
    
    free(temp);  // Free old head
}


// Function to delete node at the end
void deleteAtEnd(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = *headRef;

    // Case 1: Only one node in the list
    if (temp->next == NULL) {
        printf("Deleted node with data: %d\n", temp->data);
        free(temp);
        *headRef = NULL;
        return;
    }

    // Case 2: Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // temp now points to last node
    printf("Deleted node with data: %d\n", temp->data);
    temp->prev->next = NULL;  // Disconnect last node
    free(temp);
}

// Function to delete a node at a given position (using for loop)
void deleteAtPosition(struct Node** headRef, int position) {
    if (*headRef == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = *headRef;

    // Move to the desired node using for loop
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL) {
        printf("Invalid position! Cannot delete.\n");
        return;
    }

    // If deleting the head node
    if (temp->prev == NULL) {  // position 1
        *headRef = temp->next;
        if (*headRef != NULL)
            (*headRef)->prev = NULL;
    }
    // If deleting the last node
    else if (temp->next == NULL) {
        temp->prev->next = NULL;
    }
    // If deleting a middle node
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    printf("Deleted node with data: %d at position %d\n", temp->data, position);
    free(temp);
}
