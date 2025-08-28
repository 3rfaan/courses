package main

import (
	"fmt"
	"sync"
)

type Fetcher interface {
	// Fetch returns the body of URL and
	// a slice of URLs found on that page.
	Fetch(url string) (body string, urls []string, err error)
}

type Cache struct {
	v   map[string]bool
	mux sync.Mutex
}

// SetUrlVisited sets the value for the given key.
func (m *Cache) SetUrlVisited(key string) {
	m.mux.Lock()
	m.v[key] = true
	m.mux.Unlock()
}

// UrlVisited returns the current value of the counter for the given key.
func (m *Cache) UrlVisited(url string) bool {
	m.mux.Lock()
	defer m.mux.Unlock()
	return m.v[url]
}

// Crawl uses fetcher to recursively crawl
// pages starting with url, to a maximum of depth.
func Crawl(url string, depth int, fetcher Fetcher, status chan bool, cache *Cache) {
	// Check if this url got fetched previously.
	if ok := cache.UrlVisited(url); ok {
		status <- true
		return
	}

	// Marking this url as fetched already.
	cache.SetUrlVisited(url)

	if depth <= 0 {
		status <- false
		return
	}

	body, urls, err := fetcher.Fetch(url)
	if err != nil {
		fmt.Println(err)
		status <- false
		return
	}
	fmt.Printf("found: %s %q\n", url, body)

	statuses := make([]chan bool, len(urls))
	for i, u := range urls {
		statuses[i] = make(chan bool)
		go Crawl(u, depth-1, fetcher, statuses[i], cache)
	}

	// Wait for child goroutines.
	for _, childstatus := range statuses {
		<-childstatus
	}

	status <- true
}

func main() {
	cache := Cache{v: make(map[string]bool)}
	status := make(chan bool)
	go Crawl("https://golang.org/", 4, fetcher, status, &cache)
	<-status
}

// fakeFetcher is Fetcher that returns canned results.
type fakeFetcher map[string]*fakeResult

type fakeResult struct {
	body string
	urls []string
}

func (f fakeFetcher) Fetch(url string) (string, []string, error) {
	if res, ok := f[url]; ok {
		return res.body, res.urls, nil
	}
	return "", nil, fmt.Errorf("not found: %s", url)
}

// fetcher is a populated fakeFetcher.
var fetcher = fakeFetcher{
	"https://golang.org/": &fakeResult{
		"The Go Programming Language",
		[]string{
			"https://golang.org/pkg/",
			"https://golang.org/cmd/",
		},
	},
	"https://golang.org/pkg/": &fakeResult{
		"Packages",
		[]string{
			"https://golang.org/",
			"https://golang.org/cmd/",
			"https://golang.org/pkg/fmt/",
			"https://golang.org/pkg/os/",
		},
	},
	"https://golang.org/pkg/fmt/": &fakeResult{
		"Package fmt",
		[]string{
			"https://golang.org/",
			"https://golang.org/pkg/",
		},
	},
	"https://golang.org/pkg/os/": &fakeResult{
		"Package os",
		[]string{
			"https://golang.org/",
			"https://golang.org/pkg/",
		},
	},
}
