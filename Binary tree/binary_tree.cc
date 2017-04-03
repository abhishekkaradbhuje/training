#include <iostream>
#include <stdlib.h>
#include <malloc.h>

using namespace std;

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
}NODE;

NODE *root = NULL;

class binary_tree {

   public :
   NODE *insert(NODE *root, int data)
   {
       if(root==NULL)
       {
           root = (NODE *) malloc(sizeof(NODE));
           root->value = data;
           root->left = NULL;
           root->right = NULL;
       }
       else if(data < root->value){
           root->left = insert(root->left, data);
       }
       else {
           root->right = insert(root->right, data);
       }
       
       return root;
   }
   
   void inorder(NODE *root)
   {
       if(root!=NULL){
           inorder(root->left);
           cout<<root->value<<"\t";
           inorder(root->right);
       }
   }
 
   void preorder(NODE *root)
   {
       if(root!=NULL){
           cout<<root->value<<"\t";
           preorder(root->left);
           preorder(root->right);
       }
   }  

   void postorder(NODE *root)
   {
       if(root!=NULL){
           postorder(root->left);
           postorder(root->right);
           cout<<root->value<<"\t";
   
       }
   }
};

int main()
{
    int n,v,i;

    cout<<"Enter no. of element to insert\n";
    cin>>n;

    binary_tree bt;

    for(i=0;i<n;i++) {
        cout<<"Enter data to insert\n";
        cin>>v;
        root = bt.insert(root,v);
    }

    cout<<"Inorder Traversal : \n";
    bt.inorder(root);
    cout<<"\n";
    cout<<"Postorder Traversal : \n";
    bt.postorder(root);
    cout<<"\n";
    cout<<"Preorder Traversal : \n";
    bt.preorder(root);
    cout<<"\n";

    return 0;
} 
