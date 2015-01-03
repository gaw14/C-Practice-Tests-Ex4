//implementation file

#include <iostream>
#include <cstring>
#include <cctype>
#include "braille.h"

using namespace std;

//-------------------------------------------------------------------------------
int encode_character(const char ch, char braille[])
{
  if(isalpha(ch))
    {
      if(isupper(ch))
	{
	  upper_case(ch, braille);
	  return 12;
	}
      else
	{
	  lower_case(ch, braille);
	  return 6;
	}
    }
  else if(isdigit(ch))
    {
      digit(ch,braille);
      return 12;
    }
  else if(ispunct(ch))
    {
      punc(ch, braille);
      return 6;
    }
  else
    {
      strcpy(braille,"......");
      return 6;
    }
}
//-------------------------------------------------------------------------------
void upper_case(const char ch, char braille[])
{
  lower_case(tolower(ch), braille);
  for(int i=6; i>=0; i--)
    {
      braille[i+6] = braille[i];
    }
  braille[0] = '.';
  braille[1] = '.';
  braille[2] = '.';
  braille[3] = '.';
  braille[4] = '.';
  braille[5] = '0';
  
}
//-------------------------------------------------------------------------------
void lower_case(const char ch, char braille[])
{
  switch(ch)
    {
    case('a'): strcpy(braille, "0....."); break;
    case('b'): strcpy(braille, "00...."); break;
    case('c'): strcpy(braille, "0..0.."); break;
    case('d'): strcpy(braille, "0..00."); break;
    case('e'): strcpy(braille, "0...0."); break;
    case('f'): strcpy(braille, "00.0.."); break;
    case('g'): strcpy(braille, "00.00."); break;
    case('h'): strcpy(braille, "00..0."); break;
    case('i'): strcpy(braille, ".0.0.."); break;
    case('j'): strcpy(braille, ".0.00."); break;
    case('k'): strcpy(braille, "0.0..."); break;
    case('l'): strcpy(braille, "000..."); break;
    case('m'): strcpy(braille, "0.00.."); break;
    case('n'): strcpy(braille, "0.000."); break;
    case('o'): strcpy(braille, "0.0.0."); break;
    case('p'): strcpy(braille, "0000.."); break;
    case('q'): strcpy(braille, "00000."); break;
    case('r'): strcpy(braille, "000.0."); break;
    case('s'): strcpy(braille, ".000.."); break;
    case('t'): strcpy(braille, ".0000."); break;
    case('u'): strcpy(braille, "0.0..0"); break;
    case('v'): strcpy(braille, "000..0"); break;
    case('w'): strcpy(braille, ".0.000"); break;
    case('x'): strcpy(braille, "0.00.0"); break;
    case('y'): strcpy(braille, "0.0000"); break;
    case('z'): strcpy(braille, "0.0.00"); break;
    }
}
//-------------------------------------------------------------------------------
void digit(const char ch, char braille[])
{
  lower_case(ch-'1'+'a', braille);
  for(int i=6; i>=0; i--)
    {
      braille[i+6] = braille[i];
    }
  braille[0] = '.';
  braille[1] = '.';
  braille[2] = '0';
  braille[3] = '0';
  braille[4] = '0';
  braille[5] = '0';
}
//-------------------------------------------------------------------------------
void punc(const char ch, char braille[])
{
  switch(ch)
    {
    case('.'): strcpy(braille, ".0..00"); break;
    case(','): strcpy(braille, ".0...."); break;
    case(';'): strcpy(braille, ".00..."); break;
    case('-'): strcpy(braille, "..0..0"); break;
    case('!'): strcpy(braille, ".00.0."); break;
    case('?'): strcpy(braille, ".00..0"); break;
    case('('): strcpy(braille, ".00.00"); break;
    case(')'): strcpy(braille, ".00.00"); break;
    default:   strcpy(braille, "......"); break;
    }
}
//-------------------------------------------------------------------------------
void encode(const char* plaintext, char braille[])
{
  char letter[12];
  int length;
  int i,j;
  
  if(*plaintext=='\0')
    {
      cout << "here" << endl;
      //do nothing
    }
  else
    {
      for(i=0; braille[i]!='\0';i++)
	{
	  //do nothing - loop's sole purpose is to find end of string
	}
      cout << "End of braille string is index " << i << endl;
      length = encode_character(*plaintext, letter);
      cout << "String to add is : " << letter << endl;
      
      for(j=0; j<length; j++)
	{
	  cout << "j: " << j << endl;
	  braille[i+j] = letter[j];
	}
      braille[i+j] = '\0';
      cout << "String so far: " << braille << endl;
      
      plaintext++;
      encode(plaintext, braille);
      cout << "Exiting function with letter " << letter << endl;
      cout << "Full string is: " << braille << endl;
    }
}
//-------------------------------------------------------------------------------
/*void encode(const char* plaintext, char* braille)
{
  char letter[12];
//-------------------------------------------------------------------------------
