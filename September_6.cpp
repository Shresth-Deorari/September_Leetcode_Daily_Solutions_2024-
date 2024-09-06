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
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(auto i : nums)st.insert(i);
        ListNode * temp = head;
        ListNode * next = head->next;
        ListNode * prev = NULL;
        ListNode * newhead = head;
        while(temp!=NULL){
            if(st.find(temp->val)!=st.end()){
                if(prev!=NULL){
                    prev->next = next;
                    temp = next;
                    if(temp!=NULL)next = temp->next;
                }
                else{
                    temp->next = NULL;
                    temp = next;
                    newhead = temp;
                    if(temp!=NULL)next = temp->next;
                }
            }
            else{
                prev = temp;
                temp = next;
                if(temp!=NULL)next = temp->next;
            }
        }
        return newhead;
    }
};