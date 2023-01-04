#include <algorithm>

using namespace std;

class StackEmpty : public std::exception {
 public:
  const char* what() const throw() { return "Stack is empty"; }
};

class StackTooShort : public std::exception {
 public:
  const char* what() const throw() { return "Not enough elements in stack"; }
};
class MyStack {
 private:
  vector<int> stack_a;
  vector<int> stack_b;

 public:
  // Méthodes pour set et get stack_a
  void set_stack_a(vector<int> stack_a) { this->stack_a = stack_a; }
  vector<int> get_stack_a() { return stack_a; }

  // Méthodes pour set et get stack_b
  void set_stack_b(vector<int> stack_b) { this->stack_b = stack_b; }
  vector<int> get_stack_b() { return stack_b; }

  // Méthodes pour accéder aux éléments de stack_a
  int front_a() {
    if (stack_a.empty()) throw StackEmpty();

    return stack_a.front();
  }
  int back_a() {
    if (stack_a.empty()) throw StackEmpty();

    return stack_a.back();
  }

  // Méthodes pour accéder aux éléments de stack_b
  int front_b() {
    if (stack_b.empty()) throw StackEmpty();

    return stack_b.front();
  }
  int back_b() {
    if (stack_b.empty()) throw StackEmpty();

    return stack_b.back();
  }

  // Méthodes pour intervertir les deux premiers éléments de stack_a et stack_b
  void sa() {
    if (stack_a.empty()) throw StackEmpty();

    if (stack_a.size() == 1) throw StackTooShort();

    if (stack_a.size() > 1) {
      std::swap(stack_a.front(), *(++stack_a.begin()));
    }
  }

  void sb() {
    if (stack_b.empty()) throw StackEmpty();

    if (stack_b.size() == 1) throw StackTooShort();

    if (stack_b.size() > 1) {
      std::swap(stack_b.front(), *(++stack_b.begin()));
    }
  }

  // Méthodes pour déplacer le premier élément de stack_b sur stack_a et vice
  // versa
  void pa() {
    if (stack_a.empty()) throw StackEmpty();

    stack_b.insert(stack_b.begin(), stack_a.front());
    stack_a.erase(stack_a.begin());
  }
  void pb() {
    if (stack_b.empty()) throw StackEmpty();

    stack_a.insert(stack_a.begin(), stack_b.front());
    stack_b.erase(stack_b.begin());
  }

  // Méthodes pour faire une rotation de stack_a et stack_b sur un élément
  void ra() {
    if (stack_a.empty()) throw StackEmpty();

    if (stack_a.size() == 1) throw StackTooShort();

    rotate(stack_a.begin(), stack_a.begin()+1, stack_a.end());
  }
  void rb() {
    if (stack_b.empty()) throw StackEmpty();

    if (stack_b.size() == 1) throw StackTooShort();

    rotate(stack_b.begin(), stack_b.begin()+1, stack_b.end());
  }

  // Méthodes pour faire une rotation inverse de stack_a et stack_b sur un
  // élément
  void rra() {
    if (stack_a.empty()) throw StackEmpty();

    if (stack_a.size() == 1) throw StackTooShort();

    rotate(stack_a.end(), stack_a.begin()+1, stack_a.begin());
  }
  void rrb() {
    if (stack_b.empty()) throw StackEmpty();

    if (stack_b.size() == 1) throw StackTooShort();

    rotate(stack_b.end(), stack_b.begin()+1, stack_b.begin());
  }
};
// Exceptions
