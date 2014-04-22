// char* str = "abc" vs. char str[] = "abc"
// char* str = "this is a string";
// str[1] = 'c' <-- ILLEGAL
// char str[] = "this is a string";
// str[1] = 'c' <-- LEGAL
// http://stackoverflow.com/questions/1704407/what-is-the-difference-between-char-s-and-char-s-in-c

#include <iostream>
#include <string>

using namespace std;

void reverse_word(const char* src, char** ans_)
{
  const size_t src_len = strlen(src);
  char* ans = new char[src_len + 1];
  *ans_ = ans;
  memset(ans, 0, src_len);

  const char* src_end_word = &src[src_len];
  char* ans_write_pos = &ans[0];

  //Careful: if i is unsigned int, then loop and crash --
  //         the 'is_continue' check is done after the code is run,
  //         so if i==0 is valid, then after running the 'iteration i==0'
  //         --i is executed, and i goes back to the maximum
  for(int i = src_len-1; i >= 0; --i)
  {
    if (src[i] == ' ' || i == 0)
    {
      int offset = 1;
      if(i==0)
        offset = 0;

      memcpy(ans_write_pos, &src[i + offset], src_end_word - &src[i + offset] );
      ans_write_pos = ans_write_pos + (src_end_word - &src[i + offset]) + 1;
      src_end_word = &src[i];

      if(i != 0)
        *(ans_write_pos-1) = ' ';
      else
        *(ans_write_pos-1) = '\0';
    }    
  }
}

void reverse_between(char* start, char* end)
{
  char buf = '0';
  while(end > start)
  {
    buf = *end;
    *end = *start;
    *start = buf;

    ++start;
    --end;
  }
}

void reverse_word_inplace(char* src)
{
  size_t src_len = strlen(src);

  reverse_between( &src[0], &src[src_len-1] );

  char* begin_word = &src[0];
  char* end_word = 0;

  for(size_t i = 0; i < src_len; ++i)
  {
    if(src[i] == ' ' || i == src_len-1)
    {
      end_word = &src[i-1];
      reverse_between(begin_word, end_word);
      begin_word = &src[i+1];
    }
  }
}

void reverse_words_pose_problem_test()
{
  char str[] = "A string to invert, do it well.";
  const char sol[] = "well. it do invert, to string A";

  char* ans = 0;
  reverse_word(str, &ans);

  cout<<"str: "<<str<<endl;
  cout<<"ans: "<<ans<<endl;
  cout<<"sol: "<<sol<<endl;
  if( strcmp(sol, ans) != 0 )
  {
    cerr<<"Failed!"<<endl;
  }
  else
  {
    cout<<"Success!"<<endl;
  }

  reverse_word_inplace(str);
  cout<<"str: "<<str<<endl;

  if( strcmp(sol, str) != 0 )
  {
    cerr<<"Failed!"<<endl;
  }
  else
  {
    cout<<"Success!"<<endl;
  }
}

int main()
{
  cout<<"Begin"<<endl;

  reverse_words_pose_problem_test();

  cout<<"End"<<endl;
  return 0;
}
