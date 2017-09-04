#ifndef CONTENTTYPEREADERMANAGER_H
#define CONTENTTYPEREADERMANAGER_H

#include "../type.h"
#include "contenttypereader.h"
#include <map>

namespace yna
{

namespace framework
{

namespace content
{

class ContentTypeReaderFactory
{
public:
    virtual ContentTypeReader* Create() = 0;
};

class ContentTypeReaderManager
{
    static std::map<Type, ContentTypeReaderFactory*> _contentTypeReaderFactories;

    friend void AddContentTypeReader(Type targetType, ContentTypeReaderFactory* factory);

public:
    ContentTypeReaderManager();

    ContentTypeReader* GetTypeReader(Type targetType);
};

void AddContentTypeReader(Type targetType, ContentTypeReaderFactory* factory);

}

}

}

#endif // CONTENTTYPEREADERMANAGER_H
