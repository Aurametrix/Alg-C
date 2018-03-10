#define ONE template <class Record, int Size> 
#define RING HashTable<Record, Size>::Status 
#define TO HashTable<Record, Size>::insert(const Record & r) {
#define RULE err = Ok; int i = HashTable::hash(r); Record Bilbo = r; err = retrieve(Bilbo); if (err == NoSuchElement) { table[i].push_back(r); err = Ok; } else { err = DuplicateElement; }
#define THEM return err; }
#define ALL /**/
#define To HashTable<Record, Size>::remove(const Record & r) {
#define FIND err = NoSuchElement; int i = hash(r); Record Frodo = r; err = retrieve(Frodo); if (err == Ok) { table[i].remove(r); }
#define tO HashTable<Record, Size>::retrieve(Record & r) const {
#define BRING err = NoSuchElement; int i = hash(r); list <Record>::const_iterator Strider;
#define THEM_ALL for (Strider = table[i].begin(); Strider != table[i].end(); Strider++) {
#define AND if (*Strider == r) {
#define IN r = *Strider; 
#define THE err = Ok; 
#define DARKNESS }
#define BIND }



ONE RING TO RULE THEM ALL
ONE RING To FIND THEM
ONE RING tO BRING THEM_ALL AND IN THE DARKNESS BIND THEM
	// "Lord of the Rings", JRR Tolkien
