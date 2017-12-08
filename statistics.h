#ifndef STATISTICS_H
#define STATISTICS_H


class Statistics
{
public:
  Statistics();
  Statistics(int wins, int loses);
  inline int Wins() { return _wins; }
  inline int Loses() { return _loses; }
  void SetWins(int wins);
  void SetLoses(int loses);
  Statistics& operator+=(Statistics added);
  double WinPercentage();//Полочить процент побед лошади
private:
  int _wins, _loses;
};

#endif // STATISTICS_H
