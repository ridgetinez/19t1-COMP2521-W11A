#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int isPalindrome(char *word) {
  int n = strlen(word);
  for (int i = 0; i < n/2; i++) {
    if (word[i] == word[n-i-1]) {
      continue;
    } else {
      return 0;
    }
  }
  return 1;
}

/* Main code attributed to Nicholas Hiebl: github.com/nick-hiebl */
int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Correct usage: %s <word>\n", argv[0]);
    return EXIT_FAILURE;
  }

  if (isPalindrome(argv[1])) {
    printf("yes\n");
  } else {
    printf("no\n");
  }

  return EXIT_SUCCESS;
}
