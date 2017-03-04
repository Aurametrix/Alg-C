key = 0;
for (i = 0; i < (M + 1); i++)
{
    key = (key << d) ^ (string[i]);
    key %= hash size;
}
