//Method 1. Because the node is less than 10^5
class Solution1 {
public:
    bool hasCycle(ListNode *head) {
         int count  = 0;
         while(count < 10001){
            if(head == nullptr){
                return false;
            }
            head = head->next;
            count ++;
         }
         return true;
    }
};
//Method 2
class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        ListNode* quick = head;
        ListNode* slow = head;
        //Pay attention to the detail: quick!=nullptr should be put before quick->next != nullptr
        while( quick != nullptr && quick->next != nullptr){
            quick = quick->next->next;
            slow = slow->next;
            if(quick == slow) return true;
        }
        return false;
    }
};