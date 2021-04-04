#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QThread>

#include "ResponseManager.h"
#include "HttpService/Entities/HomeDataEntity.h"

CResponseManager::CResponseManager(QObject* pParent) : QObject(pParent)
{
}

CResponseManager::~CResponseManager()
{
    qDebug() << "Destroying CResponseManager ... ";
}

void CResponseManager::HandleResponse(quint32 nResponseId, QString sResponse)
{
    qDebug() << "Handle api #" << nResponseId << " on thread [" << QThread::currentThreadId() <<"]";

    const QJsonDocument doc = QJsonDocument::fromJson(sResponse.toUtf8());
    if(!doc.isNull())
    {
        if(doc.isObject())
        {
            const EApiType eApiType = static_cast<EApiType>(nResponseId);
            QJsonObject json = doc.object();
            ParseResponseJson(eApiType, json);
        }
        else
        {
            qDebug() << "HandleResponse error: Invalid doc";
        }
    }
    else
    {
        qDebug() << "HandleResponse error: invalid response";
    }
}

void CResponseManager::ParseResponseJson(EApiType eApiResponseType, QJsonObject& json)
{
    switch(eApiResponseType)
    {
    case EApiType::GetHomeData:
        CHomeDataEntity* pEntity = new CHomeDataEntity;
        pEntity->SetFromJson(json);
        qDebug() << " *** Home Data Received. Sample info; Building name: " << pEntity->GetAddress();
        emit HomeDataReceived(pEntity);
        break;
    }
}
