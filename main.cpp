#include <QCoreApplication>
#include "dictionary.h"
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  Statistics bolid(5,3);
  Dictionary Dic_Arr;
  Dict_elem bol;
  bol.key="c";
  bol.stats = bolid;
  Dic_Arr.insert(&bol);
  bol.key="a";
  Dic_Arr.print();
  std::cout<<std::endl;
  Dic_Arr.insert(&bol);
  bol.key="z";
  Dic_Arr.print();
  std::cout<<std::endl;
  Dic_Arr.insert(&bol);
  Dic_Arr.print();
  std::cout<<std::endl;
  bol.key="f";
  Dic_Arr.insert(&bol);
  Dic_Arr.print();
  std::cout<<std::endl;
  bol.key="d";
  bol.stats.SetLoses(2);
  Dic_Arr.insert(&bol);
  Dic_Arr.print();
  std::cout<<std::endl;
  std::cout<<Dic_Arr.getStats("d").WinPercentage()<<std::endl;
  return a.exec();
}
