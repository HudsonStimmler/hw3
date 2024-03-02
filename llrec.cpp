#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void helper(Node *&head, Node *&type);

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  //Tail recursion recurses to the end of the list then processes on the way up

  //Base Case: When we arrive at the end of head, set smaller and larger to null (before processing on way up) because they're garbage values
  if(head == nullptr){
    smaller = nullptr;
    larger = nullptr;
    //returns to the last call of llpivot
    return;
  }
  llpivot(head->next, smaller, larger, pivot);
  
  //Adds all values less than or equal to the pivot to the smaller linked list using the helper function
  if (head->val <= pivot) { 
    helper(head, smaller);
  } 
  //Adds all values greater than the pivot to the larger linked list using the helper function
  else { 
    helper(head, larger);
  }
}

void helper(Node *&head, Node *&type){
  //Make head->next the entire type list (larger or smaller), so when we make type=head we maintain ordering
  //Since we're using tail recursion, it will return type (larger or smaller) in reverse relative order unless we do this
  head->next = type; 
  //Insert item to type (larger or smaller)
  type = head;
  //Make current item we're on null, so head returns null at end
  head = nullptr;
}

//Remove helper function
Node* remove(Node*& node){
  //Create a temporary value for head->next
  Node* next = node->next;
  //Delete the head node 
  delete node;      
  //Make the head null       
  node = nullptr;
  //Return the temporary node to be used in recursive call          
  return next;             
}
