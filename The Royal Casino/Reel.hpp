#ifndef Reel_hpp
#define Reel_hpp

class Reel
{
private:
    class Node
    {
    public:
        char data;
        Node *next;
        Node *prev;
        Node(char t)
        {
            data = t;
            next = this; // Circular list assign next of new node to self
            prev = this; // Circular list assign prev of new node to self
        }
    };

public:
    Node *head;          // Circular list head
    Reel();              // Reel Constructor
    ~Reel();             // Reel Destructor
    void insert(char c); // Insert a new node at position of head in the list with given data
};

#endif /* Reel_hpp */
