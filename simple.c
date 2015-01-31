// simple memory allocator implemented as a circular linked list

#include <stdio.h>

// header of memory block
// a block consists of SIZE bytes contiguous after SIZE's address
struct block_header {
	struct block_header *next; // next header
	unsigned size; // size of block, in bytes
} block_header;

// start of freelist
block_header* base = NULL;

// simple malloc; uses first-fit algorithm
void* simple_malloc(size_t bytes) {
	block_header* freelist = base;
	block_header* prev;
	bytes += sizeof(block_header); // need to make space for header unit also

	while (freelist != NULL) {
		if (freelist->size == bytes) {
			prev->next = freelist->next; // removes allocated block's header
			return &(freelist->size) + 1;
		} else if (freelist->size > bytes) {
			// create new header with freelist->size - size bytes
			freelist->size = freelist->size - bytes;
			return (&(freelist->size) + freelist->size/4);
		}
		prev = freelist;
		freelist = freelist->next;
	}
	// no matches, ask for new block from OS
}

// simple free; searches freelist for place to put freed block, as
// freelist is maintained in order of increasing address;
// coalesces if adjacent on either side
void simple_free(void* p) {
	block_header* freelist = base;
	block_header* prev;
	block_header* freed;
	while (freelist != NULL) {
		block_header* next = freelist->next;
		if (next == NULL) {
			// append FREED to end of list
			return;
		}
		if ((&(freelist->size)+1) > p) {
			// append FREED to previous elm in freelist
		}
		prev = freelist;
		freelist = freelist->next;
	}
	// if adjacency, combine either side or both
}


int main() {
	printf("Simple Memory Allocator\n");
	return 0;
}
