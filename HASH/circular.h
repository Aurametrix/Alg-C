// circular: an opaque type for a circular buffer for double values
// This data structure allows to add double values in rear and to take them out in front.
// Each such structure has a maximal amount of elements that can be stored in it.
// typedef struct circular circular;
// circular_append, _pop, _init, _destroy, _new, _delete, _resize, _getlength
//

// Circular buffer implementation by Andrej Cizov. October 2011
// primarily used in Atmega16
// You are free to reuse the code in any of the projects

typedef struct circular {
	unsigned char *b; // pointer to a buffer
	unsigned int w; // points to last written byte
	unsigned int r; // points to next to be read byte

	unsigned int mask;
} circular;

// handle -> use this to access other methods
// buffer -> where to write data sized power of two
// size -> MUST be a power of two, size of the buffer
unsigned int circular_init(circular *handle, unsigned char *buffer, unsigned int size) {
	handle->b = buffer;
	handle->w = 0;
	handle->r = 0;

	// Would be a great idea to check for the buffer size dimensions here
	handle->mask = (size - 1);

	return 1;
}

// returns number of bytes really written to the buffer
// buffer -> bytes to be written
// size -> number of bytes to be written
unsigned int circular_write(circular *handle, unsigned char *buffer, unsigned int size) {
	unsigned int n = 0;
	unsigned int next = (handle->w + 1) & handle->mask;
	while(next != handle->r && n < size) {
		handle->w = next;
		handle->b[next] = buffer[n];
		next = (handle->w + 1) & handle->mask;
		n++;
	}
	return n;
}

// read max [size] to [buffer] using [handle]
unsigned int circular_read(circular *handle, unsigned char *buffer, unsigned int size) {
	unsigned int n = 0;
	unsigned int next = (handle->r + 1) & handle->mask;
	while(handle->r != handle->w && n < size) {
		handle->r = next;
		buffer[n] = handle->b[next];
		next = (handle->r + 1) & handle->mask;
		n++;
	}
	return n;
}
