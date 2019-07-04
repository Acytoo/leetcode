package main

import (
	"fmt"
	// "strconv"
)

func main() {
	// arr := []int{1,0,1,0,1,1}
	arr := []int{1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0,0,1,0,1,1,1,0,0,1,0}
	res := prefixesDivBy5(arr)
	for i, _ := range(res) {
		fmt.Println(res[i])
	}
}

func prefixesDivBy5(a []int) (res []bool) {
    var num int = 0
	res = make([]bool, len(a))
	for idx, cur := range(a) {
		num <<= 1				// num = num * 2
		num %= 10
		// num &= byte(15)
		num += cur
		res[idx] = (num == 0 || num == 5 || num == 10 || num == 15)
	}
	return
}
