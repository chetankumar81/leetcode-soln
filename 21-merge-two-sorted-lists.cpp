#include <bits/stdc++.h>

using namespace std;

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    void moveNode(ListNode** destRef, ListNode** sourceRef){
        ListNode* newNode = *sourceRef;
        assert(newNode != nullptr);
        
        *sourceRef = newNode->next;
        
        newNode->next = *destRef;
        
        *destRef = newNode;
        
        
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        
        ListNode* tail = &dummy;
        
        while(1){
            if(l1 == nullptr){
                tail->next = l2;
                break;
            }
            if(l2 == nullptr){
                tail->next = l1;
                break;
            }
            
            if(l1->val <= l2->val){
                moveNode(&(tail->next),&l1);
            }else{
                moveNode(&(tail->next),&l2);
            }
            
            tail = tail->next;
        }
        
        return(dummy.next);
    }
};