#include "statistics.h"
#include "QString"
#include <iostream>
#ifndef DICTIONARY_H
#define DICTIONARY_H

struct Dict_elem
{
  QString key;
  Statistics stats;
};

class Dictionary{
public:
  Dictionary();
  void insert(const Dict_elem* item);
  void print();
  //void insert(QString key_new, Statictics stats_new);
  //void insert(QString key_new, int wins, int loses);
  Statistics& getStats(QString key_searched);
  //Statistics& operator[](QString key_searched);
  //void del(QString key_searched);
private:
  void grow(int grow_by = 3);
  int binary_search_insert(int l_border,int r_border,QString key_searched);
  int binary_search(int l_border,int r_birder,QString key_searched);
  void transfer(int index);
  Dict_elem* data;
  int count, allocated;
};

#endif // DICTIONARY_H