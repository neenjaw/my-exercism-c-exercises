#include "isogram.h"

bool is_isogram(const char phrase[])
{
  if (phrase == NULL) return false;

  const char *alpha = ""
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  char ch, used[26] = {0};

  while ((ch = *phrase++) != '\0') {
    const char *p;
    int idx;

    if ((p = strchr(alpha, ch)) == NULL)
      continue;

    // This works because p is the pointer to the location of the match in the string
    // alpha is the pointer to the start of the alphabet string
    // p-alpha is the offset from the start of the alpha string (which letter matches)
    // p-alpha % 26 is the offset in the case insensitive alphabet represented by 'char used[]'
    printf("-- %s %s %ld %ld\n", p, alpha, (p-alpha), ((p - alpha) % 26));

    idx = (p - alpha) % 26;

    if (used[idx])
      return false;

    used[idx] = true;
  }

  return true;
}

