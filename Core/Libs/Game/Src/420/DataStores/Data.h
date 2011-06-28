#include "AreaTable.h"
/*
 * Copyright (C) 2010-2011 Strawberry-Pr0jcts <http://www.strawberry-pr0jcts.com/>
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

#ifndef DATA_H
#define DATA_H

#include "AreaTable.h"

template<class T>
class Data
{
    public:
        T const* GetDataId(uint32 Id) const { return (Id >= Count) ? NULL : TableIndex[Id]; }
        uint32 GetRows() const { return Count; }

    private:
        uint32 Count;
        T** TableIndex;
        T* DataTable;
};

class DataTables
{
    public:
        // Load DBC Data tables
        void LoadAreaTableData();

        AreaTableDataContainer AreaTableDataTable;
};

extern Data<AreaTableData> sAreaTableData;
#define sData ACE_Singleton<Data, ACE_Null_Mutex>::instance()
#define sDataTables ACE_Singleton<DataTables, ACE_Null_Mutex>::instance()

#endif
