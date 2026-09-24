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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {   
        //// 1. Create a dummy node to anchor the start of the new list
        ListNode dummy(0);
        ListNode *mergeList = &dummy;

        // 2. Loop while both lists have nodes
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                mergeList->next = list1;
                list1 = list1->next;
            }
            else
            {
                mergeList->next = list2;
                list2 = list2->next;
            }
            mergeList = mergeList->next; //Safely move forward
        }
        // 3. Attach the remaining nodes (if any)
        if(list1)
        {
            mergeList->next = list1;
        }
        else
        {
            mergeList->next = list2;
        }
        return dummy.next;
    }
};
