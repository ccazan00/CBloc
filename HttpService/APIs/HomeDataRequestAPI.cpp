#include "HomeDataRequestAPI.h"

#include "HttpService/Entities/HomeDataRequestEntity.h"

static const QString& GET_HOME_DATA_API_NAME = "getHomeData";

CHomeDataRequestAPI::CHomeDataRequestAPI(const QString sBuildingId, const QString sFlatId, const QString sFlatKey) :
    CBaseRequestAPI(
        new CHomeDataRequestEntity(sBuildingId, sFlatId, sFlatKey),
        EApiType::GetHomeData,
        GET_HOME_DATA_API_NAME)
{
}
