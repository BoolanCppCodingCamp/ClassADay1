#include <iostream>
#include "FileWriter.hpp"
#include "MemWriter.hpp"
#include "Client.hpp"


int main()
{
	CFileWriter writer("filename");
	CClient c(&writer);
	c.DoProcess();

	CMemWriter mWriter{};
	CClient b(&mWriter);
	b.DoProcess();
}
