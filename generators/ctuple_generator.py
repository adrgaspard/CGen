def generate_tuple_type(size) -> str:
    tuple_type = "tuple_##type1"
    for i in range(2, size + 1):
        tuple_type += "##_##type" + str(i)
    return tuple_type

def generate_line_length(size) -> int:
    return len("typedef struct " + generate_tuple_type(size)) + 1

def generate_line_completion(line, required_length) -> str:
    return line + (" "*(required_length - len(line))) + "\\"

def generate_tuple_macro(size, line_length) -> str:
    tuple_type = generate_tuple_type(size)
    define = "#define INCLUDE_TUPLE" + str(size) + "(type1"
    for i in range(2, size + 1):
        define += ", type" + str(i)
    define += ")\n"
    struct_decl = "typedef struct " + tuple_type + "\n{\n"
    struct_body = ""
    for i in range (1, size + 1):
        struct_body += "    type" + str(i) + " item" + str(i) + ";\n"
    struct_name = "} " + tuple_type + ";\n"
    macro_lines = (define + struct_decl + struct_body + struct_name).splitlines()
    for i in range(len(macro_lines) - 1):
        macro_lines[i] = generate_line_completion(macro_lines[i], line_length)
    return "\n".join(macro_lines)

def generate_tuple_file(start_size, end_size) -> str:
    line_length = generate_line_length(end_size)
    content = "#ifndef __TUPLE_H__\n#define __TUPLE_H__\n"
    for i in range(start_size, end_size + 1):
        content += "\n" + generate_tuple_macro(i, line_length)
    content += "\n\n#endif"
    return content

print(generate_tuple_file(2, 8))