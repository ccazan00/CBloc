#include "HomeDataRequestEntity.h"

CHomeDataRequestEntity::CHomeDataRequestEntity(const QString sBuildingId, const QString sFlatId, const QString sFlatKey) :
    m_sBuildingId(sBuildingId),
    m_sFlatId(sFlatId),
    m_sFlatKey(sFlatKey)
{
}

QJsonObject CHomeDataRequestEntity::toJson()
{
    QJsonObject obj;
    obj["buildingID"] = m_sBuildingId;
    obj["flatID"] = m_sFlatId;
    obj["flatKey"] = m_sFlatKey;
    return obj;
}

void CHomeDataRequestEntity::SetFromJson(QJsonObject& qJsonObject)
{
    // TODO
}
