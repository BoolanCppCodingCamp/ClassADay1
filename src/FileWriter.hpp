#ifndef FILE_WRITER_HPP_
#define FILE_WRITER_HPP_

#include <string>
#include "IWriter.hpp"
#include "IWriteStrategy.hpp"
#include "NormalStrategy.hpp"
#include "LazyStrategy.hpp"


class CFileWriter : public IWriter
{
public:
	CFileWriter(const std::string& filename, StrategyTag tag = StrategyTag::NORMAL):
	m_fileName(filename)
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

	CFileWriter() = delete;

	~CFileWriter()  
	{
		if ( m_pStrategy != nullptr )
		{
			delete m_pStrategy;
		}
	}

	CFileWriter(const CFileWriter&) = delete;
	CFileWriter& operator=(const CFileWriter&) = delete;
	CFileWriter(CFileWriter&&) = delete;
	CFileWriter& operator=(CFileWriter&&) = delete;

// IWriter interfaces
	int WriteAtBegin(void* data, int length) override {
		m_pStrategy->OnWriteAt(0, data, length);
		std::cout << "write" << length << " bytes at file begin" << std::endl;
		return length;
	}

	int WriteAt(int pos, void* data, int length) override{
		m_pStrategy->OnWriteAt(0, data, length);
		std::cout << "write" << length << " bytes at" << std::endl;
		return length;
	}


	int WriteEnd(void* data, int length) override{
		m_pStrategy->OnWriteAt(0, data, length);
		std::cout << "write" << length << " bytes at file end" << std::endl;
		return length;
	}
private:
	std::string m_fileName;
	IWriteStrategy* m_pStrategy = nullptr;

};


#endif
