void sort(vector<int> &nums, int lo, int hi) {
  if (lo >= hi) return;
  int mid = lo + (hi - lo) / 2;
  vector<int> aux(nums.size());
  sort(nums, lo, mid);
  sort(nums, mid + 1, hi);
  merge(nums, lo, mid, hi, aux);
}

void merge(vector<int> &nums, int lo, int mid, int hi, vector<int> &aux) {
  int i = lo;
  int j = mid + 1;
  for (int k = lo; k <= hi; ++k) {
    if (j > hi) {
      aux[k] = nums[i++];
    } else if (i > mid) {
      aux[k] = nums[j++];
    } else if (nums[i] < nums[j]) {
      aux[k] = nums[i++];
    } else {
      aux[k] = nums[j++];
    }
  }
  for (int k = lo; k <= hi; ++k) {
    nums[k] = aux[k];
  }
}