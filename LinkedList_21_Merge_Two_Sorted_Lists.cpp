#include <cstddef>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 &&!list2)return NULL;

        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        while(list1 && list2){
            if(list1->val > list2->val){
                dummy->next = new ListNode(list2->val);
                list2 = list2->next;
            }else{
                dummy->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            dummy = dummy->next;
        }

        while(list1){
            dummy->next = new ListNode(list1->val);
            list1 = list1->next;
            dummy = dummy->next;
        }

        while(list2){
            dummy->next = new ListNode(list2->val);
            list2 = list2->next;
            dummy = dummy->next;
        }

        return head->next;
    }
};