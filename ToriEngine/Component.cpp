#include "Component.h"
#include "Object.h"

void Component::SetObject(Object* object)
{
	object_ = object;
}

Object* Component::GetObj() const
{
	return object_;
}
