#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
using namespace std;
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if(head==nullptr||head->next==nullptr)
        {
            return nullptr;
        }
        unordered_map<ListNode* ,int> um;
        while(head!=nullptr)
        {
            if(um[head]==0)
            {
                um[head]++;
            }
            else
            {
                return head;
            }
            head = head->next;
        }
        return nullptr;
        }
};