#include <bits/stdc++.h>

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode head;
     ListNode* tail = &head;
     ListNode *trans_l1 = l1, *trans_l2 = l2;
     int sum = 0;
     while(trans_l1 != nullptr && trans_l2 != nullptr) {
         sum += (trans_l1->val + trans_l2->val);
	 trans_l1->val = sum % 10;
	 ListNode* temp = trans_l1;
	 trans_l1 = trans_l1->next;
	 trans_l2 = trans_l2->next;
	 tail ->next = temp;
	 tail = tail->next;
	 sum /= 10;
     }

     while(trans_l1 != nullptr) {
         sum += trans_l1->val;
	 trans_l1->val = sum % 10;
         ListNode* temp = trans_l1;
	 trans_l1 = trans_l1->next;
         tail ->next = temp;
	 tail = tail->next;
	 sum /= 10;
     }

     while(trans_l2 != nullptr) {
         sum += trans_l2->val;
	 trans_l2->val = sum % 10;
         ListNode* temp = trans_l2;
	 trans_l2 = trans_l2->next;
         tail ->next = temp;
	 tail = tail->next;
         sum /= 10;
     }

     if(sum == 1) {
        ListNode* temp = new ListNode(1);
	tail->next = temp;
     }

     return head.next;
}

