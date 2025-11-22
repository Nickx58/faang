ALL the arrays questions and concept to be found here.

Array Storage

Fixed Size Arrays

int arr[100];
int arr[n];

Above are stored in the Stack

int *arr = new int[n]; -> Stored in heap;

Time Complexity

Insert: O(n);
Search : O(n) -> Array is unsorted
       : O(log n) -> Array is sorted
Delete : O(n);

Note: Insert and Delete at the end can be done in constant time O(1);