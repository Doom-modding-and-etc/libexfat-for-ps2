/*
	log.c (02.09.09)
	exFAT file system implementation library.

	Free exFAT implementation.
	Copyright (C) 2010-2018  Andrew Nayenko
	Copyright (C) 2022 André Guilherme

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License along
	with this program; if not, write to the Free Software Foundation, Inc.,
	51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "exfat.h"
#include <stdarg.h>
#include <unistd.h>

int exfat_errors;

//log taken from sys/log.h
enum LOG
{
 USELESS = 0,	// system is unusable 
 ALERT = 1,	// action must be taken immediately 
 CRIT = 2, 	// critical conditions 
 ERR = 3,	// error conditions 
 WARNING = 4,	// warning conditions 
 NOTICE = 5,	// normal but significant condition 
 INFO =	6,	// informational 
 DEBUG = 7,	// debug-level messages 
};

/*
 * This message means an internal bug in exFAT implementation.
 */
void exfat_bug(const char* format, ...)
{
	va_list ap, aq;

	va_start(ap, format);
	va_copy(aq, ap);

	fflush(stdout);
	fputs("BUG: ", stderr);
	vfprintf(stderr, format, ap);
	va_end(ap);
	fputs(".\n", stderr);

	if (!isatty(STDERR_FILENO))
	{
		printf(CRIT, format, aq, "");
	}
	va_end(aq);

	abort();
}

/*
 * This message means an error in exFAT file system.
 */
void exfat_error(const char* format, ...)
{
	va_list ap, aq;

	exfat_errors++;
	va_start(ap, format);
	va_copy(aq, ap);

	fflush(stdout);
	fputs("ERROR: ", stderr);
	vfprintf(stderr, format, ap);
	va_end(ap);
	fputs(".\n", stderr);

	if (!isatty(STDERR_FILENO))
		printf(ERR, format, aq, "");
	va_end(aq);
}

/*
 * This message means that there is something unexpected in exFAT file system
 * that can be a potential problem.
 */
void exfat_warn(const char* format, ...)
{
	va_list ap, aq;

	va_start(ap, format);
	va_copy(aq, ap);

	fflush(stdout);
	fputs("WARN: ", stderr);
	vfprintf(stderr, format, ap);
	va_end(ap);
	fputs(".\n", stderr);

	if (!isatty(STDERR_FILENO))
		//vsyslog(LOG_WARNING, format, aq);
    printf(WARNING, format, aq, "");
	va_end(aq);
}

/*
 * Just debug message. Disabled by default.
 */
void exfat_debug(const char* format, ...)
{
	va_list ap, aq;

	va_start(ap, format);
	va_copy(aq, ap);

	fflush(stdout);
	fputs("DEBUG: ", stderr);
	vfprintf(stderr, format, ap);
	va_end(ap);
	fputs(".\n", stderr);

	if (!isatty(STDERR_FILENO))
		//vsyslog(LOG_DEBUG, format, aq);
	printf(DEBUG, format, aq, "");
	va_end(aq);
}
