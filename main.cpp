#include <tdict.h>
#include <QString>
#include <iostream>
#include "statistics.h"
QString GetRandomString()
{
   QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
   int randomStringLength = 7; // assuming you want random strings of 12 characters

   QString randomString;
   for(int i=0; i<randomStringLength; ++i)
   {
       int index = qrand() % possibleCharacters.length();
       QChar nextChar = possibleCharacters.at(index);
       randomString.append(nextChar);
   }
   return randomString;
}

//void fill_random(Tdict* filled, int len){
//  for (int i=0;i<len;i++)
//    filled->insert(GetRandomString(),qrand()%50,qrand()%50);
//}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  Statistics bol(5,3);
  TDict<Statistics,std::string> dict;
  std::string b = "g";
  dict.insert(bol,"g");
  dict.insert(bol,b);
  dict.del(b);
  if (dict.exists(b))
    std::cout<<dict.getStats(b).Wins();
  return a.exec();
}
