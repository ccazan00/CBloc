#include "HomeDataEntity.h"

static const char* HOME_DATA_JSON_ADDRESS               { "address" };
static const char* HOME_DATA_JSON_BUILDINGNAME          { "buildingName" };
static const char* HOME_DATA_JSON_FLATNO                { "flatNo" };
static const char* HOME_DATA_JSON_FLATSTAIRCASE         { "flatStaircase" };
static const char* HOME_DATA_JSON_MAINTENANCEPAYMENT    { "maintenancePayment" };
static const char* HOME_DATA_JSON_MAINTENANCEDUETO      { "maintenanceDueTo" };
static const char* HOME_DATA_JSON_INDEXES               { "indexes" };
static const char* HOME_DATA_JSON_NOTIFICATIONNO        { "notificationNo" };

CHomeDataEntity::CHomeDataEntity()
    : m_nNotificationNumber(0)
{

}

QString CHomeDataEntity::GetAddress() const
{
    return m_sAddress;
}

QString CHomeDataEntity::GetBuildingName() const
{
    return m_sBuildingName;
}

QString CHomeDataEntity::GetFlatNo() const
{
    return m_sFlatNo;
}

QString CHomeDataEntity::GetFlatStaircase() const
{
    return m_sFlatStaircase;
}

QString CHomeDataEntity::GetMaintenancePayment() const
{
    return m_sMaintenancePayment;
}

QString CHomeDataEntity::GetMaintenanceDueTo() const
{
    return m_sMaintenanceDueTo;
}

QString CHomeDataEntity::GetIndexes() const
{
    return m_sIndexes;
}

qint32 CHomeDataEntity::GetNotificationNumber() const
{
    return m_nNotificationNumber;
}

QJsonObject CHomeDataEntity::toJson()
{
    QJsonObject obj;
    obj[HOME_DATA_JSON_ADDRESS]             = m_sAddress;
    obj[HOME_DATA_JSON_BUILDINGNAME]        = m_sBuildingName;
    obj[HOME_DATA_JSON_FLATNO]              = m_sFlatNo;
    obj[HOME_DATA_JSON_FLATSTAIRCASE]       = m_sFlatStaircase;
    obj[HOME_DATA_JSON_MAINTENANCEPAYMENT]  = m_sMaintenancePayment;
    obj[HOME_DATA_JSON_MAINTENANCEDUETO]    = m_sMaintenanceDueTo;
    obj[HOME_DATA_JSON_INDEXES]             = m_sIndexes;
    obj[HOME_DATA_JSON_NOTIFICATIONNO]      = m_nNotificationNumber;
    return obj;
}

void CHomeDataEntity::SetFromJson(QJsonObject& json)
{
    //json example: {"address":"str.Grigore Moisil, 5","buildingName":"7BIS","flatNo":"75","flatStaircase":"B","maintenancePayment":"245 LEI","maintenanceDueTo":"25.04.2021","indexes":"trimise","notificationNo":"3"}

    if (json.contains(HOME_DATA_JSON_ADDRESS) && json[HOME_DATA_JSON_ADDRESS].isString())
    {
        m_sAddress = json[HOME_DATA_JSON_ADDRESS].toString();
    }

    if (json.contains(HOME_DATA_JSON_BUILDINGNAME) && json[HOME_DATA_JSON_BUILDINGNAME].isString())
    {
        m_sBuildingName = json[HOME_DATA_JSON_BUILDINGNAME].toString();
    }

    if (json.contains(HOME_DATA_JSON_FLATNO) && json[HOME_DATA_JSON_FLATNO].isString())
    {
        m_sFlatNo = json[HOME_DATA_JSON_FLATNO].toString();
    }

    if (json.contains(HOME_DATA_JSON_FLATSTAIRCASE) && json[HOME_DATA_JSON_FLATSTAIRCASE].isString())
    {
        m_sFlatStaircase = json[HOME_DATA_JSON_FLATSTAIRCASE].toString();
    }

    if (json.contains(HOME_DATA_JSON_MAINTENANCEPAYMENT) && json[HOME_DATA_JSON_MAINTENANCEPAYMENT].isString())
    {
        m_sMaintenancePayment = json[HOME_DATA_JSON_MAINTENANCEPAYMENT].toString();
    }

    if (json.contains(HOME_DATA_JSON_MAINTENANCEDUETO) && json[HOME_DATA_JSON_MAINTENANCEDUETO].isString())
    {
        m_sMaintenanceDueTo = json[HOME_DATA_JSON_MAINTENANCEDUETO].toString();
    }

    if (json.contains(HOME_DATA_JSON_INDEXES) && json[HOME_DATA_JSON_INDEXES].isString())
    {
        m_sIndexes = json[HOME_DATA_JSON_INDEXES].toString();
    }

    if (json.contains(HOME_DATA_JSON_NOTIFICATIONNO) && json[HOME_DATA_JSON_NOTIFICATIONNO].isString())
    {
        m_nNotificationNumber = json[HOME_DATA_JSON_NOTIFICATIONNO].toInt();
    }

}
