#pragma once

#include <QJsonObject>

class IBaseEntity
{
public:
    IBaseEntity() = default;
    virtual ~IBaseEntity() = default;

    virtual QJsonObject toJson() = 0;
    virtual void SetFromJson(QJsonObject&) = 0;
};
