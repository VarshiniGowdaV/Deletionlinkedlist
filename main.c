#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* DeleteFromTheBeginning(struct Node* head)
{
    if (head == NULL)
    {
        printf("List is already empty!\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Head node deleted successfully!\n");
    return head;
}
struct Node* DeleteFromTheEnd(struct Node* head)
{
    if (head == NULL)
    {
        printf("List is already empty!\n");
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        printf("Last node deleted successfully! The list is now empty.\n");
        return NULL;
    }
    struct Node* second_last = head;
    while (second_last->next->next != NULL)
    {
        second_last = second_last->next;
    }
    free(second_last->next);
    second_last->next = NULL;
    printf("Last node deleted successfully!\n");
    return head;
}
struct Node* DeleteFromTheSpecificPosition(struct Node* head, int position)
{
    if (head == NULL)
    {
        printf("The list is empty!\n");
        return NULL;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (position == 1)
    {
        head = temp->next;
        free(temp);
        printf("Node at position %d deleted successfully!\n", position);
        return head;
    }
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position %d is out of bounds!\n", position);
        return head;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node at position %d deleted successfully!\n", position);
    return head;
}

struct Node* DeleteASpecificNodeByValue(struct Node* head, int value) {
    if (head == NULL)
    {
        printf("The list is empty!\n");
        return NULL;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (head->data == value)
    {
        head = head->next;
        free(temp);
        printf("Node with value %d deleted successfully!\n", value);
        return head;
    }
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Value %d not found in the list!\n", value);
        return head;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted successfully!\n", value);
    return head;
}
void printList(struct Node* head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
struct Node* createNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
struct Node* createList(int n)
{
    if (n <= 0)
    {
        printf("List size must be positive!\n");
        return NULL;
    }
    int data;
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    struct Node* head = createNode(data);
    struct Node* current = head;
    for (int i = 2; i <= n; i++)
    {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        current->next = createNode(data);
        current = current->next;
    }
    return head;
}

int main()
{
    int n, choice, position, value;

    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
    struct Node* head = createList(n);
    printf("Original list: ");
    printList(head);

    do {
        printf("\nOptions:\n");
        printf("1. Delete from the beginning\n");
        printf("2. Delete from the end\n");
        printf("3. Delete from a specific position\n");
        printf("4. Delete a specific node by value\n");
        printf("5. Print the linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = DeleteFromTheBeginning(head);
            break;
        case 2:
            head = DeleteFromTheEnd(head);
            break;
        case 3:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            head = DeleteFromTheSpecificPosition(head, position);
            break;
        case 4:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            head = DeleteASpecificNodeByValue(head, value);
            break;
        case 5:
            printf("Current list: ");
            printList(head);
            break;
        case 6:
            printf("Exiting program!\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    while (choice != 6);
    struct Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
