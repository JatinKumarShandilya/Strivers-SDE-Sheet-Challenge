#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // iterative
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val > list2->val) std::swap(list1,list2);
        ListNode* res = list1;
        while(list1 != NULL && list2 != NULL){
            ListNode* temp = NULL;
            while(list1 != NULL && list1->val <= list2->val){
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            std::swap(list1,list2);
        }
        return res;
    }
};




// or


#include <bits/stdc++.h>  
using namespace std;

template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

Node<int>* solve(Node<int>* first, Node<int>* second){
    Node<int>* curr1 = first;
    Node<int>* next1 = first->next;
    Node<int>* curr2 = second;
    Node<int>* next2 = curr2->next;
    if(first->next == NULL){
        first->next = second;
        }
    while(next1 != NULL && curr2 != NULL){
        if(curr1->data <= curr2->data && next1->data >= curr2->data){
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }
    if(first->data <=  second->data){
        return solve(first,second);
    }
    else{
        return solve(second,first);
    }
}  