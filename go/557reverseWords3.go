package main

// Prob 557, reverse words in strings III
// Learning go

import (
	"fmt"
	"strings"
)

// Slow and consume a lot of memory.....
func reverseWords1(s string) string {
	if len(s) < 1 {
		return ""
	}
	runes := []rune(s)
	words := strings.Fields(s)
	resString := ""
	for _, word := range words {
		runes = []rune(word)
		for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
			runes[i], runes[j] = runes[j], runes[i]
		}
		resString += string(runes) + " "
	}
    return resString[:len(resString)-1]
}

// Try something faster
// Length of each word won't change
func reverseWords(s string) (string) {
	words := strings.Split(s, " ")
	i, stop := 0, len(words)
	for ; i != stop; i++ {
		words[i] = reverse(words[i])
	}
	return strings.Join(words, " ")
}

func reverse(word string) string {
	runes := []rune(word)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// func main() {
// 	// s := "Hello Acytoo, again"
// 	ss := "Let's take LeetCode contest"
// 	fmt.Printf("[%s]\n", reverseWords(ss))
// }
