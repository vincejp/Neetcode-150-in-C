#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int findOccurences(char *s, int s_len, char c) {
  int occurences = 0;
  for (int i = 0; i < s_len; i++) {
    if (s[i] == c) {
      occurences += 1;
    }
  }
  return occurences;
}

bool isAnagram(char *s, char *t) {
  int str_len_s = strlen(s);
  int str_len_t = strlen(t);
  if (str_len_s != str_len_t) {
    return false;
  } else if (str_len_s == 0 || str_len_t == 0) {
    return false;
  }

  for (int i = 0; i < str_len_s; i++) {
    if (findOccurences(s, str_len_s, s[i]) !=
        findOccurences(t, str_len_t, s[i])) {
      return false;
    }
  }
  return true;
}

int main(void) {
  // Test cases
  char *s = "racecar";
  char *t = "carrace";
  printf("%d\n", isAnagram(s, t));
  s = "jam";
  t = "jar";
  printf("%d\n", isAnagram(s, t));
  s = "";
  t = "jar";
  printf("%d\n", isAnagram(s, t));
  s = "";
  t = "";
  printf("%d\n", isAnagram(s, t));
  s = "raj";
  t = "jar";
  printf("%d\n", isAnagram(s, t));
}
