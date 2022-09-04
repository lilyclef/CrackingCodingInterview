# -*- coding: utf-8 -*-
class ListNode:
     def __init__(self, value=0, next=None):
          self.value = value
          self.next = next

def main():
    # [1]->[2]->[2]->[3]->[1]->[4]
    len_node1 = 6
    n1_6 = ListNode(4, None)
    n1_5 = ListNode(2, n1_6)
    n1_4 = ListNode(3, n1_5) # n1_4を指しているものが2つあるので、n1_4で衝突
    n1_3 = ListNode(4, n1_4)
    n1_2 = ListNode(5, n1_3)
    n1_1 = ListNode(1, n1_2)
    head = n1_1
    n2_2 = ListNode(4, n1_4)
    n2_1 = ListNode(3, n2_2)
    head2 = n2_1
    len_node2 = 5
    count = 0
    if len_node1 - len_node2 > 0:
        while count != (len_node1 - len_node2):
            head = head.next
            count += 1
    else:
        while count != (len_node2 - len_node1):
            head2 = head2.next
            count += 1

    # 両方とも同じ長さになったはず
    is_common = False
    while head != None and head2 != None:
        if head == head2:
            is_common = True
            break
        head = head.next
        head2 = head2.next

    # 結果ゾーン
    if is_common == True:
        print("True")    
    else:
        print("False")
if __name__ == "__main__":
     main()
