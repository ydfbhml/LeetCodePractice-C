#include "pch.h"
#include <iostream>

#define STACK_INIT_SIZE 200

typedef struct{
	char stack[STACK_INIT_SIZE];
	int base;
	int top;
}Stack;

char GetTop(Stack s) {
	if (s.top == s.base) {
		return -1;
	}
	s.top--;
	return s.stack[s.top];
}

Stack push(Stack s, char ch) {
	s.stack[s.top] = ch;
	s.top++;
	return s;
}

Stack pop(Stack s) {
	if (s.base == s.top) {
		printf("Error, stack is empty!\n");
	}
	s.top--;
	return s;
}

bool isEmpty(Stack s) {
	if (s.top == s.base) {
		return true;
	}
	else {
		return false;
	}
}

Stack build(char * str) {
	Stack s;
	for (int i = 0; i < STACK_INIT_SIZE; i++) {
		s.stack[i] = '0';
	}
	s.base = s.top = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '#') {
			if (isEmpty(s)) {
				continue;
			}
			else {
				s = pop(s);
			}
		}
		else {
			s = push(s, str[i]);
		}
	}

	return s;
}

bool backspaceCompare(char * S, char * T) {
	Stack stackS = build(S);
	Stack stackT = build(T);
	
	//stackS和stackT中一个为空，一个不为空
	if (isEmpty(stackS) ^ isEmpty(stackT)) {
		return false;
	}

	//stackS和stackT都不为空，比较栈中的元素是否相等
	while (!isEmpty(stackS) || !isEmpty(stackT))
	{
		if (GetTop(stackS) != GetTop(stackT)) {
			return false;
		}
		else {
			stackS = pop(stackS);
			stackT = pop(stackT);
		}
	}

	//stackS和stackT相等
	return true;
}

int main()
{
	//char inputS[] = "ab#c";
	//char inputT[] = "ad#c";

	//char inputS[] = "ab##";
	//char inputT[] = "c#d#";

	//char inputS[] = "a##c";
	//char inputT[] = "#a#c";

	char inputS[] = "a#c";
	char inputT[] = "b";
	
	char * S = inputS;
	char * T = inputT;

	bool equal = backspaceCompare(S, T);

	printf("%d", equal);
}
