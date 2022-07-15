#include <iostream>
#include <string>
using std::string;

bool isLetter(char character)//tests if a character is a letter
{
  if((character >= 'a' and character <= 'z') or (character >= 'A' and character <= 'Z'))
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool isCapital(char letter)//tests if a given character is a capital letter
{
  if(letter >= 'A' and letter <= 'Z')
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool isVowl(char letter)//tests if a character is a capital letter
{
  if(letter=='a' or letter=='e' or letter=='i' or  letter=='o' or letter=='u' or letter=='A' or letter=='E' or letter=='I' or letter=='O' or letter=='U')
  {
    return true;
  }
  else return false;
}
int findFirstVowl(string word)//returns the position of the first vowl if the word doesn't have a vowl it returns -1
{
  for(int i = 0; i < word.size(); i++)
  {
    if(isVowl(word[i]) == true)
    {
      return i;
    }
  }
  return -1;
}
bool isApostrophy(char character)//frick apostrophies
{
  if(character == '\'')
  {
    return true;
  }
  return false;
}
int findLetter(string word, char letter)//finds the first time a given letter happens in a givne word and returns its position if the letter isn't in that word it returns -1
{
  for(int i = 0; i < word.size(); i++)
  {
    if(word[i] == letter)
    {
      return i;
    }
  }
  return -1;
}
string resetCaps(string word)//sets the first vowl of a word to capital if the first letter of a word is capitalized.
{
  if(isCapital(word[0])== true )
  {
    word[0] = tolower(word[0]);
    word[findFirstVowl(word)] = toupper(word[findFirstVowl(word)]);
    return word;
  }
  return word;
}
bool isAllCaps(string word)
{
  int count = 0;
  for(int i = 0; i < word.size(); i++)
  {
    if(isCapital(word[i]) == true)
    {
      count++;
    }
  }
  if(count == word.size())
  {
    return true;
  }
  else
  {
  return false;
  }
}