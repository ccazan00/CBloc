#ifndef IBASEENTITY_H
#define IBASEENTITY_H

#include <QString>
#include <QJsonObject>

#include "HttpService/Entities/BaseEntity.h"
#include "APIDefinitions.h"


class CBaseRequestAPI
{
public:
    CBaseRequestAPI() = delete;
    CBaseRequestAPI(IBaseEntity* pEntity, EApiType eApiType, const QString& sApiName);

    EApiType GetApiType() const;
    const QString&  GetApiName() const;
    QByteArray      GetData() const;

protected:
    IBaseEntity* m_pEntity;

private:
    EApiType m_eApiType;
    const QString&  m_sApiName;
};

#endif // IBASEENTITY_H
