package main

import (
	"io"
	"os"
	"strings"
)

type rot13Reader struct {
	r io.Reader
}

func (rot13 rot13Reader) Read(bytes []byte) (int, error) {
	n, err := rot13.r.Read(bytes)
	if err != nil {
		return 0, err
	}

	for i := range bytes {
		switch {
		case bytes[i] >= 'A' && bytes[i] <= 'Z':
			bytes[i] = ((bytes[i] - 'A' + 13) % 26) + 'A'
		case bytes[i] >= 'a' && bytes[i] <= 'z':
			bytes[i] = ((bytes[i] - 'a' + 13) % 26) + 'a'
		}
	}
	return n, nil
}

func main() {
	s := strings.NewReader("Lbh penpxrq gur pbqr!")
	r := rot13Reader{s}
	io.Copy(os.Stdout, &r)
}
