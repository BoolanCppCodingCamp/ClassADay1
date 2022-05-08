#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <cstring>
#include <array>
#include "IWriter.hpp"

class CClient
{
public:
	CClient(IWriter* writer):m_writer(writer){}
	CClient() = delete;
	~CClient() {}
	CClient(const CClient&) = delete;
	CClient& operator=(const CClient&) = delete;
	CClient(CClient&&) = delete;
	CClient& operator=(CClient&&) = delete;

	bool DoProcess() {
	constexpr int BUF_SIZE = 64u;
	std::array<char, BUF_SIZE> buf = {0};
	buf.fill('A');
	m_writer->WriteAtBegin(buf.data(),BUF_SIZE);
	buf.fill('B');
	m_writer->WriteAt(BUF_SIZE/4, buf.data(),BUF_SIZE/2);
	buf.fill('E');
	m_writer->WriteEnd(buf.data(), BUF_SIZE/2);
	return true;
	}
private:
	IWriter* m_writer;
};



#endif
