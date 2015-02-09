/** @brief the hidden implementation of the circular buffer type
    */
struct circular {
s i z e _ t start; /**< position of element 0 */
s i z e _ t len; /**< number of elements stored */
s i z e _ t max_len; /**< maximum capacity */

circular* circular_init(circular* c, s i z e _ t max_len) {
 if (c) {
 if (max_len) {
 *c = (circular){
 .max_len = max_len,
 .tab = m all oc(sizeof(double[max_len])),
 };
 // allocation failed
 if (!c->tab) c->max_len = 0;
 } else {
 *c = (circular){ 0 };
 }
 }
 return c;
