int safe_add( int a, int b )
{
    int c = a + b;
    if ( a >= 0 && b >= 0 && c < 0 )
    {
        fprintf ( stderr, "Overflow!\n" );
    } 
    if ( a < 0 && b < 0 && c >= 0 )
    {
        fprintf ( stderr, "Underflow!\n" );
    } 
    return c;
}
