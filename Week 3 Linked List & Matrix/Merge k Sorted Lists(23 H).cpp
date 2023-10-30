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
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode(-10001, nullptr);
        ListNode* current = dummy;
        if(head1 == nullptr || head2 == nullptr) return head1==nullptr? head2:head1;
        while(head1 != nullptr && head2 != nullptr){
           if(head1->val >= head2->val){
               current->next = head2;
               head2 = head2->next;
               current = current->next;
           }
           else{
               current->next = head1;
               head1 = head1->next;
               current = current->next;
           }
        }
        if(head1 == nullptr){current->next = head2;}
        else{
            current->next = head1;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* ans = lists[0];
        for(int i = 1; i < lists.size(); i++){
            ans = merge(ans, lists[i]);
        }
        return ans;
    }
};