/*
 *  dn_logger.h - Simple, lightweight and fast logging library written in C.
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

#pragma once

typedef enum DN_LogLevel {
  DN_LOG_LEVEL_DEBUG,
  DN_LOG_LEVEL_INFO,
  DN_LOG_LEVEL_WARN,
  DN_LOG_LEVEL_ERROR,
  DN_LOG_LEVEL_FATAL,
} DN_LogLevel;

void dn_logger_initialize();
void dn_logger_shutdown();
void dn_logger_log(DN_LogLevel log_level, const char* format, ...);

#ifdef _DEBUG
#define DN_LOG_DEBUG(format, ...) dn_logger_log(DN_LOG_LEVEL_DEBUG, format, __VA_ARGS__)
#else
#define DN_LOG_DEBUG(format, ...)
#endif
#define DN_LOG_INFO(format, ...) dn_logger_log(DN_LOG_LEVEL_INFO, format, __VA_ARGS__)
#define DN_LOG_WARN(format, ...) dn_logger_log(DN_LOG_LEVEL_WARN, format, __VA_ARGS__)
#define DN_LOG_ERROR(format, ...) dn_logger_log(DN_LOG_LEVEL_ERROR, format, __VA_ARGS__)
#define DN_LOG_FATAL(format, ...) dn_logger_log(DN_LOG_LEVEL_FATAL, format, __VA_ARGS__)
