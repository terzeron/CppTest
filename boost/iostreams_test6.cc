#include <cassert>
#include <string>
#include <boost/iostreams/stream.hpp>
#include <libs/iostreams/example/container_device.hpp>

namespace io = boost::iostreams;
namespace ex = boost::iostreams::example;

int main()
{
    using namespace std;
    typedef ex::container_source<string> string_source;
    
    string input = "Hello World!";
    string output;
    io::stream<string_source> in(input);
    getline(in, output);
    assert(input == output);
}
