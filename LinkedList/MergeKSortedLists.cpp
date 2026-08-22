
//Problem:Merge K Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if(lists.size()==0)
          return NULL;
        int n=lists.size();
        ListNode* merge=lists[0];
       for(int i=1;i<n;i++){
         ListNode* dummynode=new ListNode(-1);
         ListNode* res=dummynode;
         ListNode* list1=merge;
         ListNode* list2=lists[i];
         while(list1!=NULL&& list2!=NULL){
            if(list1->val<list2->val){
                res->next=list1;
                res=res->next;
                list1=list1->next;
            }
            else{
                res->next=list2;
                list2=list2->next;
                res=res->next;
            }
         }
         if(list1) res->next=list1;
         else res->next=list2;
         merge=dummynode->next;
       }
       return merge;
    }
};