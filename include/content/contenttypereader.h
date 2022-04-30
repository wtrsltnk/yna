#ifndef CONTENTTYPEREADER_H
#define CONTENTTYPEREADER_H

#include "../property.h"
#include "../type.h"
#include "contentreader.h"

namespace yna
{

    namespace framework
    {

        namespace content
        {

            class ContentTypeReader
            {
                Type _targetType;

            protected:
                ContentTypeReader(Type targetType);

            public:
                // Gets the type handled by this reader component.
                get_property<Type> TargetType;

                virtual void *Read(ContentReader *input) = 0;
            };

        } // namespace content

    } // namespace framework

} // namespace yna

#endif // CONTENTTYPEREADER_H
