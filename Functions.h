#pragma once

template<class T> T max(T value1, T value2)
{
	if (value1 >= value2) { return value1 }
	else { return value2 }
}