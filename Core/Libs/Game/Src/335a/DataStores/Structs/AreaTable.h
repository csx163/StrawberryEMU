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

#ifndef AREATABLE_STRUCT_H
#define AREATABLE_STRUCT_H

#include "Define.h"
#include "DBCEnums.h"

struct AreaTableData
{
    uint32 Id;
    uint32 MapId;
    uint32 ZoneId;
    uint32 ExploreFlag;
    uint32 Flags;
    int32 AreaLevel;
    std::string AreaName;
    uint32 NameFlags;
    uint32 TeamId;

    bool IsSanctuary() const
    {
        if (MapId == 609)
            return true;

        return (Flags & AREA_FLAG_SANCTUARY);
    }
};

AreaTableData const* GetAreaEntryByAreaID(uint32 area_id);
AreaTableData const* GetAreaEntryByAreaFlagAndMap(uint32 area_flag, uint32 map_id);

typedef UNORDERED_MAP<uint32, AreaTableData> AreaTableDataContainer;

#endif