/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:58:27 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/16 14:22:04 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Function to push an element onto the stack
void push(int *stack, int *top, int element) {
    stack[++(*top)] = element;
}

// Function to pop an element from the stack
int pop(int *stack, int *top) {
    return stack[(*top)--];
}

// Function to insert an element in sorted order into the stack
void insertSorted(int *stack, int *top, int element) {
    // Pop elements from the second stack to the original stack until a smaller element is found
    while (*top != -1 && stack[*top] > element) {
        push(stack, top, pop(stack + 1, top + 1));
    }

    // Push the element onto the second stack
    push(stack + 1, top + 1, element);

    // Pop elements from the original stack back to the second stack
    while (*top != -1) {
        push(stack + 1, top + 1, pop(stack, top));
    }
}

// Recursive function to sort the stack using two stacks
void sortStack(int *stack, int *top) {
    if (*top > 0) {
        // Pop the top element from the stack
        int temp = pop(stack, top);

        // Recursively sort the remaining stack
        sortStack(stack, top);

        // Insert the popped element back into the sorted stack
        insertSorted(stack, top, temp);
    }
}

int main() {
    // Example usage
    int stack[] = {4, 2, 5, 1, 3};
    int top = sizeof(stack) / sizeof(stack[0]) - 1;

    // Display original stack
    printf("Original Stack: ");
    for (int i = 0; i <= top; ++i) {
        printf("%d ", stack[i]);
    }

    // Use a second stack for sorting
    int secondStack[sizeof(stack)];
    int secondTop = -1;

    // Sort the stack using two stacks
    sortStack(stack, &top);

    // Display sorted stack
    printf("\nSorted Stack: ");
    for (int i = 0; i <= top; ++i) {
        printf("%d ", stack[i]);
    }

    return 0;
}
