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

#ifndef AREA_GROUP_STRUCT_H
#define AREA_GROUP_STRUCT_H

#include "Define.h"

#define MAX_GROUP_AREA_IDS 6

struct AreaGroupData
{
    uint32  AreaGroupId;
    uint32  AreaId[MAX_GROUP_AREA_IDS];
    uint32  NextGroup;
};

typedef UNORDERED_MAP<uint32, AreaGroupData> AreaGroupDataContainer;

#endif