/***************************************************************************
*            k_hash.h
*
*  Tue January 05 01:22:53 2016
*  Copyright  2016  lk
*  <user@host>
****************************************************************************/
/*
* utils.h
*
* Copyright (C) 2016 - lk
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef k_hash_h
#define k_hash_h

typedef struct k_hash_entry_s
{
	void* key;
	void* val;
}k_hash_entry_t;

typedef struct k_hash_table_s
{
	k_hash_entry_t* entries;
	int size;
	void* key;
	void* val;
}k_hash_table_t;

int k_hash_value(const char* str_val);


#endif
