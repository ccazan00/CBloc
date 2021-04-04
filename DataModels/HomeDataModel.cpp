#include "HomeDataModel.h"
#include <QDebug>

CHomeDataModel::CHomeDataModel(QObject* pParent) :
    QObject(pParent),
    m_pData(nullptr)
{

}

CHomeDataModel::~CHomeDataModel()
{
    if (m_pData)
    {
        delete m_pData;
        m_pData = nullptr;
    }
}

void CHomeDataModel::HandleDataUpdate(CHomeDataEntity *pData)
{
    qDebug() << "CHomeDataModel::UpdateData";
    if (m_pData)
    {
        delete m_pData;
    }
    m_pData = pData;

    emit AddressChanged();
    emit BuildingNameChanged();
    emit FlatNoChanged();
    emit FlatStaircaseChanged();
    emit MaintenancePaymentChanged();
    emit MaintenanceDueToChanged();
    emit IndexesChanged();
    emit NotificationNumberChanged();
}

QString CHomeDataModel::GetAddress() const
{
    if (m_pData)
    {
        return m_pData->GetAddress();
    }
    return "";
}

QString CHomeDataModel::GetBuildingName() const
{
    if (m_pData)
    {
        return m_pData->GetBuildingName();
    }
    return "";
}

QString CHomeDataModel::GetFlatNo() const
{
    if (m_pData)
    {
        return m_pData->GetFlatNo();
    }
    return "";
}

QString CHomeDataModel::GetFlatStaircase() const
{
    if (m_pData)
    {
        return m_pData->GetFlatStaircase();
    }
    return "";
}

QString CHomeDataModel::GetMaintenancePayment() const
{
    if (m_pData)
    {
        return m_pData->GetMaintenancePayment();
    }
    return "";
}

QString CHomeDataModel::GetMaintenanceDueTo() const
{
    if (m_pData)
    {
        return m_pData->GetMaintenanceDueTo();
    }
    return "";
}

QString CHomeDataModel::GetIndexes() const
{
    if (m_pData)
    {
        return m_pData->GetIndexes();
    }
    return "";
}

qint32 CHomeDataModel::GetNotificationNumber() const
{
    if (m_pData)
    {
        return m_pData->GetNotificationNumber();
    }
    return 0;
}
