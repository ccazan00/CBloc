#pragma once

#include <QString>
#include "BaseEntity.h"

class CHomeDataRequestEntity : public IBaseEntity
{
public:
    CHomeDataRequestEntity() = delete;
    CHomeDataRequestEntity(QString sBuildingId, QString sFlatId, QString sFlatKey);

    QJsonObject toJson() override;
    void SetFromJson(QJsonObject&) override;

private:
    QString m_sBuildingId;
    QString m_sFlatId;
    QString m_sFlatKey;
};
