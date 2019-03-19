void copy(
char∗ dst : byte count(n),
const char∗ src : byte count(n),
size t n);
 
/* (a) copy prototype  */

struct buf
{
Array ptr<char> dat
: count(sz−1);
unsigned int len ;/∗ len≤ sz ∗/
unsigned int sz ;
};

/*  (b) Type definition */

static char region [MAX]; // unchecked
 static unsigned int idx = 0;

 Checked void alloc buf(
 Ptr<struct buf> q,
 Array ptr<const char> src : count(len),
 unsigned int len)
 {
 if (len > q→ sz) {
 if (idx < MAX && len ≤ MAX − idx) {
 Unchecked {
 q→ dat = &region[idx];
 q→ sz = len;
 }
 idx += len;
 } else {
 bug(”out of region memory”);
 }
 }
 copy(q→ buf, src , len);
 q→ len = len;
 }
