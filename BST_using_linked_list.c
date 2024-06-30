
#include <stdio.h>
#include <stdlib.h>

// here we are going to see about the trversal in binary search tree ....

// Here we have created the node of the tree which contain one data and two pointer which is based upon doubly linked list ...
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};

// here  we ar creating the node for taking the input values ....in which we are assigning the node .....

struct node *createnewnode(int data)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> left = NULL;
    ptr -> right = NULL;  
    return ptr;
}

// In binary search tree there are three way to traversal the BST ... Here we will discussed one by one .....
// 1 -> preorder
// 2 -> postfix
// 3 -> Inorder

// Here we have created the function for the preorder traversal

void preorder(struct node * root)
{
    if(root != NULL)
    {
        printf("%d -> ",root -> data);
        preorder(root -> left);
        preorder(root ->right);
    }
}

// Here we have created the function for the postfix traversal ..

void postfix(struct node* root)
{
    if(root != NULL)
    {
        postfix(root -> left);
        postfix(root -> right);
        printf("%d -> ",root -> data);
    }
}

// Here we have created the function for the inorder traversal.....

void inorder(struct node *root)
{
    if(root !=NULL)
    {
        inorder(root -> left);
        printf("%d -> ",root -> data);
        inorder(root -> right);
    }
}
// End of the traversal...........

// Two ways of inserting the element in the BST

// first way....
void insertion(struct node *root ,int val)
{
    struct node * prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if(val == root -> data)
        {
            return;
        }
        else if(val < root -> data)
        {
            root = root -> left;
        }
        else 
        {
            root = root -> right;
        }
    }
    struct node *new = createnewnode(val);
    if(val  < prev -> data)
    {
        prev -> left = new;
    }
    else 
    {
        prev -> right = new;
    }
}

// second way...........
struct node* insert(struct node *root,int val)
{
    if(root == NULL)
    {
        return createnewnode(val);
    }
    if(root -> data == val)
    {
        return root;
    }
    else if(val < root -> data)
    {
        root -> left = insert(root -> left,val);
    }
    else if(val > root -> data )
    {
        root -> right = insert(root -> right,val);
    }
    return root ;
}

// Here we are going to study about the deletion in binary search tree ... 
// Let's start ....

// for deleting a node first we need min value from right side from the tree .....

// lets create a function for the min value ...

struct node *minValue(struct node *root){
    struct node *currroot = root;
    while(currroot && currroot -> left !=NULL){
        currroot = currroot -> left;
    }
    return currroot;
}

struct node *deletion(struct node *root,int value)
{
    if(root == NULL){
        return NULL;
    }
    if(root -> data > value){
        root -> left  = deletion(root -> left , value);
    }
    else if(root -> data < value){
        root -> right  = deletion(root -> right , value);
    }
    else {
        if(root -> right == NULL  && root -> left  ==  NULL){
            return NULL;
        }
        else if(root -> left  == NULL){
            struct node *temp = root -> right ;
            free(root);
            return temp;
        }
        else if(root -> right == NULL){
            struct node *ptr = root -> left;
            free(root);
            return ptr;
        }
    }
    struct node *temp = minValue(root -> right);
    root -> data = temp -> data;
    root -> right = deletion(root -> right ,temp -> data);
    
}
int main()
{

    // here we calling the createnewnode function for taking the values ....

    struct node *p = createnewnode(5);
    struct node *p1 = createnewnode(3);
    struct node *p2 = createnewnode(6);
    struct node *p3 = createnewnode(1);
    struct node *p4 = createnewnode(4);

    p -> left = p1;
    p -> right = p2;
    p1 -> left = p3;
    p1 -> right = p4;

    // Here we are calling all the function one by one ......

    printf("The value of the preorder BST is : ");
    preorder(p);
    printf("NULL");
    printf("\n");
    printf("The value of the postfix BST is : ");
    postfix(p);
    printf("NULL");
    printf("\n");
    printf("The value of the inorder BST is : ");
    inorder(p);
    printf("NULL");
    printf("\n");

    insert(p,7);
    printf("the insert value is : %d\n",p->right->right->data);
    
    p1 = deletion(p1,3);
    printf("after the deletion of the root nde then the preorder traversal is : ");
    preorder(p);
    printf("NULL");
    return 0;

}