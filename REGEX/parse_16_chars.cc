inline std::uint64_t parse_16_chars(const char* string) noexcept
{
  auto chunk = _mm_lddqu_si128(
    reinterpret_cast<const __m128i*>(string)
  );
  auto zeros =  _mm_set1_epi8('0');
  chunk = chunk - zeros;

  {
    const auto mult = _mm_set_epi8(
      1, 10, 1, 10, 1, 10, 1, 10, 1, 10, 1, 10, 1, 10, 1, 10
    );
    chunk = _mm_maddubs_epi16(chunk, mult);
  }
  {
    const auto mult = _mm_set_epi16(1, 100, 1, 100, 1, 100, 1, 100);
    chunk = _mm_madd_epi16(chunk, mult);
  }
  {
    chunk = _mm_packus_epi32(chunk, chunk);
    const auto mult = _mm_set_epi16(0, 0, 0, 0, 1, 10000, 1, 10000);
    chunk = _mm_madd_epi16(chunk, mult);
  }

  return ((chunk[0] & 0xffffffff) * 100000000) + (chunk[0] >> 32);
}
