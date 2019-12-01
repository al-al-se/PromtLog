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

#pragma once
#include <vector>
#include "base_logger.h"

namespace promt_log
{
	class logger_vector :
		public base_logger
	{
	protected:
		std::vector<base_logger> m_logger;
	public:
		logger_vector();
		~logger_vector();

		virtual bool init(const char*) override;
	protected:
		virtual void skip_line(bool v)override;
		virtual void start_line()override;

		virtual size_t	get_line_count()override;

		virtual void add_current_time_to_line()override;
		virtual void add_to_line(const char*)override;
		virtual void add_to_line(int32_t)override;
		virtual void add_to_line(uint32_t)override;
		virtual void add_to_line(int64_t)override;
		virtual void add_to_line(uint64_t)override;
		virtual void add_to_line(float)override;
		virtual void add_to_line(double)override;

		virtual void finish_line()override;
	};
}

