#include <iostream>
#include <string>
#include <fstream>
#include "advanced.h"


using namespace std;

int main()
{
  ofstream fout;
  string translate;
  
  cout<<"Welcome to my Pig Latin translator! Please type a sentence.\n";
  getline(cin,translate);
  cout<<translateSentence(translate);
  fout.open("translated.txt");
  fout<<translateSentence(translate);
  fout.close();

}//end of main