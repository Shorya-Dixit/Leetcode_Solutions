struct LNode {
        int val;
        LNode *next;
        LNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:  
    int findTheWinner(int n, int k) {
        if(k==1) return n;
        vector<int>out(n,0);
        int c=0;
        LNode* head= new LNode(1);
        LNode* temp= head;
        for(int i=2;i<=n;i++){
            temp->next= new LNode(i);
            temp=temp->next;
        }
        temp->next=head;
        while(c<n-1){
            int j=1;
            LNode* temp=head;
            while(j<k-1){
                temp=temp->next;
                j++;
            }
            cout<<temp->next->val;
            temp->next=temp->next->next;
            head=temp->next;
            c++;
        }
        return head->val;
    }
};