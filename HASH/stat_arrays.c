void foo(int myArray[10]);

void bar(int myArray[static 10]);

/* passing null */
bar(NULL);

/* passing a larger array */
int b[11];
bar(b);
