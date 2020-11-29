# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        dummy = ListNode(-1)
        dummy.next = list1
        for i in range(1, a):
            list1 = list1.next
        l1 = list1.next;
        list1.next = list2
        for i in range(a, b):
            l1 = l1.next
        while list1.next:
            list1 = list1.next
        list1.next = l1.next
        return dummy.next
