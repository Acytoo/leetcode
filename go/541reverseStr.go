package main

// problem 541, easy
// Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.


import (
	"fmt"
	// "strings"
)

// 找到一共有多少的个段需要翻转，然后循环每个需要翻转的地方。
// First seperate words every 2k, then reverse the first k characters
func reverseStr(s string, k int) string {
	base, kk, length := 0, k*2, len(s)
	numOfWords := length/kk+1
	characters := []rune(s)
	for wordIdx := 0; wordIdx != numOfWords; wordIdx++ {
		base = wordIdx*kk
		stop := base + k
		i, j := base, base + k - 1
		if stop > length {
			j = length-1
		}
		for {
			if i >= j {
				break
			}
			characters[i], characters[j] = characters[j], characters[i]
			i, j = i+1, j-1
		}
	}
	return string(characters)
}


func main() {
	s := "abcdefgh"
	fmt.Println(reverseStr(s, 3))
}
