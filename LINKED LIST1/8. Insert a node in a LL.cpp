SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position)
{
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    // Insert at the beginning
    if (position == 0) {
        newNode->next = llist;
        return newNode;
    }

    SinglyLinkedListNode* temp = llist;

    // Traverse to the (position - 1)th node
    for (int i = 0; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        // Invalid position (position > length of list)
        return llist;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return llist;
}

//TC : 	O(n)
//SC : O(1)
