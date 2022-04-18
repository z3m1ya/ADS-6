// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template <typename T, int Size>
class TPQueue {
 private:
  T arr[Size];
  int n = 0;

 public:
  void push(T item) {
    if (n >= Size) throw "full!"
    else for (int i = n++; i >= 0; i--)
      if (i > 0 && arr[i - 1].prior >= item.prior) {
        arr[i] = arr[i - 1];
      } else {
        arr[i] = item;
        break;
      }
  }
  T pop() {
    if (n <= 0) throw "empty!";
    return arr[--n];
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
