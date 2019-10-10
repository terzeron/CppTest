#include <algorithm>
#include <iosfwd>
#include <boost/iostreams/categories.hpp>

namespace boost { namespace iostreams { namespace example {
    
    template<typename Container>
    class container_source {
    public:
	typedef typename Container::value_type char_type;
	typedef source_tag category;
	container_source(Container& container) : 
	    container_(container), pos_(0) {
	}
	
	std::streamsize read(char_type* s, std::streamsize n) {
	    using namespace std;
	    streamsize amt = static_cast<streamsize>(container_.size() - pos_);
	    streamsize result = (min)(n, amt);
	    if (result != 0) {
		std::copy(container_.begin() + pos_,
			  container_.begin() + pos_ + result, s);
		pos_ += result;
		return result;
	    } else {
		return -1;
	    }
	}

	Container& container() { 
	    return container_;
	}

    private:
	typedef typename Container::size_type size_type;
	Container& container_;
	size_type pos_;
    };
} } } // boost::iostreams::example

	    
	
