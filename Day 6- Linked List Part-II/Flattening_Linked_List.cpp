
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* mergeLists(Node* root1, Node* root2){
    
    Node* dummy=new Node(0);
    Node* temp= dummy;
    
    while(root1 && root2){
        if(root1->data<=root2->data){
            temp->bottom=root1;
            temp=temp->bottom;
            root1=root1->bottom;
        }
        else{
            temp->bottom=root2;
            temp=temp->bottom;
            root2=root2->bottom;
        }
    }
    
    if(root1){
        temp->bottom=root1;
    }
    else{
        temp->bottom=root2;
    }
    
    return dummy->bottom;
}
    
Node *flatten(Node *root)
{
   
   if(root==NULL){
       return root;
   }
   
   root->next= flatten(root->next);
   
   root= mergeLists(root, root->next);
   
   return root;
   
}
