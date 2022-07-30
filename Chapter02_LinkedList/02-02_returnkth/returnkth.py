# -*- coding: utf-8 -*-
class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

def main(k):
    # [1]->[2]->[2]->[3]->[1]->[4]
    n6 = ListNode(4)
    n5 = ListNode(1, n6)
    n4 = ListNode(3, n5)
    n3 = ListNode(2, n4)
    n2 = ListNode(2, n3)
    n1 = ListNode(1, n2)
    head = n1
    vector = []
    while head != None :
        vector.append(head.value)
        head = head.next
    n = (-1)*k
    print(vector[n])
if __name__ == "__main__":
     k = int(input())
     main(k)
