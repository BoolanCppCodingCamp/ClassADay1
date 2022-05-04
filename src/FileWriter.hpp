#ifndef FILE_WRITER_HPP_
#define FILE_WRITER_HPP_

#include <string>
#include "IWriter.hpp"

class CFileWriter : public IWriter
{
public:
	CFileWriter(const std::string& filename):
	m_fileName(filename)
	{

	}


	CFileWriter() = delete;

	~CFileWriter() = default;
	CFileWriter(const CFileWriter&) = delete;
	CFileWriter& operator=(const CFileWriter&) = delete;
	CFileWriter(CFileWriter&&) = delete;
	CFileWriter& operator=(CFileWriter&&) = delete;

// IWriter interfaces
	int WriteAtBegin(void* data, int length) override {
		std::cout << "write" << length << " bytes at file begin" << std::endl;
		return length;
	}

	int WriteAt(int pos, void* data, int length) override{
		std::cout << "write" << length << " bytes at" << std::endl;
		return length;
	}


	int WriteEnd(void* data, int length) override{
		std::cout << "write" << length << " bytes at file end" << std::endl;
		return length;
	}
private:
	std::string m_fileName;

};


#endif
