#include "Reel.hpp"

Reel::Reel()
{
    head = nullptr;
}

Reel::~Reel()
{
    // Create a temp node
    Node *temp = head;
    while (temp != nullptr)
    {
        head = head->next;  // Move head to next node
        delete temp;        // Delete current node
        temp = head;
    }
}

void Reel::insert(char c)
{
    if (head == nullptr)
    {
        // Insert new node as head
        head = new Node(c);
    }
    else
    {
        // Create a new node
        Node *temp = new Node(c);
        // Assign links of nodes to circular list
        temp->next = head;
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev = temp;
        // Reassign head
        head = temp;
    }
}