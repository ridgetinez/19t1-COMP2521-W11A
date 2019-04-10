#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long long rollingStrHash(char *s);

// h(s) -> long long value

int 
main(int argc, char **argv)  // comparing two strings, we'll have to traverse min(|s1|, |s2|)
{
    int currIndex = 0, hasDuplicate = 0;
    long long *sHashes = malloc(argc * sizeof(long long));
    for (int i = 1; i < argc; i++) {
        long long currHash = rollingStrHash(argv[i]);
        hasDuplicate = 0;
        /* Exercise: turn this loop into a hash table lookup */
        for (int j = 0; j < currIndex; j++) {
            if (sHashes[j] == currHash) {
                hasDuplicate = 1;
                break;
            }
        }
        if (hasDuplicate) {
            printf("%s\n", argv[i]);
        } else {
            sHashes[currIndex++] = currHash;
        }
    }
}

/* h(s) = s[0] + s[1]*p + s[2]*p^2 + ... s[n-1]*p^n-1 mod m */
static long long rollingStrHash(char *s)
{
    int p = 31;
    int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char *c = s; *c != '\0'; c++) {
        hash_value = (hash_value + (*c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}