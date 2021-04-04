#ifndef CRESPONSEMANAGER_H
#define CRESPONSEMANAGER_H

#include <QObject>
#include <QJsonObject>

#include <HttpService/APIs/APIDefinitions.h>

class CHomeDataEntity;

class CResponseManager : public QObject
{
    Q_OBJECT
public:
    explicit CResponseManager(QObject* pParent);
    ~CResponseManager();

public slots:
    void HandleResponse(quint32 nApiId, QString sResponse);

private:
    void ParseResponseJson(EApiType eApiResponseType, QJsonObject&);

signals:
    void HomeDataReceived(CHomeDataEntity* entity);
};

#endif // CRESPONSEMANAGER_H
