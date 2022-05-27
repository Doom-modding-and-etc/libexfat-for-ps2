/*
	exfat.c (14.12.21)
	Definitions of structures and constants used in BDM exFAT file system
	implementation.

	Free exFAT implementation for sony Plastation 2.
  CopyRight(C) 2021-2022 André Guilherme
  
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
  Description: PURE WIP
*/

#include "ps2exfat.h"
#include "exfat.h"
#include <kernel.h>
#include <malloc.h>
#include <sifrpc.h>
#include <fcntl.h>
#include <dirent.h>

extern char *bdm_irx[];
extern char *size_bdm_irx;
extern char *usbd_irx[];
extern char *size_usbd_irx;


void bdm_init_exfat_partition()
{
  int ret; // good old ret.

  printf("Initializing exfat");
  SifRpcInit(0);

  SifExecModuleBuffer(bdm_irx, size_bdm_irx, NULL, ret);
  SifExecModuleBuffer(usbd_irx, size_usbd_irx, NULL, ret);
  
  ret = SifRpcLoadModuleBuffer("host0: bdm.irx", 0, NULL);
  if(!ret)
  {
    printf("Failed to load the module");
  }
  
  ret = SifRpcLoadModuleBuffer("host0:, usbd.irx", 0, NULL);
  if(!ret)
  {
    printf("Failed to load the module");
  }
}

int bdm_exfat_dir_list(const char *dir)
{
  DIR *dp;
  struct dirent *ep; 
  struct exfat_node *exfs_node;   
  struct exfat *exfs; 
  u32 size;
  dp = opendir(dir);
  
  //get the size of the sectors
  for(u32 i; i < exfs_node->start_cluster; i++)
  {
      return sizeof(exfs);
  }

    printf("RIP ROMHACK");
  
  if(dp)
  {
    while (ep = readdir(dp))
      puts(exfs_node->name);

    closedir(dp);
  }
  else
  {
    printf("Couldn't open the directory");
  }
  return 0;
}

bool mkdir_bdm_exfat(const char *dir, BDM_DISC_INTERFACE *device)
{
  if(device == USB)
  {
    mkdir(dir, 0777);
  }
  
  if(device == MX4SIO)
  {
    mkdir(dir, 777);
  }

  if(device == ilink)
  {
    mkdir(dir, 0777);
  }
  else
  {
    printf("Unknown device");
  }
}

void bdm_exfat_get_fragmentation(const BDM_DISC_INTERFACE *device)
{
  const struct exfat *exfs;
  struct exfat_super_block *block;
  off_t a, b;
  for(u32 i; i < 0; i++)
  {
      sizeof(block->sector_count);
      exfat_find_used_sectors(exfs, &a, &b);
  }
}

#ifdef PURE_WIP
bool ummount_bdm_exfat(bool *ummount, const BDM_DISC_INTERFACE *device)
{
   

}
#endif

//int main();
