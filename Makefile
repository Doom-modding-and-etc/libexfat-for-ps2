#
#	Makefile.am (30.03.15)
#	Makefile (13.12.21)
#   Automake source.
#
#	Free exFAT implementation.
#	Copyright (C) 2010-2018  Andrew Nayenko
#       Copyright (C) 2021-2022 André Guilherme
#	This program is free software; you can redistribute it and/or modify
#	it under the terms of the GNU General Public License as published by
#	the Free Software Foundation, either version 2 of the License, or
#	(at your option) any later version.
#
#	This program is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	GNU General Public License for more details.
#
#	You should have received a copy of the GNU General Public License along
#	with this program; if not, write to the Free Software Foundation, Inc.,
#	51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#

EE_CFLAGS += -Wall -Os -I. -I../include -I../include/exfat

EE_LIB = libexfat.a 

EE_OBJS = mount.o

EE: $(EE_LIB) 
ifeq ($(PS2DEV),)
	@echo "$PS2DEV ENVIROMENT is not set. Could not install libexfat."
	@exit 1
endif
	@echo Copying...
	@cp -frv include/exfat.h $(PS2SDK)/ee/include
	@cp -f $(EE_LIB) $(PS2SDK)/ee/lib
	@echo Done!

clean:
	@rm -f -r $(EE_LIB) $(EE_OBJS) 

install: EE clean

include $(PS2SDK)/Defs.make
include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
