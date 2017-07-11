size_t hash_fast(_Char key)
{
	size_t h = 0; 
	for ( ; *key; ++key) h = 5 * h + *key;

	return h;
}
	
