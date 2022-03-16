#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>

using namespace std;

template <typename T, size_t... I>
array<T, sizeof...(I)> make_array(T const& value, index_sequence<I...>) {
    return array<T, sizeof...(I)>{ (I, value)... };
}

template <int N, typename T>
array<T, N> make_array(T const& value) {
    return make_array(value, make_index_sequence<N>());
}

int main(void)
{
    auto array = make_array<20>(string("value"));
    copy(array.begin(), array.end(),
              ostream_iterator<string>(cout, " "));
    cout << endl;

    return 0;
}
