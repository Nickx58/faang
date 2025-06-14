/*

Problem Statement

Given the head of a linked list, Find the number of critical points. (The starting and end are not considered critical points).

Local minima or maxima are called critical points.

A Node is called a local minima if both next and previous elements are greater than the current element.

A Node is called a local maxima if both next and previous elements are smaller than the current element.

*/

int solve(Node * head) {
    if (head == nullptr || head -> next == nullptr) {
        return 0;
    }
    int count = 0;
    Node * temp = head;
    while (temp -> next != nullptr && temp -> next -> next != nullptr) {
        if (temp -> next -> data < temp -> data && temp -> next -> data < temp -> next -> next -> data) {
            count++;
        }
        if (temp -> next -> data > temp -> data && temp -> next -> data > temp -> next -> next -> data) {
            count++;
        }
        temp = temp -> next;
    }
    return count;

}