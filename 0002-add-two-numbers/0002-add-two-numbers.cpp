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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* current = dummy_head;
        int carry = 0;

        while (l1 != nullptr || l2!=nullptr){
            int x = (l1 != nullptr) ? l1->val : 0; 
            int y = (l2 != nullptr) ? l2->val : 0; 
            int sum = carry + x + y; 
            carry = sum / 10;
            int last_digit = sum % 10;

            current->next = new ListNode(last_digit);
            current= current->next;

            if(l1!=nullptr)
                l1= l1->next;
            if(l2!=nullptr)
                l2= l2->next;
        }
        if (carry > 0) current->next = new ListNode(carry);
    
        return dummy_head->next;
    }
};