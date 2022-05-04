#ifndef MEM_WRITER_HPP_
#define MEM_WRITER_HPP_

#include <string>
#include "IWriter.hpp"

class CMemWriter : public IWriter
{
public:
	CMemWriter() = default;
	~CMemWriter() = default;
	CMemWriter(const CMemWriter&) = delete;
	CMemWriter& operator=(const CMemWriter&) = delete;
	CMemWriter(CMemWriter&&) = delete;
	CMemWriter& operator=(CMemWriter&&) = delete;

// IWriter interfaces
	int WriteAtBegin(void* data, int length) override {
		std::cout << "write" << length << " bytes at memory begin" << std::endl;
		return length;
	}

	int WriteAt(int pos, void* data, int length) override{
		std::cout << "write" << length << " bytes at memory" << std::endl;
		return length;
	}


	int WriteEnd(void* data, int length) override{
		std::cout << "write" << length << " bytes at memory end" << std::endl;
		return length;
	}
private:
	std::string m_fileName;
};


#endif
