package iteration

import "strings"

func Repeat(c string, n int) string {
	var repeated strings.Builder
	for range n {
		repeated.WriteString(c)
	}
	return repeated.String()
}
