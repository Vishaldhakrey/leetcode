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
    
        priority_queue<pair<int, ListNode*>,
                    vector<pair<int, ListNode*>>,
                    greater<pair<int, ListNode*>>> pq;

    
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

    
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (!pq.empty()) {
            auto pt = pq.top();
            pq.pop();

            temp->next = pt.second;
            temp = temp->next;

            if (pt.second->next) {
                pq.push({pt.second->next->val, pt.second->next});
            }
        }

        return dummyNode->next;
    }
};