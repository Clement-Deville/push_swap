/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:16:32 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/12 19:33:02 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define ll long long

void sortStack(int input[],int size)
{
  int tmpStack[size];
  int top=-1;
  while (size>=0)
  {
      int tmp = input[size];
      size--;
      // while temporary stack is not empty and top
      // of stack is greater than temp
      while (top>=0 && tmpStack[top] < tmp)
      {
          // pop from temporary stack and push
          // it to the input stack
          input[++size]=tmpStack[top];
		  printf("pb\n");
          top--;
      }
      // push temp in tempory of stack
	  printf("pa\n");
      tmpStack[++top]=(tmp);
  }
  while (top>=0)
  {
      printf("%d ",tmpStack[top]);
      top--;
  }
}
int main()
{
	int t;
	// int input[] = {5, 2, 7, 1, 3};
	int input[] = {55, 98, 94, 47, 15, 42, 21, 18, 65, 73, 6, 7, 91, 4, 78, 43, 23, 3, 38, 61, 93, 58, 79, 32, 22, 29, 69, 10, 45, 11, 70, 25, 60, 82, 36, 37, 77, 39, 50, 63, 84, 5, 24, 72, 0, 30, 64, 27, 95, 56, 62, 1, 41, 34, 67, 86, 92, 99, 96, 40, 48, 81, 89, 74, 97, 19, 16, 13, 14, 85, 66, 53, 88, 75, 54, 20, 59, 87, 80, 33, 90, 46, 9, 26, 52, 2, 17, 8, 35, 83, 57, 49, 44, 51, 31, 76, 100, 68, 28, 71};


	// This is the temporary stack
	sortStack(input, 99);
	// printf("\n");
	return 0;
 }
