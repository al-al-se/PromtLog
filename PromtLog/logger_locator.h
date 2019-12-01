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
#include <map>
#include "log_vector.h"

namespace promt_log
{
	class logger_locator
	{
	private:
		static bool s_b_initialized;
		static logger_vector m_app_logger;
		static std::map<int64_t, logger_vector> m_key_to_logger;
		static std::map<std::string, logger_vector> m_name_to_logger;
	public:
		static bool init_from_json_string(const char *);
		static bool init_from_json_file(const char *);

		static base_logger& app();
		static base_logger& by_key(int64_t);
		static base_logger& by_name(const char*);
	};
};

