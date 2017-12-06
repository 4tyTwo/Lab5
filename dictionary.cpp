#include "dictionary.h"

Dictionary::Dictionary(){
  count = allocated = 0;
  data = NULL;
}

void Dictionary::grow(int grow_by){
  if (grow_by < 1)
    grow_by = 1;
  Dict_elem* tmp = new Dict_elem[count+grow_by];
  for (int i=0;i<count;i++)
    tmp[i] = data[i];
  data = tmp;
  allocated += grow_by;
}

int Dictionary::binary_search_insert(int l_border, int r_border, QString key_searched){
  int mid = (l_border + r_border)/2;
  if (data[mid].key > key_searched)
    if (mid == l_border)
      return mid;
    else
      return binary_search_insert(l_border,mid,key_searched);
 else
    if (mid==l_border)
      return mid+1;
    else
      return binary_search_insert(mid,r_border,key_searched);
}

void Dictionary::transfer(int index){
  if (count>=allocated)
      grow();
  if (count != 0)
    for(int i=count;i>index;i--){
      data[i]= data[i-1];
    }
 }

void Dictionary::insert(const Dict_elem* item){
  int pos=0;
  if (count != 0)
    pos = binary_search_insert(0,count,item->key);
  transfer(pos);
  if (count >= allocated)
    grow();
  data[pos] = *item;
  ++count;
}

void Dictionary::insert(QString key_new, Statistics stats_new){
  Dict_elem* item = new Dict_elem;
  item->key = key_new;
  item->stats = stats_new;
  insert(item);
  delete item;
}

void Dictionary::insert(QString key_new, int wins, int loses){
  Dict_elem* item = new Dict_elem;
  item->key = key_new;
  item->stats.SetLoses(loses);
  item->stats.SetWins(wins);
  insert(item);
  delete item;
}

Statistics& Dictionary::getStats(QString key_searched){
  int pos = binary_search(0,count,key_searched);
  pos = (pos == -1)? 0 : pos;
  return data[pos].stats;
}

void Dictionary::del(QString key_searched){
  int pos = binary_search(0,count,key_searched);
  if (pos != -1){
    for (int i=pos;i<count-1;i++)
        data[i] = data[i+1];
      --count;
  }
}

void Dictionary::print(){
  for (int i=0;i<count;i++)
    std::cout<<"Horse "<<data[i].key.toStdString()<<": "<<
    data[i].stats.Wins()<<" wins "<<data[i].stats.Loses()<<" loses "<<
    data[i].stats.WinPercentage()*100<< "% winrate"<<std::endl;
}

std::vector<QString> Dictionary::keys(){
  std::vector<QString> _keys(count);
  for (int i=0;i<count;i++)
    _keys.push_back(data[i].key);
  return _keys;
}

void Dictionary::join(Dictionary joined){
  std::vector<QString> joined_keys(joined.size());
  for (int i=0;i<joined.size();i++)
    if (binary_search(0,count,joined_keys[i])==-1)
      insert(joined_keys[i],joined[joined_keys[i]]);
}

int Dictionary::binary_search(int l_border, int r_border, QString key_searched){
  if (key_searched.length()){
  int mid = (l_border + r_border)/2;
  if (data[mid].key == key_searched)
    return mid;
  else
    if (mid!=0){
      if (data[mid-1].key < key_searched && data[mid+1].key > key_searched)
        return -1;
    }
    else
      if (data[mid+1].key > key_searched)
        return -1;
    if (data[mid].key > key_searched)
      return binary_search(l_border,mid,key_searched);
    else
      return binary_search(mid,r_border,key_searched);
  }
  else
    return -1;
}

std::vector<Dict_elem> Dictionary::elements(){
  std::vector<Dict_elem> items(count);
  for (int i=0;i<count; i++)
    items.push_back(data[i]);
  return items;
}

Dictionary::~Dictionary(){

}
