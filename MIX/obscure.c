#define CAT(x, y) _CAT(x, y)
#define _CAT(x, y) x ## y

#define SUCC(n) _SUCC ## n
#define _SUCC0 1
#define _SUCC1 2
#define _SUCC2 3

struct Test {
  char const *name;
  int (*fn)(void);
  struct Test *next;
};

#define TEST(id) _TEST(id, __COUNTER__)
#define _TEST(id, n) \
static struct Test CAT(test_, SUCC(n)); \
static int id(void); \
static struct Test CAT(test_, n) = { #id, &id, CAT(&test_, SUCC(n)) }; \
static int id(void)

TEST(add)
{
  return 0 + 1 == 1;
}

TEST(sub)
{
  return 1 - 1 == 1;
}

#include <stdio.h>

int main(void)
{
  struct Test *test = &test_0;
  while (test->name) {
    printf("%s: %s\n", test->name, test->fn() ? "pass" : "fail");
    test = test->next;
  }
}
