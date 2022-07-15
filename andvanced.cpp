#include <string>
#include<iostream>
#include "basics.h"

using std::string;

string singleWord(string translate)
{
  if(translate.size()==1)//checks if the word is a single letter and appropriately translates it
  {
    if(isVowl(translate[0])==true)
    return translate + "yay";
    else
    return translate + "ay";
  }
  if(isLetter(translate[0])==false)
  {
    return "";
  }
  if(isCapital(translate[0])==true)
  {
   translate = resetCaps(translate); 
  }
  if(isVowl(translate[0])== true)//this case trips when the first letter is a vowl
  {
    return translate+"yay";
  }
  else if((isVowl(translate[0]) == false) and (findFirstVowl(translate) != -1))//this case trips if the first letter is a consonant and there is a normal vowl in the word
  {
    return translate.substr(findFirstVowl(translate)) + translate.substr(0,findFirstVowl(translate)) + "ay";
  }
  else if((isVowl(translate[0]) == false) and (findFirstVowl(translate) == -1))//this case trips if the first leter is a consonant and there are no standard vowls in the word
  {
    if(findLetter(translate, 'y') == -1)//the letter y is not in the word
    {
      return translate + "ay";
    }
    else if(findLetter(translate, 'y') != -1)//the letter y is in the word
    {
      return translate.substr(findLetter(translate, 'y')) + translate.substr(0,findLetter(translate, 'y')) + "ay";
    }
  }
  return 0;
}

string translateSentence(string sentence)
{
  string passToTranslator;
  string translated;
  int position = -1;
  for(int i = 0; i < sentence.size(); i++)
  {
    if(isApostrophy(sentence[i]) == true)
    {
      sentence[i] = sentence[i];
    }
    else if(isLetter(sentence[i]) == true)
    {
      passToTranslator += sentence[i];
    }
    else if(isLetter(sentence[i]) == false)
    {
      translated += singleWord(passToTranslator) + sentence[i];
      passToTranslator = "";
      position = i;
    }
  }
  return translated;
}