#include "texture2d.h"

using namespace yna::framework::graphics;

Texture2D::Texture2D()
    : Bounds(_bounds), Height([this] () { return _bounds.Height; }), Width([this] () { return _bounds.Width; })
{ }

void Texture2D::GetData(std::vector<Color>& data)
{ }

void Texture2D::GetData(std::vector<Color>& data, int width, int height)
{ }

void Texture2D::SetData(const std::vector<Color>& data)
{ }

void Texture2D::SetData(const std::vector<Color>& data, int width, int height)
{ }
