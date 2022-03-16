#include <iostream>
#include <initializer_list>
#include <utility>

using namespace std;

template <typename T, T... I>
void print_sequence(integer_sequence<T, I...>) {
    initializer_list<bool>{ bool(cout << I << ' ')... };
    cout << endl;
}

template <int offset, typename T, T... I>
void print_offset_sequence(integer_sequence<T, I...>) {
    print_sequence(integer_sequence<T, T(I + offset)...>());
}

int main() {
    print_sequence(integer_sequence<int, 1, 2, 3>());
    print_sequence(integer_sequence<char, 'f', 'o', 'o'>());

    print_sequence(make_index_sequence<10>());
    print_sequence(make_integer_sequence<short, 10>());
    print_sequence(make_integer_sequence<short, 26>());
    print_offset_sequence<'A'>(make_integer_sequence<char, 26>());
}
