package main

import (
	"fmt"
	"golang.org/x/tour/tree"
)

const Capacity = 10

// Walk walks the tree t sending all values
// from the tree to the channel ch.
func Walk(t *tree.Tree, ch chan int) {
	if t == nil {
		return
	}
	Walk(t.Left, ch)
	ch <- t.Value
	Walk(t.Right, ch)
}

// Same determines whether the trees
// t1 and t2 contain the same values.
func Same(t1, t2 *tree.Tree) bool {
	ch1, ch2 := make(chan int, Capacity), make(chan int, Capacity)

	go Walk(t1, ch1)
	go Walk(t2, ch2)

	for range Capacity {
		if <-ch1 != <-ch2 {
			return false
		}
	}
	return true
}

func main() {
	ch := make(chan int, Capacity)
	go Walk(tree.New(1), ch)

	for range 10 {
		fmt.Println(<-ch)
	}

	fmt.Println("Same(tree.New(1), tree.New(1)): ", Same(tree.New(1), tree.New(1)))
	fmt.Println("Same(tree.New(1), tree.New(2)): ", Same(tree.New(1), tree.New(2)))
}
