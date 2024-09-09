class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Step 1: Count the number of nodes in the linked list
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        
        // Step 2: Calculate the base size of each part and the number of extra nodes
        int partSize = n / k;   // Base size of each part
        int extraNodes = n % k; // Number of parts that need one extra node

        // Step 3: Create the result vector
        vector<ListNode*> ans;
        temp = head;

        // Step 4: Split the list into k parts
        for (int i = 0; i < k; i++) {
            ListNode* partHead = temp; // This will be the head of the current part
            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0); // Extra node for the first 'extraNodes' parts
            extraNodes--; // Decrease count of extra nodes as we assign them

            // Traverse and cut the part
            ListNode* prev = nullptr;
            for (int j = 0; j < currentPartSize; j++) {
                prev = temp;
                temp = temp->next;
            }
            if (prev) prev->next = nullptr; // End the current part

            ans.push_back(partHead); // Add the current part to the result vector
        }

        return ans;
    }
};
