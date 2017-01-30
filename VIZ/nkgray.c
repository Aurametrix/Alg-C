// inputs: base, digits, value
// output: gray
// Convert a value to a graycode with the given base and digits.
// Iterating through a sequence of values would result in a sequence
// of Gray codes in which only one digit changes at a time.
void to_gray(unsigned base, unsigned digits, unsigned value, unsigned gray[digits])
{ 
	unsigned baseN[digits];	// Stores the ordinary base-N number, one digit per entry
	unsigned i;		// The loop variable
 
	// Put the normal baseN number into the baseN array. For base 10, 109 
	// would be stored as [9,0,1]
	for (i = 0; i < digits; i++) {
		baseN[i] = value % base;
		value    = value / base;
	}
 
	// Convert the normal baseN number into the graycode equivalent. Note that
	// the loop starts at the most significant digit and goes down.
	unsigned shift = 0;
	while (i--) {
		// The gray digit gets shifted down by the sum of the higher
		// digits.
		gray[i] = (baseN[i] + shift) % base;
		shift = shift + base - gray[i];	// Subtract from base so shift is positive
	}
}
// EXAMPLES
// input: value = 1899, base = 10, digits = 4
// output: baseN[] = [9,9,8,1], gray[] = [0,1,7,1]
// input: value = 1900, base = 10, digits = 4
// output: baseN[] = [0,0,9,1], gray[] = [0,1,8,1]
