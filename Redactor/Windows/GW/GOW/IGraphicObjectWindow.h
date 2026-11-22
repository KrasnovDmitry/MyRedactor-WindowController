#ifndef __GRAPHIC_OBJECT_WINDOW_INTERFACE_H__
#define __GRAPHIC_OBJECT_WINDOW_INTERFACE_H__

#include "../../Window/Window.h"

namespace Redactor
{

namespace Windows
{

namespace GW
{

namespace GOW
{
    template<typename TObject>
    class IGraphicObjectWindow: public Redactor::Windows::Window
    {
    public:
        virtual ~IGraphicObjectWindow(void) {};

        TObject* GetObjectPtr(void) const
        {
            return objectPtr;
        }

        void SetObjectPtr(TObject* objectPtr)
        {
            this->objectPtr = objectPtr;
        }

    protected:
        TObject* objectPtr;
    };
}

}

}

}

#endif // __GRAPHIC_OBJECT_WINDOW_INTERFACE_H__
