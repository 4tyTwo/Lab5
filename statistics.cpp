#include "statistics.h"

Statistics::Statistics(){
  _wins = _loses = 0;
}

Statistics::Statistics(int wins, int loses){
  _wins = (wins>=0) ? wins : 0;
  _loses = (wins>=0) ? loses : 0;
}

void Statistics::SetWins(int wins){
  _wins = (wins>=0) ? wins : 0;
}

void Statistics::SetLoses(int loses){
  _loses = (loses>=0) ? loses : 0;
}

float Statistics::WinPercentage(){
  if (_loses == 0)
    return 1.0;
 return (_wins+.0)/(_wins + _loses);
}
