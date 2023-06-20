#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *reverseList(LinkedListNode<int> *head){
        LinkedListNode<int> *pre = NULL;
        LinkedListNode<int> *next = NULL;
        while(head != NULL){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;

}
bool isPalindrome(LinkedListNode<int> *head) {
    if(head == NULL || head->next == NULL)
        return true;
        
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverseList(slow->next);
    slow = slow->next;

    while(slow != NULL){
        if(head->data != slow->data)
            return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}
    