#include "async.h"

struct async pt;
struct timer timer;

async example(struct async *pt) {
    async_begin(pt);
    
    while(1) {
        if(initiate_io()) {
            timer_start(&timer);
            await(io_completed() || timer_expired(&timer));
            read_data();
        }
    }
    async_end;
}
