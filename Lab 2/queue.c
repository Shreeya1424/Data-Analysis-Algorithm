#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

// Enqueue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue overflow!\n");
    } else {
        if (front == -1) front = 0; 
        rear++;
        queue[rear] = value;
        printf("Pushed %d into queue\n", value);
    }
}

// Dequeue
int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow!\n");
        return -1;
    } else {
        int poppedValue = queue[front];
        front++;
        return poppedValue;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    dequeue();
    display();
    return 0;
}
