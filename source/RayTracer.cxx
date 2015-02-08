#include "RayTracer.hxx"

REX_NS_BEGIN

// new ray tracer
RayTracer::RayTracer( Scene* scene )
    : _pScene( scene )
{
}

// destroy ray tracer
RayTracer::~RayTracer()
{
    const_cast<Scene*>( _pScene ) = 0;
}

// trace the ray
Color RayTracer::Trace( const Ray& ray ) const
{
    return Color::Black;
}

// trace the ray
Color RayTracer::Trace( const Ray& ray, int depth ) const
{
    return Color::Black;
}

REX_NS_END