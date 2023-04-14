# Templates

__Disadvantage of overloaded function:__ Each overloaded function definition does identical tasks. But the only change/difference with the overloaded function is that, they are handling arguments of different data types to do identical tasks. This is a disadvantage because, the data types of function arguments are different, we are writing separate code for function definition for performing the same task.

__Concept of templates:__ Pass the data type as a parameter so that we don’t need to write the same code for different data types. C++ adds two new keywords to support templates: ‘template’ and ‘type name’. The second keyword can always be replaced by the keyword ‘class’.

__templates characteristics:__

- Expanded at compile time.(Like Macro but, bit different)
- Compiler does type-checking before template expansion.
- Source code contains only one function/class, but compiled code may contain multiple copies of the same function/class.
- Templates are not at all expanded or verified (if any syntax error) if it is not used for single time in entire program.
- Templates are sometimes called parameterized classes or functions.

[Sample Code.](../templates.cpp)

## Function Templates

Refer [function templates example.](../function_templates.cpp)
Refer [bubble sort using templates.](../bubble_sort_templates.cpp)

## Class Templates

Refer [Array class using templates.](../array_class_templates.cpp)

## Templates with multiple arguments

Refer [Multiple arguments in templates.](../multiple_arguments_templates.cpp)

## Default value for template argument

Refer [default value to the arguments in templates.](../default_value_template_argumets.cpp)

## Static member in a template function

Each instance of a template contains its own static variable.

[sample code.](../static_member_function_templates.cpp)

## Static member in a template class

[sample code.](../static_member_class_templates.cpp)

## Template specialization

Different code for a particular data type.

Example of [function template specialization](../function_template_specialization.cpp)
Example of [class template specialization](../class_template_specilization.cpp)

If a specialized version is present, compiler first checks with the specialized version and then the main template.

## Passing non-type parameters to templates

We can pass non-type arguments to templates and must be const. Non-type parameters are mainly used for specifying max or min values or any other constant value for a particular instance of a template. Compiler must know the value of non-type parameters at compile time. Compiler needs to create functions/classes for a specified non-type value at compile time.

Example of [passing non-type parameters](../non_type_parameters_template.cpp)

