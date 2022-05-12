/*
	exfat.h (14.12.21)
	Definitions of structures and constants used in BDM exFAT file system
	implementation.

	Free exFAT implementation for sony Plastation 2.
    CopyRight (C) 2021-2022 André Guilherme Mendes Da Luz Bastos

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

//types 
typedef unsigned int mount_t;
typedef unsigned char name_t;
typedef unsigned int ummount_t;
typedef double clusters_t;
typedef unsigned int dir_t;
typedef unsigned short list_t;
typedef long init_t;
typedef unsigned int cache_t; 

void bdm_init_exfat_partition(name_t *partition_name, init_t *partition, clusters_t *cluster, BDM_DISC_INTERFACE);
int bdm_exfat_dir_list(list_t *list, dir_t *dir);
bool mkdir_bdm_exfat_partition_mount(mount_t *partition, dir_t *dir);
void bdm_exfat_get_fragmentation(const BDM_DISC_INTERFACE *fragmentation);
void bdm_exfat_ignore_fragmentation(const bool fragmentation);
bool ummount_bdm_exfat(ummount_t *ummount, clusters_t *clusters_off);



