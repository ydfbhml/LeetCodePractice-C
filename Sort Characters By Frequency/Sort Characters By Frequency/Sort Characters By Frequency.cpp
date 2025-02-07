#include "pch.h"
#include <iostream>

int CompareTo(int a, int b) {
	if (a < b) {
		return 1;
	}
	else if (a == b) {
		return 0;
	}
	else {
		return -1;
	}
}

int Partition(int * map, int left, int right) {
	int l = left;
	int r = right;
	//判断大小时要注意，按照ch中的值去判断
	int temp = map[r];

	while (l != r) {
		while (CompareTo(map[l], temp) <= 0 && r > l) {
			l++;
		}
		if (l < r) {
			map[r] = map[l];
			r--;
		}

		while (CompareTo(map[r], temp) >= 0 && r > l) {
			r--;
		}

		if (l < r) {
			map[l] = map[r];
			l++;
		}

	}
	map[l] = temp;
	return l;
}

void swap(int * map, int i, int j) {
	int temp = map[i];
	map[i] = map[j];
	map[j] = temp;
}

int * sort(int * map, int left, int right) {
	if (right <= left) {
		return map;
	}

	int pivot = (left + right) / 2;
	swap(map, pivot, right);
	pivot = Partition(map, left, right);
	sort(map, left, pivot - 1);
	sort(map, pivot + 1, right);

	return map;
}

char * frequencySort(char * s) {
	//Frequency * map = (Frequency *)malloc(128 * sizeof(Frequency));
	int left = 0;
	int right = 127;
	int i, j, k;
	int map[128] = { 0 };
	int tempmap[128] = { 0 };
	char ch;
	char * head = s;

	char *q;
	for (q = s; *q != '\0'; q++) {
		map[*q]++;
		tempmap[*q]++;
	}

	//sort it in decreasing order based on the frequency of characters
	sort(tempmap, left, right);

	for (i = 0; i < 128; i++) {
		if (tempmap[i] == 0) {
			break;
		}
		for (j = 0; j < 128; j++) {
			if (tempmap[i] == map[j]) {
				ch = j;
				for (k = 0; k < tempmap[i]; k++) {
					*head = ch;
					head++;
				}
				map[j] = 0;
			}
		}
	}

	return s;
}

int main()
{
	//char input[] = "tree";
	//char input[] = "Aabb";
	char input[] = "cccaaa";
	
	char * s = input;

	char * output = frequencySort(s);

	printf("%s", output);
}


