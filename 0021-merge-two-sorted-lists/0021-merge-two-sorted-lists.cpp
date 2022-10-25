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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* fh=NULL,*ft=NULL;
        while(head1!=NULL&&head2!=NULL)
        {
            if(fh==NULL&&ft==NULL)
            {
                if(head1->val<head2->val)
                { fh=head1;
                    ft=head1;
                    head1=head1->next;}
                else
                {
                    fh=head2;
                    ft=head2;
                    head2=head2->next;
                }
            }
            else
                if(head1->val<head2->val)
                {
                    ft->next=head1;
                    head1=head1->next;
                    ft=ft->next;
                }
                else
                {
                    ft->next=head2;
                    head2=head2->next;
                    ft=ft->next;
                }
        }
       if(fh==NULL)
        {
            if(head1!=NULL)
                return head1;
            else
                return head2;
        }
        
        if(head1!=NULL)
        {//cout<<"head2 is empty"<<endl;
            ft->next=head1;}
        else if(head2!=NULL)
        {ft->next=head2;
       // cout<<"head1 is empty"<<endl;
        }
        
        
        return fh;
    }
};