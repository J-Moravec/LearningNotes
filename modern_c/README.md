# Modern C (Jens Gustedt, 2019)

In the book, exercises are presented as footnotes, which are numbered according to *Level*, not chapter. Not all footnotes are excercises, so do not search for exercises 1 and 2, they don't exist. Not all exercise are coding ones, so there is no program for each single one.

## Exercise

### Level 0. Encounter

Exercise 3 is just a compilation.

Exercise 4 is "taking notes", so here are the notes.

Exercise 6 is to correct the program.

Exercise 7 is to compare the programs from exercise 3 and 6 (after correcting) and explain the difference. The difference is the instantiated `int i` outside the loop instead of `size_t i` within the loop. I fixed thsi in the exercise 6 anyway since this is usually a bad style.

Exercise 8 is the explan differences between `[]` and `{}` in listing 1.1. The `[]` are used in two contexts, both for arrays. One is for instantiation of array, where `int arr[len]` specify array of size `len`, the second is for accessing the `i` element of array `int element = arr[i]. The `{}` are used in two contexts, one is to denote a block of code and another for element-wise instantiation of an array.

### Level 1. Acquaintance
