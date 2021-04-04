#include <QJsonDocument>

#include "BaseRequestAPI.h"
#include "HttpService/Entities/BaseEntity.h"

CBaseRequestAPI::CBaseRequestAPI(IBaseEntity* pEntity, EApiType eApiType, const QString& sApiName):
    m_pEntity(pEntity),
    m_eApiType(eApiType),
    m_sApiName(sApiName)
{
}

EApiType CBaseRequestAPI::GetApiType() const
{
    return m_eApiType;
}

const QString& CBaseRequestAPI::GetApiName() const
{
    return m_sApiName;
}

QByteArray CBaseRequestAPI::GetData() const
{
    const QJsonDocument doc(m_pEntity->toJson());
    return doc.toJson();
}
