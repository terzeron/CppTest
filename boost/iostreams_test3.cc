#include <iosfwd>
#include <boost/iostreams/categories.hpp>

namespace io = boost::iostreams;

class my_source {
public:
    typedef char char_type;
    typedef source_tag category;

    std::streamsize read(char* s, std::streamsize n) {
	// Read up to n characters from the underlying data source
	// into the buffer s, returning the number of characters
	// read; return -1 to indicates EOF
    }
    
    /* Other members */
};
