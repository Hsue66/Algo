public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode r = new ListNode();
        ListNode ri;
        ri = r;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                ri.next = l1;
                l1 = l1.next;
            } else {
                ri.next = l2;
                l2 = l2.next;
            }
            ri = ri.next;
        }

        if(l1 != null)
            ri.next = l1;
        if(l2 != null)
            ri.next = l2;

        return r.next;
    }
