#include "dictionary.h"
#include <QString>

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

void fill_random(Dictionary* filled, int len){
  for (int i=0;i<len;i++)
    filled->insert(GetRandomString(),qrand()%50,qrand()%50);
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  Statistics bolid(5,3);
  Dictionary Dic_Arr;
  Dict_elem bol;
  fill_random(&Dic_Arr,8);
  Dic_Arr.print();
  return a.exec();
}
