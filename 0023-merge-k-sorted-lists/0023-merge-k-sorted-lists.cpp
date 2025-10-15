class Solution {
public:
    
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val <= l2->val) {
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
    }

    // Recursive divide-and-conquer merge
    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists) {
        if (start == end) return lists[start];
        if (start > end) return NULL;

        int mid = start + (end - start) / 2;

        ListNode* left = partitionAndMerge(start, mid, lists);
        ListNode* right = partitionAndMerge(mid + 1, end, lists);

        return mergeTwoSortedLists(left, right);
    }

    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        return partitionAndMerge(0, lists.size() - 1, lists);
    }
};
