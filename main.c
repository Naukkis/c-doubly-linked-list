#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    struct node *prev;
    struct node *next;
    char data[];
};

struct node *head;

void insert();

void display();

void search();

void delete();

int main() {
    int choice = 0;
    while (choice != 9) {
        printf("\n===============================================\n");
        printf("\n1.Insert \n2.List all \n3.Find \n4.Delete \n9.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                delete();
                break;
            case 9:
                exit(0);
            default:
                printf("Please enter valid choice");
        }
    }
}


void insert() {
    struct node *ptr;
    char dataToInsert[10];
    ptr = (struct node *) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter Item value\n");
        scanf("%s", &dataToInsert);
    }

    if (head == NULL) {
        ptr->next = NULL;
        ptr->prev = NULL;
        strcpy(ptr->data, dataToInsert);
        head = ptr;
    } else {
        strcpy(ptr->data, dataToInsert);
        ptr->prev = NULL;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
    printf("\nNode inserted\n");
}

void search() {
    struct node *ptr;
    int notFound = 1;
    char data[10];
    printf("\nEnter item which you want to search?\n");
    scanf("%s", &data);
    while (ptr != NULL) {
        notFound = strcmp(ptr->data, data);
        if (notFound == 0) {
            printf("\nitem found");
            return;
        }
        ptr = ptr->next;
    }
    printf("\nNot found!");
}

void display() {
    if (head == NULL) {
        printf("\nEMPTY");
    } else {

        struct node *ptr;
        printf("\n printing values...\n");
        ptr = head;

        while (ptr != NULL) {
            printf("%s\n", ptr->data);
            ptr = ptr->next;
        }
    }
}


void delete() {
    struct node *ptr, *temp, *temp2;
    char dataToDelete[10];

    printf("\n Enter item to be deleted: ");
    scanf("%s", &dataToDelete);
    ptr = head;
    while (strcmp(ptr->data, dataToDelete) != 0) {
        ptr = ptr->next;
        if (ptr == NULL) {
            return;
        }
    }

    temp = ptr;
    ptr = temp->prev;
    ptr->next = temp->next;
    temp2 = ptr;
    while (temp2->prev != NULL) {
        temp2 = temp2->prev;
    }
    head = temp2;
    free(temp);
    free(temp2);
    printf("\nnode deleted\n");
}
