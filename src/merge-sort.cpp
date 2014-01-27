
#include <assert.h>
#include <stdlib.h>
#include <string.h>
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
			array_result[cursor1 + cursor2] = array2[cursor2];
			cursor2 ++;
		} else {
			array_result[cursor1 + cursor2] = array1[cursor1];
			cursor1 ++;
		}
	}

	if (cursor1 < len1) {
		while (cursor1 < len1) {
			array_result[cursor1 + cursor2] = array1[cursor1];
			cursor1 ++;
		}
	}

	if (cursor2 < len2) {
		while (cursor2 < len2) {
			array_result[cursor1 + cursor2] = array2[cursor2];
			cursor2 ++;
		}
	}

    //Copy the sorted elements back into the source array
    memcpy((void*)array, (void*)array_result, len * sizeof(int));
    delete []array_result;

	assert(cursor1 == len1 || cursor1 == 0);
	assert(cursor2 == len2 || cursor2 == 0);
	return array;
}

int main() {
  srand(time(NULL));
  int tested_array_len = 10000;
  int *array = new int[tested_array_len];
  for (int i = 0; i < tested_array_len; i ++) {
	  array[i] = rand() % 100000;
  }
  std::vector<int> v(array, array + tested_array_len);
  std::sort(v.begin(), v.end());
  int *ret = merge_sort(array, tested_array_len);

  for (int i = 0; i < tested_array_len; i ++) {
	  assert(ret[i] == v[i]);
      std::cout << ret[i] << ", ";
  }
  std::cout << "OK" << std::endl;
  return 0;
}
