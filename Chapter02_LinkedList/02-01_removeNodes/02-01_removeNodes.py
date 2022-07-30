# -*- coding: utf-8 -*-
class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next


dic = {}
def removeNodes(node):
    curr = ListNode()
    ans = curr
    while node != None :
        if not node.value in dic:
            # print(node.value)
            curr.next = ListNode(node.value)
            curr = curr.next
            dic[node.value] = 1
        node = node.next;
    return ans.next

def main():
    # [1]->[2]->[2]->[3]->[1]->[4]
    n6 = ListNode(4)
    n5 = ListNode(1, n6)
    n4 = ListNode(3, n5)
    n3 = ListNode(2, n4)
    n2 = ListNode(2, n3)
    n1 = ListNode(1, n2)
    head = removeNodes(n1)
    while head != None :
        print(head.value)
        head = head.next

if __name__ == "__main__":
    main()