class CIString {
  string s;

public:
  bool operator==(const CIString& b) const {
    return s.size() == b.s.size() &&
      ci_compare(s.c_str(), b.s.c_str()) == 0;
  }
  std::weak_ordering operator<=>(const CIString& b) const {
    return ci_compare(s.c_str(), b.s.c_str()) <=> 0;
  }

  bool operator==(char const* b) const {
    return ci_compare(s.c_str(), b) == 0;
  }
  std::weak_ordering operator<=>(const char* b) const {
    return ci_compare(s.c_str(), b) <=> 0;
  }
};
