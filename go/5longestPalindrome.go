package main

// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
// Dynamic programming

import (
	"fmt"
)

func main() {
	s := "ssdfaaa"
	res := longestPalindrome(s)
	fmt.Println(res)

}

func longestPalindrome(s string) string {
	n, count := len(s) -1, 0
	if n <= 0 {
		return s
	}
	start, length := 0, 0
	for i:=0; i<n; i++ {
		if length >= 2*n {
			return s[start:length]
		}
		count = 0
		for {
			if i+1 <= n && s[i] == s[i+1] {
				count++
				i++
			} else {
				break
			}
		}
		first, end := i-count, i
		for {
			first--
			end++
			if first >= 0 && end <= n && s[first] == s[end] {
				continue
			} else {
				break
			}
			first++
			end--
			if length < end-first+1 {
				start = first
				length = end-first+1
			}

		}

	}
	fmt.Println(start, length)
	return s[start:length]
}
