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

struct minHeapNode {
    int ele;
    int i;
};

void swap(minHeapNode *x, minHeapNode *y) {
    minHeapNode temp = *x;
    *x = *y;
    *y = temp;
}

int left(int i) { return (2 * i + 1); }
int right(int i) { return (2 * i + 2); }

void MinHeapify(int i, int heap_size, minHeapNode* harr) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].ele < harr[i].ele)
        smallest = l;
    if (r < heap_size && harr[r].ele < harr[smallest].ele)
        smallest = r;
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest, heap_size, harr);
    }
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return nullptr;
        // Initialize min heap array
        minHeapNode* harr = new minHeapNode[k];
        int heap_size = 0;
        for (int i = 0; i < k; i++) {
            if (lists[i] != nullptr) {  // Only add non-empty lists
                harr[heap_size].ele = lists[i]->val;
                harr[heap_size].i = i;
                lists[i] = lists[i]->next;
                heap_size++;
            }
        }
        // Build the heap
        for (int i = (heap_size - 1) / 2; i >= 0; i--) {
            MinHeapify(i, heap_size, harr);
        }
        // Dummy node to ease list merging
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        // Process the heap and build the merged list
        while (heap_size > 0) {
            minHeapNode root = harr[0];
            temp->next = new ListNode(root.ele);
            temp = temp->next;
            if (lists[root.i] != nullptr) {
                root.ele = lists[root.i]->val;
                lists[root.i] = lists[root.i]->next;
                // Replace root with the next element and re-heapify
                harr[0] = root;
                MinHeapify(0, heap_size, harr);
            } else {
                // If the list is exhausted, remove the root and reduce heap size
                harr[0] = harr[heap_size - 1];
                heap_size--;
                MinHeapify(0, heap_size, harr);
            }
        }
        // Free heap array and return merged list
        delete[] harr;
        return head->next;
    }
};


// new MinHeapNode[k] dynamically allocates an array of k MinHeapNode objects on the 
// heap. It returns a pointer to the first element of this array, and this pointer has 
// type MinHeapNode*.

// If k is only known at runtime and stack allocation is still preferred, you’ll need to 
// either:
// Use a smaller array size that’s always within stack limits, or
// Use std::vector, which dynamically manages memory but could be treated similarly to 
// an array for convenience:

// * is used with pointers because pointers store addresses of dynamically allocated 
// memory, which must be manually managed. Stack arrays like MinHeapNode harr[k]; don’t 
// need * because they’re actual arrays directly allocated with automatic storage duration 
// (deallocated when out of scope).