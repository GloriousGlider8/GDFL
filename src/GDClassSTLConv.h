#include "godot_cpp/classes/file_access.hpp"

#include <istream>
#include <streambuf>

class GodotFileInStreamBuf : public std::streambuf {

public:
	GodotFileInStreamBuf(godot::FileAccess *fa) {
		_file = fa;
	}
	int underflow() {
		if (_file->eof_reached()) {
			return EOF;
		} else {
			size_t pos = _file->get_position();
			uint8_t ret = _file->get_8();
			_file->seek(pos); // Required since get_8() advances the read head.
			return ret;
		}
	}
	int uflow() {
		return _file->eof_reached() ? EOF : _file->get_8();
	}

private:
	godot::FileAccess *_file;
};

class MemoryStreamBuf : public std::streambuf {
public:
	MemoryStreamBuf(const uint8_t* data, size_t size) {
		char* begin = reinterpret_cast<char*>(const_cast<uint8_t*>(data));
		this->setg(begin, begin, begin + size);
	}
};

class MemoryIStream : public std::istream {
public:
	MemoryIStream(const uint8_t* data, size_t size)
		: std::istream(&buffer), buffer(data, size) {
		rdbuf(&buffer);
	}
private:
	MemoryStreamBuf buffer;
};