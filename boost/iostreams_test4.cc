#include <boost/iostreams/concepts.hpp>

class my_source : public source {
public:
    std::streamsize read(char* s, std::streamsize n);
    
    /* Other members */
}
