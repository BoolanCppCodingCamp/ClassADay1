#ifndef I_WRITER_HPP_
#define I_WRITER_HPP_

class IWriter
{
public:
	IWriter() = default;
	IWriter(const IWriter&) = default;
	IWriter& operator=(const IWriter&) = default;
	IWriter(IWriter&&) = delete;
	IWriter& operator=(IWriter&&) = delete;

	virtual int WriteAtBegin(void* data, int length) = 0;
	virtual int WriteAt(int pos, void* data, int length) = 0;
	virtual int WriteEnd(void* data, int length) = 0; 
	virtual ~IWriter() {};

};


#endif
