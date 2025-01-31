/*
 *  dn_logger.c - Simple, lightweight and fast logging library written in C.
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

#include <stdarg.h>
#include <stdio.h>
#include <windows.h>

#define DN_RESET_SEQ "\x1b[0m"

static const char* const COLORS[5] = {
    "\x1b[35m",
    "\x1b[32m",
    "\x1b[33m",
    "\x1b[31m",
    "\x1b[1;31m",
};

static const char* const PREFIXES[5] = {
    "[DEBUG]: ",
    "[INFO]: ",
    "[WARN]: ",
    "[ERROR]: ",
    "[FATAL]: ",
};

void dn_logger_initialize() {
  DWORD mode = 0;
  HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
  GetConsoleMode(console_handle, &mode);
  mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(console_handle, mode);
}

void dn_logger_shutdown() {
  DWORD mode = 0;
  HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
  GetConsoleMode(console_handle, &mode);
  mode &= ~ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(console_handle, mode);
}

void dn_logger_log(DN_LogLevel log_level, const char* format, ...) {
  const char* color = COLORS[log_level];
  const char* prefix = PREFIXES[log_level];

  char buffer[512] = {0};
  char output[512] = {0};

  va_list args;
  va_start(args, format);
  vsnprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 1, format, args);
  va_end(args);

  sprintf_s(output, sizeof(output), "%s%s%s%s", color, prefix, buffer, DN_RESET_SEQ);
  printf_s("%s", output);
}
