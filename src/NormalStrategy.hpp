#ifndef NORMAL_STRATEGY_HPP_
#define NORMAL_STRATEGY_HPP_

#include <iostream>

class NormalStrategy : public IWriteStrategy
{
public:
	NormalStrategy() = default;
	NormalStrategy(const NormalStrategy&) = default;
	NormalStrategy& operator=(const NormalStrategy&) = default;
	NormalStrategy(NormalStrategy&&) = delete;
	NormalStrategy& operator=(NormalStrategy&&) = delete;
	~NormalStrategy() = default;

	int OnWriteAt(int pos, void* data, int length) override
	{
		std::cout << "NORMAL>>" << std::endl;
		return length;
	}
private:
};

#endif
