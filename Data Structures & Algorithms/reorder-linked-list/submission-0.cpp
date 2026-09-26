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
    void reorderList(ListNode* head) 
    {
        if (!head || !head->next) return;

        //First Find the mid point of the LinkedList
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *mid = nullptr;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        mid = slow->next;
        slow->next = nullptr;

        //reverse the secondhalf of the LInkedList
        ListNode *second = reverse(mid);
        ListNode *front = head;

        //Create the final list
        ListNode *first = head;
        while(second)
        {
            ListNode *firstTemp = first->next;
            ListNode *secondTemp = second->next;

            first->next = second;
            second->next = firstTemp;

            first = firstTemp;
            second = secondTemp;
        }
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;

        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
