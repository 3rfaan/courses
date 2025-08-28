package main

import "golang.org/x/tour/pic"

func Pic(dx, dy int) [][]uint8 {
	s := make([][]uint8, dy) // Create 2D slice of length `dy`

	for y := range dy { // Iterate over range 0..dy
		for range dx { // Iterate over range 0..dx
			s[y] = make([]uint8, dx) // Create slice of `uint8` integers of length `dx`

			for x := range s[y] { // Iterate over elements in inner slice
				s[y][x] = uint8(x*x + y*y) // Apply formula to distort image
			}
		}
	}
	return s
}

func main() {
	pic.Show(Pic)
}
