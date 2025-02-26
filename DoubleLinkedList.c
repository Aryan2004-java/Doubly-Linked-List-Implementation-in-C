#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

struct node *start = NULL;

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);

int main() {
    int ch;
    do {
        printf("\n\n **MAIN MENU **");
        printf("\n 1:  Create a list");
        printf("\n 2:  Display the list");
        printf("\n 3:  Add a node at the beginning");
        printf("\n 4:  Add a node at the end");
        printf("\n 5:  Add a node before a given node");
        printf("\n 6:  Add a node after a given node");
        printf("\n 7:  Delete a node from the beginning");
        printf("\n 8:  Delete a node from the end");
        printf("\n 9:  Delete a node after a given node");
        printf("\n 10: Exit");
        printf("\n\n Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
        case 1:
            start = create_ll(start);
            printf("\n LINKED LIST CREATED");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;
        case 5:
            start = insert_before(start);
            break;
        case 6:
            start = insert_after(start);
            break;
        case 7:
            start = delete_beg(start);
            break;
        case 8:
            start = delete_end(start);
            break;
        case 9:
            start = delete_after(start);
            break;
        case 10:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice; Enter a choice from 1-10\n");
            break;
        }
    } while (ch != 10);

    return 0;
}

struct node *create_ll(struct node *start) {
    struct node *newnode, *ptr;
    int num;
    printf("Enter -1 to end\n");
    printf("Enter the data:\n");
    scanf("%d", &num);
    while (num != -1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = NULL;
        if (start == NULL) {
            newnode->prev = NULL;
            start = newnode;
        } else {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newnode;
            newnode->prev = ptr;
        }
        printf("Enter the data:\n");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start) {
    struct node *ptr;
    if (start == NULL) {
        printf("\nList is empty\n");
        return start;
    }
    ptr = start;
    printf("\nThe list is: ");
    while (ptr != NULL) {
        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return start;
}

struct node *insert_beg(struct node *start) {
    struct node *newnode;
    int num;
    printf("Enter the data:\n");
    scanf("%d", &num);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->prev = NULL;
    newnode->next = start;

    if (start != NULL) {
        start->prev = newnode;
    }

    start = newnode;
    return start;
}

struct node *insert_end(struct node *start) {
    struct node *newnode, *ptr;
    int num;
    printf("Enter the data:\n");
    scanf("%d", &num);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;

    if (start == NULL) {
        newnode->prev = NULL;
        start = newnode;
    } else {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newnode;
        newnode->prev = ptr;
    }

    return start;
}

struct node *insert_after(struct node *start) {
    struct node *newnode, *ptr;
    int num, val;
    printf("Enter the data:\n");
    scanf("%d", &num);
    printf("Enter the value after which the node is to be inserted:\n");
    scanf("%d", &val);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    ptr = start;
    while (ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if (ptr == NULL) {
        printf("Node with value %d not found.\n", val);
        free(newnode);
        return start;
    }

    newnode->next = ptr->next;
    newnode->prev = ptr;
    if (ptr->next != NULL) {
        ptr->next->prev = newnode;
    }
    ptr->next = newnode;
    
    return start;
}

struct node *insert_before(struct node *start) {
    struct node *newnode, *ptr;
    int num, val;
    printf("Enter the data:\n");
    scanf("%d", &num);
    printf("Enter the value before which the node is to be inserted:\n");
    scanf("%d", &val);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;

    if (start == NULL) {
        printf("List is empty.\n");
        free(newnode);
        return start;
    }

    if (start->data == val) {
        return insert_beg(start);
    }

    ptr = start;
    while (ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if (ptr == NULL) {
        printf("Node with value %d not found.\n", val);
        free(newnode);
        return start;
    }

    newnode->next = ptr;
    newnode->prev = ptr->prev;
    ptr->prev->next = newnode;
    ptr->prev = newnode;

    return start;
}

struct node *delete_beg(struct node *start) {
    struct node *ptr;
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }

    ptr = start;
    start = start->next;
    if (start != NULL) {
        start->prev = NULL;
    }
    free(ptr);
    
    return start;
}

struct node *delete_end(struct node *start) {
    struct node *ptr;
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }

    ptr = start;
    if (start->next == NULL) {
        free(start);
        start = NULL;
        return start;
    }

    while (ptr->next != NULL)
        ptr = ptr->next;
    
    ptr->prev->next = NULL;
    free(ptr);

    return start;
}

struct node *delete_after(struct node *start) {
    struct node *ptr, *temp;
    int val;
    printf("Enter the value after which the node is to be deleted:\n");
    scanf("%d", &val);
    ptr = start;
    while (ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if (ptr == NULL) {
        printf("Node with value %d not found.\n", val);
        return start;
    }

    if (ptr->next == NULL) {
        printf("No node exists after the given node.\n");
        return start;
    }

    temp = ptr->next;
    ptr->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = ptr;
    }
    free(temp);
    
    return start;
}

struct node *delete_node(struct node *start) {
    struct node *ptr;
    int val;
    printf("Enter the value of the node to be deleted:\n");
    scanf("%d", &val);
    ptr = start;
    
    if (ptr == NULL) {
        printf("List is empty.\n");
        return start;
    }

    if (ptr->data == val) {
        start = delete_beg(start);
        return start;
    }

    while (ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if (ptr == NULL) {
        printf("Node with value %d not found.\n", val);
        return start;
    }

    ptr->prev->next = ptr->next;
    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }
    free(ptr);

    return start;
}
