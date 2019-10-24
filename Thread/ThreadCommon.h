#pragma once

#include <QRunnable>
#include <QThreadPool>
#include <QThread>
#include <functional>
namespace TaoCommon
{
    using WorkCallback = std::function<bool()>;
    using WorkResultCallback = std::function<void(bool)>;
    Q_DECLARE_METATYPE(WorkCallback);
    Q_DECLARE_METATYPE(WorkResultCallback);
}
