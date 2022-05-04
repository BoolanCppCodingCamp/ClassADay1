#ifndef I_WRITE_STRATEGY_HPP_
#define I_WRITE_STRATEGY_HPP_

enum class StrategyTag : int
{
	NORMAL,
	LAZY,
	RELIABLE
};

class IWriteStrategy
{
public:
	IWriteStrategy() = default;
	IWriteStrategy(const IWriteStrategy&) = default;
	IWriteStrategy& operator=(const IWriteStrategy&) = default;
	IWriteStrategy(IWriteStrategy&&) = delete;
	IWriteStrategy& operator=(IWriteStrategy&&) = delete;

	virtual int OnWriteAt(int pos, void* data, int length) = 0;
	virtual ~IWriteStrategy() {};

};


#endif
