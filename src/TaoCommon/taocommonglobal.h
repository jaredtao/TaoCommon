#pragma once
#include <QtCore/QtGlobal>

#ifndef BUILD_STATIC
# if defined(TaoCommon_Library)
#  define TAO_API Q_DECL_EXPORT
# else
#  define TAO_API Q_DECL_IMPORT
# endif
#else
# define TAO_API
#endif
