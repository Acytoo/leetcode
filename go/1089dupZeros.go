package main

import (
	"fmt"
)

func main() {
	arr := []int{1,22,0,3,4,50,6,0}
	for _, i := range arr {
		fmt.Printf("%d ", i)
	}
	fmt.Printf("\n")
	duplicateZeros(arr)
	for _, i := range arr {
		fmt.Printf("%d ", i)
	}
	fmt.Printf("\n")

}

func duplicateZeros(arr []int) {
    end := len(arr)-1
	for i:=0; i <= end; i++ {
		if arr[i] == 0 {
			shiftRight(arr, i, end)
			i++
		}
	}
}

func shiftRight(arr []int, pos, end int) {
	for idx := end; idx > pos; idx-- {
		arr[idx] = arr[idx-1]
	}
	arr[pos] = 0
}
