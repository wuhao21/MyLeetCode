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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *res = NULL;
        ListNode *curr, *lst = NULL;
        while (l1 && l2){
            if (l1->val <= l2->val) {
                curr = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                curr = new ListNode(l2->val);
                l2 = l2->next;
            }
            if (lst != NULL) lst->next = curr;
            else res = curr;
            lst = curr;
        }
        while (l1) {
            curr = new ListNode(l1->val);
            l1 = l1->next;
            lst->next = curr;
            lst = curr;
        }
        while (l2) {
            curr = new ListNode(l2->val);
            l2 = l2->next;
            lst->next = curr;
            lst = curr;
        }
        return res;
    }
};
