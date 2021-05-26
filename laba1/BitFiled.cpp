#include "BitFiled.h"

TBitField::TBitField(int len) :BitLen(len) {
  MemLen = (len + 31) / 32;
  pMem = new TELEM[MemLen];
  if (pMem != NULL) {
    for (int i = 0; i < MemLen; i++) {
      pMem[i] = 0;
    }
  }
}

TBitField::TBitField(const TBitField& bf) { // Конструктор копирования.
  BitLen = bf.BitLen;
  MemLen = bf.MemLen;
  pMem = new TELEM[MemLen];
  if (pMem != NULL) {
    for (int i = 0; i < MemLen; i++) {
      pMem[i] = bf.pMem[i];
    }
  }
}

TBitField :: ~TBitField() {
  delete pMem;
  pMem = NULL;
}

int TBitField::GetMemIndex(const int n) const {
  int r= n / 32;
  return r;
}

TELEM TBitField::GetMemMask(const int n) const {
  int ind = GetMemIndex(n);
  int res = n - ind * 32;
  res = pow(2, res);
  return res;
}

int TBitField::GetLength(void) const { // Получаем длину (к-во битов).
  return BitLen;
}

void TBitField::SetBit(const int n) {// Установливаем бит.
  if ((n > -1) && (n < BitLen)) {
    pMem[GetMemIndex(n)] |= GetMemMask(n);
  }
}


void TBitField::ClrBit(const int n) {
  if ((n > -1) && (n < BitLen)) {
    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
  }
}

int TBitField::GetBit(const int n) const { // получить значение бита
  if ((pMem[GetMemIndex(n)] & GetMemMask(n)) != NULL) {
    return 1;
  }
  return 0;
}

TBitField& TBitField :: operator=(const TBitField& bf) { // Оператор: присваивания.
  BitLen = bf.BitLen;
  if (MemLen != bf.MemLen) {
    MemLen = bf.MemLen;
    if (pMem != NULL) {
      delete pMem;
    }
    pMem = new TELEM[MemLen];
  }
  if (pMem != NULL) {
    for (int i = 0; i < MemLen; i++) {
      pMem[i] = bf.pMem[i];
    }
  }
  return *this;
}

int TBitField :: operator==(const TBitField& bf) {
  int res = 1;
  if (BitLen != bf.BitLen) {
    res = 0;
  }
  else {
    for (int i = 0; i < MemLen; i++) {
      if (pMem[i] != bf.pMem[i]) {
        res = 0; break;
      }
    }
  }
  return res;
}


TBitField TBitField :: operator|(const TBitField& bf) { // Оператор:  “или"
  int i, len;
  len = BitLen;
  if (bf.BitLen > len) {
    len = bf.BitLen;
  }
  TBitField temp(len);
  for (i = 0; i < MemLen; i++) {
    temp.pMem[i] = pMem[i];
  }
  for (i = 0; i < bf.MemLen; i++) {
    temp.pMem[i] |= bf.pMem[i];
  }
  return temp;
}


TBitField TBitField::operator&(const TBitField& bf) { // Оператор:  "и"
  int i, len;
  len = BitLen;
  if (bf.BitLen > len) {
    len = bf.BitLen;
  }
  TBitField temp(len);
  for (i = 0; i < MemLen; i++) {
    temp.pMem[i] = pMem[i];
  }
  for (i = 0; i < bf.MemLen; i++) {
    temp.pMem[i] &= bf.pMem[i];
  }
  return temp;
}


TBitField TBitField :: operator~(void) { // Оператор: отрицание
  int len;
  len = BitLen;
  TBitField temp(len);
  for (int i = 0; i < MemLen; i++) {
    temp.pMem[i] = ~pMem[i];
  }
  return temp;
}

istream& operator>>(istream& istr, TBitField& bf) {
  int i = 0;
  char ch;
  do {
    istr >> ch;
  } while (ch != ' ');
  while (1) {
    istr >> ch;
    if (ch == 'O') {
      bf.ClrBit(i++);
    }
    else if (ch == '1') {
      bf.SetBit(i++);
    }
    else {
      break;
    }
  }
  return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) {
  int len;
  len = bf.GetLength();
  for (int i = 0; i < len; i++) {
    if (bf.GetBit(i)) {
      ostr << '1';
    }
    else {
      ostr << '0';
    }
  }
  return ostr;
}