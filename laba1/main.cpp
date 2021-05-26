#include "BitFiled.h"
#include "Set.h"
#include <iomanip>
#include <conio.h>


void main() {
  setlocale(LC_ALL, "Russian");
  TBitField f(1000);
  f.SetBit(100);
  int k, count, na, m;
  cout << "Тестирование программ поддержки множества" << endl;
  cout << "Решето Эратосфена" << endl;
  cout << "Введите верхнюю границу целых значений - ";
  cout << "Ввод: ";
  cin >> na;
  TSet pna(na + 1);
 
  for (m = 2; m <= na; m++) {
    pna.InsElem(m);
  }
  
  for (m = 2; sqrt(m) <= na; m++) {
    
    if (pna.IsMember(m)) {
      for (k = 2 * m; k <= na; k += m) {
        if (pna.IsMember(k)) {
          pna.DelElem(k);
        }
      }
    }
  }
  cout << endl;
 
  cout << "Вывод на экран множества" << endl;
  cout << pna << endl << endl;
  cout << "Вывод на экран простых чисел" << endl;
  count = 0;
  k = 1;
  for (m = 2; m <= na; m++) {
    if (pna.IsMember(m)) {
      count++;
      cout << setw(3) << m << " ";
      if (k++ % 10 == 0)
        cout << endl;
    }
  }
  cout << endl;
  cout << "Всего " << na << " чисел. " << " Из них " << count << " простых." << endl;
  getchar();
  getchar();
}