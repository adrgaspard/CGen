def generate_line_completion(line, required_length):
    return line + (" "*(required_length - len(line))) + "\\"

def generate_cgen_file(input, output) -> str:
    lines = None
    with open(input) as file:
        lines = file.read().replace("JOIN", "##").replace("\t", "    ").replace("_type", "_##type").replace("type_", "type##_").splitlines()
    max_length = 0
    for line in lines:
        max_length = max(max_length, len(line))
    max_length = max_length + 1
    result = list()
    last_line = None
    inside_macro = False
    for line in lines:
        if line.startswith("/* --- Ignore --- */"):
            continue
        if line.startswith("/* --- macro_end --- */"):
            inside_macro = False
            if (len(result) > 0):
                result.pop()
                result.append(last_line)
            continue
        if line.startswith("/* --- macro_start --- "):
            inside_macro = True
            macro_name = line.replace("/* --- macro_start --- ", "").replace(" */", "")
            result.append(generate_line_completion("#define " + macro_name, max_length))
            continue
        last_line = line
        if inside_macro:
            result.append(generate_line_completion(line, max_length))
        else:
            result.append(line)
    with open(output, "w") as file:
        file.write("\n".join(result))
        

generate_cgen_file("../template/cgen.c", "../lib/cgen_generated.h")