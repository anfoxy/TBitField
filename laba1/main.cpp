#include "BitFiled.h"
#include "Set.h"
#include <iomanip>
#include <conio.h>


void main() {
  setlocale(LC_ALL, "Russian");
  TBitField f(1000);
  f.SetBit(100);
  int k, count, na, m;
  cout << "������������ �������� ��������� ���������" << endl;
  cout << "������ ����������" << endl;
  cout << "������� ������� ������� ����� �������� - ";
  cout << "����: ";
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
 
  cout << "����� �� ����� ���������" << endl;
  cout << pna << endl << endl;
  cout << "����� �� ����� ������� �����" << endl;
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
  cout << "����� " << na << " �����. " << " �� ��� " << count << " �������." << endl;
  getchar();
  getchar();
}