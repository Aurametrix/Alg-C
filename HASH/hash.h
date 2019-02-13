// 32-bit perfect hash
uint32_t hash32(uint32_t key) {
    __m128i hash_32 = _mm_set1_epi32(key);
    hash_32 = _mm_aesenc_si128(hash_32, _mm_set1_epi32(0xDEADBEEF));
    return *reinterpret_cast<uint32_t*>(&hash_32);
}

// 16-bit perfect hash
uint16_t hash16(uint16_t key) {
    __m128i hash_16 = _mm_set1_epi16(key);
    hash_16 = _mm_aesenc_si128(hash_16, _mm_set1_epi32(0xDEADBEEF));
    return *reinterpret_cast<uint16_t*>(&hash_16);
}

// 8-bit perfect hash
uint8_t hash8(uint8_t key) {
    __m128i hash_8 = _mm_set1_epi8(key);
    hash_8 = _mm_aesenc_si128(hash_8, _mm_set1_epi32(0xDEADBEEF));
    return *reinterpret_cast<uint8_t*>(&hash_8);
}

// 64-bit perfect hash
uint64_t hash64(uint64_t key) {
    __m128i hash_64 = _mm_set1_epi64x(key);
    hash_64 = _mm_aesenc_si128(hash_64, _mm_set1_epi32(0xDEADBEEF));
    hash_64 = _mm_aesenc_si128(hash_64, _mm_set1_epi32(0xDEADBEEF));
    return *reinterpret_cast<uint64_t*>(&hash_64);
}
