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

#ifndef ANIMATION_DATA_STRUCT_H
#define ANIMATION_DATA_STRUCT_H

#include "Define.h"

struct AnimationDataData
{
    uint32 Id;
    std::string Name;
    uint32 WeaponFlags;
    uint32 BodyFlags;
    uint32 Flags;
    uint32 FallBack;
    uint32 BehaviorId;
    uint32 BehaviorTier;
};

typedef UNORDERED_MAP<uint32, AnimationDataData> AnimationDataDataContainer;

#endif