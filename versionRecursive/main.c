/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:21:51 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/16 12:30:05 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	insertSorted(int stack[], int *top, int element, int stackSize);

void	sortStack(int stack[], int *top, int stackSize) {
	if (*top < stackSize) {
		// Pop the top element from the stack
		int temp = stack[(*top)++];
		// Recursively sort the remaining stack
		sortStack(stack, top, stackSize);
		write(1, "pb\n", 3);
		// Insert the popped element back into the sorted stack
		insertSorted(stack, top, temp, stackSize);
	}
}

void	insertSorted(int stack[], int *top, int element, int stackSize) {
	// Base case: if the stack is empty or the top element is smaller, push the element
	if (*top == stackSize || stack[*top] >= element) {
		stack[--(*top)] = element;
		write(1, "pa\n", 3);
	} else {
		// Pop elements from the stack until a smaller element is found
		int temp = stack[(*top)++];
		insertSorted(stack, top, element, stackSize);
		stack[--(*top)] = temp;
    }
}

int main() {
	int stack[] = {5, 2, 7};
	// int stack[] = {5, 2, 7, 1, 3};
	// int stack[] = {55, 98, 94, 47, 15, 42, 21, 18, 65, 73, 6, 7, 91, 4, 78, 43, 23, 3, 38, 61, 93, 58, 79, 32, 22, 29, 69, 10, 45, 11, 70, 25, 60, 82, 36, 37, 77, 39, 50, 63, 84, 5, 24, 72, 0, 30, 64, 27, 95, 56, 62, 1, 41, 34, 67, 86, 92, 99, 96, 40, 48, 81, 89, 74, 97, 19, 16, 13, 14, 85, 66, 53, 88, 75, 54, 20, 59, 87, 80, 33, 90, 46, 9, 26, 52, 2, 17, 8, 35, 83, 57, 49, 44, 51, 31, 76, 100, 68, 28, 71};
	int stackSize = sizeof(stack) / sizeof(stack[0]);
	int top = 0;
	if (stackSize > 0)
		write(1, "pb\n", 3);

	// Sorting the stack
	sortStack(stack, &top, stackSize);

    // Printing the sorted stack
	printf("Sorted Stack: ");
	for (int i = 0; i < stackSize; i++) {
	printf("%d ", stack[i]);
	}

	return 0;
}
