#include "TaoCommon_plugin.h"

#include <QtQml>
#include "Common/Tools.h"
void TaoCommonPlugin::registerTypes(const char *uri)
{
    // @uri com.JaredTao.TaoCommon
    qmlRegisterSingletonType<TaoCommon::Tools>(uri, 1, 0, "Tools", &TaoCommon::tools_singletontype_provider);
}

