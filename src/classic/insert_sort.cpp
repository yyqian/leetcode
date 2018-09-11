/*
        j
1 2 4 5 3 6
        i
*/

void insert_sort(vector<int> nums) {
  for (int i = 1; i < nums.size(); ++i) {
    for (int j = i; j >= 1 && nums[j - 1] > nums[j]; --j) {
      swap(nums[j], nums[j - 1]);
    }
  }
}

void insert_sort(vector<int> nums) {
  int step = 1;
  for (int i = step; i < nums.size(); ++i) {
    for (int j = i; j >= step && nums[j - step] > nums[j]; j -= step) {
      swap(nums[j - step], nums[j]);
    }
  }
}