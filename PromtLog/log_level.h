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

namespace promt_log
{
	class log_level
	{
	public:
		enum value
		{
			LL_IMPORTANT_INFO,
			LL_ERROR = LL_IMPORTANT_INFO,
			LL_NOT_SET = LL_IMPORTANT_INFO,
			LL_WARNING,
			LL_DEBUG,
			LL_TRACE,
			LL_COUNT
		};
	protected: 
		value m_value;
	public:
		log_level(size_t v = LL_NOT_SET);
		log_level(const char*);
		~log_level();

		inline bool operator<=(const log_level& o) const { return m_value <= o.m_value; }
		inline size_t to_size_t() const  { return static_cast<size_t>(m_value); }
		inline const char * to_string() const { return (const char*)s_log_level_names[m_value]; }

		static void set_log_names(const char*);
	private:
		static const size_t s_log_level_name_len = 100;
		static char s_log_level_names[value::LL_COUNT][s_log_level_name_len];
		static bool s_log_level_names_alreadey_set;
	};
};

