#ifndef LAZY_STRATEGY_HPP_
#define LAZY_STRATEGY_HPP_

#include <iostream>

class LazyStrategy : public IWriteStrategy
{
public:
	LazyStrategy() = default;
	LazyStrategy(const LazyStrategy&) = default;
	LazyStrategy& operator=(const LazyStrategy&) = default;
	LazyStrategy(LazyStrategy&&) = delete;
	LazyStrategy& operator=(LazyStrategy&&) = delete;
	~LazyStrategy() = default;

	int OnWriteAt(int pos, void* data, int length) override
	{
		// TODO, only flush when the internal buffer is about
		// to full.
		std::cout << "LAZY>>" << std::endl;
		return length;
	}
private:
};

#endif
