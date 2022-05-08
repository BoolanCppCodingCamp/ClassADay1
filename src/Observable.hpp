#pragma once

#include  <iostream>
#include "Event.hpp"

class Observable
{
public:
	auto& GetWriteEvent(){
		return m_WriteEvent;
	}
	
	auto& GetWriteEndEvent() {
		return m_WriteEndEvent;
	}

	void OnWrite(int pos, int length) {
		GetWriteEvent().raise(pos, length);
	}
		
	void OnWriteEnd() {
		GetWriteEndEvent().raise();
	}

private:
	Event<int, int> m_WriteEvent;
	Event<>m_WriteEndEvent;
};
