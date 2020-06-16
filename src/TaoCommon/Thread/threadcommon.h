#pragma once
#include <QMetaType>
#include <functional>
namespace TaoCommon
{
    using WorkCallback = std::function<bool()>;
    using WorkResultCallback = std::function<void(bool)>;
    Q_DECLARE_METATYPE(WorkCallback);
    Q_DECLARE_METATYPE(WorkResultCallback);
}
