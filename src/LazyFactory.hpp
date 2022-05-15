#pragma once

#include "StrategyFactory.hpp"
#include "LazyStrategy.hpp"
#include <memory>

class LazyFactory : public StrategyFactory
{
	protected:
	std::unique_ptr<IWriteStrategy> createStrategy() override {
		return std::make_unique<LazyStrategy>();
	}
};


