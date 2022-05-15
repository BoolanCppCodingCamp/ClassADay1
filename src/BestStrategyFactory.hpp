#pragma once

#include "StrategyFactory.hpp"
#include <memory>

using namespace std;

class BestFactory : public StrategyFactory
{
public:
	explicit BestFactory(vector<unique_ptr<StrategyFactory>>&& factories):
m_factories { std::move(factories)}
{
	if (m_factories.empty())
	{
		throw runtime_error { "No factory" };
	}
}


protected:

std::unique_ptr<IWriteStrategy> createStrategy() override 
{
	StrategyFactory* bestSoFar { m_factories[0].get() };

	for (auto& factory : m_factories) 
	{
		if (factory->getNumerProduced() <
				bestSoFar->getNumerProduced())
		{
			bestSoFar = factory.get();
		}
	}
	return bestSoFar->requestStrategy();
}

private:
	vector<unique_ptr<StrategyFactory>> m_factories;
};


