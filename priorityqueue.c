#include <stdio.h>

struct Student {
    char sname[100];
    int cgpa_marks;
};

void Build_priorityQ(int priority_queue[], int hash[], struct Student Records[], int n);
int Dequeue_priorityQ(int priority_queue[], int hash[], struct Student Records[], int n);
void Enqueue_priorityQ(int priority_queue[], int hash[], struct Student Records[], int new_roll, int n);
void Max_heapify(int priority_queue[], int hash[], struct Student Records[], int prQ_indx, int n);
void heap_increase_key(int priority_queue[], int hash[], struct Student Records[], int prQ_indx, int n);

int main() {
    int n;

    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student Records[n];

    // Input student information
    for (int i = 0; i < n; i++) {
        printf("Enter student name for roll# %d: ", i);
        scanf("%s", Records[i].sname);
        printf("Enter CGPA for roll# %d: ", i);
        scanf("%d", &Records[i].cgpa_marks);
    }

    int priority_queue[n];
    int hash[n];

    // Build the max-heap and initialize hash array
    Build_priorityQ(priority_queue, hash, Records, n);

    int choice;
    int new_roll;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue new student\n");
        printf("2. Dequeue student with max CGPA\n");
        printf("3. Increase CGPA of a student\n");
        printf("4. Decrease CGPA of a student\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the roll number of the new student: ");
                scanf("%d", &new_roll);
                Enqueue_priorityQ(priority_queue, hash, Records, new_roll, n);
                break;
            case 2:
                Dequeue_priorityQ(priority_queue, hash, Records, n);
                break;
            case 3:
                printf("Enter the roll number to increase CGPA: ");
                scanf("%d", &new_roll);
                heap_increase_key(priority_queue, hash, Records, hash[new_roll], n);
                break;
            case 4:
                printf("Enter the roll number to decrease CGPA: ");
                scanf("%d", &new_roll);
                Max_heapify(priority_queue, hash, Records, hash[new_roll], n);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}

void Build_priorityQ(int priority_queue[], int hash[], struct Student Records[], int n) {
    for (int i = 0; i < n; i++) {
        priority_queue[i] = i;
        hash[i] = i;
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        Max_heapify(priority_queue, hash, Records, i, n);
    }
}

int Dequeue_priorityQ(int priority_queue[], int hash[], struct Student Records[], int n) {
    if (n < 1) {
        printf("Priority queue is empty.\n");
        return -1;  // Return -1 to indicate an empty queue
    }

    int max_roll = priority_queue[0];

    // Swap the root with the last element
    int temp = priority_queue[0];
    priority_queue[0] = priority_queue[n - 1];
    priority_queue[n - 1] = temp;

    n--;

    // Re-arrange the max-heap
    Max_heapify(priority_queue, hash, Records, 0, n);

    printf("Dequeued student with max CGPA. Roll# %d\n", max_roll);

    return max_roll;
}

void Enqueue_priorityQ(int priority_queue[], int hash[], struct Student Records[], int new_roll, int n) {
    n++;
    priority_queue[n - 1] = new_roll;
    hash[new_roll] = n - 1;

    // Adjust the max-heap
    heap_increase_key(priority_queue, hash, Records, n - 1, n);
}

void Max_heapify(int priority_queue[], int hash[], struct Student Records[], int prQ_indx, int n) {
    int left = 2 * prQ_indx + 1;
    int right = 2 * prQ_indx + 2;
    int largest = prQ_indx;

    if (left < n && Records[priority_queue[left]].cgpa_marks > Records[priority_queue[largest]].cgpa_marks) {
        largest = left;
    }

    if (right < n && Records[priority_queue[right]].cgpa_marks > Records[priority_queue[largest]].cgpa_marks) {
        largest = right;
    }

    if (largest != prQ_indx) {
        // Swap
        int temp = priority_queue[prQ_indx];
        priority_queue[prQ_indx] = priority_queue[largest];
        priority_queue[largest] = temp;

        // Update hash array
        hash[priority_queue[prQ_indx]] = prQ_indx;
        hash[priority_queue[largest]] = largest;

        // Recursively heapify the affected sub-tree
        Max_heapify(priority_queue, hash, Records, largest, n);
    }
}

void heap_increase_key(int priority_queue[], int hash[], struct Student Records[], int prQ_indx, int n) {
    if (prQ_indx < 0 || prQ_indx >= n) {
        printf("Invalid index.\n");
        return;
    }

    int parent = (prQ_indx - 1) / 2;

    while (prQ_indx > 0 && Records[priority_queue[parent]].cgpa_marks < Records[priority_queue[prQ_indx]].cgpa_marks) {
        // Swap
        int temp = priority_queue[prQ_indx];
        priority_queue[prQ_indx] = priority_queue[parent];
        priority_queue[parent] = temp;

        // Update hash array
        hash[priority_queue[prQ_indx]] = prQ_indx;
        hash[priority_queue[parent]] = parent;

        prQ_indx = parent;
        parent = (prQ_indx - 1) / 2;
    }
}
