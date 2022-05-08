#ifndef FILE_WRITER_HPP_
#define FILE_WRITER_HPP_

#include <string>
#include "IWriter.hpp"
#include "IWriteStrategy.hpp"
#include "NormalStrategy.hpp"
#include "LazyStrategy.hpp"
#include "Observable.hpp"

class CFileWriter : public IWriter, public Observable
{
public:
	CFileWriter(const std::string& filename, StrategyTag tag = StrategyTag::NORMAL);

	CFileWriter() = delete;
	~CFileWriter();

	CFileWriter(const CFileWriter&) = delete;
	CFileWriter& operator=(const CFileWriter&) = delete;
	CFileWriter(CFileWriter&&) = delete;
	CFileWriter& operator=(CFileWriter&&) = delete;

// IWriter interfaces
	int WriteAtBegin(void* data, int length) override;
	

	int WriteAt(int pos, void* data, int length) override;


	int WriteEnd(void* data, int length) override;
private:
	struct FileWriterImpl;
	FileWriterImpl* m_pImpl;
	IWriteStrategy* m_pStrategy = nullptr;
};

#endif
