// binary buddy memory allocator implemented as a linked list
// memory is originaly a single block; then it is divided up accordingly

#include <stdio.h>

struct block_header* {
	struct block_header* next;
	struct block_header* splitbuddy;
	bool left; // is left split
	unsigned size; // must be power of 2
} block_header;

// starting block
block_header* base = NULL;

// allocates leftmost available space, or splitting necessary
void* buddy_malloc(size_t bytes) {
	block_header* buddylist = base;
	while (true) {
		while (buddylist != NULL) {
			if (bytes > .5*buddylist->size &&
				buddylist->size >= bytes) {
				// allocate leftmost block, removing it from free buddylist
				return (&buddylist->size)+1;
			}
			buddylist = buddylist->next;
		}
		buddylist = base;
		while (buddylist != NULL) {
			if (buddylist->size < bytes) {
				continue;
			} else {
				split(buddylist);
			}
			buddylist = buddylist->next;
		}
		// ask OS for more memory
	}
}

// deallocate and merge companion buddies
void buddy_free(void* p) {
	block_header* buddylist = base;
	while (buddylist != NULL) {
		if (buddylist->splitbuddy == p) {
			if (buddylist->left) {
				// append p to buddylist
			} else {
				// prepend p to buddy list
			}
		}
		buddylist = buddylist->next
	}
	// error
}

// splits block header in two
void split(block_header* b) {
	block_header->size /= 2;
	block_header->next = // new node with halved block size
}

int main() {
	printf("Binary Buddy Memory Allocator\n");
	// minimum and maximum block sizes
	unsigned min = 4;
	unsigned max = 10;
	unsigned request = 70;
	return 0;
}
