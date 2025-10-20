class Solution {
  public:
    Node* reverseListSegment(Node* head, int k) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        int count = 0;

        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        return prev; 
    }

    Node* reverseKGroup(Node* head, int k) {
        Node* curr = head;
        int count = 0;

        while (curr != NULL && count < k) {
            curr = curr->next;
            count++;
        }

        if (count > 0) {
            
            Node* newHead = reverseListSegment(head, count);


            head->next = reverseKGroup(curr, k); 
            return newHead;
        }

        return NULL;
    }
};
