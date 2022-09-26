/*
Use the ascii value to check whether a pattern is present in other string or not.

https://youtu.be/qQ8vS2btsxI?t=695 detail Explaination

We use a rolling hash function
Average case is O(m-n+1)
m = len of str1
n = len of str2

Used for pattern matching
*/

#include <iostream>
#include <cstring>
#include <string.h>
#include <algorithm>
#define d 10 // define a number
using namespace std;

void rabinKarp(char pattern[], char text[], int q)
{
    int m = strlen(pattern); // the pattern to be found
    int n = strlen(text);    // the text in which patern to be found

    int p = 0, t = 0; // initial hash for pattern and text
    int h = 1;        // hash value
    int j = 0, i = 0;
    for (i = 0; i < m - 1; i++) // iterate over length of pattern as it is small than length of text
        h = (h * d) % q;        // calculate hash value for the pattern

    // calculate hash value for pattern and text
    for (i = 0; i < m; i++) // iterate ovet length of pattern
    {
        p = (d * p + pattern[i]) % q; // pattern hash
        t = (d * t + text[i]) % q;    // text hash for size of pattern
    }

    // find match
    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m) // if we reach end of length of pattern without breaking loop i.e. match found
                cout << "pattern found at: " << i << endl;
        }
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t = t + q;
        }
    }
}

int main()
{
    char pattern[] = "ABC";
    char text[] = "PABC";
    // insted of 13 we can take any prime number
    rabinKarp(pattern, text, 13);
    return 0;
}

