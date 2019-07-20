package main

import (
	"fmt"
)

func main() {
	numOfPeople, candies := 3, 11
	res := distributeCandies(numOfPeople, candies)
	for _, i := range res {
		fmt.Printf("%d ", i)
	}
	fmt.Printf("\n")


}

func distributeCandies(candies int, num_people int) []int {
	// a:= []int {1,2,3}
	// return a

}
