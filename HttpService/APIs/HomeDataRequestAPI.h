#ifndef REQUESTHOMEDATAAPI_H
#define REQUESTHOMEDATAAPI_H

#include "BaseRequestAPI.h"

class CHomeDataRequestEntity;

class CHomeDataRequestAPI : public CBaseRequestAPI
{
public:
    CHomeDataRequestAPI(const QString sBuildingId, const QString sFlatId, const QString sFlatKey);
};

#endif // REQUESTHOMEDATAAPI_H
