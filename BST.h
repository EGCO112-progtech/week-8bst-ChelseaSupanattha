// An integer binary search tree

struct TreeNode {                                           
    struct TreeNode *leftPtr; // pointer to left subtree
   int data; // node value                               
    struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes

void insertNode( BST *, int );
/*
void insertNode_R(TreeNodePtr * t,int value){
  if(t==NULL){
   t=new TreeNode;
	 if(t){
		t->leftPtr=NULL;
		t->rightPtr=NULL;
		t->data=value;
   }
  }
  else{
     if(t->data>=value) //left
        
     else //right
      
   }
}
*/
void insertNode( BST *b, int value ){
	 TreeNodePtr t =b->root,new_node;
	 int inserted=0;
	new_node =(TreeNodePtr) malloc(sizeof(struct TreeNode));
	if(new_node){
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
		/*First Node*/
		if(!b->root)	b->root=new_node;
		else {
while(!inserted){
   if(t->data >=value){
      if(t->leftPtr == NULL)
      {
         /* move/insert to the left*/
         t->leftPtr=new_node;        
         inserted=1;
      }
      else
      {
         t=t->leftPtr;
      }
     }
   else{
      if(t->rightPtr == NULL)
      {
         /* move/ insert to the right*/
         t->rightPtr=new_node;
         inserted=1;         
      }
      else
      {
         t=t->rightPtr;
      }
    }
   
  }//end while		
  }//end else;
  b->size++;
  }
  
}//end function


void preOrder( TreeNodePtr treePtr )
{
   if ( treePtr != NULL ) {        
      printf("%3d",treePtr->data) ;  //print the value 
        
      preOrder( treePtr->leftPtr ); //Recursion to the left
   
      preOrder( treePtr->rightPtr ); //Recursion to the right

   }
}

void postOrder ( TreeNodePtr treePtr )
{
   if ( treePtr != NULL ) {       
      postOrder( treePtr->leftPtr ); //Recursion to the left

      postOrder( treePtr->rightPtr ); //Recursion to the right

      printf("%3d",treePtr->data) ;  //print the value 
   
   }
}


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      inOrder( treePtr->leftPtr ); //Recursion to the left
 
      printf("%3d",treePtr->data) ;  //print the value 
   
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

void printTree ( TreeNodePtr treePtr , int level)
{
   if ( treePtr != NULL ) {    
      printTree(treePtr->rightPtr, level+1);

      for(int i=0; i<level; i++)
      {
         printf("   ");
      }

      printf("%3d\n",treePtr->data) ;  //print the value 

      printTree( treePtr->leftPtr, level+1); //Recursion to the left
   }
}