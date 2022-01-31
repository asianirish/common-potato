#ifndef HIERHIN_CONST_H
#define HIERHIN_CONST_H

#include "type.h"

//#define DEFAULT_LINK_OWNER_ROLE Role("links")

namespace hierhin {

class Const
{
public:
static const Role DEFAULT_LINK_OWNER_ROLE;
static const QString LINK_REF_SIGN; //TODO: + link role?

static const QString TARGET_PROP;
static const QString SOURCE_PROP;
static const QString BIDIR_PROP;


};


} // namespace hierhin

#endif // HIERHIN_CONST_H
