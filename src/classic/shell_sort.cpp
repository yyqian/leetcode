void sort(vector<int> &nums) {
  int step = nums.size() / 3;
  while (step > 0) {
    for (int i = step; i < nums.size(); ++i) {
      for (int j = i; j >= step && nums[j - step] > nums[j]; j -= step) {
        swap(nums[j - step], nums[j]);
      }
    }
    step /= 2;
  }
}
