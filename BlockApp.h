#ifndef BLOCKAPP_H
#define BLOCKAPP_H

#include <QObject>
#include <QQmlApplicationEngine>

class CRESTService;
class CHomeDataModel;

class CBlockApp : public QObject
{
    Q_OBJECT
public:
    explicit CBlockApp(QObject* pParent = nullptr);
    ~CBlockApp();

    void SetEngine(const QQmlApplicationEngine& engine);

    void SendRequest();

private:
    CRESTService* m_pRestService;
    CHomeDataModel* m_pHomeDataModel;

};

#endif // BLOCKAPP_H
