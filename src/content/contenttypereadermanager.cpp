#include "contenttypereadermanager.h"
#include "texture2dreader.h"

#include <algorithm>

using namespace yna::framework::content;

std::map<Type, ContentTypeReaderFactory*> ContentTypeReaderManager::_contentTypeReaderFactories;

ContentTypeReaderManager::ContentTypeReaderManager()
{
    // List of readers that need to be added to this ContentTypeReaderManager
    Texture2DReader::textureContentTypeReaderFactory.Init();
}

ContentTypeReader* ContentTypeReaderManager::GetTypeReader(Type targetType)
{
    auto found = _contentTypeReaderFactories.find(targetType);

    if (found != _contentTypeReaderFactories.end())
    {
        return found->second->Create();
    }

    return nullptr;
}

namespace yna
{

namespace framework
{

namespace content
{

void AddContentTypeReader(Type targetType, ContentTypeReaderFactory* factory)
{
    ContentTypeReaderManager::_contentTypeReaderFactories.insert(std::make_pair(targetType, factory));
}

}

}

}
