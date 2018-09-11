void sort(vector<int> &nums, int lo, int hi) {
  if (lo >= hi) return;
  int p = partition(nums, lo, hi);
  sort(nums, lo, p - 1);
  sort(nums, p + 1, hi);
}

int partition(vector<int> &nums, int lo, int hi) {
  int target = nums[lo];
  int i = lo;
  int j = hi + 1;
  while (true) {
    while (nums[++i] < target) {
      if (i == hi) break;
    }
    while (target < nums[--j]) {
      if (j == lo + 1) break;
    }
    if (i >= j) break;
    swap(nums[i], nusm[j]);
  }
  swap[nums[lo], nums[j]];
  return j;
}