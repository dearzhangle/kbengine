/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __DEADLINE_FORMAT__
#define __DEADLINE_FORMAT__
#include "cstdkbe/cstdkbe.hpp"
#include <math.h>

namespace KBEngine
{

/**
 *	期限
 */
class Deadline
{
public:
	Deadline(uint32 secs):
	days(0),
	hours(0),
	minutes(0),
	seconds(0),
	secs_(secs)
	{
		if(secs > 0)
		{
            days = secs / (3600 * 24);
            int m = secs % (3600 * 24);
            hours = m / 3600;
            m = m % 3600;
            minutes = m / 60;
            seconds = m % 60;
		}
	}
	
	virtual ~Deadline() {}

	std::wstring wprint()
	{
		return (boost::wformat(L"%1%天%2%小时%3%分%4%秒") % days % hours % minutes % seconds).str();
	}

	std::string printCN()
	{
		return (boost::format("%1%days/%2%:%3%:%4%") % days % hours % minutes % seconds).str();
	}
	
	uint32 days, hours, minutes, seconds;
	uint32 secs_;
};


}

#endif // __DEADLINE_FORMAT__
