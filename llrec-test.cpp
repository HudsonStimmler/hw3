#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------





int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code
    Node* smaller;
    Node* larger;
    llpivot(head, smaller, larger, 10);
    cout << "Using 10 as a pivot, head should be an empty list, smaller should contain 8 9 6 8, larger should contain 12 19" << endl;
    cout << "head list: ";
    print(head);
    cout << "smaller list: ";
    print(smaller);
    cout << "larger list: ";
    print(larger);
    dealloc(head);
    dealloc(smaller);
    dealloc(larger);

    Node* headw = readList(argv[1]);
    cout << "Original list part 2: ";
    print(headw);

    struct func {
        // returns true for even numbers
        bool operator() (int i){
            if (i % 2 == 0){
                return false;
            } 
            else{
                return true;
            }
        }
    };
    func x;
    headw = llfilter(headw, x);
    cout << "Should be only even numbers" << endl;
    print(headw);




    
    return 0;

}
