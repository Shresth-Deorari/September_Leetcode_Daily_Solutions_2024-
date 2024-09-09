class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Step 1: Initialize the matrix with -1
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        // Step 2: Initialize boundaries for the spiral traversal
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        
        // Pointer to traverse the linked list
        ListNode* current = head;
        
        // Step 3: Traverse the matrix in spiral order
        while (top <= bottom && left <= right) {
            // Traverse from left to right along the top row
            for (int j = left; j <= right && current; j++) {
                matrix[top][j] = current->val;
                current = current->next;
            }
            top++; // Move the top boundary down
            
            // Traverse from top to bottom along the right column
            for (int i = top; i <= bottom && current; i++) {
                matrix[i][right] = current->val;
                current = current->next;
            }
            right--; // Move the right boundary left
            
            // Traverse from right to left along the bottom row
            for (int j = right; j >= left && current; j--) {
                matrix[bottom][j] = current->val;
                current = current->next;
            }
            bottom--; // Move the bottom boundary up
            
            // Traverse from bottom to top along the left column
            for (int i = bottom; i >= top && current; i--) {
                matrix[i][left] = current->val;
                current = current->next;
            }
            left++; // Move the left boundary right
        }
        
        return matrix;
    }
};