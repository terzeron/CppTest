#include <cassert>
#include <string>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/range/iterator_range.hpp>

namespace io = boost::iostreams;

int main(void)
{
    using namespace std;

    string input = "Hello World!";
    string output;
    
    io::filtering_istream in(boost::make_iterator_range(input));
    getline(in, output);
    assert(input == output);
}
