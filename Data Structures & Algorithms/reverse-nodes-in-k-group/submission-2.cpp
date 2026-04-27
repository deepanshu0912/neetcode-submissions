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

    ListNode* reverseList(ListNode* head, ListNode* nxt) {
        ListNode* prev = nxt;
        ListNode* curr = head;

        while (curr != nxt) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        vector<ListNode*> a;
        ListNode* temp = head;
        int count = 0;

        // store next node after every complete k-group
        while (temp) {
            count++;
            if (count == k) {
                a.push_back(temp->next);
                count = 0;
            }
            temp = temp->next;
        }

        temp = head;
        ListNode* prevTail = nullptr;

        for (int i = 0; i < a.size(); i++) {
            ListNode* groupStart = temp;
            ListNode* nextGroup = a[i];

            // reverse current group
            ListNode* newHead = reverseList(groupStart, nextGroup);

            if (i == 0) {
                head = newHead;
            } else {
                prevTail->next = newHead;
            }

            // old groupStart becomes tail after reverse
            prevTail = groupStart;
            temp = nextGroup;
        }

        return head;
    }
};