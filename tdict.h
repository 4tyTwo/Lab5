#ifndef TDICT_H
#define TDICT_H
#include <QCoreApplication>
template <typename T, typename T2>//Лошадь
class TDict
{
public:
  struct Dict_elem{
    T item;
    T2 key;
  };

  TDict(){
    count = 0;
    allocated = 0;
    data = NULL;
  }

  void insert(Dict_elem* _item){
    int pos=0;
    int found = 0;
    found = binary_search(0,count,_item->key);
    if (found != -1)
      data[found].item += _item->item;
    else{
      if (count != 0){
        pos = binary_search_insert(0,count,_item->key);
        transfer(pos);
        data[pos] = *_item;
      }
      else{
        if (this->count == this->allocated)
          grow();
        data[0] = *_item;
      }
      ++count;
    }
  }

  void insert(T item,T2 key){
    Dict_elem* tmp = new Dict_elem;
    tmp->item = item;
    tmp->key = key;
    insert(tmp);
    delete tmp;
  }

  T& getStats(T2 key_searched){
    int pos = binary_search(0,count,key_searched);
    pos = (pos == -1)? 0 : pos;
    return data[pos].item;
  }
  void del(T2 key_searched){
    int pos = binary_search(0,count,key_searched);
    if (pos != -1){
      for (int i = pos;i<count-1;i++)
        data[i] = data[i+1];
      --count;
    }
  }

  bool exists(T2 key_searched){
    return binary_search(0,count,key_searched) + 1;
  }

  std::vector<T2> keys(){
    std::vector<T2> _keys(count);
    for (int i=0;i<count;i++)
      _keys.push_back(data[i].key);
    return _keys;
  }

  void join(TDict joined){
    std::vector<T2> joined_keys(joined.size());
    Dict_elem tmp;
    for (int i=0;i<joined_keys.size();i++){
      tmp.item = joined.getStats(joined_keys[i]);
      tmp.key = joined_keys[i];
      insert(tmp);
    }
  }

  int size() { return count; }
  void clear() { data = NULL; }

private:
  Dict_elem* data;
  int count, allocated;
  void transfer(int index){
    if (count>=allocated)
      grow();
    if (count != 0)
      for(int i=count;i>index;i--){
        data[i]= data[i-1];
      }
  }
  void grow(int grow_by=3){
    if (grow_by < 1)
      grow_by = 1;
    Dict_elem* tmp = new Dict_elem[count+grow_by];
    for (int i=0;i<count;i++)
      tmp[i] = data[i];
    data = tmp;
    allocated += grow_by;
  }
  int binary_search_insert(int l_border,int r_border,T2 key_searched){
    if (count){
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
    else
      return 0;
  }
  int binary_search(int l_border,int r_border,T2 key_searched){
    if (count){
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
};

#endif // TDICT_H
