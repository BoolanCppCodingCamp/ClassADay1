#include <string>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "FileWriter.hpp"
#include "IWriter.hpp"
#include "IWriteStrategy.hpp"
#include "NormalStrategy.hpp"
#include "LazyStrategy.hpp"
#include "Event.hpp"


struct CFileWriter::FileWriterImpl
{
	FileWriterImpl(const std::string& filename)
	{
		assert(m_fp = std::fopen(filename.c_str(), "wb")); //NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay, cppcoreguidelines-owning-memory)
	}

	~FileWriterImpl()
	{
		std::fclose(m_fp); //NOLINT(cppcoreguidelines-owning-memory)
	}

	FileWriterImpl(const FileWriterImpl&) = delete;
	FileWriterImpl& operator=(const FileWriterImpl&) = delete;
	FileWriterImpl(FileWriterImpl&&) = delete;
	FileWriterImpl& operator=(FileWriterImpl&&) = delete;
	FILE* m_fp;

	int WriteAtBegin(void* data, int length) {
		fseek(m_fp, 0, SEEK_SET);
		return fwrite(data, sizeof(char), length, m_fp);
	}

	int WriteEnd(void* data, int length) {
		fseek(m_fp, 0, SEEK_END);
		int rc = fwrite(data, sizeof(char), length, m_fp);
	        fwrite("\n", sizeof(char), 1, m_fp);
		return rc + 1;
	}
};



CFileWriter::CFileWriter(const std::string& filename, StrategyTag tag):
m_pImpl(new FileWriterImpl(filename))
		
{
	if ( tag == StrategyTag::NORMAL )
	{
		m_pStrategy = new NormalStrategy{};
	}
	else
	{
		m_pStrategy = new LazyStrategy{};
	}

}

CFileWriter::~CFileWriter()  
{
	delete m_pImpl;
	if ( m_pStrategy != nullptr )
	{
		delete m_pStrategy;
	}
}


// IWriter interfaces
int CFileWriter::WriteAtBegin(void* data, int length) {
	m_pStrategy->OnWriteAt(0, data, length);
	m_pImpl->WriteAtBegin(data, length);
	std::cout << "write" << length << " bytes at file begin" << std::endl;
	return length;
}

int CFileWriter::WriteAt(int pos, void* data, int length) {
	m_pStrategy->OnWriteAt(0, data, length);
	OnWrite(pos, length);
	return length;
}


int CFileWriter:: WriteEnd(void* data, int length) {
	m_pStrategy->OnWriteAt(0, data, length);
	m_pImpl->WriteEnd(data, length);
	std::cout << "write" << length << " bytes at file end" << std::endl;
	return length;

}

