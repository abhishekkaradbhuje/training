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

class binary_search_tree {

   public :
   NODE *insert(NODE *root, int data)
   {
       if(root==NULL) {
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
   
   NODE *search(NODE *root, int data)
   {
       if(root==NULL) {
           cout<<"Data is not available\n";
           return NULL;   
       }
       else {
          if(data < root->value) {
              search(root->left, data);
          }
          else if(data > root->value) {
              search(root->right, data);
          }
          else {
              return root;
          }
       }
   }

   int find_min(NODE *root)
   {
       if(root->left!=NULL) {
          find_min(root->left);
       }
       else {
          return root->value;
       }
   }

   int find_max(NODE *root) {
       if(root->right!=NULL) {
          find_max(root->right);
       }
       else {
          return root->value;
       }
   }

};

int main()
{
    int n,v,i;
    int choice=1;
    while(choice!=0)
    {
        cout<<"Enter your choice for oeration :\n";
        cout<<"1-Insert\n2-Search\n3-Find MIN\n4-Find MAX\n0-Exit\n";
        cin>>choice;
        binary_search_tree bst;
        if(choice == 1) {
           cout<<"Enter no. of element to insert\n";
           cin>>n;
           for(i=0;i<n;i++) {
               cout<<"Enter data to insert\n";
               cin>>v;
               root = bst.insert(root,v);
           }
        }

        else if(choice == 2) {
           int data;
           NODE *location;
           cout<<"Enter data to search \n";
           cin>>data;
           location = bst.search(root,data);
           if(location != NULL)
               cout<<"Location of data is :"<<location<<"-->"<<data<<"\n";
        }

        else if(choice == 3) {
           int min;
           min = bst.find_min(root);
           cout<<min<<" is minimmun value \n";
        }
        else if(choice == 4) {
           int max;
           max = bst.find_max(root);
           cout<<max<<" is maximum value\n";
        }
	else {
           cout<<"Invalid input\n";
        }
    }
    return 0;
} 
