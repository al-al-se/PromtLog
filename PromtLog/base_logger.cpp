/*
   Copyright 2019 Alekseev Aleksandr al.al.se@yandex.ru

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "stdafx.h"

#include "config.h"

#include "base_logger.h"

promt_log::base_logger::base_logger()
{
}


promt_log::base_logger::~base_logger()
{
}

void promt_log::base_logger::set_log_level(log_level lv) 
{
	m_log_level = lv; 
}

uint64_t get_thread_id()
{
#ifdef FOR_WINDOWS
	return static_cast<uint64_t>(GetCurrentThreadId());
#endif

#ifdef FOR_LINUX
		/*to do linux case*/
#endif
}

promt_log::base_logger& promt_log::operator<<(base_logger& lg, log_level lv)
{
	if (lv <= lg.get_log_level())
	{
		lg.skip_line(false);
		lg.start_line();
		lg.add_to_line(lg.get_line_count());
		lg.add_to_line(" ");
		lg.add_current_time_to_line();
		lg.add_to_line(" ");
		lg.add_to_line(get_thread_id());
		lg.add_to_line(" ");
		lg.add_to_line(lv.to_string());
		lg.add_to_line(" ");
	}
	else
	{
		lg.skip_line(true);
	}
	return lg;
}

promt_log::base_logger& promt_log::operator<<(base_logger& lg, const char* pc )
{
	if (pc == nullptr)
		return lg;
	if (*pc == '\0')
		return lg;
	if (*pc == '\n')
	{
		lg.finish_line();
		return lg;
	}
	lg.add_to_line(pc);
	return lg;
}

promt_log::base_logger& promt_log::operator<<(base_logger& lg, int32_t v)
{
	lg.add_to_line(v);
	return lg;
}

promt_log::base_logger& promt_log::operator<<(base_logger& lg, uint32_t v)
{
	lg.add_to_line(v);
	return lg;
}


promt_log::base_logger& promt_log::operator<<(base_logger& lg, int64_t v)
{
	lg.add_to_line(v);
	return lg;
}


promt_log::base_logger& promt_log::operator<<(base_logger& lg, uint64_t v)
{
	lg.add_to_line(v);
	return lg;
}


promt_log::base_logger& promt_log::operator<<(base_logger& lg, float v)
{
	lg.add_to_line(v);
	return lg;
}


promt_log::base_logger& promt_log::operator<<(base_logger& lg, double v)
{
	lg.add_to_line(v);
	return lg;
}


