#include "Stat.h"

Stat::Stat(int statValue)
{
	needStart = statValue;
	currentStat = needStart / 2;
}