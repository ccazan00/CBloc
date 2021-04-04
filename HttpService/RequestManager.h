#ifndef CREQUESTMANAGER_H
#define CREQUESTMANAGER_H

#include <QObject>
#include <QJsonObject>
#include <QNetworkAccessManager>

#include "APIs/APIDefinitions.h"

class CBaseRequestAPI;

class CRequestManager : public QObject
{
    Q_OBJECT
public:
    explicit CRequestManager(QObject *parent = nullptr);
    ~CRequestManager();

signals:

public slots:
    void ProcessHttpReply(QNetworkReply* pNetworkReply);
    void ProcessHttpRequest(CBaseRequestAPI* pApiRequest);

signals:
    void ResponseReceived(quint32 nApiId, QString sResponse);

private:
    QNetworkAccessManager m_qRequestManager;
    static uint64_t m_nUniqueRequestIdCount;
};

#endif // CREQUESTMANAGER_H
