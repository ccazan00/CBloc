#include "BlockApp.h"

#include "HttpService/RESTService.h"
#include "HttpService/APIs/HomeDataRequestAPI.h"
#include "DataModels/HomeDataModel.h"

#include <QQuickView>
#include <QQmlContext>

static const char* APP_NAME_PROPERTY_NAME { "applicationTitle" };
static const char* APP_NAME_PROPERTY_VALUE { "CBlock Application " };
static const char* HOME_DATA_MODEL_PROPERTY_NAME { "homeDataModel" };

CBlockApp::CBlockApp(QObject *pParent):
    QObject(pParent),
    m_pRestService(new CRESTService(this)),
    m_pHomeDataModel(new CHomeDataModel(this))
{
    connect(m_pRestService->GetResponseManager(), &CResponseManager::HomeDataReceived, m_pHomeDataModel, &CHomeDataModel::HandleDataUpdate);
    connect(m_pHomeDataModel, &CHomeDataModel::requestUpdate, [=]() {
        CHomeDataRequestAPI* request = new CHomeDataRequestAPI("M3Zh5N0d", "ANfZyWlF", "a4oFHT5G");
        m_pRestService->ProcessOneTimeRequest(request);
    });
}

CBlockApp::~CBlockApp()
{
    qDebug() << "Destroying CBlockApp... ";
}

void CBlockApp::SetEngine(const QQmlApplicationEngine &engine)
{

    QQmlContext* pRootContext = engine.rootContext();
    pRootContext->setContextProperty(APP_NAME_PROPERTY_NAME, QVariant(APP_NAME_PROPERTY_VALUE));
    pRootContext->setContextProperty(HOME_DATA_MODEL_PROPERTY_NAME, m_pHomeDataModel);

//    QQuickView view;
//    view.rootContext()->setContextProperty("ten", QVariant(10));

//    const QUrl url(QStringLiteral("qrc:/MainWindow.qml"));
//    view.setSource(url);
//    view.show();
}

void CBlockApp::SendRequest()
{
//    CHomeDataRequestAPI* request1 = new CHomeDataRequestAPI("M3Zh5N0d", "ANfZyWlF", "a4oFHT5G");
//    m_pRestService->ProcessOneTimeRequest(request1);
}
