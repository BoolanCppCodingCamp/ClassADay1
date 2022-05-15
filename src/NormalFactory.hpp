#pragma once

#include "StrategyFactory.hpp"
#include "NormalStrategy.hpp"
#include <memory>

class NormalFactory : public StrategyFactory
{
	protected:
	std::unique_ptr<IWriteStrategy> createStrategy() override {
		return std::make_unique<NormalStrategy>();
	}
};


