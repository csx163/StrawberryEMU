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

#ifndef BARBERSHOPSTYLE_STRUCT_H
#define BARBERSHOPSTYLE_STRUCT_H

#include "Define.h"

struct BarberShopStyleData
{
    uint32 Id;
    uint32 Type;
    std::string Name;
    uint32 NameFlags;
    std::string Description;
    uint32 DescriptionFlags;
    float CostMultiplier;
    uint32 RaceId;
    uint32 GenderId;
    uint32 HairId;
};

typedef UNORDERED_MAP<uint32, BarberShopStyleData> BarberShopStyleDataContainer;

#endif