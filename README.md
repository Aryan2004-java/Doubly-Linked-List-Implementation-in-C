# Doubly-Linked-List-Implementation-in-C
This project implements a Doubly Linked List (DLL) in C
This project implements a Doubly Linked List (DLL) in C, allowing users to perform various operations such as insertion, deletion, and traversal. The program provides an interactive menu to manage the linked list dynamically.

Features
The program supports the following operations:

Create a Doubly Linked List – Allows the user to create a list by entering elements.
Display the List – Prints the elements in the list.
Insertion Operations
At the beginning
At the end
Before a given node
After a given node
Deletion Operations
From the beginning
From the end
A specific node
A node after a given node
Exit the Program – Terminates execution.
Functions and Their Purpose
Function	Description
create_ll(start)	Creates a new doubly linked list.
display(start)	Prints all elements in the list.
insert_beg(start)	Inserts a new node at the beginning.
insert_end(start)	Inserts a new node at the end.
insert_before(start)	Inserts a new node before a given value.
insert_after(start)	Inserts a new node after a given value.
delete_beg(start)	Deletes the first node.
delete_end(start)	Deletes the last node.
delete_node(start)	Deletes a specific node.
delete_after(start)	Deletes a node after a given node.
Edge Cases Handled
Empty List: Displays appropriate messages when performing operations on an empty list.
Node Not Found: Handles cases where the specified node does not exist.
Memory Allocation Failure: Ensures graceful handling of memory allocation issues.
Possible Enhancements
Implement a circular doubly linked list for efficient navigation.
Add a search function to find elements in the list.
Implement a reverse function to print the list in reverse order.
