void memset(void *s,int c,size_t n)
{
  unsigned char *m = s;

  while(n--)
    *m++ = c;

  return s;
}
