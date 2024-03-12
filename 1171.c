/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Gets the first node in a sublist that sums to zero, starting from the given node.
 *
 * Time complexity: O(n) in the worst case, where n is the number of nodes in the sublist
 *                   with zero sum. However, the average complexity depends on the distribution
 *                   of zero-sum sublists in the input linked list.
 * Space complexity: O(1) as it uses constant extra space.
 *
 * @param head The head node of the sublist to check.
 * @return The first node in the sublist that sums to zero, or NULL if no such sublist exists.
 */
struct ListNode* getSum(struct ListNode* head) {
    struct ListNode *node = head;
    int sum = 0;
    while (node) {
        sum += node->val;
        if (sum == 0) {
            return node; // Found a zero-sum sublist starting at "node"
        }
        node = node->next;
    }
    return NULL; // No zero-sum sublist found
}

/**
 * Removes all sublists from the linked list that sum to zero.
 *
 * Time complexity: O(n^2) in the worst case, where the entire linked list consists of
 *                   multiple consecutive zero-sum sublists. However, the average complexity
 *                   depends on the actual distribution of zero-sum sublists.
 * Space complexity: O(1) as it uses constant extra space.
 *
 * @param head The head node of the linked list.
 * @return The head node of the modified linked list without zero-sum sublists.
 */
struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    // Create a dummy head node to handle edge cases seamlessly
    struct ListNode *dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = head;

    struct ListNode *prev = dummyHead;
    struct ListNode *node = head;

    while (node) {
        int found = 0;  // Flag to indicate if a zero-sum sublist was removed

        // Find the first node of a zero-sum sublist (if any) starting from "node"
        struct ListNode *zeroSumStart = getSum(node);
        if (zeroSumStart) {
            found = 1;
            // Remove the entire zero-sum sublist
            prev->next = zeroSumStart->next;
            node = zeroSumStart->next; // Advance "node" to continue processing
        } else {
            // No zero-sum sublist found, move both "prev" and "node"
            prev = node;
            node = node->next;
        }
    }

    // Return the head of the modified linked list (excluding the dummy head)
    return dummyHead->next;
}

