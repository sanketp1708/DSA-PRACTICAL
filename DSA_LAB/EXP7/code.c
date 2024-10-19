#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node* createscll() {
    struct node *head = NULL, *temp, *newnode;
    int x;
    char ans;
    do {
        printf("Enter data to node: ");
        scanf("%d", &x);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            newnode->next = head;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }

        printf("Do you want to add more nodes? (y/n): ");
        scanf(" %c", &ans);
    } while (ans == 'y');

    return head;
}

void display(struct node *head) {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}


struct node* insertatbeginning(struct node *head) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    int x;

    printf("Enter data for node: ");
    scanf("%d", &x);
    newnode->data = x;

    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
    } else {
        while (temp->next != head) {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }

    return head;
}


struct node* insertinmiddle(struct node *head, int loc) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    int x, i = 1;

    printf("Enter data for node: ");
    scanf("%d", &x);
    newnode->data = x;

    if (loc == 1) {
        return insertatbeginning(head);
    }

    while (i < loc - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (temp->next == head && i < loc - 1) {
        printf("Location out of bounds\n");
        free(newnode);
        return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}


struct node* insertatend(struct node *head) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    int x;

    printf("Enter data for node: ");
    scanf("%d", &x);
    newnode->data = x;

    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
    } else {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }

    return head;
}

struct node* deletefirstnode(struct node *head) {
    struct node *temp = head, *dnode;

    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    while (temp->next != head) {
        temp = temp->next;
    }

    dnode = head;
    head = head->next;
    temp->next = head;
    free(dnode);

    return head;
}


struct node* deletemiddlenode(struct node *head, int loc) {
    struct node *temp = head, *dnode;
    int i = 1;

    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (loc == 1) {
        return deletefirstnode(head);
    }

    while (i < loc - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (temp->next == head || temp->next->next == head && i < loc - 1) {
        printf("Location out of bounds\n");
        return head;
    }

    dnode = temp->next;
    temp->next = dnode->next;
    free(dnode);
    return head;
}
struct node* deletelastnode(struct node *head) {
    struct node *temp = head, *dnode;
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;}
    while (temp->next->next != head) {
        temp = temp->next;
    }
    dnode = temp->next;
    temp->next = head;
    free(dnode);
    return head;
}

int main() {
    struct node *head = NULL;
    int choice, loc;

    while (1) {
        printf("\n1. Create circular linked list\n
            2. Display list\n3. Insert at beginning\n
            4. Insert in middle\n5. Insert at end\n
            6. Delete from beginning\n
            7. Delete from middle\n
            8. Delete from end\n
            9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = createscll();
                break;
            case 2:
                display(head);
                break;
            case 3:
                head = insertatbeginning(head);
                break;
            case 4:
                printf("Enter location to insert: ");
                scanf("%d", &loc);
                head = insertinmiddle(head, loc);
                break;
            case 5:
                head = insertatend(head);
                break;
            case 6:
                head = deletefirstnode(head);
                break;
            case 7:
                printf("Enter location to delete: ");
                scanf("%d", &loc);
                head = deletemiddlenode(head, loc);
                break;
            case 8:
                head = deletelastnode(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n"); }
    }
    return 0;}
