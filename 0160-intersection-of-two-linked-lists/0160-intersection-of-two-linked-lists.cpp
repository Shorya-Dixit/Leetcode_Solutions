/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptA=headA;
        ListNode* ptB=headB;
        while(ptA!=ptB){
            if(ptA==NULL) ptA=headB;
            else ptA=ptA->next;
            if(ptB==NULL) ptB=headA;
            else ptB=ptB->next;
        }
        return ptA;
    }
};