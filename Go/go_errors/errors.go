package main

import "fmt"

type ErrNegativeSqrt float64

func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprintf("cannot Sqrt negative number: %v", float64(e))
}

func Sqrt(f float64) (float64, error) {
	if f < 0 {
		return 0, ErrNegativeSqrt(f)
	}

	z := 1.0
	for range 10 {
		z = z - (z*z-f)/(2*z)
	}
	return z, nil
}

func main() {
	fmt.Println(Sqrt(0.04))
	fmt.Println(Sqrt(2))
	fmt.Println(Sqrt(4))
	fmt.Println(Sqrt(-2))
}
