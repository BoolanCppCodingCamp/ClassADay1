#include <iostream>
#include "FileWriter.hpp"
#include "MemWriter.hpp"
#include "Client.hpp"
#include "IWriteStrategy.hpp"


int main()
{
	CFileWriter writer("filename");
	CClient c(&writer);
	c.DoProcess();

	CFileWriter lazyWriter("filename", StrategyTag::LAZY);
	CClient c1(&lazyWriter);
	c1.DoProcess();

	CMemWriter mWriter{};
	CClient b(&mWriter);
	b.DoProcess();
}
