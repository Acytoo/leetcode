func shuffle(nums []int, n int) []int {
	res := make([]int, len(nums))
	j := -1
	for i := 0; i < n; i += 1 {
		j += 1
		res[j] = nums[i]
		j += 1
		res[j] = nums[i + n]
	}
	return res
}
