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
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        vector<int> nums;
        
        while(curr != NULL){
            nums.push_back(curr->val);
            len++;
            curr = curr->next;
        }
        
        for(int i = 0; i < len / 2; i++){
            head = head->next;
        }
        return head;
    }
};
