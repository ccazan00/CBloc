#pragma once

#include <QObject>
#include "HttpService/Entities/HomeDataEntity.h"

class CHomeDataModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString address              READ GetAddress             NOTIFY AddressChanged)
    Q_PROPERTY(QString buildingName         READ GetBuildingName        NOTIFY BuildingNameChanged)
    Q_PROPERTY(QString flatNo               READ GetFlatNo              NOTIFY FlatNoChanged)
    Q_PROPERTY(QString flatStaircase        READ GetFlatStaircase       NOTIFY FlatStaircaseChanged)
    Q_PROPERTY(QString maintenancePayment   READ GetMaintenancePayment  NOTIFY MaintenancePaymentChanged)
    Q_PROPERTY(QString maintenanceDueTo     READ GetMaintenanceDueTo    NOTIFY MaintenanceDueToChanged)
    Q_PROPERTY(QString indexes              READ GetIndexes             NOTIFY IndexesChanged)
    Q_PROPERTY(qint32  notificationNumber   READ GetNotificationNumber  NOTIFY NotificationNumberChanged)

public:
    explicit CHomeDataModel(QObject* pParent);
    ~CHomeDataModel();

public slots:
    void HandleDataUpdate(CHomeDataEntity*);

protected:
    QString GetAddress() const;
    QString GetBuildingName() const;
    QString GetFlatNo() const;
    QString GetFlatStaircase() const;
    QString GetMaintenancePayment() const;
    QString GetMaintenanceDueTo() const;
    QString GetIndexes() const;
    qint32 GetNotificationNumber() const;

signals:
    void AddressChanged();
    void BuildingNameChanged();
    void FlatNoChanged();
    void FlatStaircaseChanged();
    void MaintenancePaymentChanged();
    void MaintenanceDueToChanged();
    void IndexesChanged();
    void NotificationNumberChanged();

    Q_INVOKABLE void requestUpdate();

private:
    CHomeDataEntity* m_pData;
};
