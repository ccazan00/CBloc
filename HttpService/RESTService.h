#ifndef CRESTSERVICE_H
#define CRESTSERVICE_H

#include <QObject>
#include <QThread>

#include "HttpService/RequestManager.h"
#include "HttpService/ResponseManager.h"
#include "HttpService/APIs/BaseRequestAPI.h"

class CRESTService : public QObject
{
    Q_OBJECT
public:
    explicit CRESTService(QObject *parent = nullptr);
    ~CRESTService();

    void ProcessOneTimeRequest(CBaseRequestAPI*);

    CResponseManager* GetResponseManager() const;

signals:
    void SendRequestToManager(CBaseRequestAPI*);

public slots:

private:
    QThread* m_pThread;
    CRequestManager* m_pRequestManager;
    CResponseManager* m_pResponseManager;
};

#endif // CRESTSERVICE_H
