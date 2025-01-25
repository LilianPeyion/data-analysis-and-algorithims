#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node in a linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* list1, Node* list2) {
    Node* dummy = createNode(0);  // Create a dummy node to simplify code
    Node* tail = dummy;  // Pointer to track the last node in the merged list

    // Merge the two lists
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Append the remaining elements of the non-exhausted list
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    Node* mergedList = dummy->next;  // The actual merged list starts after the dummy node
    free(dummy);  // Free the dummy node
    return mergedList;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Example: Creating two sorted linked lists

    // List 1: 1 -> 3 -> 5 -> NULL
    Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    // List 2: 2 -> 4 -> 6 -> NULL
    Node* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    // Merging the two sorted lists
    Node* mergedList = mergeSortedLists(list1, list2);

    // Printing the merged list
    printList(mergedList);

    return 0;
}
