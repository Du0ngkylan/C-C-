// Kth Largest Element in an Array
// Tìm phần tử lớn thứ k trong mảng

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
	int size = nums.size();
	nth_element(nums.begin(), nums.begin() + size - k, nums.end());
	return nums[size - k];
}

// Sorting: O(nlogn )
int findKthLargest1(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());
	return nums[nums.size() - k];
}

// Using minHeap O(nlogk )
int findKthLargest2(vector<int>& nums, int k) {
	priority_queue<int, vector<int>, greater<int>> minheap;
	for (int i = 0; i < k; ++i) minheap.push(nums[i]);

	for (int i = k; i < nums.size(); ++i) {
		if (nums[i] <= minheap.top()) continue;
		minheap.pop();
		minheap.push(nums[i]);
	}

	return minheap.top();
}

// Partition : (n) average = O(n^2)
int findKthLargest3(vector<int>& nums, int k) {

	if (k < 1 || k > nums.size()) return -1;

	int start = 0, end = nums.size() - 1;
	int pivot, l, r;

	while (true) {
		// partition code
		l = start; r = end;
		pivot = nums[start];

		while (l <= r) {
			if (nums[l] >= pivot) l++;
			else if (nums[r] <= pivot) r--;
			else swap(nums[l], nums[r]);
		}
		swap(nums[start], nums[r]);
		//pivot is fixed at index r, which is (r+1)th 

		if (k == r + 1) return nums[r];
		else if (k > r + 1) start = r + 1;
		else end = r - 1;
	}
	return -1;
}

int main() {
	vector<int> nums = { 3,2,1,5,5,6,4 };
	int k = 4;

	auto result = findKthLargest3(nums, k);

	cout << "result = " << result << endl;

	return 0;
}
