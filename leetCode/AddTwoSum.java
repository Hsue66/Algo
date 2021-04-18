class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode();

        int ten = 0;
        ListNode L1 = new ListNode(0, l1);
        ListNode L2 = new ListNode(0, l2);
        ListNode L3 = new ListNode();
        result = L3;

        while (L1.next != null && L2.next != null) {
            L1 = L1.next; L2 = L2.next; L3.next = new ListNode(); L3 = L3.next;
            int sum = L1.val + L2.val + ten;
            ten = 0;
            if( sum >= 10){
                ten = 1;
                sum -= 10;
            }
            L3.val = sum;
        }
        ListNode L = new ListNode();
        if(L1.next != null)
            L = L1;
        else
            L = L2;

        while (L.next != null) {
            L = L.next; L3.next = new ListNode(); L3 = L3.next;
            int sum = L.val + ten;
            if (sum < 10) {
                L3.val = sum;
                L3.next = L.next;
                ten = 0;
                break;
            }
            L3.val = sum -10;
        }
        if(ten == 1)
            L3.next = new ListNode(1);

        return result.next;
    }
}
