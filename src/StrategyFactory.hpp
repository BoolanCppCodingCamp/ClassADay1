#pragma once
#include "IWriteStrategy.hpp"
#include <memory>

class StrategyFactory
{
public:
	virtual ~StrategyFactory() = default;
	std::unique_ptr<IWriteStrategy> requestStrategy()
	{
		++m_numberProduced;
		return createStrategy();
	}

	size_t getNumerProduced() const {
		return m_numberProduced;
	}

protected:
	virtual std::unique_ptr<IWriteStrategy> createStrategy() = 0;

private:
	size_t m_numberProduced{0};
};
