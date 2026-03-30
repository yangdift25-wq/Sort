/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* MergeList(struct ListNode* l1 ,struct ListNode* l2)
{
    //定义哨兵位
    struct ListNode dummy;
    struct ListNode* tail=&dummy;
    dummy.next=NULL;

    while(l1&&l2)
    {
        if(l1->val<l2->val)
        {
            tail->next=l1;
            l1=l1->next;
        }
        else
        {
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }
    if(l1)
    {
        tail->next=l1;
    }
    if(l2)
    {
        tail->next=l2;
    }

    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    //当节点数为0或1天然有序
    if(head==NULL||head->next==NULL)
    {
        return head;
    }

    //定义快慢指针找中点
    struct ListNode* fast=head;
    struct ListNode* slow=head;
    struct ListNode* prev=NULL;

    while(fast&&fast->next)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }

    //分割链表
    prev->next=NULL;

    //左右递归
    struct ListNode* left=sortList(head);
    struct ListNode* right=sortList(slow);

    //合并链表
    return MergeList(left,right);
}
