#ifndef CRESPONSEHOMEDATAENTITY_H
#define CRESPONSEHOMEDATAENTITY_H

#include "BaseEntity.h"

class CHomeDataEntity : public IBaseEntity
{
public:
    CHomeDataEntity();

    QString GetAddress() const;
    QString GetBuildingName() const;
    QString GetFlatNo() const;
    QString GetFlatStaircase() const;
    QString GetMaintenancePayment() const;
    QString GetMaintenanceDueTo() const;
    QString GetIndexes() const;
    qint32 GetNotificationNumber() const;

    virtual QJsonObject toJson();
    virtual void SetFromJson(QJsonObject&);

private:
    QString m_sAddress;
    QString m_sBuildingName;
    QString m_sFlatNo;
    QString m_sFlatStaircase;
    QString m_sMaintenancePayment;
    QString m_sMaintenanceDueTo;
    QString m_sIndexes;
    qint32 m_nNotificationNumber;
};

#endif // CRESPONSEHOMEDATAENTITY_H
