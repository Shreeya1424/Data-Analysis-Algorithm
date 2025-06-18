// Online C compiler to run C program online
#include<stdio.h>
#define max 100

int stack[max];
int top = -1;

int isFull(){
    return top == max-1;
}
int isEmpty(){
    return top == -1;
}

// push

void push(int value){
    if(isFull()){
        printf("Stack overflow %d\n",value);
    }
    else{
        top++;
        stack[top] = value;
        printf("Pushed %d into stack \n",value);
    }
}

// pop
int pop(){
    if(isEmpty()){
        printf("Stack Empty ! %d\n");
        return -1;
    }
    else{
        int popedvalue=stack[top];
        top--;
        return popedvalue;
    }
}

//peek
int peek(){
    if(isEmpty()){
        printf("Stack Empty ! %d\n");
    }
    return stack[top];
}

//change
void change(int position, int new_value){
int index = top - position + 1;
    if(position<=0 || position>top +1){
        printf("invalid position %D \n");
    }
    else{
        stack[index]=new_value;
    }
}

//display

void display(){
    if(isEmpty()){
        printf("Stack Empty ! %d\n");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}

//main 

int main(){
    push(10);
    push(20);
    display();
    return 0;
}
