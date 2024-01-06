#include <stdio.h>
#include <string.h>
#define CHAR_SIZE 256
// Function to compute the maximum of two integers
int max(int a, int b) {
return (a > b) ? a : b;
}
// Function to preprocess the bad character heuristic table
void badCharHeuristic(char* pattern, int patternLength, int badChar[CHAR_SIZE]) {
int i;
for (i = 0; i < CHAR_SIZE; i++) {
badChar[i] = -1;
}
for (i = 0; i < patternLength; i++) {
badChar[(int)pattern[i]] = i;
}
}
// Function to perform pattern matching using Boyer-Moore algorithm
void boyerMooreSearch(char* text, char* pattern) {
int textLength = strlen(text);
int patternLength = strlen(pattern);
int badChar[CHAR_SIZE];
badCharHeuristic(pattern, patternLength, badChar);
int shift = 0;
while (shift <= (textLength - patternLength)) {int j = patternLength - 1;
while (j >= 0 && pattern[j] == text[shift + j]) {
j--;
}
if (j < 0) {
printf("Pattern found at index %d\n", shift);
shift += (shift + patternLength < textLength) ? patternLength - badChar[text[shift +
patternLength]] : 1;
} else {
shift += max(1, j - badChar[text[shift + j]]);
}
}
}
int main() {
char text[] = "AABAACAADAABAAABAA";
char pattern[] = "AABA";
boyerMooreSearch(text, pattern);
return 0;
}