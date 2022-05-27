/*
	ps2exfat.h(14.12.21)
	Definitions of structures and constants used in BDM exFAT file system
	implementation.

	Free exFAT implementation for sony Plastation 2.
    CopyRight (C) 2021-2022 André Guilherme

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

#include <stdbool.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
//Normal definitions 
#define EXFAT_NAME_MAX 255 
#define MBR 0X07
#define PARTITION MBR 
#define VOLUME_SIZE_MIN 7168
#define CLUSTER_SIZE_MIN 4096
#define VOLUME_SIZE_MAX 2408000
#define CLUSTER_SIZE_MAX 1024
#define DRIVE 0X00000001
#define FRAGMENTATION

typedef enum
{
	MX4SIO = 0X000004,
	ilink = 0x0000010,
	USB = 0X000000012
} BDM_DISC_INTERFACE;

void bdm_init_exfat();
int bdm_exfat_dir_list(const char *dir);
bool mkdir_bdm_exfat(const char *dir, BDM_DISC_INTERFACE *device);
void bdm_exfat_get_fragmentation(const BDM_DISC_INTERFACE *device);

#ifdef PURE_WIP
bool ummount_bdm_exfat(bool *ummount, const BDM_DISC_INTERFACE *device);
#endif
