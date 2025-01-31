/*
 *  demo.c - Simple, lightweight and fast logging library written in C.
 *  Copyright (C) 2025  Bekir Kağan Karaahmetoğlu <kagankaraahmetoglu@hotmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <dn_logger/dn_logger.h>

int main(int argc, char* argv[]) {
  dn_logger_initialize();
  dn_logger_log(DN_LOG_LEVEL_INFO, "%s\n", "This is an info message.");
  DN_LOG_DEBUG("%s\n", "This is a debug message.");
  DN_LOG_INFO("%s\n", "This is an info message.");
  DN_LOG_WARN("%s\n", "This is a warning message.");
  DN_LOG_ERROR("%s\n", "This is an error message.");
  DN_LOG_FATAL("%s\n", "This is a fatal message.");
  dn_logger_shutdown();
  return 0;
}
