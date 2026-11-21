#ifndef __DRAWER_INTERFACE_H__
#define __DRAWER_INTERFACE_H__

namespace Redactor
{

namespace Graphic
{

namespace Drawers
{
    template<typename TObject, class TContext>
    class IDrawer
    {
    public:
        virtual ~IDrawer(void) {};
        virtual void Draw(const TObject& object, const TContext& context) const = 0;
    };
}

}

}

#endif // __DRAWER_INTERFACE_H__
