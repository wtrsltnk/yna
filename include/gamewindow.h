#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "platform.h"
#include "property.h"

namespace yna
{

    namespace framework
    {

        class GameWindow
        {
        protected:
            WindowHandle _handle;
            int _clientSizeWidth;
            int _clientSizeHeight;

        public:
            GameWindow();
            virtual ~GameWindow();

            get_property<WindowHandle> Handle;
            get_property<int> ClientSizeWidth;
            get_property<int> ClientSizeHeight;

        protected:
            void OnClientSizeChanged();
        };

    } // namespace framework

} // namespace yna

#endif // GAMEWINDOW_H
