# -*- coding: utf-8 -*-
class ListNode:
     def __init__(self, value="", next=None):
          self.value = value
          self.next = next

def main():
     # [1]->[2]->[2]->[3]->[1]->[4]
     len_node = 5
     n5 = ListNode("🐟")
     n4 = ListNode("💖", n5)
     n3 = ListNode("🌻", n4)
     n2 = ListNode("💖", n3)
     n1 = ListNode("🐟", n2)
     head = n1
     stack = []
     count = 0
     while count < (int)(len_node/2):
          stack.append(head.value)
          head = head.next
          count += 1
     if len_node % 2 == 1:
          head = head.next

     while head != None:
          if head.value != stack.pop():
               print("False")
               return
          head = head.next
     print("True")
if __name__ == "__main__":
     main()
