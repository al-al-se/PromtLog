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
#include <stdint.h>
#include <string>
#include "log_level.h"

namespace promt_log
{
	class base_logger
	{
	public:
		base_logger();
		~base_logger();

		virtual bool init(const char*) = 0;
	protected:
		bool m_b_initialized = false;
	public:
		inline bool is_initialized() const { return m_b_initialized; }

	protected:
		log_level m_log_level;
	public:
		inline log_level	get_log_level() const { return m_log_level; }
		virtual void		set_log_level(log_level lv);

		/*
		 !!!Start new line!!!
		 */
		static friend base_logger& operator<<(base_logger& lg, log_level lv);
		/* \n end - line */
		static friend base_logger& operator<<(base_logger&, const char*);
		static friend base_logger& operator<<(base_logger&, int32_t);
		static friend base_logger& operator<<(base_logger&, uint32_t);
		static friend base_logger& operator<<(base_logger&, int64_t);
		static friend base_logger& operator<<(base_logger&, uint64_t);
		static friend base_logger& operator<<(base_logger&, float);
		static friend base_logger& operator<<(base_logger&, double);
		/*
		add friend operator << to yours class
		*/
	protected:
		virtual void skip_line(bool v) = 0;
		virtual void start_line() = 0;

		virtual size_t	get_line_count() = 0;

		virtual void add_current_time_to_line() = 0;
		virtual void add_to_line(const char*) = 0;
		virtual void add_to_line(int32_t) = 0;
		virtual void add_to_line(uint32_t) = 0;
		virtual void add_to_line(int64_t) = 0;
		virtual void add_to_line(uint64_t) = 0;
		virtual void add_to_line(float) = 0;
		virtual void add_to_line(double) = 0;

		virtual void finish_line() = 0;
	};

};
