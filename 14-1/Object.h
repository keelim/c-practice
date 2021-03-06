#pragma once
#include "Common.h"

typedef struct _Object Object;
typedef int ObjectValue;

Object *Object_new(void); // 기본 생성자

Object *Object_newWith(ObjectValue aValue);

// Object 값이 주어지는 생성자
void Object_delete(Object *_this);

void Object_setValue(Object *_this, ObjectValue newValue);

ObjectValue Object_value(Object *_this);