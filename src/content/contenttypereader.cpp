#include "content/contenttypereader.h"

using namespace yna::framework::content;

ContentTypeReader::ContentTypeReader(Type targetType)
    : TargetType(_targetType), _targetType(targetType)
{ }
