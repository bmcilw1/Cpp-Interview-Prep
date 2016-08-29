// Brian McIlwain
// Cracking the Coding Interview 2.7
// Intersection: Given two singly linked lists, determine if the two lists intersect. 
// Return the intersecting node. Note that intersection is based on reference, not value.
// NOTE: This problem is SUPER easy, but is good practice for both hash tables and
// linked lists.

#include<map>
#include<string>
#include<sstream>
#include<iostream>

using std::map;
using std::string;
using std::cout;
using std::ostringstream;

class Node
{
public:
    int data;
    Node * next;

    Node(int d)
    {
        data = d;
        next = 0;
    }
    Node()
    {
        next = 0;
    }
};

class MyLinkedList
{
private:
    void deleteNodes(Node * n)
    {
        if (n -> next)
        {
            deleteNodes(n -> next);
        }
        delete n;
    }

public:
    Node * root;

    MyLinkedList()
    {
        root = 0;
    }
    ~MyLinkedList()
    {
        if (root)
        {
            deleteNodes(root);
        }
        root = 0;
    }
    void Insert(Node * newNode)
    {
        if (root == 0)
        {
            root = newNode;
        }
        else
        {
            Node * n = root;

            while(n -> next)
            {
                n = n -> next;
            }

            n -> next = newNode;
        }
    }
};

Node * CheckIntersection(MyLinkedList ll, MyLinkedList ll2)
{
    Node * llTrack = ll.root;
    Node * ll2Track = ll2.root;
    map<string, bool> passedAddresses;
    ostringstream oss;

    while (llTrack)
    {
        // Clear stream
        oss.str("");

        // Store address
        oss << llTrack;
        passedAddresses[oss.str()] = true;
        llTrack = llTrack -> next;
    }
    while (ll2Track)
    {
        // Clear stream
        oss.str("");

        // Store address
        oss << llTrack;
        if(passedAddresses[oss.str()] != true)
        {
            return ll2Track;
        }
        ll2Track = ll2Track -> next;
    }

    return llTrack;
}

int main()
{
    Node * a = new Node(1);
    Node * b = new Node(2);
    Node * c = new Node(3);
    Node * d = new Node(4);
    Node * e = new Node(5);

    MyLinkedList ll;
    MyLinkedList ll2;

    ll.Insert(a);
    ll.Insert(b);
    ll.Insert(c);
    ll.Insert(d);

    //ll2.Insert(d);
    ll2.Insert(e);

    if (Node * n = CheckIntersection(ll, ll2))
    {
        cout << "Intersection found at node: " << n -> data;
    }
    else
    {
        cout << "Nope, no intersection between linked lists";
    }

    return 0;
}