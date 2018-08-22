#define add_of(c,a,b) ({ \
  typeof(a) __a=a; \
  typeof(b) __b=b; \
  (__b)<1 ? \
    ((__MIN(typeof(c))-(__b)<=(__a))?assign(c,__a+__b):1) : \
    ((__MAX(typeof(c))-(__b)>=(__a))?assign(c,__a+__b):1); \
