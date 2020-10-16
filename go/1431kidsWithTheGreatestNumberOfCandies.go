func kidsWithCandies(candies []int, extraCandies int) []bool {
    m := candies[0]
	for _, can := range(candies) {
		if can > m {
			m = can
		}
	}
	res := make([]bool, len(candies))
	for i := 0; i < len(candies); i += 1 {
		if extraCandies + candies[i] >= m {
			res[i] = true
		} else {
			res[i] = false
		}
	}
	return res
}
