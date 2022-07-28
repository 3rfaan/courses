
#define ALLOCSIZE 10000  // size of available space

static char allocbuf[ALLOCSIZE];  // storage for alloc
static char *allocp = allocbuf;   // next free position

int main(void) { return 0; }

/* alloc: return pointer to n characters */
char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {  // it fits
        allocp += n;
        return allocp - n;  // old p
    } else                  // not enough room
        return 0;
}

/* falloc: return pointer to n characters of type float */
float *falloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return (float *)allocp - n;  // old p
    } else                           // not enough room
        return 0;
}

/* afree: free storage pointed to by p */
void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}