#include<stdio.h>
#include <stdlib.h>


/*  Here we are going to see about the deletion in  linked list ......
    some linked list deletion are ...
    1. Deletion at the beginnning 
    2. Deletion at the given position 
    3. Deletion at the end ..... 
*/

struct node
{
    int data ;
    struct node * next ;
};


// we are going to traversal in the strucct ....

struct node * linked_list_traversal(struct node *ptr)
{
    printf("The element in the linked list are : ");
    while(ptr != NULL)
    {
        printf("%d --> ",ptr -> data );
        ptr = ptr ->  next ;
    }
    printf("NULL");
}

// Here we going to delete the first node in the linked list ... lets play with the code....

struct node * deletion_at_the_beg(struct node * head)
{
    struct node * ptr = head ;
    head  = head -> next ;
    free(ptr);
    return head ;
}

// Here we are going to delete the element in the given position ....in the linked list ......

struct node * deletion_at_the_index(struct node *head,int index)
{
    struct node *p = head;
    struct node *q = head -> next;
    for(int i=0;i<index-1;i++)
    {
        p = p -> next ;
        q = q -> next ;
    }
    p -> next = q -> next ;
    free(q);
    return head ;
}

// Here we are going to delete the element at the end of the linked list ......

struct node* deletion_at_the_end(struct node *head )
{
    struct node* p = head;
    struct node *q = head -> next;
    while(q -> next != NULL)
    {
        p = p -> next;
        q = q -> next;
    }
    p -> next = q -> next ;
    free(q);
    return head ;
    
}

// Here we are going to create a function of deleting the node of given value .....

struct node * deletion_at_the_given_value(struct node *head ,int value)
{
    struct node * p = head ;
    struct node * q = head -> next ;
    while(q -> data == value && q -> next != NULL)
    {
        p = p -> next ;
        q = q -> next ;
    }
    if(q -> data == value)
    {
        p -> next = q -> next ;
        free(q);
    }
    return head;
}


int main()
{
    struct node * head = (struct node *)malloc(sizeof(struct node ));
    struct node * second = (struct node *)malloc(sizeof(struct node ));
    struct node * third = (struct node *)malloc(sizeof(struct node ));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    struct node * fifth = (struct node *)malloc(sizeof(struct node ));

    head -> data = 123;
    head -> next = second;

    second -> data = 234;
    second -> next = third ;

    third -> data = 897;
    third -> next = fourth ;

    fourth -> data = 678;
    fourth -> next = fifth ;

    fifth -> data = 567;
    fifth -> next = NULL;

    // Here we are going to call the traversal function.....

    linked_list_traversal(head);
    // Here we are going to call the function to delete the node at the beg .....
    printf("\n");
    head = deletion_at_the_beg(head);
    linked_list_traversal(head);
    printf("\n");
    head = deletion_at_the_index(head,2);
    linked_list_traversal(head);
    printf("\n");
    head = deletion_at_the_end(head);
    linked_list_traversal(head);
    printf("\n");
    head = deletion_at_the_given_value(head,234);
    linked_list_traversal (head);
}