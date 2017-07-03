OPHeap* heap;
// Initialize a 64GB OPIC heap via mmap
OPHeapNew(&heap);
// pointer for accessing the object
int *a_ptr = OPMalloc(heap, sizeof(int));
// deallocate an object does not require specifying the heap
OPDealloc(a_ptr);

void OPHeapWrite(OPHeap* heap, FILE* stream);
bool OPHeapRead(OPHeap** heap_ref, FILE* stream);

// Convert the pointer to a offset to the OPHeap base address
// The pointer must be a pointer created by OPHeap
opref_t a_ref = OPPtr2Ref(a_ptr);
// Add the offset a_ref with OPHeap base address to restore
// the pointer.
int* a_ptr = OPRef2Ptr(heap, a_ref);

**
 * @relates OPHeap
 * @brief Store a pointer to a root pointer slot in OPHeap.
 *
 * @param heap OPHeap instance.
 * @param ptr the pointer we want to store in root pointer slot.
 * @param pos index in the root pointer slot. 0 <= pos < 8.
 */
void OPHeapStorePtr(OPHeap* heap, void* ptr, int pos);

/**
 * @relates OPHeap
 * @brief Restore a pointer from specified root pointer slot.
 *
 * @param heap OPHeap instance.
 * @param pos index in the root pointer slot. 0 <= pos < 8.
 * @return The pointer we stored in the root pointer slot.
 */
void* OPHeapRestorePtr(OPHeap* heap, int pos);
