#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/stream_buffer.hpp>

namespace io = boost::iostreams;

class my_device { /* */ };

typedef io::stream<my_device> my_stream;
typedef io::stream_buffer<my_device> my_streambuf;

