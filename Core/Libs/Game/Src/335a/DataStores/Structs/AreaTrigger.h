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

#ifndef AREATRIGGER_STRUCT_H
#define AREATRIGGER_STRUCT_H

#include "Define.h"

struct AreaTriggerData
{
    uint32  Id;
    uint32  MapId;
    float   X;
    float   Y;
    float   Z;
    float   Radius;
    float   BoxLength_X;
    float   BoxLength_Y;
    float   BoxLength_Z;
    float   BoxOrientation;
};

typedef UNORDERED_MAP<uint32, AreaTriggerData> AreaTriggerDataContainer;

#endif