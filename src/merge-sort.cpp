#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <iostream>
#include <vector>

int* merge_sort(int *array, int len) {
   if (len <= 1) {
     return array;
   }
   int len1 = len / 2;
   int len2 = len - len1;
   int *array1 = array;
   int *array2 = array + len1;
   array1 = merge_sort(array1, len1);
   array2 = merge_sort(array2, len2);
   int *array_result = new int[len];
   // Do the merge.
   int cursor1 = 0, cursor2 = 0;
    while (cursor1 < len1 && cursor2 < len2) {
		if (array1[cursor1] > array2[cursor2]) {
			array_ret[cursor1 + cursor2] = array2[cursor2];
			cursor2 ++;
		} else {
			array_ret[cursor1 + cursor2] = array1[cursor1];
			cursor1 ++;
		}
	}

	if (cursor1 < len1) {
		while (cursor1 < len1) {
			array_ret[cursor1 + cursor2] = array1[cursor1];
			cursor1 ++;
		}
	}

	if (cursor2 < len2) {
		while (cursor2 < len2) {
			array_ret[cursor1 + cursor2] = array2[cursor2];
			cursor2 ++;
		}
	}

	assert(cursor1 == len1 || cursor1 == 0);
	assert(cursor2 == len2 || cursor2 == 0);
	return array_ret;
}

int main() {
	srand(time(NULL));
	const int array1_size = 20;
	const int array2_size = 30;
	const int num_span = 10;
	int array1[array1_size];
	int array2[array2_size];
	std::vector<int> std_result(50);
	for (int i = 0; i < array1_size; i ++) {
		array1[i] = i * num_span + rand() % num_span;
	}
	for (int i = 0; i < array2_size; i ++) {
		array2[i] = i * num_span + rand() % num_span;
	}
	std::merge(array1, array1 + array1_size, array2, array2 + array2_size, std_result.begin());

	int *ret = merge_sort(array1, array1_size, array2, array2_size);

	for (int i = 0; i < array1_size + array2_size; i ++) {
		assert(ret[i] == std_result[i]);
	}
	return 0;
}
