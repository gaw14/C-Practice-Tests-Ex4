//header file

#ifndef BRAILLE_H
#define BRAILLE_H

//function to convert an input character, 'ch', to its equivalent in braille. Function
//returns an integer which is the length of the 'braille' string
int encode_character(const char ch, char braille[]);

void upper_case(const char ch, char braille[]);

void lower_case(const char ch, char braille[]);

void digit(const char ch, char braille[]);

void punc(const char ch, char braille[]);

void encode(const char* plaintext, char braille[]);

#endif
