package main

import (
	"golang.org/x/tour/wc"
	"strings"
)

func WordCount(s string) map[string]int {
	m := make(map[string]int)

	for v := range strings.FieldsSeq(s) {
		m[v]++
	}
	return m
}

func main() {
	wc.Test(WordCount)
}
