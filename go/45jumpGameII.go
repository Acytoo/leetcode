package main

// Using BFS
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.

import (
	"fmt"
)

func main() {

	a := []int{0}
	res := jump(a)
	fmt.Println(res)
}

func YtMax(x, y int) int  {
	if x > y {
		return x
	}
	return y
}

func jump(nums []int) int {
	stop, step, i, end, maxLength := len(nums)-1, 0, 0, 0, 0
	if stop == 0 {
		return 0
	}
	for end < stop {
		step++
		for ; i <= end; i++ {
			maxLength = YtMax(maxLength, nums[i] + i)
			if maxLength >= stop {
				return step
			}
		}
		if end == maxLength {
			break
		}
		end = maxLength
	}
	return -1;					// Can't reach end
}
