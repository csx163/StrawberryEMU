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

#include "Data.h"
#include "ObjectMgr.h"

Data<AreaTableData> sAreaTableData;

void DataTables::LoadAreaTableData()
{
    sLog->outString("Loading AreaTable Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* AreaTableDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_AREATABLE_DATA_DBC);
        PreparedQueryResult AreaTableDataResult = DataDB.Query(AreaTableDataStatement);

        if (!AreaTableDataResult)
        {
            sLog->outError("Error while loading AreaTable Data");
            sLog->outString();
        }
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = AreaTableDataResult->Fetch();
                AreaTableData areaTableData;

                areaTableData.Id = TableFields[0].GetUInt32();
                areaTableData.MapId = TableFields[1].GetUInt32();
                areaTableData.ZoneId = TableFields[2].GetUInt32();
                areaTableData.ExploreFlag = TableFields[3].GetUInt32();
                areaTableData.Flags = TableFields[4].GetUInt32();
                areaTableData.SoundProvider = TableFields[5].GetUInt32();
                areaTableData.SoundProviderUw = TableFields[6].GetUInt32();
                areaTableData.AmbienceId = TableFields[7].GetUInt32();
                areaTableData.ZoneMusicId = TableFields[8].GetUInt32();
                areaTableData.IntroId = TableFields[9].GetUInt32();
                areaTableData.AreaLevel = TableFields[10].GetInt32();
                areaTableData.AreaName = TableFields[11].GetString();
                areaTableData.NameFlags = TableFields[12].GetUInt32();
                areaTableData.TeamId = TableFields[13].GetUInt32();
                areaTableData.LiquidTypeId = TableFields[14].GetUInt32();
                areaTableData.MinElevation = TableFields[15].GetFloat();
                areaTableData.AmbientMultiplier = TableFields[16].GetFloat();

                AreaTableDataTable[areaTableData.Id] = areaTableData;

                ++count;
            }
            while (AreaTableDataResult->NextRow());

            sLog->outString(">> Loaded %u area tables %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}
