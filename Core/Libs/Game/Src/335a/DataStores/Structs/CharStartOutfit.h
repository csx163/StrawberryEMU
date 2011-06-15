/*
 * Copyright (C) 2010-2011 Strawberry-Pr0jcts <http://www.strawberry-pr0jcts.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CHARSTARTOUTFIT_STRUCT_H
#define CHARSTARTOUTFIT_STRUCT_H

#include "Define.h"

#define MAX_ITEMS 24

struct CharStartOutfitData
{
    uint32 Id;
    uint32 RaceId;
    uint32 ClassId;
    uint32 GenderId;
    uint32 SomeValues;
    uint32 ItemId[MAX_ITEMS];
    uint32 DisplayId[MAX_ITEMS];
    uint32 InventoryType[MAX_ITEMS];
};

typedef UNORDERED_MAP<uint32, CharStartOutfitData> CharStartOutfitDataContainer;

#endif