#include <iostream>
#include "FileWriter.hpp"
#include "MemWriter.hpp"
#include "Client.hpp"
#include "IWriteStrategy.hpp"


int main()
{
	CFileWriter writer{"filename"};
	CClient c(&writer);

	auto handler1{
		writer.GetWriteEvent()+=[](int pos, int length){
			std::cout << "lambda: write " << pos << ", " << length << std::endl;
		}
	};
	c.DoProcess();
	writer.GetWriteEvent()-=handler1;
	c.DoProcess();

	CFileWriter Writer{"filename"};
	CClient c1(&Writer);
	c1.DoProcess();

	CMemWriter mWriter{};
	CClient b(&mWriter);
	b.DoProcess();
}
