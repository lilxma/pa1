#include "chain.h"
#include "chain_given.cpp"
#include <cmath>
#include <iostream>

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain()
{
    clear();
    length_ = 0;
    height_ = 0;
    width_ = 0;
    delete head_;
    head_ = NULL;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block &ndata)
{
    Node *curr = head_;
    Node *newNode = new Node(ndata);
    while (curr->next != head_) {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->next = head_;
    length_ += 1;
    width_ = ndata.width();
    height = ndata.height();
}


/**
 * Swaps the two nodes at the indexes "node1" and "node2".
 * The indexes of the nodes are 1 based.
 * assumes i and j are valid (in {1,length_} inclusive)
 * 
 */
void Chain::swap(int i, int j)
{
    Node *node1 = head_;
    Node *node2 = head_;
    //BRO THERES A WALK FUNCTION
    //USE THAT INSTEAD OF THESE FOR LOOPS
    for (int n1=1; n1 < i - 1; n1++){
        node1 = node1->next;
    }
    for (int n2=1; n2 < i - 1; n2++){
        node2 = node2->next;
    }
    //swap 1
    Node *temp1 = node1;
    Node *temp2 = node2;
    node1->next = node2->next;
    node2->next = temp->next->next;
    //swap 2 (i'm confusing myself here)
    temp2->next = temp1->next;
    node1->next = node2->next->next;

}

/**
 * Reverses the chain
 */
void Chain::reverse()
{
    
}

/*
* Modifies the current chain by "rotating" every group of k nodes by one position.
* In every k-node sub-chain, remove the first node, and place it in the last 
* position of the sub-chain. If the last sub-chain has length less than k,
* then don't change it at all. 
* Some examples with the chain a b c d e:
*   k = 1: a b c d e
*   k = 2: b a d c e
*   k = 3: b c a d e
*   k = 4: b c d a e
*/
void Chain::rotate(int k)
{
/* your code here */
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear()
{
    Node *curr = head_;
    while (curr->next != head_) {
        curr = curr->next;
        delete curr;
        curr->next = NULL;
    }
    delete curr;
    curr->next = NULL;
}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */

 //finish!!
void Chain::copy(Chain const &other)
{
    Node *curr = head_;
    Node *copyCurr = other.head_->next;
    while (copyCurr != other.head){
        Node *n = new Node(copyCurr->data);
        cur->next = n;
    }
}
