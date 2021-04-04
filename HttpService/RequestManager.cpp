#include <QNetworkReply>
#include <QUrlQuery>
#include <QThread>

#include "RequestManager.h"
#include "HttpService/APIs/BaseRequestAPI.h"

//#include "HttpService/Entities/HomeDataEntity.h" // TODO:delete

static const QNetworkRequest::Attribute AutoDeleteReplyOnFinishAttribute = static_cast<QNetworkRequest::Attribute>(28);
static const QNetworkRequest::Attribute RequestAttributeUniqueId         = static_cast<QNetworkRequest::Attribute>(QNetworkRequest::User + 1);
static const QNetworkRequest::Attribute RequestAttributeApiId            = static_cast<QNetworkRequest::Attribute>(QNetworkRequest::User + 2);
static const QNetworkRequest::Attribute RequestAttributeApiName          = static_cast<QNetworkRequest::Attribute>(QNetworkRequest::User + 3);

uint64_t CRequestManager::m_nUniqueRequestIdCount = 0;

static const QString CBLOCK_API_URL = "https://us-central1-cblocapi.cloudfunctions.net/app-API/";

CRequestManager::CRequestManager(QObject *parent) : QObject(parent)
{
    m_qRequestManager.setParent(this);
    connect(&m_qRequestManager, &QNetworkAccessManager::finished, this, &CRequestManager::ProcessHttpReply);
}

CRequestManager::~CRequestManager()
{
    qDebug() << "Destroying CRequestManager ... ";
    disconnect(&m_qRequestManager, &QNetworkAccessManager::finished, this, &CRequestManager::ProcessHttpReply);
}

void CRequestManager::ProcessHttpRequest(CBaseRequestAPI* pApiRequest)
{
    QUrl url(CBLOCK_API_URL + pApiRequest->GetApiName());
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    const quint64 nRequestId = m_nUniqueRequestIdCount++;
    const quint32 nApiID = static_cast<quint32>(pApiRequest->GetApiType());
    const QString& sApiName = pApiRequest->GetApiName();
    const QByteArray& sData = pApiRequest->GetData();

    request.setAttribute(RequestAttributeUniqueId, QVariant::fromValue(nRequestId));
    request.setAttribute(RequestAttributeApiId, QVariant::fromValue(nApiID));
    request.setAttribute(RequestAttributeApiName, QVariant(sApiName));
    request.setAttribute(AutoDeleteReplyOnFinishAttribute, QVariant(true));

    qDebug() << "Request on thread [" << QThread::currentThreadId() << "]"
                   << " id:" << request.attribute(RequestAttributeUniqueId)
                   << " type: "<< request.attribute(RequestAttributeApiId)
                   << " name: " << request.attribute(RequestAttributeApiName)
                   << " autodelete: " << request.attribute(AutoDeleteReplyOnFinishAttribute)
                   << " header: " << request.rawHeaderList()
                   << " data: " << sData;

    m_qRequestManager.post(request, sData);

    delete pApiRequest;
}

void CRequestManager::ProcessHttpReply(QNetworkReply* pReply)
{
    qDebug() << "CRequestManager::OnHttpFinished";

    if (pReply->error() != QNetworkReply::NoError)
    {
        qDebug() << pReply->error();
    }
    else
    {

        const quint32 nRequestId = pReply->request().attribute(RequestAttributeUniqueId).toUInt();
        const quint32 nApiId = pReply->request().attribute(RequestAttributeApiId).toUInt();
        const QString sApiName = pReply->request().attribute(RequestAttributeApiName).toString();

        qDebug() << "Response on [" << QThread::currentThreadId() <<"] for request #" << nRequestId << " api " << sApiName << " (" << nApiId << ")";
        qDebug() << "Reply AutoDeleteReplyOnFinishAttribute: " << pReply->attribute(AutoDeleteReplyOnFinishAttribute).toBool();

        const QString sResponse = QString::fromUtf8(pReply->readAll());
        //qDebug() << "answer------------>"<<sResponse;

        emit ResponseReceived(nApiId, sResponse);

    }
}

//void CRequestManager::ProcessDemoRequest()
//{
//    DoSampleRequest();
//}

//void CRequestManager::DoSampleRequest()
//{
//    qDebug() << "CRequestManager::DoSampleRequest";

//    QUrl url("https://us-central1-cblocapi.cloudfunctions.net/app-API/getHomeData");
//    QNetworkRequest request(url);
//    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

//    request.setAttribute(RequestAttributeUniqueId, QVariant::fromValue(m_nUniqueRequestIdCount++));
//    request.setAttribute(RequestAttributeApiId, QVariant::fromValue(1));
//    request.setAttribute(RequestAttributeApiName, QVariant("getHomeData"));
//    request.setAttribute(AutoDeleteReplyOnFinishAttribute, QVariant(true));

//    QJsonObject obj;
//    obj["buildingID"] = "M3Zh5N0d";
//    obj["flatID"] = "ANfZyWlF";
//    obj["flatKey"] = "a4oFHT5G";
//    const QJsonDocument doc(obj);
//    const QByteArray& data = doc.toJson();
//    m_qRequestManager.post(request, data);


//    //qDebug() << "Request attribute id: " << request.attribute(RequestAttributeUniqueId) << " [" << QThread::currentThreadId() << "]";
//    qDebug() << request.rawHeaderList();

//}
