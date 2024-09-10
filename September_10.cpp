/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
int findgcd(int x,int y){
    if(y>x)return findgcd(y,x);
    while(y){
        int d = x%y;
        x = y;
        y = d;
    }
    return x;
}
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode * temp1 = head;
        ListNode * temp2 = head->next;
        while(temp1 && temp2){
            int val = findgcd(temp1->val,temp2->val);
            ListNode * gcd = new ListNode(val);
            temp1->next = gcd;
            gcd->next = temp2;
            temp2 = temp2->next;
            temp1 = temp1->next->next;
        }
        return head;
    }
};