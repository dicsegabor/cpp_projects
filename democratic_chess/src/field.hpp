#ifndef _FIELD_H
#define _FIELD_H

#include "control.h"

class Field
{
    int content;

    int value;

  public:
    Field(int content = neutral) : content(content), value(content) {}
    Field(const Field &f) : content(f.content), value(f.value) {}

    int get_Content() { return content; }
    int get_Value() { return value; }

    bool is_Empty() { return content == 0; }

    void add_to_Value(int x) { value += x; }

    void empty_Field()
    {
        content = neutral;
        value   = 0;
    }

    void reset_Value() { value = content; }

    Field &operator=(const Field &f);
};

#endif // !_FIELD_H
