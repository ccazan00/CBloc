#include "RESTService.h"
#include "APIs/APIDefinitions.h"

#define WAIT_FOR_THREAD_TIMEOUT 1500

CRESTService::CRESTService(QObject *parent) :
    QObject(parent),
    m_pThread(new QThread(this)),
    m_pResponseManager(new CResponseManager(this)),
    m_pRequestManager(new CRequestManager())
{
    connect(m_pThread, &QThread::finished, m_pThread, &QThread::deleteLater);

    // Initialize http request manager thread
    m_pThread->setObjectName("httpNetworkThread");
    m_pRequestManager->moveToThread(m_pThread);
    m_pThread->start();

    qRegisterMetaType<EApiType>("EApiType");
    qRegisterMetaType<QJsonObject>("QJsonObject");
    connect(this, &CRESTService::SendRequestToManager, m_pRequestManager, &CRequestManager::ProcessHttpRequest);
    connect(m_pRequestManager, &CRequestManager::ResponseReceived, m_pResponseManager, &CResponseManager::HandleResponse);
}

CRESTService::~CRESTService()
{
    qDebug() << "Destroying CRESTService ... ";
    if (m_pRequestManager)
    {
        m_pRequestManager->deleteLater();
        m_pRequestManager = nullptr;
    }

    if (m_pThread)
    {
        m_pThread->quit();
        m_pThread->wait(WAIT_FOR_THREAD_TIMEOUT);
        m_pThread = nullptr;
    }
}

void CRESTService::ProcessOneTimeRequest(CBaseRequestAPI* pApiRequest)
{
    emit SendRequestToManager(pApiRequest);
}

CResponseManager *CRESTService::GetResponseManager() const
{
    return m_pResponseManager;
}
