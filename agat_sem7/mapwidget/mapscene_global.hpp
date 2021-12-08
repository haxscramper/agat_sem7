#ifndef MAPSCENE_GLOBAL_H
#define MAPSCENE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MAPWIDGET_LIBRARY)
#  define MAPWIDGET_EXPORT Q_DECL_EXPORT
#else
#  define MAPWIDGET_EXPORT Q_DECL_IMPORT
#endif

#endif // MAPSCENE_GLOBAL_H
